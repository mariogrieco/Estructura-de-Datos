#ifndef _NODO_H_
#define _NODO_H_

template <class T> class Nodo { 
private:

public:

  Nodo<T> *next;
  Nodo<T> *before;
  T data;

  Nodo<T>(){
    this->next = NULL;
    this->before = NULL;
  };

  Nodo<T>(const T data){
    this->next = NULL;
    this->before = NULL;
    this->data = data;
  };

  void swap(const Nodo<T> data){

  }

  // T getData(){
  //   return this->data;
  // }

  // void setData(const T data){
  //   this->data = data;  // jyst for sort o swaping
  // }

  // int setNext(Nodo<T>* next){   // mOst use Nodo(new T)
  //     this->next = next;
  // }

  // int setBefore(Nodo<T>* before){
  //   this->before = before;
  // }

  // Nodo<T>* getBefore()
  // {
  //   return this->before;
  // }

  // Nodo<T>* getNext(){
  //   return this->next;
  // }

  ~Nodo<T>(){
    std::cerr << "delete ~Nodo? \n"; 
  };
  
};

#endif