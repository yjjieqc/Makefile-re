obj-m := module_param.o
kernel_path=/usr/src/linux-headers-4.4.0-75-generic

all:
	make -C $(kernel_path)  M=$(PWD) modules
clean:
	make -C $(kernel_path)  M=$(PWD) clean
