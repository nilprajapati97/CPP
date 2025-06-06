#include<iostream>
#include<stdlib.h>
using namespace std;

class A
{
  private:int x; 
          
  public:void set()
	{
          x=10;
	}
    
        void display()
	{
          cout<<x<<endl;
        }
  
       void* operator new(size_t size)
       {
          void *p;
          p=malloc(size);
          return p;
       }


      void operator delete(void *q)
       {
          cout<<"In delete"<<endl;
          free(q);
       }
};

main()
{
  A *s=new A;
  s->set();
  s->display();
  delete s; 
}


