FLAGS= -Wall -pedantic -std=c++17 -iquote inc

__start__: ./test_arytm_zesp
	./test_arytm_zesp test-arytmetyka.txt 

./test_arytm_zesp: obj obj/main.o obj/LZespolona.o\
                     obj/WyrazenieZesp.o obj/StatystykaTestu.o obj/WykonajTest.o
	g++ -o ./test_arytm_zesp obj/main.o obj/LZespolona.o\
                     obj/WyrazenieZesp.o obj/StatystykaTestu.o obj/WykonajTest.o
					 
					 

obj:
	mkdir obj

obj/main.o: src/main.cpp inc/LZespolona.hh inc/WyrazenieZesp.hh inc/StatystykaTestu.hh inc/WykonajTest.hh
	g++ -c ${FLAGS} -o obj/main.o src/main.cpp

obj/LZespolona.o: src/LZespolona.cpp inc/LZespolona.hh
	g++ -c ${FLAGS} -o obj/LZespolona.o src/LZespolona.cpp

obj/WyrazenieZesp.o: src/WyrazenieZesp.cpp inc/WyrazenieZesp.hh\
                       inc/LZespolona.hh
	g++ -c ${FLAGS} -o obj/WyrazenieZesp.o src/WyrazenieZesp.cpp

obj/StatystykaTestu.o: src/StatystykaTestu.cpp inc/StatystykaTestu.hh
	g++ -c ${FLAGS} -o obj/StatystykaTestu.o src/StatystykaTestu.cpp

obj/WykonajTest.o: src/WykonajTest.cpp inc/WykonajTest.hh inc/LZespolona.hh inc/WyrazenieZesp.hh inc/StatystykaTestu.hh
	g++ -c ${FLAGS} -o obj/WykonajTest.o src/WykonajTest.cpp

/tests/bin/tests_dodawanie: /tests/bin obj/LZespolona.obj
	g++ -o /tests/bin/tests_dodawanie ${FLAGS} -I{/tests}/doctest ${/tests}/tests_dodawanie.cpp obj/LZespolona.o

clean:
	rm -f ./test_arytm_zesp obj/*
