
/*
3. Basic Operations on vector
(a) Adding and Removing Elements
Function   ->   	Description
----------------------------------------------
push_back(x)        ---> Adds an element at the end
pop_back()          ---> Removes the last element
insert(pos, x)      ---> Inserts x at position pos
erase(pos)          ---> Removes element at pos
clear()             ---> Removes all elements
resize(n, x)        ---> Resizes the vector to n elements (optional fill with x)

*/
#include <iostream>
#include <vector>
using namespace std;
void display (vector <int> &v)
{
    for(int i=0 ;i<v.size();i++)
    {
        cout<<v[i]<< " ";
    }
    cout<<endl;

}
int main() {
    vector<int> vec1;
    int ele;
    for(int i=0; i<5;i++)
    {
        cout<<"Enter the Element add to this vector";
        cin>>ele;
        vec1.push_back(ele);
    }

    display(vec1);

    return 0;
}
