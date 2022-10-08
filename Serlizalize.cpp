#include <iostream>
#include <vector>
#include <fstream>
#include "boost/serialization/vector.hpp"
#include "boost/archive/text_oarchive.hpp"
#include "boost/archive/text_iarchive.hpp"

class Info
{
  
private:
    // Allow serialization to access non-public data members.
    
    friend class boost::serialization::access;

    template<class Archive>
    void save(Archive & ar, const unsigned int version) const 
    {
      ar & filenames;
    }

    template<class Archive>
    void load(Archive & ar, const unsigned int version) 
    {
      ar & filenames;
    }

    BOOST_SERIALIZATION_SPLIT_MEMBER()
   
    std::vector<std::string> filenames;

public:
    void Addobj( const std::string& hellow );    
    void Print() const;
};

void Info::Print() const
{
    std::copy(filenames.begin(),     
              filenames.end(),     
              std::ostream_iterator<std::string>(std::cout, "\n"));     
}

void Info::Addobj( const std::string& hellow )
{
    filenames.push_back( hellow );    
}

int main(int argc, char** argv) 
{
    Info info;
    info.Addobj( "ThisFile.txt" );
    info.Addobj( "ThatFile.txt" );
    info.Addobj( "OtherFile.txt" );
    
    // Save hellow data contained in Info object
    {
      // Create an output archive
      std::ofstream ofs( "store.dat" );
      boost::archive::text_oarchive ar(ofs);

      // Save the data
      ar & info;
    }
    
    // Restore from saved data and print to verify contents
    Info restored_info;
    {
        // Create and input archive
        std::ifstream ifs( "store.dat" );
        boost::archive::text_iarchive ar( ifs );

        // Load the data
        ar & restored_info;
   }
    
    restored_info.Print();

    return 0;
}
