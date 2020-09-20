obj-m	+= kset.o
KDIR := 
TOOLCHAIN = 
CPUARCH = 
all:
	make -C $(KDIR) M=$(PWD) modules ARCH=$(CPUARCH) CROSS_COMPILE=$(TOOLCHAIN)
clean:
	rm -rf *.ko *.o *.mod.o *.mod.c *.symvers modul* .my.* .tmp_versions