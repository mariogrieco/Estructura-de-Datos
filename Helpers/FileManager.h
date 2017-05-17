#ifndef _FILE_MANAGER_H_
#define _FILE_MANAGER_H_

/* just for BINARY mode open file in hexadecimal mode 
  ( be carefull: save mode need to be ..,)
*/

#include <fstream>
#include <time.h>
#include <string.h>

template <class T> class FileManager {


public:

  /*
      Directa MERGE SORT PRIVATE RESORCES   
        // verificar velocidad con eof y contadores!!!
        // quitar los write del class colocarlos directo
      n = 1M ~ 9s
      n^1/2
  */

      std::fstream bufer1;
      std::fstream bufer2;


  void split( unsigned int block_length ){

        FILE.clear();
        FILE.seekg(0,std::fstream::beg);
        int count = 0;
        bool b = true;
        block_length += 1;
        
        // std::fstream bufer1;
        // std::fstream bufer2;

        bufer1.open("bufer1.temp", std::ios::out | std::ios::binary );
        bufer2.open("bufer2.temp", std::ios::out | std::ios::binary );
  
        if ( bufer1.fail() || bufer2.fail() )
        {
          std::cerr << "Fail while creating bufer mergeSort binary files!!! line ~ on FileManager\n";
          bufer1.close();
          bufer2.close();
          this->close();
          exit(0);
        }

        while( true ){   
          this->read(&bufer);
          if ( !FILE.eof() )
          {
              count++;
              if ( count%block_length == 0 )
              {
                b = !b; 
                count = 1;
              }

              if ( b )
              {
                bufer1.write(reinterpret_cast<char*>(&bufer),sizeof(T));
              }
              else
              {
                bufer2.write(reinterpret_cast<char*>(&bufer),sizeof(T));
              }
          }
          else
          {
            break;
          }

        }

        bufer1.close();
        bufer2.close();
  }
void merge( unsigned int block_length ){
          
        FILE.clear();
        FILE.seekg(0,std::fstream::beg);
        bufer1.open("bufer1.temp", std::ios::in  | std::ios::binary );
        bufer2.open("bufer2.temp", std::ios::in  | std::ios::binary );

      T b1;
      T b2;

      unsigned int bc1 = 0;
      unsigned int bc2 = 0;

        if ( bufer1.fail() || bufer2.fail() || FILE.fail() )
        {
          std::cerr << "Fail while opening bufer"; 
          std::cerr << " mergeSort binary files!!! line ~ on FileManager\n";
          bufer1.close();
          bufer2.close();
          this->close();
          exit(0);
        }

         do{
        
        bc1 = 0;
        bc2 = 0;

        bufer1.read(reinterpret_cast<char*>(&b1),sizeof(T));
        bufer2.read(reinterpret_cast<char*>(&b2),sizeof(T));

        while ( !bufer1.eof() && !bufer2.eof() && bc1 < block_length && bc2 < block_length )
        {

            if ( b1 < b2 )
            {
              FILE.write(reinterpret_cast<char*>(&b1),sizeof(T));
              bc1++;
              if ( bc1 < block_length )
              {
                 bufer1.read(reinterpret_cast<char*>(&b1),sizeof(T));
              }
            }
            else
            {
              bc2++;
              FILE.write(reinterpret_cast<char*>(&b2),sizeof(T));
              if ( bc2 < block_length )
              {
                 bufer2.read(reinterpret_cast<char*>(&b2),sizeof(T));
              }
            }
        }

        while( bc1 < block_length && !bufer1.eof() )
        {
            FILE.write(reinterpret_cast<char*>(&b1),sizeof(T));
            bc1++;
              if ( bc1 < block_length )
              {
                 bufer1.read(reinterpret_cast<char*>(&b1),sizeof(T));
              }        }

        while( bc2 < block_length && !bufer2.eof() )
        {
            FILE.write(reinterpret_cast<char*>(&b2),sizeof(T));
            bc2++;
              if ( bc2 < block_length )
              {
                 bufer2.read(reinterpret_cast<char*>(&b2),sizeof(T));
              }        
        }

       } while ( !bufer1.eof() || !bufer2.eof() );
      
            bufer1.close();
            bufer2.close();
  } 


public:
  unsigned int lines;
  unsigned int seekg;
  unsigned int lineSize;
  T bufer; // ~swap
  std::fstream FILE;
  char file_name[256];

  FileManager(){
  };

  FileManager(char* file_name ){

      std::cerr << "FILE IS LOADING...\n";
      strcpy(this->file_name,file_name);
      this->seekg = 0;
      this->lineSize = sizeof(T);
      FILE.open( file_name, std::ios::in | std::ios::out | std::ios::binary );
      if ( FILE.fail() ) 
      {
        std::cerr << "fail while opening file " << file_name << " FileManager exit(0)\n" ;
        exit(0);
      }
      else{
        std::cerr << "file has been load!\n";
        this->FILE.seekg(0,std::ios::end);
        this->lines = ( this->FILE.tellg()/sizeof(T));
        std::cerr << "lines: " << this->lines << '\n';
      }

      update();  // before this->FILE.seekg(0,std::ios::end); nd this line after
  };

  void open(char* file_name ){

      std::cerr << "FILE IS LOADING...\n";
      strcpy(this->file_name,file_name);
      this->seekg = 0;
      this->lineSize = sizeof(T);
      FILE.open(file_name, std::ios::in | std::ios::out | std::ios::binary);
      if ( FILE.fail() ) 
      {
        std::cerr << "fail while opening file " << file_name << " FileManager exit(0)\n" ;
        exit(0);
      }
      else{
        std::cerr << "file has been load!\n";
        this->FILE.seekg(0,std::ios::end);
        this->lines = ( this->FILE.tellg()/sizeof(T));
        std::cerr << "lines: " << this->lines << '\n';
      }

      update();
  }

  void gotoline(unsigned int pos ){
    FILE.seekg(pos*this->lineSize);
    this->seekg = pos;
  }

  void write(T *buf){
    FILE.write(reinterpret_cast<char*>(buf),sizeof(T));
  }

  void update(){
    FILE.clear();
    FILE.seekg(0,std::fstream::beg);
  }
  void close(){
    if ( FILE.is_open() )
    {
      FILE.close();
    }
  }
  
  T read(){
    FILE.read(reinterpret_cast<char*>(&bufer),sizeof(T));
    return bufer;  //zTO SLOW FOR sort
  }

  void read(T *data){
    FILE.read(reinterpret_cast<char*>(data),sizeof(T));
    // return bufer;  TO SLOW FOR RETURN DATA
  }

  bool eof(){
    return FILE.eof();
  }

  bool createFile(char *filename = (char*)"FILE.HEX" ){

        std::fstream output(filename, std::ios::out | std::ios::binary);
        if (  output.fail() )
        {
           std::cerr << "ERROR AL CREAR ARCHIVO " << filename << " \n";
           output.close();
        }else{
          std::cerr << "ARCHIVO " << filename << " CREADO \n";
          output.close();
        }
  
  }

  void print(){
      this->update();
      while ( true ){
        this->read(&this->bufer);
        if ( !FILE.eof() )
        {
           std::cout << this->bufer << " \n";   // use operator fstream << for class data!
        }
        else{
          std::cout << "\n";
          break;
        }
      }
      this->update();
  }

  // void genFromArray(){}
  // void arrayFromFile(){}
      // ad more here...
  // void swapFiles(){}

  void shellSort(bool ascendente = true){   // jajaj lol
      FILE.clear();
      FILE.seekg(0,std::fstream::beg);
      unsigned int pivote = (this->lines-1)/2;
      bool bandera = true;
      T swap1;
      T swap2;

      while ( pivote > 0 ) {
        bandera = false;
          for (unsigned int i = 0; i+pivote < this->lines; i++) {
                this->gotoline(i);
                this->read(&swap1);
                this->gotoline(i+pivote);
                this->read(&swap2);
             if ( swap1 > swap2 == ascendente) {
                this->gotoline(i);
                this->write(&swap2);   // mas rapido si va primero ?
                this->gotoline(i+pivote);
                this->write(&swap1);
                bandera = true;
             }
          }

          if ( bandera == false ) {
              pivote /= 2;
          }
      }
      FILE.clear();
      FILE.seekg(0,std::fstream::beg);
  }


  // external sort methods !!!
  void mergeSort(){   // mezcla directa
      for (int i = 1; i < this->lines; i*=2)
      {
           this->split(i);
           this->merge(i);
      }
  } 

  // void mezcalNatural o equilibradaMultiple
  // MÉTODO POLIFÁSICO

  ~FileManager(){
  };
  
};

#endif