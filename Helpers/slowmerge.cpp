
  void merge( unsigned int block_length ){
          
      FILE.clear();
      FILE.seekg( 0, std::fstream::beg );

      std::fstream bufer1;
      std::fstream bufer2;

      T b1;
      T b2;

      unsigned int bc1 = 0;
      unsigned int bc2 = 0;


          bool bb1 = true;
          bool bb2 = true;


        bufer1.open("bufer1.temp", std::ios::in | std::ios::binary );
        bufer2.open("bufer2.temp", std::ios::in | std::ios::binary );

        if ( bufer1.fail() || bufer2.fail() )
        {
          std::cerr << "Fail while opening bufer"; 
          std::cerr << " mergeSort binary files!!! line ~ on FileManager\n";
          bufer1.close();
          bufer2.close();
          this->close();
          exit(0);
        }



        while(  !bufer1.eof() || !bufer2.eof() ){

                  if ( bb1 && !bufer1.eof() )
                  {
                      bufer1.read(reinterpret_cast<char*>(&b1),sizeof(T));
                  }

                  if ( bb2 && !bufer2.eof() )
                  {
                      bufer2.read(reinterpret_cast<char*>(&b2),sizeof(T));
                  }

                  if ( bc1 < block_length && bc2 < block_length && !bufer2.eof() && !bufer1.eof())
                  {
                      if ( b1 < b2 )
                      {
                          this->FILE.write(reinterpret_cast<char*>(&b1),sizeof(T));
                          bb1 = true;
                          bb2 = false;
                          bc1++;
                      }
                      else{
                          this->FILE.write(reinterpret_cast<char*>(&b2),sizeof(T));
                          bb2 = true;
                          bb1 = false;
                          bc2++;
                      }

                  }  
                  else if ( bc1 < block_length && !bufer1.eof())
                  {
                          this->FILE.write(reinterpret_cast<char*>(&b1),sizeof(T));
                          bb1 = true;
                          bb2 = false;
                          bc1++;
                  }
                  else if ( bc2 < block_length && !bufer2.eof())
                  {
                         this->FILE.write(reinterpret_cast<char*>(&b2),sizeof(T));
                          bb2 = true;
                          bb1 = false;
                          bc2++;
                  }

                  if( bc1 == block_length && bc2 == block_length)
                  {
                      bc1 = 0;
                      bc2 = 0;
                  } 
        } 

            bufer1.close();
            bufer2.close();
  } 