#include<iostream>
using namespace std;

// older print
class OldPrinter
{
	public : 
		void printOld()
		{
			cout<<"Print using old Printr\n";
		}
};
// target print
class IPrinter{
	public:
		virtual void print()= 0;
};
class PrintAdaptor : public IPrinter
{
	OldPrinter* oldPrinter;
	public:
	PrintAdaptor (OldPrinter *p):oldPrinter(p)
	{
	}
	void print() override
	{
		oldPrinter -> printOld();
	
	}
};
int main()
{
	OldPrinter old;
	PrintAdaptor adaptor(&old);
	adaptor.print();
	return 0;
}
