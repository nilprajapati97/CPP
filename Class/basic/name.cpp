//  getline(char_type* __s, streamsize __n, char_type __delim);

#include<iostream>
using namespace std;
main()
{
  char name[50];
  int a[5],i;

  cout<<"Please enter the name.."<<endl;

  cin.getline(name,sizeof(name),'\n');

  cout<<name<<endl;

 cout.putline(name);
  
// cin.ignore(sizeof(a),3);

//  for(i=0;i<5;i++)
//  cout<<a[i]<<endl;
}
