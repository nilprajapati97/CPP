#include <iostream>
using namespace std;
// arroaw operator
class My{

	private : int *num;
    public:
	    My()
	    {
	    	num = NULL;
	    }
	    My(int n)
	    {
	    	num = new int(n);
	    }
         My *operator->()
	 {
	 	if (num == NULL)
		{
			cout<< "Error attempt to dereference a NULL pointer.!"<<endl;
			num = new int(0);
		}
		return this;
	 
	 }	 
	 void print()
	 {
		 if(num == NULL)
		 {
		 	cout<< "Error: number is NULL..!"<<endl;
		 }
		 else
		 {
		 	cout<< "Number = "<<*num<<endl;
		 }
	 }
        void set(int n)
	{
		if(num == NULL)
		{
			cout<< "Error : number is NULL...!"<<endl;
			num = new int (0);
		}
		*num = n;
	}
	~My()
	{
		delete num;
	}
};

int main()
{
	My w(42);
	w->print();

       My Empty;
       Empty->print();


       Empty->set(100);
       Empty->print();
       return 0;
}

