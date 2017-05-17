#ifndef _TOKENIZER_
#define _TOKENIZER_

// SOLO PARA 256 CARACTERES SIN VERIFICAR !!!!!!
// SLOW MODE , ACUM INDEX

#include "string.h"
#include "iostream"
using namespace std;


	// TOKENIZER
		class Token 
		{

		public:
		  Token *nextToken;
		  char data[256];

		  Token(){
		    nextToken = NULL;
		    data[0] = '\0';
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
    	Token **temp = &head;
            head = NULL;
            size = 0;
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
            // save(bufer);
           	(*temp) = new Token();
        	strcpy((*temp)->data,bufer);
            temp =  &(*temp)->nextToken;
            size++;
            bufer[0] = '\0';
          }
            j = 0;
          }
        i++;
      }
      bufer[j] = '\0';
      if ( strcmp(bufer,"\0") != 0){
           size++;
          // save(bufer);
            (*temp) = new Token();
        	strcpy((*temp)->data,bufer);
            temp =  &(*temp)->nextToken;
          bufer[0] = '\0';
      }
    }

    void save(char* ho){
    	this->size++;
    	Token **temp = &head;
    	while((*temp) != NULL )
    	{
    		temp =  &(*temp)->nextToken;
    	}

    	(*temp) = new Token();
        strcpy((*temp)->data,ho);
        strcpy(ho,"\0");
    }

    void list(){
        Token *temp = head;
        while( temp != NULL){
          cout << temp->data << endl;
          temp = temp->nextToken;
        }
    }

  char* pop(bool from = true){
      if ( head == NULL){
          return NULL;
      }
         char *temp = head->data;
          head = head->nextToken;
          this->size--;
        return temp;
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

// END TOKENIZER!

#endif

