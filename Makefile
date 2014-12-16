
# Defining cross-compiling variables
ARCH=arm
CROSS_COMPILE=/home/pablo/Projects/vodabox3/poky/build/tmp/sysroots/x86_64-linux/usr/bin/arm-poky-linux-gnueabi/arm-poky-linux-gnueabi-

# If KERNELRELEASE is defined, we've been invoked from the
# kernel build system and can use its language.
ifneq ($(KERNELRELEASE),)
	obj-m := adv7611.o

# Otherwise we were called directly from the command
# line; invoke the kernel build system.
else
	KERNELDIR ?= /home/pablo/Projects/vodabox3/poky/build/tmp/work/vodabox3-poky-linux-gnueabi/linux-vodalys/3.18+gitAUTOINC+fd36744cb5-r0/git
	PWD := $(shell pwd)
default:
	$(MAKE) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) -C $(KERNELDIR) M=$(PWD) modules

endif
