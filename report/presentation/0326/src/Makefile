rootfs=myroot
output=c
all: init
	gcc -DROOTFS=${rootfs} *.[ch] -o ${output}

init:
	./build.sh ${rootfs}

clean:
	rm -rf ${rootfs} ${output}
