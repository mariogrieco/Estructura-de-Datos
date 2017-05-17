#include "Global.h"

#include "Burbuja.h"
#include "SeleccionDirecta.h"
#include "InsercionDirecta.h"
#include "ShellSort.h"
#include "ShakerSoft.h"


int main(int argc, char const *argv[])
{
	int length = 20000; 
	short array[length];



    initRand();
	
    cout << "enter para empezar test..." ;
    cin.get();
    cout << "==================" << endl;
	generar(array,length,10);   //32767
	keepFor(array,length);

	shaker(array,length);
	burbuja(array,length);
	burbuja2(array,length);
	metodoShell(array,length);
	selecionDirecta(array,length);
	inseccionDirecta(array,length);


	cout << "listo!!" << endl;
	cin.get();
	return 0;
}

