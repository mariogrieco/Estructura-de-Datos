/**

  el last deberia ser ** para que sea auto la modificacion;
  sin tantos if cochinos cambios noos

**/

#ifndef _NODO_H_
#define _NODO_H_

template <class T> class Nodo {
private:
  Nodo *next;
  Nodo *before;
  T data;

public:

  Nodo(){
    this->next = NULL;
    this->before = NULL;
  };

  Nodo(T data){
    this->next = NULL;
    this->before = NULL;
    this->data = data;
  };

  Nodo(T *data){  // mOst use Nodo(new T)
    this->next = NULL;
    this->before = NULL;
    this->data = *data;
  };

  T* getData(){
    return &this->data;
  }

  void setData(T *data){
    this->data = *data;
  }


  void setData(T data){
    this->data = data;  // jyst for sort o swaping
  }

  int setNext(Nodo* next){   // mOst use Nodo(new T)
      this->next = next;
  }

  int setBefore(Nodo *before){
    this->before = before;
  }

  Nodo<T>* getBefore()
  {
    return this->before;
  }

  Nodo** getNext(){
    return &this->next;
  }

  ~Nodo(){
    // EXPERIMENTAL
    // this->before = NULL
    // this->next = NULL;
    // delete this->data;
  };
  
};

#endif



#ifndef _LIST_H_
#define _LIST_H_



template <class T> class List {

private:
  Nodo<T> *head;
  Nodo<T> *last;
  int size;

public:

  List(){
    this->head = NULL;
    this->last = NULL;
    this->size = 0;
  };

  Nodo<T>* front(){
    if ( this->size > 0)
    {
      return this->head;
    }
    return NULL;
  }

  Nodo<T>* back(){
    if ( this->size > 0)
    {
      return this->last;
    }
    return NULL;
  }

  // int push(bool reverse = false){}

  int insert(T coming,int(T::*ptr)(void), bool ascendente = true){
     
      size++;
      Nodo<T> *temp = NULL;
      Nodo<T> *before = NULL;
      Nodo<T> **bufer = &(this->head);

      if ( this->head != NULL ){
              while((((*bufer)->getData()->*ptr)()) > ((coming.*ptr)()) != ascendente ){
                  before = (*bufer);
                  bufer = ((*bufer)->getNext());
                  if ( (*bufer) == this->head ){
                    this->last = NULL;
                    break;
                  }
              }
                   temp = (*bufer);
                   (*bufer) = new Nodo<T>(coming);
                   (*bufer)->setNext(temp);
                    temp->setBefore( (*bufer) );

                if ( this->last == NULL )
                {
                    (*bufer)->setBefore(before);
                     this->last = (*bufer); 
                    (*bufer)->setNext(this->head);
                }
                else if ( temp == *(this->last->getNext()) ) 
                {
                    (*bufer)->setBefore(this->last);
                    this->last->setNext((*bufer));
                }else{
                  (*bufer)->setBefore(before);
                }
      }
      else
      {
        this->head = new Nodo<T>(coming);
        this->head->setNext(this->head);
        this->head->setBefore(this->head);
        this->last = this->head;
      };
  }
  // add proto func here....

  int insert(T coming, bool ascendente = true){
     
      size++;
      Nodo<T> *temp = NULL;
      Nodo<T> *before = NULL;
      Nodo<T> **bufer = &(this->head);

      if ( this->head != NULL ){
              while( (*bufer)->getData()->operator>(coming) != ascendente ){
                  before = (*bufer);
                  bufer = ((*bufer)->getNext());
                  if ( (*bufer) == this->head ){
                    this->last = NULL;
                    break;
                  }
              }
                   temp = (*bufer);
                   (*bufer) = new Nodo<T>(coming);
                   (*bufer)->setNext(temp);
                    temp->setBefore( (*bufer) );

                if ( this->last == NULL )
                {
                    (*bufer)->setBefore(before);
                     this->last = (*bufer); 
                    (*bufer)->setNext(this->head);
                }
                else if ( temp == *(this->last->getNext()) ) 
                {
                    (*bufer)->setBefore(this->last);
                    this->last->setNext((*bufer));
                }else{
                  (*bufer)->setBefore(before);
                }
      }
      else
      {
        this->head = new Nodo<T>(coming);
        this->head->setNext(this->head);
        this->head->setBefore(this->head);
        this->last = this->head;
      };
  }


  void seePtrs(bool reverse = false){
    Nodo<T> *temp = head;
    if ( reverse )
    {
       cout << "\n reverse!" << endl;
       temp = (this->last);

      while( temp != this->head ){
        cout << " where: " << temp << " next " << (*temp->getNext()) << " back " << temp->getBefore() << endl;
        temp = (temp->getBefore());
      }
      cout << " where: " << temp << " next " << (*temp->getNext()) << " back " << temp->getBefore() << endl;
    }else{
      while( (*temp->getNext()) != this->head ){
        cout << " where: " << temp << " next " << (*temp->getNext()) << " back " << temp->getBefore() << endl;
        temp = (*temp->getNext());
      }      
      cout << " where: " << temp << " next " << (*temp->getNext()) << " back " << temp->getBefore() << endl;

    }
  }


  bool indexOf(T item, int(T::*fun)(void)){
  }

  // more proto func here!

  bool indexOf(T item){
  
  }

  int length(){
    return this->size;
  }

  int sort(bool reverse = false){
    if ( this->head != NULL && this->size > 1)
    {
      Nodo<T> *temp = (*this->head->getNext());
      Nodo<T> *bufer = NULL;
      Nodo<T> *bf = NULL;
      for ( ; temp != NULL; temp = (*temp->getNext()))
      {
        if ( temp == this->head )
        {
           break;
        }

        bufer = temp;
        bf = bufer->getBefore();

          while ( bf != this->last ){
                T dataTemp = (*bufer->getData());
                T *data2Temp = bf->getData();
              if ( dataTemp.operator>(data2Temp) != !reverse){
                  bufer->setData(data2Temp);
                  bf->setData(dataTemp);
              }

            bufer = bf;
            bf = bf->getBefore();
          }
      }
    }
  }

  T* pop(bool reverse = false){

    // no elimina el 100% !!!

    Nodo<T> *temp;
    if ( reverse )
    {
      temp = this->last;
      this->last->getBefore()->setNext(this->head);
      this->last = this->last->getBefore();
      this->head->setBefore(this->last);
      this->size--;
      return temp->getData();

    }
    else
    {
        temp = this->head;
        this->head = (*this->head->getNext());
        this->head->setBefore(this->last);
        this->last->setNext(this->head);
        this->size--;
        return temp->getData();
    }
  }

  T* remove(){

  }

  T* get(int indexOf){
    if (indexOf >= this->size || indexOf < 0 ) { return NULL; }
    
          Nodo<T> *temp = this->head;

    while( indexOf > 0 ){
          temp = *(temp->getNext());
          indexOf--;
    }  

    return temp->getData();
  }

  int list(int(T::*ptr)(void), bool reverse = false){
      Nodo<T> *temp;

      if ( reverse )
      {
        temp = last;
              if ( last != NULL)
              {
                while ( temp != NULL){
                  cout << (temp->getData()->*ptr)() << endl;
                  temp = temp->getBefore();
                  if ( temp == this->last )
                  {
                     break;
                  }
                }
              }
      }
      else
      {
        temp = head;
             while( temp != NULL ){
                  cout << (temp->getData()->*ptr)() << endl;
                  temp = *(temp->getNext());
                  if ( temp == this->head )
                  {
                     break;
                  }
              }
      }
  }

  // more proto funct here
  int list(bool reverse = false){
      Nodo<T> *temp;

      if ( reverse )
      {
        temp = this->last;
              if ( last != NULL)
              {
                while ( temp != NULL){
                  cout << temp->getData() << endl;
                  temp = temp->getBefore();
                  if ( temp == this->last )
                  {
                     break;
                  }
                }
              }
      }
      else
      {
        temp = this->head;
             while( temp != NULL ){
                  cout << temp->getData() << endl;
                  temp = *(temp->getNext());
                  if ( temp == this->head )
                  {
                     break;
                  }
              }
      }
  }


  // int clear(){
  // }

  ~List(){

  };
  
};


#endif