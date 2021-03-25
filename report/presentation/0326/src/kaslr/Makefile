obj-m:=kaslr.o

PWD := $(shell pwd)
KDIR := /lib/modules/$(shell uname -r)/build

default:
	$(MAKE) -C $(KDIR) M=$(PWD) modules ARCH=um

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean ARCH=um
