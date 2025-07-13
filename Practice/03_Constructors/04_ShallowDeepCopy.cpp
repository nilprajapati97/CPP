#include<iostream>
#include <cstring>
using namespace std;
/*

Shallow COpy

*/

class A
{
  char *str;

  public:
  A(const char *p)
  {
    cout<< "01 Default Constructor" <<endl;
    str = new char [strlen(p)] +1;
    strcpy(str,p);

  }

 
 // Deep Copy 
  // A(A &obj)
  // {
  //   cout<< "Explicit copy Constructor Constructor" <<endl;
  //   str = new char [strlen(obj.str)] +1;
  //   strcpy(str,obj.str);

  // }

void modify()
{
    str[0]= 'S';
}

  void print() 
  {
    cout <<"String="<<str<<endl;
    cout << __func__ << endl;
  
  }
};

int main()
{
 A obj1("Vector");
 A obj2 = obj1;

 
 obj1.modify();
 obj1.print();
 obj2.print();

}
