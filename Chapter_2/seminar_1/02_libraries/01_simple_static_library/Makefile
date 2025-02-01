CXX_COMPILER=g++
LIBRARY_NAME=SPACE
INSTALL_PREFIX=./SPACE

# Соберем статическую библиотеку
# Статические библиотеки -- это "архив бинарников"
# Можно считать, что это просто собранные в стопку наши объектные файлы,
# содержищие реализации того, что написано в хедерах (.h .hpp) для этой 
# библиотеки
#
# Статические библиотеки собираются с помощью специального архиватора ar
#  -- флаг -q <название> <список файлов.о> означает добавление бинарников в архив
#  если архива нет, то он создается
#
#  Далее цели all install и clean прописаны так, как они определеяются почти всеми библиотеками
#
#  all -- сбор всего что имеется
#  clean -- очистка всего что имеется
#  install -- установка библиотеки в папку INSTALL_PREFIX
#
#  Подробнее про install:
#  эта цель копирует херед файлы и собранную библиотеку в нужную
#  вам директорию, которая задается с помощью переменной
#  INSTALL_PREFIX

all: goodbye.o anatoly.o cherdenko.o
	echo ${INSTALL_PREFIX}
	ar -q lib${LIBRARY_NAME}.a goodbye.o anatoly.o cherdenko.o

install: all
	mkdir -p ${INSTALL_PREFIX}/include
	mkdir -p ${INSTALL_PREFIX}/lib
	cp *.h ${INSTALL_PREFIX}/include
	cp *.a ${INSTALL_PREFIX}/lib

clean: 
	rm *.o *.a

goodbye.o: goodbye.cpp
	${CXX_COMPILER} -c goodbye.cpp -o goodbye.o

anatoly.o: anatoly.cpp
	${CXX_COMPILER} -c anatoly.cpp -o anatoly.o

cherdenko.o: cherdenko.cpp
	${CXX_COMPILER} -c cherdenko.cpp -o cherdenko.o
