#ifndef _TEMPLATES_H_
#define _TEMPLATES_H_

    using namespace std;

/*
Nombres Descripción
memcpy  copia n bytes entre dos áreas de memoria que no deben solaparse
memmove copia n bytes entre dos áreas de memoria; al contrario que memcpy las áreas pueden solaparse
memchr  busca un valor a partir de una dirección de memoria dada y devuelve un puntero a la primera ocurrencia del valor buscado o NULL si no se encuentra
memcmp  compara los n primeros caracteres de dos áreas de memoria
memset  sobre escribe un área de memoria con un patrón de bytes dado
strcat  añade una cadena al final de otra
strncat añade los n primeros caracteres de una cadena al final de otra
strchr  localiza un carácter en una cadena, buscando desde el principio
strrchr localiza un carácter en una cadena, buscando desde el final
strcmp  compara dos cadenas alfabéticamente ('a'!='A')
strncmp compara los n primeros caracteres de dos cadenas numéricamente ('a'!='A')
strcoll compara dos cadenas según la colación actual ('a'=='A')
strcpy  copia una cadena en otra
strncpy copia los n primeros caracteres de una cadena en otra
strerror  devuelve la cadena con el mensaje de error correspondiente al número de error dado
strlen  devuelve la longitud de una cadena
strspn  devuelve la posición del primer carácter de una cadena que no coincide con ninguno de los caracteres de otra cadena dada
strcspn devuelve la posición del primer carácter que coincide con alguno de los caracteres de otra cadena dada
strpbrk encuentra la primera ocurrencia de alguno de los caracteres de una cadena dada en otra
strstr  busca una cadena dentro de otra
strtok  parte una cadena en una secuencia de tokens
strxfrm transforma una cadena en su forma de colación (??)
strrev  invierte una cadena
*/
          template <class T>
          int generateFromBinary(char* file_name,T **Objects,int &largo);

          // template <class T>
          // void reallocate(T**,int);

          // template <class T>
          // void reallocate(T**,int);
          template <class T>
          void quickSort();

          template <class T>
          void radixsort(T&,int);

          template <class T>
          void shakerSort(T&,int);

          template <class T>
          int bloques(T*,T,int);

          template <class T,class K>
          int* binaria(T,K,int);

          template <class T>
          void inter(T &, T &);

          template <class T>
          void seleccionDirecta(T&, int,bool ascendente = true);

          template <class T>
          void insercionDirecta(T &,int,bool ascendente = true);


              template <class T>
              void burbuja(T &a, int largo, bool ascendente = true);

          template <class T>
          class Colas_Array;

          template <class T>
          class Merge;


//   template <class T>
//   class Merge {
//     private:
//       fstream F1;
//       fstream F2;
//       fstream DATA;
//       fstream RESPALDO;
//       fstream SALIDA;
//       T *Objects;
//       int line;
//       int length;
//       int arralen;


//     public:
//       Merge(){

//       }

//       Merge(char *nameFile,int largo){
//         DATA.open(nameFile,ios::binary | ios::out | ios::in );
//         this->setlargo();
//         DATA.clear();
//         this->arralen = largo;

//       };

//       void imprimir(){
//         for (size_t i = 0; i < this->arralen; i++) {
//            this->Objects[i].imprimir();
//         }
//       }

//       void open(const std::_Ios_Openmode &t){
//       }

//       T* getArray(){
//         return this->Objects;
//       }

//       int getLargo(){
//         return this->arralen;
//       }
//       void crearArray(){
//         this->posicionar(0);

//         int contador = 0;
//         int max = 1;
//         this->Objects = new T;

//         while ( true ) {
//           T *bufer = new T;
//           DATA.read((char*)bufer,sizeof(T));
//             if ( !DATA.eof() ) {
//               if ( contador == max ) {
//                 this->Objects = (T*)(realloc((this->Objects),sizeof(T)*(max+10)));
//                 max=max+10;
//               }
//               this->Objects[contador] = *bufer;
//               // this->Objects[contador].imprimir();
//               contador++;
//             }else{
//               break;
//             }
//         }
//         this->length = contador;
//       }

//       void leer(T &bufer){
//           DATA.read((char*)&bufer,sizeof(T));
//       }

//       int setlargo(){
//         this->length = 0;
//             while ( true ) {
//               T temp;
//               DATA.read((char*)&temp,sizeof(T));
//                if ( DATA.eof()) {
//                  this->length--;
//                  return 1;
//                }else{
//                  this->length++;
//                }
//             }
//       }

//       void escribir(T &data){
//           DATA.write((char*)&data,sizeof(T));
//       }

//       void clear(){
//         DATA.clear();
//         DATA.seekg(0,ios::beg);
//       }

//       void posicionar(int pos){
//             clear();
//             DATA.seekg(sizeof(T)*pos,ios::beg);
//       }

//       void generateFromBinary(){
//         // generateFromBinary(this->Objects,this->lines);
//       }
//       void mesclar(){

//       }

//       void separar(){

//       }

//       void getUL(){
//           T INTER;
//         posicionar(length);
//         leer(INTER);
//         cout << INTER.nombre << endl;


//       }

//       void saveTObinary(){
//           generateFromBinary("Cliente.dat",this->Objects,this->arralen);
//           saveTObinary(this->Objects,this->arralen,"Cliente.dat");
//       }

//       void seleccionDirecta(){
//           int menor = 0;
//           int pos_T;
//           int mayor = length;
//           T bufer2;
//           T min;
//           T INTER;

//           r:

//           posicionar(menor);
//           leer(min);
//           pos_T = menor;

//           for (int i = menor+1; i <= mayor; i++) {
//                 leer(bufer2);
//                 if ( min>&bufer2 ) {
//                    pos_T = i;
//                    min = bufer2;
//                 }
//           }

//           posicionar(menor);
//           leer(INTER);
//           posicionar(menor);
//           escribir(min);
//           posicionar(pos_T);
//           escribir(INTER);

//           menor++;
//           if ( menor < mayor) {
//              goto r;
//           }
//       }

//       void shell(){

//       }

//       void inter(int pos1, int pos2){
//       }

//       void ver(int t){
//         Objects[t].imprimir();
//       }
//       int bloques(int key){

//           int pos = 0;
//           int increment = sqrt(this->arralen);

//           RE:

//           for (int i = pos; i < this->arralen; i+=increment) {
//              if ( this->Objects[i] == key ) {
//                 return i;
//              }
//           }
//           pos++;

//           if ( pos < ((this->arralen-1)/2)-1) {
//             goto RE;
//           }
//           return -1;

//       }

//       int verBusqda(int key){
//         for (int i = 0; i < this->arralen; i++) {
//             if ( this->Objects[i].id == key ) {
//                this->Objects[i].imprimir();
//             }
//         }
//       }
//       void verBusqdaCI(int key){
//         for (int i = 0; i < this->arralen; i++) {
//             if ( this->Objects[i].ced == key ) {
//                this->Objects[i].imprimir();
//             }
//         }
//       }
//       ~Merge(){
//         DATA.close();
//         F1.close();
//         F2.close();
//         DATA.close();
//         RESPALDO.close();
//         SALIDA.close();
//       }


// };




    //
    // template <class T,class K>
    // int* secuencial(T array, K key, int length){
    //   int *pos_T = new int[3];
    //   int n = 1;
    //   int tam = 3;
    //   int numbers = 0;
    //   int bandera = false;
    //
    //   if ( array[0] > key) return NULL;
    //   if ( array[length-1] < key) return NULL;
    //
    //   for (int i = 0; i < length; i++) {
    //     if ( array[i] > key && bandera == true ){
    //         goto retu;
    //     }
    //     else if ( array[i] > key ){
    //       return NULL;
    //     }
    //     if ( array[i] == key ){
    //         pos_T[n] = i;
    //         n++;
    //         numbers++;
    //         bandera = true;
    //      }
    //      if ( n >= tam ) {
    //        pos_T = reallocate(pos_T,sizeof(int)*n+1);
    //        tam = n+1;
    //      }
    //   }
    //     retu:
    //      pos_T[0] = numbers;
    //      return pos_T;
    //
    // }


    template <class T>
    void hashModulo(){

    }

    template <class T>
    void hashRaiz(){

    }

    template <class T>
    void hashPlegamiento(){

    }

    template <class T>
    void hasTruncamiento(){

    }

    template <class T>
    void tablaHasH(){

    }



    template <class T>
    void quickSort(){

    }




    

    //crearr!

    // template <class T,class A,class B>
    //         int generateFromFile(T **Object1, char *file_name, int &l3){
    //             l1 = l2 = l3 = 0;
    //             fstream DATA(file_name,ios::in);
    //             DATA.clear();
    //             DATA.seekg(0,ios::beg);
    //             int tipe = 0;
    //             if ( DATA.fail() ) {
    //               cout << "error leyendo Data ";
    //               exit(0);
    //               return 0;
    //             }
    //             int contador = 0;
    //             int max = 1;
    //             (*Object1) = new T;
    //             (*Object2) = new B;
    //             (*Object3) = new A;

    //             while ( true ) {

    //               char a[256];
    //               int d;
    //               a:
    //               DATA.getline(a,sizeof(char)*256);

    //                 if ( !DATA.eof() ) {
    //                   if (  strcmp(a,"SQ2") != 0 && strcmp(a,"SQ1") != 0 ) {
    //                     if ( contador == max  && tipe == 0) {
    //                       (*Object1) = (T*)(realloc((*Object1),sizeof(T)*(max+10)));
    //                       max=max+10;
    //                     }
    //                     if ( contador == max  && tipe == 1) {
    //                       (*Object2) = (B*)(realloc((*Object2),sizeof(T)*(max+10)));
    //                       max=max+10;
    //                     }
    //                     if ( contador == max  && tipe == 2) {
    //                       (*Object3) = (A*)(realloc((*Object3),sizeof(T)*(max+10)));
    //                       max=max+10;
    //                     }
    //                     /* code */
    //                   }else{
    //                     tipe++;
    //                     contador = 0;
    //                     max = 1;
    //                     goto a;
    //                   }
    //                   if ( tipe == 0 && strcmp(a,"SQ2") != 0 && strcmp(a,"SQ1") != 0) {
    //                     char b[256];
    //                     strcpy(b,nextTokenNizer(a,','));
    //                     (*Object1)[contador].ced = atoi(b);
    //                     strcpy(b,nextTokenNizer(a,','));
    //                     strcpy((*Object1)[contador].nom,b);
    //                     l1++;
    //                   }
    //                   if ( tipe == 1 && strcmp(a,"SQ2") != 0 && strcmp(a,"SQ1") != 0) {
    //                     char b[256];

    //                     strcpy(b,nextTokenNizer(a,','));
    //                     (*Object2)[contador].id = atoi(b);

    //                     strcpy(b,nextTokenNizer(a,','));
    //                     strcpy((*Object2)[contador].nom,b);

    //                     strcpy(b,nextTokenNizer(a,','));
    //                     (*Object2)[contador].hora_am1 = atoi(b);

    //                     strcpy(b,nextTokenNizer(a,','));
    //                     (*Object2)[contador].hora_am2 = atoi(b);

    //                     strcpy(b,nextTokenNizer(a,','));
    //                     (*Object2)[contador].hora_pm1 = atoi(b);

    //                     strcpy(b,nextTokenNizer(a,','));
    //                     (*Object2)[contador].hora_pm2 = atoi(b);
    //                     l2++;
    //                   }
    //                   if ( tipe == 2 && strcmp(a,"SQ2") != 0 && strcmp(a,"SQ1") != 0 ) {
    //                     char b[256];
    //                     strcpy(b,nextTokenNizer(a,','));
    //                     (*Object3)[contador].id = atoi(b);
    //                     strcpy(b,nextTokenNizer(a,','));
    //                     (*Object3)[contador].ced = atoi(b);
    //                     strcpy(b,nextTokenNizer(a,','));
    //                     strcpy((*Object3)[contador].fecha,b);
    //                     l3++;

    //                     /*
    //                       NORA EL FORMATO DE ARCHIVO NO TENIA , EN ESTE PUNTO REQUERIA
    //                       GUARDAR EL QUE QUDA
    //                       SI SE USA , atoi dara error!;
    //                     */

    //                     (*Object3)[contador].hora = atoi(a);


    //                   }
    //                   contador++;

    //                   // cin.get();
    //                   // // add method using read
    //                   // //end

    //                 }
    //                 else{
    //                   break;
    //                 }
    //             }
    //             DATA.close();
    //             return 1;
    //         }


            template <class T>
                    int generateFromBinary(char* file_name,T **Objects,int &largo){
                        fstream DATA(file_name,ios::in | ios::binary );
                        if ( DATA.fail() ) {
                          return 0;
                        }
                        int contador = 0;
                        int max = 1;
                        (*Objects) = new T;

                        while ( true ) {
                          T *bufer = new T;
                          DATA.read((char*)bufer,sizeof(T));
                            if ( !DATA.eof() ) {
                              if ( contador == max ) {
                                (*Objects) = (T*)(realloc((*Objects),sizeof(T)*(max+10)));
                                max=max+10;
                              }
                              (*Objects)[contador] = *bufer;
                              contador++;
                              // cin.get();
                              // add method using read
                              //end
                            }else{
                              break;
                            }
                        }
                        largo = contador;
                        DATA.close();
                        return 1;
                    }


    template <class T>
    int saveTObinary(T* Array, int size,char* outName){
              fstream F(outName, ios::out | ios::binary );

              if ( F.fail() ) {
                 return 0;
              }

              for (int i = 0; i < size; i++) {
                  T *bufer = new T;
                  F.write((char*)&Array[i],sizeof(T));
              }
              F.close();
              return 1;
    }





#endif
