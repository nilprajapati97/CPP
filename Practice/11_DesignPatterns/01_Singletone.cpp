#include<iostream>
#include<mutex>
using namespace std;

class Singletone {
  private :
	  static Singletone* instance;
	  static mutex mtx;

	  Singletone()
	  {
	    cout<<"Singltone instanse created"<<endl;
	  
	  }
         
	  Singletone(const Singletone &) = delete;
	  Singletone& operator=(const Singletone&) = delete;

  public:
	  static Singletone* getinstance()
	  {
	   if(instance == nullptr)
	   {
	   	lock_guard<mutex>lock(mtx);
		if(instance == nullptr)
		{
		instance = new Singletone();
		
		}
	   
	   }
	   return instance;
	  
	  
	  }
    void doSomething()
    {
    	cout<<"Do something called"<<endl;
    }

};
Singletone* Singletone::instance = nullptr;
mutex Singletone::mtx;

int main()
{
	Singletone* s1 = Singletone::getinstance();
	s1->doSomething();


	Singletone* s2 = Singletone::getinstance();
	s1->doSomething();

	cout<<"s1 address:"<<s1<<endl;
	cout<<"s2 address:"<<s2<<endl;
       
	return 0;
}
