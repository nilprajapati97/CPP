#include<iostream>
using namespace std;
struct BigData {
	int data[1024][1024];
};
 
void f(BigData & value){
	value.data[0][0] = 5;
}
int main() {
	BigData x;
	f(x);
	cout<<x.data[0][0]<<endl;
}
