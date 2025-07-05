/*
Problem: You have an old class that doesn’t match a new interface you need.

Solution: Wrap the old class with an adapter.


*/

#include <iostream>
using namespace std;

// Old interface
class OldPrinter
{
public:
	void printOld()
	{
		cout << "Printing using OldPrinter\n";
	}
};

// Target interface
class IPrinter
{
public:
	virtual void print() = 0;
};

// Adapter
class PrinterAdapter : public IPrinter
{
	OldPrinter *oldPrinter;

public:
	PrinterAdapter(OldPrinter *p) : oldPrinter(p) {}
	void print() override { oldPrinter->printOld(); }
};

int main()
{
	OldPrinter old;
	PrinterAdapter adapter(&old);
	adapter.print(); // Output: Printing using OldPrinter
}
