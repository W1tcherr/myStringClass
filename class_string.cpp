#include"Class_string.h"

myString::myString(const char* str) // 
{
	length = strLength(str);
	this->str = new char[length + 1];

	for (int i = 0; i < length; i++)
	{
		this->str[i] = str[i];
	}

	this->str[length] = 0;
}

myString::myString(const myString& other) // 
{

	length = strLength(other.str);
	str = new char[length + 1];

	for (int i = 0; i < length; i++)
	{
		str[i] = other.str[i];
	}

	str[length] = 0;
}

myString::myString(myString&& other) // 
{
	this->length = other.length;
	this->str = other.str;
	other.str = nullptr;
}

myString::~myString()
{
	delete[] str;
	str = nullptr;
}

myString& myString::operator = (const myString& other)
{
	if (str != nullptr)
	{
		delete[] str;
		str = nullptr;
	}

	if (other.str == nullptr)
	{
		this->str = nullptr;
		return *this;
	}

	length = strLength(other.str);
	this->str = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		this->str[i] = other.str[i];
	}
	this->str[length] = 0;
	return *this;
}

myString myString::operator + (const myString& other)
{
	myString newStr;

	int size1 = strLength(this->str);
	int size2 = strLength(other.str);
	newStr.length = size1 + size2;

	newStr.str = new char[newStr.length + 1];

	int i = 0;
	for (; i < size1; i++)
	{
		newStr.str[i] = this->str[i];
	}

	for (int j = 0; j < size2; j++, i++)
	{
		newStr.str[i] = other.str[j];
	}

	newStr.str[newStr.length] = 0;
	return newStr;
}

bool myString::operator == (const myString& other)
{
	if (this->length != other.length)
	{
		return false;
	}

	for (int i = 0; i < length; i++)
	{
		if (this->str[i] != other.str[i])
		{
			return false;
		}
	}
	return true;
}

bool myString::operator != (const myString& other)
{
	return !(this->operator==(other));
}

char& myString::operator [](int index)
{
	return str[index];
}

void myString::append(char symbol)
{
	char* temp = str;
	str = new char[length + 2];

	for(int i = 0; i < length; ++i)
	{
		str[i] = temp[i];
	}
	str[length] = symbol;
	length++;
	str[length] = 0;

	delete[] temp;
}

int myString::strLength(const char* string)
{
	int i = 0;
	while(string[i] != '\0')
	{
		++i;
	}
	return i;
}

int myString::Length()
{
	return length;
}

void myString::print()
{
	std::cout << str << std::endl;
}

std::ostream& operator <<(std::ostream& ost, const myString& String)
{
	return ost << String.str;
}

std::istream& operator >>(std::istream& ist, myString& String)
{
	if (String.str != nullptr)
	{
		delete[] String.str;
		String.str = nullptr;
	}
	String.str = new char[0];
	String.length = 0;

	char c;
	while (ist.get(c) && c != '\n')
	{
		String.append(c);
	}
	return ist;
}