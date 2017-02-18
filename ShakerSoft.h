#ifndef SHAKER_H
#define SHAKER_H


		void shaker(short[], int);

void shaker(short a[], int length){

	init = clock();
	int limS = length-1;
	int limI = 0;
	short swap;
	do
	{
		for (int i = limI; i < limS; i++)
		{
		    if ( a[i] > a[i+1] )
			{
				swap = a[i];
				a[i] = a[i+1];
				a[i+1] = swap;
			}
		}
		limS--;
    	for (int i = limS; i > limI; i--)
		{
			if ( a[i] < a[i-1] )
			{
				swap = a[i];
				a[i] = a[i-1];
				a[i-1] = swap;
			}
		}
		limI++;

	} while (limS - limI > 0);
	end = clock();
	imprimir(a,length);
	verificar(a,length);
	getUsedTime();
	restart(a,keepData,length);

}



#endif