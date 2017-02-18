#include "Global.h"

#include "Burbuja.h"
#include "SeleccionDirecta.h"
#include "InsercionDirecta.h"
#include "ShellSort.h"


int main(int argc, char const *argv[])
{
	int length = 50; 
	short array[length];



    initRand();
	
    cout << "enter para empezar test..." ;
    cin.get();
    cout << "==================" << endl;
	generar(array,length,32767); 
	keepFor(array,length);

	imprimir(array,length);

	burbuja(array,length);
	burbuja2(array,length);
	metodoShell(array,length);
	selecionDirecta(array,length);
	inseccionDirecta(array,length);


	cout << "listo!!" << endl;
	cin.get();
	return 0;
}

