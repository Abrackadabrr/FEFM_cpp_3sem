make_lib: make_object
	ar rcs libs/libHello.a src/hello.o

make_object: src/hello.cpp
	g++ src/hello.cpp -c -o src/hello.o

.PHONY: clean Allclean
clean:
	rm libs/libHello.a
	rm src/hello.o
	
Allclean: clean
	rm main
