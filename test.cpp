#include <string>       // std::string
#include <iostream>     // std::cout
using namespace std;

class A
{
public:
  ~A(){printf("~A \n");}
  void aaa();
};
void A::aaa(){}
class B
{
public:
  ~B(){printf("~B \n");}
  void bbb(A a);
};
void B::bbb(A a)
{
  a.aaa();
}

int main()
{
  A a1;
  B b1;
  for (int i = 0; i < 10; i++)
  {
    b1.bbb(a1);
  }

}



