
  void merge( unsigned int block_length ){
        
        unsigned int bc1 = 0;
        unsigned int bc2 = 0;

        std::fstream bufer1;
        std::fstream bufer2;
        
        T b1;
        T b2;

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
    FILE.clear();
    FILE.seekg( 0, std::fstream::beg );
  }
