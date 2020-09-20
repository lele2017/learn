obj-m += mybus.o mydevice.o mydevice-drv.o
KDIR := 
TOOLCHAIN = 
CPUARCH = 
all:
	make -C $(KDIR) M=$(PWD) modules ARCH=$(CPUARCH) CROSS_COMPILE=$(TOOLCHAIN)
clean:
	rm -f *.ko *.o *.mod.o *.mod.c *.symvers  modul* .my.*