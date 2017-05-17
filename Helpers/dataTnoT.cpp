#include "iostream"
#include "fstream"
#include "stdlib.h"
#include "string.h"
// #include "typeinfo" 
#include "string"

using namespace std;

			class data_t;
			class Pila;
			class Cola;
			class Lista;
			class Nodo;
			class Token;
			class Tokenizer;
			class Reader;

class Nodo
{
private:
	int entero;
	char caracter;
	char cadena[256];
	Nodo *next;

public:

	Nodo(){

	}

	Nodo(char *tipo, char *data){
		this->next = NULL;
		if ( strcmp(tipo,"numerico") == 0 )
		{
			this->entero = atoi(data);
			this->caracter= ' ';
			this->cadena[0] = '\0';
		}
		else if ( strcmp(tipo,"cadena") == 0 )
		{
			strcpy(this->cadena,data);
			this->caracter = ' ';
			this->entero  = -1;
		}
		else if ( strcmp(tipo,"caracter") == 0 )
		{
			this->caracter = (char)*data;
			this->entero  = -1;
			this->cadena[0] = '\0';
		}
	};

	int getEntero(){
		return this->entero;
	}

	char getCaracter(){
		return this->caracter;
	}

	char* getCadena(){
		return this->cadena;
	}

	void print(){
		if( this->entero != -1){
			cout << this->entero << " ";
		}
		else if( this->caracter != ' ') {
			cout << caracter << " ";
		}
		else{
			cout << cadena << " ";
		}
	}

	Nodo** getNext(){
		return &(this->next);
	}

	void setNext(Nodo *next){
		this->next = next;
	}

	bool operator>(Nodo* otro){

		if( this->entero != -1 )
		{
			return this->entero > otro->getEntero();
		}
		else if( this->caracter != ' ') 
		{
			return( (int)this->caracter > (int)otro->getCaracter());
		}
		else
		{
			return (int)this->cadena[0] > (int)otro->getCadena()[0];
		}
	}

	~Nodo(){
	};

};
	
class DataT
{
	private:

	
	public:
		Nodo *head;
		int size;

	virtual void add(char *tipo, char *data) = 0;

	DataT(){};
	~DataT(){};


	
	virtual void list()
	{
		Nodo *temp = this->head;
		while ( temp != NULL )
		{	
			temp->print();
			temp = *temp->getNext();
		}
	};

	void add(Nodo* data){
		size++;
 		Nodo **temp = &(this->head);
		while( (*temp) != NULL ){
			temp = (*temp)->getNext();
		}
		(*temp) = data;
	}

	void set(int size, Nodo *data){
		this->size += (size-1);
		this->add(data);
	}


	void clear(){
		this->head = NULL;
		this->size = 0;
	}

	int getSize(){
		return this->size;
	}

	Nodo* pop(bool feom = true){
		if ( feom ){
			size--;
			Nodo *temp = this->head;
			this->head = *(this->head->getNext());
			return temp;
		}
		else
		{
			Nodo **temp = &(this->head);
			Nodo *r;
			if ( (*temp) != NULL){
				while ( *(*temp)->getNext() != NULL )
				{	
					temp = (*temp)->getNext();
				}
				if ( (*temp ) != NULL){	
					if( *(*temp)->getNext() != NULL){
						cout << "esto no debia pasar mm lo arreglaremos?";
						(*temp)->setNext(NULL);
					}
				}
			}
			r = (*temp);
			(*temp) = NULL;
			return r;
		}
	}

	virtual DataT* make(char *what, DataT *datos,DataT *d2 = NULL){
			if ( strcmp(what,"convertir") == 0 )
			{	
				datos->set(this->size,this->head);
				if ( d2 != NULL)
				{   
					cout << "tam: " << datos->getSize()<<endl;
					datos->list();
					datos->clear();
					cout << endl;           
					int si = d2->getSize();
					datos->set(si,d2->pop());
					cout << endl;
					cout << "MISMO FORMATO PARA CONVERTIR...\n";
				} 
				return datos;
			}
			else if ( strcmp(what,"concatenar") == 0 )
			{
				datos->set(this->size,this->head);
				if ( d2 != NULL)
				{
					int si = d2->getSize();
					datos->set(si,d2->pop());
				}
				return datos;
			}
			else if ( strcmp(what,"mezclar") == 0 )
			{
  				Nodo *temp2 = this->head;
				Nodo *temp = d2->pop();
				Nodo *ad2;

				while( temp != NULL && temp2 != NULL )
				{
					ad2 = *temp2->getNext();
					temp2->setNext(NULL);
					datos->add(temp2);
					temp2 = ad2;

					ad2 = *temp->getNext();
					temp->setNext(NULL);
					datos->add(temp);
					temp = ad2;

				}

				while( temp2 != NULL )
				{
					ad2 = *temp2->getNext();
					temp2->setNext(NULL);
					datos->add(temp2);
					temp2 = ad2;
				}

					
				while ( temp != NULL )
				{	
					ad2 = *temp->getNext();
					temp->setNext(NULL);
					datos->add(temp);
					temp = ad2;
				}
				return datos;
			}
			else if ( strcmp(what,"ordenar") == 0 )
			{	
				Nodo *re = this->head;
				Nodo *temp = NULL;
				while( re != NULL)
				{
					temp = *re->getNext();
					re->setNext(NULL);
					datos->insert(re);
					re = temp;
				}

			    if ( d2 != NULL)
				{
					cout << "tam: " << datos->getSize()<<endl;
					datos->list();
					datos->clear();
					cout << endl;       

					re = d2->pop();
					temp = NULL;
					while( re != NULL)
					{
						temp = *re->getNext();
						re->setNext(NULL);
						datos->insert(re);
						re = temp;
					}
					cout << endl;  
					cout << "MISMO FORMATO PARA ORDENAR...\n";

				}

				return datos;
			}
			else if ( strcmp(what,"revertir") == 0 )
			{
				 Nodo *temp = this->pop(false);
                 while( temp != NULL ){
                 	datos->add(temp);
                 	temp = this->pop(false);
                 } 
                 if ( d2 != NULL)
				{

					cout << "tam: " << datos->getSize()<<endl;
					datos->list();
					datos->clear();
					cout << endl;       
					temp = d2->pop(false);
                 	while( temp != NULL ){
                 		datos->add(temp);
                 		temp = d2->pop(false);
                 	} 
					cout << endl;  
					cout << "MISMO FORMATO PARA REVERTIR...\n"; 
				} 

                 return datos;
			}
			else
			{
				return NULL;
			}
	}
	
	int insert(Nodo *coming, bool ascendente = true){
     	 this->size++;
     	 Nodo *temp;
     	 Nodo **bufer = &(this->head);
      	if ( (*bufer) != NULL ){
           	   while( (  ((*bufer)->operator>(coming) )  == !ascendente  )  ){
           	       bufer = (*bufer)->getNext();
        	          if ( (*bufer) == NULL){
        	                break;
        	          }
        	      }
      	}
      	  temp = (*bufer);
      	  coming->setNext(temp);
    	  (*bufer) = coming;
  	}

};


class Pila : public DataT
{

public:

	Pila(){
		this->head = NULL;
		this->size = 0;
	};

	void add(char *tipo, char *data){
		size++;
		Nodo **temp = &	head;
		while( (*temp) != NULL ){
			temp = (*temp)->getNext();
		}
		(*temp) = new Nodo(tipo,data);

	}

	void list(){
		cout << "Pila->list()" << endl;
		DataT::list();
	}
	
	DataT* make(char *what, DataT *datos,DataT *d2 = NULL){
			cout << "Pila->make()" << endl;
			DataT::make(what,datos,d2);
	}
	~Pila(){

	};
	
};

class Cola : public DataT
{
private:
public:

	Cola(){ 
		this->head = NULL;
		this->size = 0;
	};
	
	void add(char *tipo, char *data){
		size++;
		Nodo **temp = &	head;
		while( (*temp) != NULL ){
			temp = (*temp)->getNext();
		}
		(*temp) = new Nodo(tipo,data);
	}

	void list()
	{
		cout << "cola->list()" << endl;
		DataT::list();
	}

	DataT* make(char *what, DataT *datos,DataT *d2 = NULL){	
			cout << "cola->make()" << endl;
			DataT::make(what,datos,d2);
	}

	~Cola(){
		
	};
	
};

class Lista : public DataT
{
private:

public:

	Lista(){ 
		this->head = NULL;
		this->size = 0;
	};
	
	void add(char *tipo, char *data){
		size++;
		Nodo **temp = &head;
		while( (*temp) != NULL ){
			temp = (*temp)->getNext();
		}
		(*temp) = new Nodo(tipo,data);
	}

	void list()
	{
		cout << "List->list()" << endl;
		DataT::list();
	}

	DataT* make(char *what, DataT *datos,DataT *d2 = NULL){
			cout << "List->make()" << endl;
			DataT::make(what,datos,d2);
	}
};



class Token 
{

public:
  Token *nextToken;
  char data[256];

  Token(){
    nextToken = NULL;
    // data = NULL;
  };

  ~Token(){};
  
};

class Tokenizer
{

public:
  Token *head;
  int size;

  Tokenizer(){
    head = NULL;
    size = 0;
  };

    Tokenizer(char *Name, char token){
      // EL TOKENIZER MAS FEO s: MEJORAR...
            size = 0;
            head = NULL;
      Token **temp = &head;
      char bufer[256] = { '\0' };
      int i = 0;
      int j = 0;

      while( Name[i] != '\0' )
      {
        if ( Name[i] != token )
        {
          bufer[j] = Name[i];
          j++;
        }else{
        	if ( strcmp(bufer,"\0") != 0){        		
	           bufer[j] = '\0';
	           (*temp) = new Token();
	          save((*temp)->data,bufer);
	          temp = &(*temp)->nextToken;
	          size++;
	          bufer[0] = '\0';
        	}
	          j = 0;
        	}
        i++;
      }
      bufer[j] = '\0';
      if ( strcmp(bufer,"\0") != 0){
           (*temp) = new Token();
           size++;
          save((*temp)->data,bufer);
          temp = &(*temp)->nextToken;
          bufer[0] = '\0';
      }
    }

    void save(char *where, char* ho){
        strcpy(where,ho);
        strcpy(ho," "); //restaurar bufer S: bad way
    }

      void list(){
        Token *temp = head;
        while( temp != NULL){
          cout << temp->data << endl;
          temp = temp->nextToken;
        }
      }

  char* pop(bool from = true){
  	if ( from )
  	{
	  	if ( head == NULL){
	    	  return NULL;
	    }
	       char *temp = head->data;
	        head = head->nextToken;
	    	return temp;
  	}
  }

  char* get(int pos){
      Token *temp = head;
      while( pos > 0 ){
        temp = temp->nextToken;
        pos--;
      }
      return temp == NULL ? NULL : temp->data;
  }

  ~Tokenizer()
  {
  };
  
};

void toLower(char* out, char* data)
{
	int i;

	for (i = 0; data[i] != '\0'; ++i)
	{
			out[i] = tolower(data[i]);
	}

	out[i] = '\0';
}

int length(char *cadena_t)
{
  int count = 0;

  while ( cadena_t[count] != '\0' ) {
    count++;
  }
  return count;
}

//END

class Reader
{
private:
	fstream ARCH;
	DataT **info;
	int lineCount;
	int step;

public:
	Tokenizer *line;


	Reader(char* dir){
		this->step = 0;
			ARCH.open(dir,ios::in);
			if ( ARCH.fail())
			{
				cout << "error al abrir " << dir << endl;
				exit(0);
			}
	};

	void getline(char delim = '\0'){
		char bufer[256] = { ' ' };
		ARCH.getline(bufer,2000,'\n');
		line = new Tokenizer(bufer,delim);
	}

	bool nextStep(){
		this->step++;
		int len;
		int *size_fotmat = NULL;
		char metodo[256];
		char tipo[256];

		this->getline(',');

		if( !ARCH.eof() ){	
			cout << "-------------------------\n";
			cout << " CASO N#  " << this->step << endl;
			char *data = line->pop();
			if ( length(data) == 1 && isdigit(data[0])){
				len = atoi(data);

				this->getline(',');
				if ( line->size != 2+len){
					cout << "sizeof " << line->get(0) << " incorrecta" << endl;
				 	goto fail_format;
				 }

				size_fotmat = new int[len];
				toLower(metodo,line->get(0));
				toLower(tipo,line->get(1));

				 for (int i = 0; i < len; ++i)
				 {
				 		for (int x = 0; x < length(line->get(2+i)	); ++x)
				 		{
				 			if ( !isdigit(line->get(2+i)[x]))
				 			{
				 				cout << "TAMANO DE " << line->get(0) << " incorrecta" << endl;
				 				goto fail_format;
				 			}
				 		}
					 	size_fotmat[i] = atoi(line->get(2+i));
				 }	

					if ( strcmp(tipo,"caracter") == 0 ){}
					else if( strcmp(tipo,"numerico") == 0){}
					else if ( strcmp(tipo,"cadena") == 0 ){}
					else
					{
						cout << "Error el Tipo de dato '" << tipo << "' No es reconocido!"  << endl;
						goto fail_format;
					}

					if ( strcmp(metodo,"pila") == 0 ){
							info = (DataT**)new Pila*[len]();
							for (int i = 0; i < len; ++i)
							{
								info[i] = new Pila();
							}
					}
					else if( strcmp(metodo,"cola") == 0){
							info = (DataT**)new Pila*[len]();
							for (int i = 0; i < len; ++i)
							{
								info[i] = new Cola();
							}
					}
					else if ( strcmp(metodo,"lista") == 0 ){
							info = (DataT**)new Pila*[len]();
							for (int i = 0; i < len; ++i)
							{
								info[i] = new Lista();
							}
					}
					else
					{
						cout << "Error el metodo '" << metodo << "' No es reconocido!"  << endl;
						goto fail_format;
					}
				for (int i = 0; i < len; ++i)
				{
					this->getline(',');
					cout << endl;
					cout << "Entrada  " << i+1 << "/" << len << "\n";
					for (int X = 0; X < line->size; ++X)
					{
						cout << line->get(X) << " ";
					}
					if ( line->size != size_fotmat[i]){
						cout << "eror en el tamano de " << metodo <<  " " << tipo << endl;
						goto fail_format;
					}
						char* bufer = line->pop();
						while( bufer != NULL )
						{
							info[i]->add(tipo,bufer);
							bufer = line->pop();
						}
					cout <<"\n"<< metodo << " " << tipo << endl;
					info[i]->list();
					cout << endl;
				}

				this->getline(',');

				if ( line->size != 2 ){
					cout << "parametros de transformacion incorrectos " << endl;
					goto fail_format;
				}

				char para[256];
				char como[256];
				cout << "\nOPERACION(s) ... ";
				toLower(para,line->pop());
				toLower(como,line->pop());

				cout << endl;

				DataT *temp = NULL;
					
					if ( strcmp(como,"pila") == 0 ){
						temp = new Pila();
					}
					else if( strcmp(como,"cola") == 0){
						temp = new Cola();
					}
					else if ( strcmp(como,"lista") == 0 ){
						temp = new Lista();
					}




				if ( len == 1 )
				{
					cout << endl;
					cout << metodo <<"->"<<para << "->" << como << endl;
					if (!(info[0]->make(para,temp)))
					 {
					 	cout << "error " << para << " en " << como << " no conocido " << endl;
					 	goto fail_format;
					 } 
				}else
				{	
					if ( strcmp(para,"mezclar") != 0 && strcmp(para,"concatenar") != 0){

						for ( int x = 0; x < len; x++){
							cout << metodo <<"->"<<para << "->" << como << endl;
						}

					}else{
						cout << metodo <<"(s)->"<<para << "->" << como << endl;
					}


					for (int i = 0; i < len-1; i+=2)
					{
						cout << endl;
					  	if (!(info[i]->make(para,temp,info[i+1])))
					 	{
					 		cout << "error " << para << " en " << como << " no conocido " << endl;
					 		goto fail_format;
					 	} 
					}
							


				}
					if (  temp  ){
						cout << "tam: " << temp->getSize() <<  endl;
						temp->list();
						cout << endl;
						temp->clear();
					}
					else
					{
						cout << "error al convertir" << endl;
					}

				cout << endl;
				cout << "-------------------------\n";
					cout << endl;
					cout << endl;
					cout << endl;

			}else{
				fail_format:
				cout << "el formato de archivo no es correcto! " << endl;
				fflush(stdin);
				fflush(stdout);
				cin.get();
				exit(0);
			}
			return true;
		}
		else {
			return false;
		}
	}

	bool end(){
		return ARCH.eof();
	}

	~Reader(){

	};
	
};

int main(int argc, char const *argv[])
{
	Reader data("estructuras.txt");

	while( data.nextStep() ){
		cin.get();
		cout << endl;
	}

	return 0;
}