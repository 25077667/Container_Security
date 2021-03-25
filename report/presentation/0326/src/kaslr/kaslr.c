#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/fs.h>

static void file_write(void *buf, size_t size)
{
	struct file *destFile;
	char *filePath = "/tmp/kaslr.txt";
	destFile = filp_open(filePath, O_CREAT | O_WRONLY | O_APPEND, 0666);
	if (IS_ERR(destFile) || destFile == NULL)
	{
		printk("Cannot open destination file");
		return;
	}

	loff_t offset = default_llseek(destFile, 0, SEEK_END);
	kernel_write(destFile, buf, size, &offset);
	filp_close(destFile, NULL);
}

static int _init(void)
{
	char buf[16] = {0};
	printk("\n%llu\n", _init);
	snprintf(buf, 16, "%llu\n", _init);
	file_write(buf, strlen(buf));
	return 0;
}

static void _exit(void) {}

module_init(_init);
module_exit(_exit);
MODULE_LICENSE("GPL");
