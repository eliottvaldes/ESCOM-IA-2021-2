#include "codigoHuffman.h"
#include <time.h>

void main(int argc, char** argv){
	unsigned int t0, t1;
	t0=clock();
	iniciaOperacion(argc, argv);
	t1=clock();
	double time=(t1-t0)/CLOCKS_PER_SEC;
	printf("\nTiempo de ejecución: %f",time);
}