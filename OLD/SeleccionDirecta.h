#ifndef SELECCION_DIRECTA_H
#define SELECCION_DIRECTA_H
	
		void selecionDirecta(short[],int);    

     // correcta? esta al contrario de la clase
	// nota en la clase busca al mayor sin y despues lo pone al final

void selecionDirecta(short array[], int length){  
	cout << "Cargando..." << endl;
	init = clock();
	int pos;
	short swap;
	for (int i = 0; i < length-1; ++i)
	{
		pos = i;
		for (int x = i+1; x < length; ++x)
		{
			if ( array[x] < array[pos] )
			{
				pos = x;
			}
		}
		if ( pos != i )
		{
			swap = array[i]; 
			array[i] = array[pos];
			array[pos] = swap;
		}
	}
	end = clock();
	cout << "selecionDirecta terminado..." << endl;
	getUsedTime();
	imprimir(array,length);
	cout << "verificando..." << endl;
	verificar(array,length);
	restart(array,keepData,length);
		cout << "========================="<<endl;

}

#endif