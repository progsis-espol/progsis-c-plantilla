#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <getopt.h>

#include "input.h"

bool eflag = false; //Opción -e, switch to english
bool iflag = false; //Opción -i, ingresa una línea de texto

int main(int argc, char **argv)
{
	int opt, index;

	/* Este lazo recorre los argumentos buscando las
	opciones -e y -h... */
	while ((opt = getopt (argc, argv, "ieh")) != -1){
		switch(opt)
		{
			case 'i':
				iflag = true;
				break;
			case 'e':
				eflag = true;
				break;
			case 'h':
				printf("Programa en C ejemplo, imprime argumentos ingresados en consola.\n");
				printf("uso:\n %s [-i] [-e] [arg 1] [arg 2] ... [arg n]\n", argv[0]);
				printf(" %s -h\n", argv[0]);
				printf("Opciones:\n");
				printf(" -h\t\t\tAyuda, muestra este mensaje\n");
				printf(" -e\t\t\tSwitch to english\n");
				printf(" -i\t\t\tIngresa una línea de texto\n");
				return 0;
			case '?':
			default:
				fprintf(stderr, "uso: %s [-e] [arg 1] [arg 2] ... [arg n]\n", argv[0]);
				return -1;
		}
	}

	/* Aquí imprime argumentos que no son opción */
	for (index = optind; index < argc; index++) {
		if(eflag)
			printf ("Non-option argument: %s\n", argv[index]);
		else
			printf ("Argumento no-opción: %s\n", argv[index]);
	}

	/* Aquí ingresa una línea de texto desde consola y la reimprime en consola */
	if(iflag) {
		char *texto;
		get_from_console(&texto);
		printf("%s\n", texto);
		free(texto);
	}
}