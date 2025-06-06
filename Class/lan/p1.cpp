/*  1) Write a C++ programe with the Employee class that creates five employees; sets their Age,
            Year of Service, and Salary; provide  a method of Employee that reports how many 
            thousands of rupees the employee earns, rounded to the nearest Rs.80,000/-.
*/

#include<iostream>
using namespace std;

class employee
{
  private: int age;
	   int yos;
           int salary;

  public: void setdata()
         {
           cout<<"Enter the age of employee"<<endl;
           cin>>age; 
          
	   cout<<"Enter the year of services of employee"<<endl;
           cin>>yos; 
          
	   cout<<"Enter the salary of employee"<<endl;
           cin>>salary; 
	 }
  
         void rounded()
         {
            cout<<"The result is.."<<endl;
            
            if(salary>=79000 && salary<=80000)
            display();
         }

         void display()
         {
            cout<<age<<endl<<yos<<endl<<salary<<endl;
         }
         
};

main()
{
  employee e1,e2,e3,e4,e5;

  e1.setdata();
  e2.setdata();
  e3.setdata();
  e4.setdata();
  e5.setdata();
 

  e1.rounded();
  e2.rounded();
  e3.rounded();
  e4.rounded();
  e5.rounded();
}






















