#include<iostream>
using namespace std;

template <class T>
class stack
{
  protected:T stk[5];
 	    int top;

  public:stack()
	{
          top=-1;    
	}
 
  void push(T item)
   {
     top++;
     stk[top]=item;
     cout<<item<<"inserted"<<endl; 
   }

T pop();
void show();
};

template <class T>
T stack<T>::pop()
{
  T item;
  
  item=stk[top];
  top--;
  cout<<item<<"poped"<<endl;
  return item;

}

template <class T>
void stack <T>::show()
{
  if(top==-1)
    cout<<"stack is empty"<<endl;
  else
    cout<<"stack element:";

  for(int i=top;i>=0;i--)
   cout<<stk[i]<<endl;
}

main()
{
  stack<int>int_stack;

  int_stack.push(10);
  int_stack.push(20);
  int_stack.push(30);

  int_stack.show();
  int_stack.pop();

 cout<<"+++++++++++++++++"<<endl;

  stack<char>char_stack;
 
  char_stack.push('a');
  char_stack.push('b');
  char_stack.push('c');

 
  char_stack.show();
}



