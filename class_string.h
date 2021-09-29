#include<iostream>

class myString
{
public:
	myString(): str(nullptr), length(0) //member init list
	{}

	myString(const char* str); //base
	
	myString(const myString& other); //copy constructor

	myString(myString&& other); //move constructor

	~myString();

	myString& operator = (const myString& other);

    myString& operator = (const char* other);

	myString operator + (const myString& other);

    myString operator += (const myString& other);

	bool operator == (const myString& other);

	bool operator != (const myString& other);

	char& operator [](unsigned index);

	void append(char sim); //add new symbol in str

	int Length();

	void print();

private:
	char* str;
	unsigned length;

	friend std::ostream& operator << (std::ostream& os, const myString& str);
	friend std::istream& operator >> (std::istream& is, myString& str);
};