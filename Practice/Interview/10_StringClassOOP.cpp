#include <iostream>
#include <cstring>

using namespace std;

class String {
	private:
		char* str;
		size_t length;

	public:
		// Constructor
		String(const char* s = "")
		{
			length = strlen(s);
			str = new char[length + 1];
			strcpy(str, s);
		}

		// Copy Constructor
		String(const String& other) 
		{
			length = other.length;
			str = new char[length + 1];
			strcpy(str, other.str);
		}

		// Move Constructor
		String(String&& other) noexcept : str(nullptr), length(0) 
		{
			str = other.str;
			length = other.length;
			other.str = nullptr;
			other.length = 0;
		}

		// Destructor
		~String() 
		{
			delete[] str;
		}

		// Assignment Operator Overloading
		String& operator=(const String& other) 
		{
			if (this != &other) {
				delete[] str;
				length = other.length;
				str = new char[length + 1];
				strcpy(str, other.str);
			}
			return *this;
		}

		// Move Assignment Operator
		String& operator=(String&& other) noexcept 
		{
			if (this != &other) {
				delete[] str;
				str = other.str;
				length = other.length;
				other.str = nullptr;
				other.length = 0;
			}
			return *this;
		}

		// Concatenation Operator Overloading
		String operator+(const String& other) const 
		{
			size_t newLength = length + other.length;
			char* newStr = new char[newLength + 1];
			strcpy(newStr, str);
			strcat(newStr, other.str);

			String temp(newStr);
			delete[] newStr;
			return temp;
		}

		// Comparison Operator Overloading
		bool operator==(const String& other) const 
		{
			return strcmp(str, other.str) == 0;
		}

		// Display Function
		void display() const 
		{
			cout << str << endl;
		}
};

int main() {
	String s1("Hello");
	String s2(" World");

	String s3 = s1 + s2; // Concatenation
	s3.display();

	String s4 = s3; // Copy Constructor
	s4.display();

	String s5;
	s5 = s4; // Assignment Operator
	s5.display();

	cout << (s4 == s5 ? "Equal" : "Not Equal") << endl;

	return 0;
}
