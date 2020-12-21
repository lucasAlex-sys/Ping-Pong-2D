all: prog1

prog1: jogos2.o
	@ echo '                Programas tp1'
	@ echo '                                '
	@ echo ' '
	@ echo '                '
	@ echo ' '
		gcc jogos2.c -o jogo2 -lGL -lglut -lGLEW -lm -lSOIL
			./jogo2
	@ echo ' '
	@ echo ' '                              
jogos2.o: jogos2.c



