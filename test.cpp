#include <iostream>
#include <time.h>
#include <stdlib.h>

// #include "DataStructures/Queue.h"
// #include "DataStructures/Stack.h"
// #include <queue> 
// #include "Sort/quickSort.h"

#include "Helpers/FileManager.h"
using namespace std;

int main(){

	clock_t inicio,fin;
	
	srand(time(NULL));
	inicio = fin = 0;

	FileManager<int> data;
	data.createFile("temo.DAT");

	data.open("temo.DAT");
	for (int i = 0; i < 10; ++i)
	{
		data.write(new int(10-i));
	}
	data.close();	
	data.open("temo.DAT");
	// data.print();

		inicio = clock();
			data.mergeSort();
		fin = clock();

		data.update();
		data.print();

	cout << "time: " << fin-inicio << endl;
	// data.print();

	data.close();
	cin.get();
	return 1;

}