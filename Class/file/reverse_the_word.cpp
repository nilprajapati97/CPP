#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;

main()
{
	string s1;
	char a[100]={},temp;
	int i=0,j,k=0;
	fstream fout;

	fout.open("new",ios::out|ios::in);

	if(fout.fail())
		cout<<"File is not opened"<<endl; 
	else
		cout<<"File is opened"<<endl;

	while(!fout.eof())
		a[i++]=fout.get();
	a[i]='\0';

	for(i=0;a[i];i++)
		cout<<a[i]; 
	cout<<endl;

	k=0;
	for(i=0; ;i++) 
	{
		if(a[i]==' ' || a[i]=='\0')
		{
			for(j=i-1;k<j;k++,j--)
			{
				temp=a[j];
				a[j]=a[k];
				a[k]=temp; 
			}
			k=i+1;
		}
		if(a[i]=='\0')
			break;
	}


	for(i=0;a[i];i++)
		cout<<a[i]; 

	fout.close();

	fout.open("new");

	for(i=0;a[i];i++)
		fout.put(a[i]);          
}

