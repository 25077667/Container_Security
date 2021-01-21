rootfs=rootfs
output=c
all: init
	gcc *.[ch] -o ${output}

init:
	./build.sh ${rootfs}

clean:
	rm -rf ${rootfs} ${output}
