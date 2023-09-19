windows:
	gcc -o dhmodel.exe main.c dhmodel.c matrices.c

linux:
	gcc -o dhmodel main.c dhmodel.c matrices.c -lm