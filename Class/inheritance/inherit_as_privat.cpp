#include<iostream>
using namespace std;

class A
{
  private:    int x;
  protected:  int y;
  public :    int z; 
};

class B:private A
{
   private:   int i;
   protected: int j;
   public:    int k;
  
};

main()
{
  A a1;
  B b1;

  a1.z=10;
//  b1.z=10;
   b1.k=20;
}
