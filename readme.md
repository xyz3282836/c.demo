# C语言静态动态编译

## 看看运行效果
```
gcc main.c ./inc/add.c ./lib/sub.c -o main.o
```
## gcc
-l xxx or -lxxx 可以是libxxx.so 动态编译的库文件也可以是libxxx.a 静态编译的库文件
-L./xxx or -L ./xxx 库文件所在位置
-Wl,-rpath=/root/c/mydemo/lib 不要用相对路径，用绝对路径
使用相对路径 ldd xxx.so 在编译路径就是显示相对路径，而其他路径直接no found
是为程序添加一个运行时库文件搜索路径的命令，在使用gcc编译链接时添加即可
-fPIC 


-Wl 表示编译器将后面的参数传递给链接器ld

## inc 静态编译
```
cd ./inc
gcc -c ./add.c -o add.o
ar -r libadd.a ./add.o
cd ../
gcc mainadd.c ./inc/libadd.a -o mainadd.o 效果同下
gcc mainadd.c -L ./inc -l add -o mainadd.o

ldd mainadd.o
	linux-vdso.so.1 =>  (0x00007fff5c370000)
	libc.so.6 => /lib64/libc.so.6 (0x00007fbf5c37e000)
	/lib64/ld-linux-x86-64.so.2 (0x00007fbf5c74b000)
```

## lib 动态编译
```
cd ./lib
gcc -shared -fPIC ./sub.c -o libsub.so
cd ../
gcc mainsub.c -L ./lib -l sub -Wl,-rpath=/root/c/mydemo/lib -o mainsub.o

ldd ./lib/libsub.so
	linux-vdso.so.1 =>  (0x00007ffc6fde4000)
	libc.so.6 => /lib64/libc.so.6 (0x00007f1616d3a000)
	/lib64/ld-linux-x86-64.so.2 (0x00007f1617309000)

ldd mainsub.o
	linux-vdso.so.1 =>  (0x00007ffdd17dd000)
	libsub.so => /root/c/mydemo/lib/libsub.so (0x00007f27505f0000)
	libc.so.6 => /lib64/libc.so.6 (0x00007f2750223000)
	/lib64/ld-linux-x86-64.so.2 (0x00007f27507f2000)
```

## 静态库加动态库编译
```
gcc main.c -L ./inc/ -l add -L ./lib/ -l sub -Wl,-rpath=/root/c/mydemo/lib -o main.mix.o
gcc main.c -L ./lib/ -l sub -Wl,-rpath=/root/c/mydemo/lib -L ./inc/ -l add -o main.mix.o
ldd main.mix.o
	linux-vdso.so.1 =>  (0x00007ffc06ba7000)
	libsub.so => /root/c/mydemo/lib/libsub.so (0x00007f9f78a2c000)
	libc.so.6 => /lib64/libc.so.6 (0x00007f9f7865f000)
	/lib64/ld-linux-x86-64.so.2 (0x00007f9f78c2e000)
```






