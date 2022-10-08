#include <iostream>
#include <string>
#include <limits>
#include "LoginSys.utils.h"

using std::string; 


class User{
  private:
  int32_t ID;
  string USERNAME;
  string PASSWORD;
  string ADDRESS;
  double Balance;
  string EncryptUser = "NULL";
  string EncryptPass = "NULL";



  public:
 
  User(){
    ID = -1;
    USERNAME ="/0";
    PASSWORD = "/0";
    ADDRESS = "/0";
    Balance =  -1;  
  }
  
  void registeration ();
  void login();

};




void User::registeration() {
    // Collectiong the username from new users

      while ((std::cout << "Enter User-Name "<<std::endl) 
      && (!(std::cin >> USERNAME) || USERNAME.size() < 8 || USERNAME.size()> 25))
       {
    std::cout << "That's not a Valid User-Name (Min 8-characters)"<<std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
      // Collectiong the password from new users
      while ((std::cout << "Enter Password "<<std::endl) 
      && (!(std::cin >> PASSWORD) || PASSWORD.size() < 8 || PASSWORD.size()> 25))
       {
    std::cout << "That's not a valid Password (Min 8-characters)"<<std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
      // Collectiong the username from new Address
      while ((std::cout << "Enter Address" <<std::endl) 
      && (!(std::cin >> ADDRESS) || ADDRESS.size() < 10 || ADDRESS.size()> 25))
       {
    std::cout << "That's not a valid Address "<<std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
       }
      // Setting Min _ Credit for the  user      
      while ((std::cout << "Enter Starting Balance "<<std::endl) 
      && (!(std::cin >> Balance) || (Balance < 1000 )))
       {
    std::cout << "That's not a valid Password (Min Balance is a 1000)"<<std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
       }
      // Collectiong the username from new users
      //Saves password11 and username to txt file.
      
      std::cout<<EncryptUser<<": UserName"<<std::endl;
      std::cout<<EncryptPass<<": Password"<<std::endl;
      EncryptUser = sha1(USERNAME);
      EncryptPass = sha1(PASSWORD);
      std::cout<<EncryptUser<<": UserName"<<std::endl;
      std::cout<<EncryptPass<<": Password"<<std::endl;


}

void User::login()
{

}

int main()

{   int userChoice;
    std::cout<<" Enter User Choice"<<std::endl;
      while ((std::cout << "1.Register Account 2.Login 3.Exit "<<std::endl) 
      && (!(std::cin >> userChoice) || userChoice < 1 || userChoice > 3))
       {
    std::cout << "That's not a Valid option "<<std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
    
    switch(userChoice)
    {
        case 1:
        {
            User Person;
            Person.registeration();
            break;
        }
        

        case 2:
        {
          User Person;
          Person.login();
           break;
        }

       

        case 3:

        break;

        default:
        std::cout<<"Oops choose an option from the given menu"<<std::endl;
        break;
    }
    
    return 0; 
}