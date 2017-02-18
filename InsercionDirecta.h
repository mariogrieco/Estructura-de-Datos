#ifndef INSERCCION_DIRECTA_H
#define INSERCCION_DIRECTA_H
	
	
		void inseccionDirecta(short[], int);  



	void inseccionDirecta(short array[], int length){
		cout << "Cangando..." << endl;
		init = clock();
		short aux;
		bool bandera = true;
		int x;

		for (int i = 1; i < length; ++i)
		{
			aux = array[i];
			x = i-1;
			bandera = false;
			while( x >= 0 && array[x] > aux){
				array[x+1] = array[x]; 
				bandera = true;
				x--;
			}
			if ( bandera )
			{
				array[x+1] = aux;
			}
		}

		end = clock();
	cout << "inseccionDirecta terminado..." << endl;
	imprimir(array,length);
	verificar(array,length);
	getUsedTime();
	restart(array,keepData,length);
}

#endif