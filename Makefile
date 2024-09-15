namb: main.c
	gcc ./src/File.o ./src/Lexer.o  main.c -g -o namb
File: ./src/File.c
	gcc ./src/File.c -c -o ./src/File.o
Lexer: ./src/Lexer.c
	gcc ./src/Lexer.c -c -o ./src/Lexer.o
