#include <iostream>
#include <stdexcept> // For exception handling

using namespace std;

class MyArray{
	private : int *Arr;
		  int size;
  public:	
      MyArray(int size)
      {
	      Arr = new int [size];
	      for(int i=0 ;i<size ;i++)
	      {
	      	Arr[i] = i*10;
	      }
      }
      int& operator [] (int index)
      {
	      if(index < 0 || index > size)
	       {
		 		 throw out_of_range("Index out of bounds");
	       }
	       return Arr[index];
      }
};
int main()
{
	MyArray a(5);

	//cout<< "a[-1]-:"<<a[-1]<<endl;
	cout<< "a[0]-:"<<a[0]<<endl;
	cout<< "a[1]-:"<<a[1]<<endl;
	cout<< "a[2]-:"<<a[2]<<endl;
	cout<< "a[3]-:"<<a[3]<<endl;
	cout<< "a[4]-:"<<a[4]<<endl;
	cout<< "a[5]-:"<<a[5]<<endl;

}
