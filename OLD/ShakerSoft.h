#ifndef SHAKER_H
#define SHAKER_H


		void shaker(short[], int);

void shaker(short array[], int length){

	init = clock();
	int limS = length-1;
	int limI = 0;
	short swap;
	do
	{
		for (int i = limI; i < limS; i++)
		{
		    if ( array[i] > array[i+1] )
			{
				swap = array[i];
				array[i] = array[i+1];
				array[i+1] = swap;
			}
		}
		limS--;
    	for (int i = limS; i > limI; i--)
		{
			if ( array[i] < array[i-1] )
			{
				swap = array[i];
				array[i] = array[i-1];
				array[i-1] = swap;
			}
		}
		limI++;

	} while (limS - limI > 0);
	end = clock();
	cout << "metodo shaker terminado..." << endl;
	getUsedTime();
	imprimir(array,length);
	cout << "verificando..." << endl;
	verificar(array,length);
	restart(array,keepData,length);
		cout << "========================="<<endl;
}



#endif