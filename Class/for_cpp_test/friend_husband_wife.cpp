#include<iostream>
using namespace std;

class wife;
class husband
{
  private:int salary;
	  string name;

  public:void set()
         {
          cout<<"Enter the husband name"<<endl;   
          cin>>name;

          cout<<"Enter the husband salary"<<endl;   
          cin>>salary;
         } 
         
friend int total_salary(husband,wife);   
};


class wife
{
  private:int salary;
	  string name;

  public:void set()
         {
          cout<<"Enter the wife name"<<endl;   
          cin>>name;

          cout<<"Enter the wife salary"<<endl;   
          cin>>salary;
         } 
         
friend int total_salary(husband,wife);   
};

int total_salary(husband h,wife w)
{
  return(h.salary+w.salary);
}

main()
{
  husband h;
  wife w;

  h.set();
  w.set();
 
  cout<<"total salary="<<total_salary(h,w)<<endl;  
}
