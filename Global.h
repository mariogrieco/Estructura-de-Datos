#ifndef GLOBAL_H
#define GLOBAL_H 

#include "iostream"
#include "math.h"
#include "stdlib.h"
#include "time.h"
#include "windows.h"

    void initRand(void);
	void imprimir(short[], int);   	    
	void generar(short[],  int, int);		    		    
	void keepFor(short[],  int); 
	int verificar(short[], int);  // VERIFICA SI SE ORDENO CORRECTAMENTE ( DE MENOR A MAYOR ) AUN NO VERIFICA SI EL ARRAY SE ALTERO !
   		
	/**
		function param the array to keep keepFor(*int,int) | keepFor(int[],int)
		RESTAURA EL ARRAY TAL CUAL COMO SE GENERO EN EL COMIENZO ( INTENTA QUE LOS TIEMPOS SEAN PRECISOS ) 
	**/
	void restart(short[],short[],int);   


	// GLOBAL VARS

		clock_t init,end;
		short intercambio = 0;
		short *keepData;         // usada para mantener el array en memoria  

		using namespace std;

void restart(short to[], short what[], int length){
	for (int i = 0; i < length; ++i)
	{
		to[i] = what[i];
	}
}


void keepFor(short array[], int length){
	    keepData = new short[length];
		for (int i = 0; i < length; ++i)
		{
			keepData[i] = array[i];
		}
}

void initRand(void){
	srand(time(NULL));
}

int verificar(short array[], int length){
	for (int i = 0; i < length-1; ++i)
	{
		if ( array[i] > array[i+1] )
		{
			cout << "quedo mal :(" << endl;
			return 0;
		}
	}
	cout << "quedo bien!" << endl;
}


void generar(short array[],int length ,int rango){
	for (int i = 0; i < length; ++i)
	{
		array[i] = rand()%(rango);
	}
}

void imprimir(short array[], int length){
	// for (int i = 0; i < length; ++i)
	// {
	// 	cout << array[i] << " ";
	// }
	// cout << endl;
}

void getUsedTime(){
	cout << "El Tiempo de ejecucion fue de:  ";
	cout << (((double(end-init))/CLOCKS_PER_SEC)*1000) << "ms" << endl;
	cout << "========================="<<endl;
}

#endif