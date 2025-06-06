#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
// set 1 Prime using function



bool isPrime(int x)
{
    for(int i=2 ;i<x ;i++)
        if(x%i==0)
            return false;
    return true;

}
void printPrime(int n)
{
    if(isPrime(n))
    {
        cout<<n<<" ";
    }
}
int main()
{
    vector <int> v1={10,13,15,21,23,29,31,35,40};

    for_each(v1.begin(),v1.end(),printPrime);
    cout<<endl;
    return 0;
}
*/ 


/*
//set 2 Functor


class Prime{
    public:
        bool isPrime(int x)
        {
            for(int i=2 ;i<x ;i++)
               if(x%i==0)
                return false;
            
            return true;
        }
    void operator()(int n) // function call
    {
        if(isPrime(n))
            cout<<" "<<n;
    }

};
int main()
{
    vector <int> v1={10,13,15,21,23,29,31,35,40};

    for_each(v1.begin(),v1.end(),Prime());
    cout<<endl;
    return 0;
}

*/


//Set 3 Lambda 
int main()
{
    vector <int> v1={10,13,15,21,23,29,31,35,40};

    for_each(v1.begin(),v1.end(),[](int &x)
    {
        int i;
        for(i=2; i<x; i++)
        {
            if(x % i == 0)
            break;
        }
          
        if(i==x)
            cout<<x<<" ";

    });
    cout<<endl;
    return 0;
}


