#include <iostream>
 
using namespace std;
 
int s1 = 43 ;
int s2 = 54 ;


void add(  );

int main () {

std::cout<<"s1 and s2 are "<<s1<< " : "<<s2<<std::endl;

add();

std::cout<<"s1 and s2 are "<<s1<< " : "<<s2<<std::endl;

}

void add()
{  std::cout<<"s1 and s2 are in the function "<<s1<< " : "<<s2<<std::endl; 
    s1 = 4;
   std::cout<<"s1 and s2 are in the function "<<s1<< " : "<<s2<<std::endl; 
    s2 =5 ;
   std::cout<<"s1 and s2 are in the function "<<s1<< " : "<<s2<<std::endl; 
  
}