
/*
ARRAY in STL

important member function of array class
- at
- []operato
- front()
- back()
- fill()
- swap()
- size()
- begin()
- end()

*/
#include <iostream>
#include <array>
using namespace std;

int main() {
    // Declare and initialize an std::array
    std::array<int, 5> arr = {11, 22, 33, 44, 55};

    cout<<arr.at(2)<<endl;
    
    cout<<"After"<<endl;
    arr.at(2) = 100;
    cout<<arr.at(0)<<endl;
    cout<<arr.at(1)<<endl;
    cout<<arr.at(2)<<endl;
    cout<<arr.at(3)<<endl;
    cout<<arr.at(4)<<endl;

   
    return 0;
}
