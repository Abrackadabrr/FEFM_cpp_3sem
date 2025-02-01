# Присвоение переменной:
#
#	VAR = something
#
# Взятие значения:
#
#	VAR1 = ${VAR}
#

CXX_COMPILER=g++
CXX_FLAGS =-std=c++17 -O2
SOURCES = one.cpp two.cpp three.cpp

$(info ${SOURCES})  # вывели на экран значение переменной SOURCES

OBJECTS=$(SOURCES:.cpp=.o)  # заменили все вхождения .cpp в SOURCES на .o

$(info ${OBJECTS})
 
main: ${OBJECTS}
	${CXX_COMPILER} ${CXX_FLAGS} -o main main.cpp ${OBJECTS}

one.o: one.cpp	
	${CXX_COMPILER} ${CXX_FLAGS} one.cpp -c
two.o: two.cpp
	${CXX_COMPILER} ${CXX_FLAGS} two.cpp -c
three.o: three.cpp
	${CXX_COMPILER} ${CXX_FLAGS} three.cpp -c

.PHONY: clean
clean:
	rm ${OBJECTS} main

