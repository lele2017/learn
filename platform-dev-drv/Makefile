obj-m += platform-drv.o platform-dev01.o platform-dev02.o
KDIR := 
TOOLCHAIN = 
CPUARCH = 
all:
	make -C $(KDIR) M=$(PWD) modules ARCH=$(CPUARCH) CROSS_COMPILE=$(TOOLCHAIN)
clean:
	rm -f *.ko *.o *.mod.o *.mod.c *.symvers  modul* .my.*