#include<iostream>
using namespace std;

class A
{
  private:
    int  a;
	  int  b;

  public:
  	void SetData(int x, int y)
  	{
  	 	a=x;
  		b=y;
    
  	}	

    void display()
    {
      cout<<"a="<<a<<endl<<"b="<<b<<endl;
    } 

  A operator +(A c)
    {
        A temp;
        cout<<"in operator function"<<endl;
        temp.a= a+c.a;
        temp.b= b+c.b;
        return (temp);
    }
};

int main()
{
  //A c1(12.3,23.5),c2(1.3,3.8),c3;
  
  A c1, c2,c3;
  
  c1.SetData(3,4);
  c2.SetData(5,6);

  c1.display();    
  c2.display();    
 
  c3= c1+c2;  // c.operator+ (c2)
  c3.display(); 
  return 0;
}

