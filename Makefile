
obj = zmalloc.o main.o

all : main

# main 是目标文件，$(obj)是依赖文件，cc -o $@ $^ 是生成目标的方法
main : $(obj)
	# $@: 目标文件 $^: 依赖文件
	cc -o $@ $^

zmalloc.o: zmalloc.c zmalloc.h

main.o : main.c
	cc -c main.c
run :
	./main

# clean 是1伪目标(不会生成文件)
.PHONY : clean
clean :
	-rm main && rm -f *.o
