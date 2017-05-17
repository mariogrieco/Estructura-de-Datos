#ifndef _HELPERS_H_
#define _HELPERS_H_

        int length(char *);   //Tamano del char
        int length(int);      // tamano del int
        int getAt(int, int ); // pos del int (cual,pos)

int length(char *cadena_t){
  int count = 0;

  while ( cadena_t[count] != '\0' ) {
    count++;
  }

  return count;
}

int length(int numbers_t){
  int count = 0;
  while ( numbers_t != 0 ) {
        count++;
        numbers_t /= 10;
  }
  return (count);
}

int getAt(int entero, int pos){
    int i = 0;
    while ( i < pos) {
       entero /= 10;
      i++;
    }
    return (entero%10);
}

void toLower(char* out, char* data)
{
  int i;

  for (i = 0; data[i] != '\0'; ++i)
  {
      out[i] = tolower(data[i]);
  }

  out[i] = '\0';
}



// FILE FileManager BINARY ONLY
template <class T>
class FileManager
{
public:
  int lines;
  int seekg;
  int lineSize;
  char *bufer;
  fstream FILE;
  fstream output;
  T *BuferSwapData;

  FileManager(){
  };

  FileManager(char* fileName,int lineSize = 2000){
      seekg = 0;
      bufer = new char[lineSize];
      this->lineSize = lineSize;
      FILE.open(fileName, ios::in | ios::out | ios::binary);
      if ( FILE.fail() ) 
      {
        cout << "error En la apertura de " << fileName << " FileManager exit(0)" << endl;
        exit(0);
      }
      FILE.seekg(0,ios::end);
      lines = FILE.tellp() / lineSize;
      update();
  };

  void gotoline(int pos){
    update();
    FILE.seekg(lineSize*pos,ios::beg);
  }

  int getKg(){
    return FILE.tellg();
  }
  void write(char* buf){
    FILE >> buf;
  }

  void update(){
    FILE.clear();
    FILE.seekg(0,ios::beg);
  }
  void close(){
    FILE.close();
  }
  char* read(){
    FILE.getline(bufer,2000,' ');
    return bufer;
  }

  bool eof(){
    return FILE.eof() ? true:false;
  }

  void verify(){
    // warning! PUEDE DAÑAR EL ARCHIVO
      // update();
      // while(true){
      //   if ( FILE.eof()) { break; }
      //   FILE.getline(bufer,2000,' ');
      //   cout << bufer << endl;
      //   cin.get();
      //   fflush(stdin);
      //   fflush(stdout);
      // }
  }

  void genFromArray(T &in, int size){

  }

  void genFromBinary(){
      BuferSwapData = new T[lines];
      int contador = 0;
      this->update();
      while( contador < lines ){
        FILE.read(BuferSwapData[contador],lineSize);
        contador++;
      }
      this->update(); 
  
  }

  void genFromTxt(){
    // CA,BIA RADICALMENTE
    while ( true ){
      FILE.getline(bufer,lineSize,'\n');
      if ( FILE.eof() ){
        break;
      }

    }
      // BuferSwapData = new T[];
      // int contador = 0;
      // this->update();
      // while( contador < lines ){
      //   FILE.read(BuferSwapData[contador],lineSize);
      //   contador++;
      // }

      // this->update(); 
  
  }

  void saveToTxt(char *fileName){ // FILE TEXT
    output(fileName,ios::out);

    /* 
      BAD BAD BAD...
    */

    output.close();
  }

  void saveToBinary(char *fileName){ // FILE bin
    output(fileName,ios::out | ios::binary);
    for (int i = 0; i < lines; ++i)
    {
      output.write(BuferSwapData[i],lineSize);
    }

    output.close();
  }


  ~FileManager(){
  };
  
};

// end file manager

// int hashPlegamiento(int tipe){
//   int num = 0;
//   int result = 0;
//   int size = getSize(tipe);
//   int contador = 0;
//   bool bandera = true;

//   while ( size > 0 ) {

//     if ( contador == 2 ) {
//        contador = 0;
//        result *= 10;
//        result += num;
//        num  = 0;
//     }
//     num += getFor(tipe,size-1);
//     size--;
//     contador++;
//   }
//    result *= 10;
//    result += num;

//   if ( getSize(result) > 2 ) {
//       hashPlegamiento(result);
//   }else{
//       return result;
//   }
// }

// void initIn(int *ar, int largo,int ho){
//     for (int i = 0; i < largo; i++) {
//        ar[i] = ho;
//     }
// }

// int cuacua(int *array,int hash, int bufer,int length){
//   int pos = 1;
//   int bandera = false;
//   int contador = 2;

//   a:
//   for (int i = hash+pos; i < 100; i+=contador) {
//         if ( array[i] == -1 ) {
//              array[i] = bufer;
//              bandera = true;
//              return 1;
//         }
//   }

//   contador*=2;
//   pos+=1;
//   if ( pos+contador < 100 ) {
//     goto a;
//   }

//    pos = 0;
//    contador = 2;

//   b:
//   if ( bandera == false ) {
//     for (int i = pos; i < hash; i+=contador) {
//       if ( array[i] == -1 ) {
//            array[i] = bufer;
//            bandera = true;
//            return 1;
//       }
//     }
//   }

//   contador*=2;
//   pos+=1;
//   if ( contador+pos <= hash ) {
//     cout << endl;
//     goto b;
//   }

//   return 0;

// }

#endif
