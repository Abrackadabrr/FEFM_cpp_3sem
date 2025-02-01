CXX_COMPILER=g++
LIBRARY_NAME=SPACE
INSTALL_PREFIX=./

# Динамические бибилиотеки компилируется уже самим g++,
# поэтому туда можно сразу подавать исходники .cpp
#
# Отличие динамических библиотек от статически в том, что при линковке 
# они не копируются в исполняемых файл, а загружаются в память
# перед исполнением программы. Таким образом, несколько разных приложений
# могут использовать одну и ту же динамическую библиотеку для своих нужд
# Эта библиотека будет лежать в памяти единственным экземпляром, 
# а значит будет меньше тратиться оперативной памяти

all: goodbye.o anatoly.o cherdenko.o
	echo ${INSTALL_PREFIX}
	${CXX_COMPILER} -fPIC -shared goodbye.cpp anatoly.cpp cherdenko.cpp -o libSPACE.so

install: all
	mkdir -p ${INSTALL_PREFIX}/include
	mkdir -p ${INSTALL_PREFIX}/lib
	cp *.h ${INSTALL_PREFIX}/include
	cp *.so ${INSTALL_PREFIX}/lib

clean: 
	rm *.o *.so

goodbye.o: goodbye.cpp
	${CXX_COMPILER} -c goodbye.cpp -o goodbye.o -fPIC

anatoly.o: anatoly.cpp
	${CXX_COMPILER} -c anatoly.cpp -o anatoly.o -fPIC

cherdenko.o: cherdenko.cpp
	${CXX_COMPILER} -c cherdenko.cpp -o cherdenko.o -fPIC
