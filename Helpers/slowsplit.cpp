  void split( unsigned int block_length ){

        FILE.clear();
        FILE.seekg(0,std::fstream::beg);
        int count = 0;
        bool b = true;
        block_length += 1;
        
        std::fstream bufer1;
        std::fstream bufer2;

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