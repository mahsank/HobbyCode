# If KERNELRELEASE is defined, we're invoked from the kernel
# build system and can use its language
ifneq ($(KERNELRELEASE),)
	# kbuild part of makefile
	obj-m := hello.o

else
	# normal makefile
	KERNELDIR ?= /lib/modules/$(shell uname -r)/build
	PWD := $(shell pwd)


default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules

endif

clean:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) clean

