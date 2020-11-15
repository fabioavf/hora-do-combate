output: main.o personagem.o
	g++ -std=c++2a main.o personagem.o -o hora-do-combate.exe

main.o: src/main.cpp
	g++ -c src/main.cpp

personagem.o: src/personagem.cpp
	g++ -c src/personagem.cpp

clean: 
	rm *.o hora-do-combate.exe