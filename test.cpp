#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream>      // std::stringstream, std::stringbuf
 
using namespace std;
 
int main()
{	
    string str= "hello world I am very happy!";                           
    stringstream sstream;     //sstream<<
    sstream << str;
 
    // cout << sstream << endl;
    while (sstream)
      {
        string substr;
 
        sstream >> substr;
        cout << substr << endl;    //也可vec.push_back(substr);
      } 


}

