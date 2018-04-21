obj-m :=mylist.o
kernel_path=/usr/src/linux-headers-4.6.0-rc2-pure

all:
	make -C $(kernel_path)  M=$(PWD) modules
clean:
	make -C $(kernel_path)  M=$(PWD) clean
