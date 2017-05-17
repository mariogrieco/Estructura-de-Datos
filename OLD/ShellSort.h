#ifndef SHELL_SORT_H 
#define SHELL_SORT_H
	
	
	void metodoShell(short[], int);  


void metodoShell(short array[], int length){
	cout << "Cargando..." << endl;
	init = clock();
	int increment = (length/2);
	bool bandera = true;
	short swap;

		while(bandera)
		{
			bandera = false;
			for (int i = 0; increment+i < length; i++) // fases
			{
				if ( array[i] > array[i+increment] )
				{
					swap = array[i];
					array[i] = array[i+increment];
					array[i+increment] = swap;
					bandera = true;
				}	
			}

			if ( bandera == false && (increment/2)>0)
			{
				increment = increment/2;
				bandera = true;
			}
		}
		end = clock();
	cout << "metodoShell terminado..." << endl;
	getUsedTime();
	imprimir(array,length);
	cout << "verificando..." << endl;
	verificar(array,length);
	restart(array,keepData,length);
		cout << "========================="<<endl;
}

#endif