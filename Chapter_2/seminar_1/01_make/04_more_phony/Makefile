# Больше того, что может быть в фиктивных целях
#
# install - установка собранного проекта в систему.
#
# uninstall - обратная операция. 
#
# С этими операциями нужно быть аккуратными, потому что можно что-то случайно перезаписать,
# не туда поставить или что-то удалить слйчайно
#
# Пример с утановкой приложения "hello_there_general_kenobi" в стандартное хранилище бинарников на линукс

.PHONY: all clean install uninstall

all: hello_there_general_kenobi

clean: 
	rm *.o hello_there_general_kenobi

install: hello_there_general_kenobi
	install ./hello_there_general_kenobi /usr/local/bin

uninstall:
	rm /usr/local/bin/hello_there_general_kenobi

general.o: ../02_multiple_rules/general.cpp ../02_multiple_rules/general.hpp
	g++ -c ../02_multiple_rules/general.cpp -o general.o

kenobi.o: ../02_multiple_rules/kenobi.cpp ../02_multiple_rules/kenobi.hpp
	g++ -c ../02_multiple_rules/kenobi.cpp -o kenobi.o

hello_there_general_kenobi: main.cpp general.o kenobi.o ../02_multiple_rules/general.hpp ../02_multiple_rules/kenobi.hpp
	g++ main.cpp general.o kenobi.o -o hello_there_general_kenobi

