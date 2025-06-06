#include<iostream>
using namespace std;
template <typename t>
void bubble_sort(t (&b)[5],int ele)
{
	t i,j,temp;
	
	for(i=0;i<ele-1;i++)
	{
		for(j=0;j<ele-i-1;j++)
		{
			if(b[j]>b[j+1])
			{
				temp=b[j];
				b[j]=b[j+1];
				b[j+1]=temp;
			}
		}
	}
}
main()
{
	int a[5],ele,i;
	
	ele = sizeof(a)/sizeof(a[0]);
	
	cout<<"enter the element for array"<<endl;
	for(i=0;i<ele;i++)
	cin>>a[i];
	
	cout<<"display of element"<<endl;
	for(i=0;i<ele;i++)
	cout<<a[i]<<endl;
	 
	bubble_sort(a,ele);
	
	cout<<"after sorting of element"<<endl;
	for(i=0;i<ele;i++)
	cout<<a[i]<<endl;
}

