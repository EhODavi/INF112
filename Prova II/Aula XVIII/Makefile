all: Teste.o testeStatic_contaInstSeparado.o
	g++ -o teste Teste.o testeStatic_contaInstSeparado.o

Teste.o: Teste.cpp Teste.h
	g++ -c Teste.cpp

testeStatic_contaInstSeparado.o: testeStatic_contaInstSeparado.cpp
	g++ -c testeStatic_contaInstSeparado.cpp
