#include "iostream"
// #include "Tokenizer.h"
using namespace std;
#include "Lista.h"



class Numero
{
public:
	int i;

	Numero(){

	};

	Numero(int i){
		this->i = i;
	};

	int getNumero(){
		return this->i;
	}

	bool operator>(Numero *two){
		if ( this->i > two->getNumero())
		{
			return true;
		}
		return false;
	}

    bool operator>(Numero two){
		if ( this->i > two.getNumero())
		{
			return true;
		}
		return false;
	}

	~Numero(){

	};
	
};

int main(int argc, char const *argv[])
{
	List<Numero> temp;

	temp.insert(Numero(4));
	temp.insert(Numero(3));
	temp.insert(Numero(1));
	temp.insert(Numero(2));

	temp.seePtrs(false);
	cout << endl;
	temp.seePtrs(true);

	return 0;	
}