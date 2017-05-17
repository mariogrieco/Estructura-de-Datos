// cola
// FIFO (First In First Out)
// USING partial template specialization
#ifndef _QUEUE_H_
 #define _QUEUE_H_

#include "Nodo.h"
#ifndef std
	#include <iostream>
#endif


template <class T, int SIZE = NULL> class Queue { // static Tipe QUEUE 
  
  private:
  	int siz;
  	int len;
  	T data[SIZE];
  	int stepAcum;

  public:

 	Queue(){
 		this->len = 0;
 		this->siz = SIZE;
 		this->stepAcum = 0;
 	};

 	int length(){
 		return this->len;
 	}


 	void push(T coming){
 			if ( (this->len)<this->siz )
 			{
 				this->data[this->stepAcum] = (coming);
	 			this->len++;
	 			this->stepAcum++;
			}else {
				std::cerr << "ARRAY OVERFLOW !\n";
			}
 	}

 	void list(){
 		int temp = 0;
 		while( temp < this->len ){
 			std::cout << (this->data[temp]) << std::endl;
 			temp++;
 		}
 	}

 	T pop(){
 		if ( this->len > 0 ){

 			T temp = this->data[0];

 		 // 	delete (this->data[0]);    ):
 		 	
 		 	for (int i = 0; i < this->len-1; ++i)
 		 	{
 		 		*(this->data+i) = *(this->data+(i+1));
 		 	}
	 		
 		 	 this->len--;
 		 	 this->stepAcum--;
	 		return temp;
 		}
 	}

 	
 	// int indexOf(T data){}
 	// void front(){}
 	// void back(){}
	
	// void concat(Nodo<T> data){}
 	// void merge(){}
 	// void reverse(){}
 	// void sort();
 	// void sort(proto func);
 	//   ... add proto func here
 	// bool save(){}
 	// bool restore(){}
 	// void clear(){}
 	//T* get(int index){}

 	// MIXTO ??
 	// void operator==(Queue<T,SIZE> data){}
 	// void operator>(Queue<T,SIZE> data){}
 	// void operator!=(Queue<T,SIZE> data){}


 	~Queue(){
 		std::cerr << "~QUEUE() ?? \n";
 	};
 	
 };	


 template<class T> class Queue<T> {  // dinami Tipe QUEUE 
  
  private:
  	unsigned int size;
  	Nodo<T> *head;
  	Nodo<T> *last;
  	Queue<T> *shadows;

  public:

 	Queue(){
 		this->size  = 0;
 		this->head = NULL;
 		this->last = NULL;
 		this->shadows = NULL;
 	};

 	void push(const T data){
 		this->size++;

 		if ( !this->head )
 		{
 			this->head = new Nodo<T>();
 			this->head->data = data;
 			this->last = this->head;
 		}
 		else{
 			this->last->next = new Nodo<T>();
 			this->last = this->last->next;
 			this->last->data = data;
 		}
 	}


 	Nodo<T> front(){
 		if ( this->size > 0 )
 		{
 			return this->head;
 		}
 		return NULL;
 	}

 	Nodo<T> back(){
 		
 		if ( this->size > 0 )
 		{
 			return this->last;
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
 			Nodo<T> *temp = this->head;
 			T data = temp->data;
 			this->head = this->head->next;
 			temp->next = NULL;
 			temp->before = NULL;
 			delete temp;  //>??

 			return data;
 		}
 		return NULL;
 	}
 	
 	void list(){
 		Nodo<T> *temp = this->head;
 		while( temp != NULL)
 		{
 			std::cout << temp->data << " \n";
 			temp = temp->next;
 		}
 	}


 	// void concat(Nodo<T> data){}
 	// void merge(){}
 	// void reverse(){}
 	// void sort();
 	// void sort(proto func);
 	//   ... add proto func here
 	// bool save(){}
 	// bool restore(){}
 	// void clear(){}
 	//T* get(int index){}
 	// int indexOf(T data){}
 	 	// MIXTO ??
 	// void operator==(Queue<T> data){}
 	// void operator>(Queue<T> data){}
 	// void operator!=(Queue<T> data){}


 	~Queue(){
 	 	std::cerr << "delete ~Queue ?\n";
 		// Nodo<T> *temp = this->head;
 		// Nodo<T> *before = NULL;
 		
 		// while( temp != NULL )
 		// {
 		// 	before = temp;
 		// 	temp = temp->next;
 		// 	delete before;
 		// }
 	};
 	
 };	

#endif