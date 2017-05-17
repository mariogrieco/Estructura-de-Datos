// Pila
// LIFO (First In First Out)
// USING partial template specialization
#ifndef _STACK_H_
 #define _STACK_H_

#include "Nodo.h"
#ifndef std
	#include <iostream>
#endif


template <class T, int SIZE = NULL> class Stack { 
  
  private:
  	int siz;
  	int len;
  	T data[SIZE];
  	int stepAcum;

  public:

 	Stack(){
 		this->len = 0;
 		this->siz = SIZE;
 		this->stepAcum = 0;
 	};

 	int length(){
 		return this->len;
 	}

 	~Stack(){
 		std::cerr << "~Stack() ?? \n";
 	};
 	
 };	


 template<class T> class Stack<T> {  
  
  private:
  	unsigned int size;
  	Nodo<T> *head;
  	Nodo<T>* last;
  	Stack<T> *shadows;

  public:

 	Stack(){
 		this->size  = 0;
 		this->head = new Nodo<T>;
 		this->last = this->head;
 		this->shadows = NULL;
 	};

 	void push(const T data){
 		this->size++;
		this->head->data = data;
		Nodo<T>* temp = this->head;
		this->head = new Nodo<T>();
		this->head->next = temp;
 	}


 	T front(){
 		
 		if ( this->size > 0 )
 		{
 			return this->head->next->data;
 		}
 		return NULL;
 	}

 	T back(){
 		
 		if ( this->size > 0 )
 		{
 			return this->last->data;
 		}

 		return NULL;
 	}

 	int length(){
 		return this->size;
 	}


 	T pop(){
 		if ( this->size > 0)
 		{
 	 		this->size--;
 			Nodo<T> *temp = this->head->next;
 			T data = temp->data;
 			this->head->next = temp->next;
 			delete temp;  //>??

 			return data;
 		}
 		return NULL;
 	}
 	
 	void list(){
 		Nodo<T> *temp = this->head->next;
 		while(temp != NULL)
 		{
 			std::cout << temp->data << " \n";
 			temp = temp->next;
 		}
 	}


 	// void concat(Queue<T> data, bool orden = true){
 	// }

 	// void concat(List<T> data, bool orden = true){
 	// }

 	// void concat(Stack<T> data, bool orden = true){
 	// }


 	// void merge(Queue<T> data, bool orden = true){
 	// }

 	// void merge(List<T> data, bool orden = true){
 	// }

 	// void merge(Stack<T> data, bool orden = true){
 	// }

 	void clear(){
 		// delete this->bufer;
 		// this->size = 0;
 	}

 	void operator==(Queue<T> data){

 	}

 	~Stack(){
 		std::cerr << "delete ~Stack ?\n";
 		Nodo<T> *temp = this->head;
 		Nodo<T> *before = NULL;
 		
 		while( temp != NULL )
 		{
 			before = temp;
 			temp = temp->next;
 			delete before;
 		}
 	};
 	
 };	

#endif