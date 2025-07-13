#include<iostream>
#include <cstring>
using namespace std;
/*

Shallow COpy

*/

class Car
{
 public:
    void shiftGear()
    {
        cout<< "In parent class : ShiftGear" <<endl;
    }
    void f2()
    {
        cout<< "In parent class : f2" <<endl;
    }
 
 };
class SportScar:public Car
{
    int x;
public:

// void shiftGear()
//    {
//         cout<< "In Child class : ShiftGear" <<endl;
//    } 

   void f2(int x)
   {
       cout<< "In Child class : f2" <<endl;
   }

};

int main()
{
    SportScar obj;
    obj.shiftGear();
    //obj.f2();

}
