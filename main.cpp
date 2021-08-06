#include<iostream>
#include"Class_string.h"

int main()
{
	bool result;
	myString a("hi"), b(" bro");
	myString c;
	std::cout << "Length c string: " << c.Length() << std::endl;
	std::cout << "a string: " << a << std::endl;
	std::cout << "b string: " << b << std::endl;
	std::cout << "Length a string: " << a.Length() << std::endl;
	c = a + b;
	std::cout << "c = a + b: " << c << std::endl;
	std::cout << "Length c string: " << c.Length() << std::endl;
	c = "hello";
	std::cout << "c string = hello: " << c << std::endl;
	std::cout << "Length c string: " << c.Length() << std::endl;
	result = a == b;
	std::cout << "a == b: " << result << std::endl;
	c = a;
	std::cout << "c = a" << std::endl;
	result = a == c;
	std::cout << "a == c: " << result << std::endl;
	std::cout << "a[0]: " << a[0] << std::endl;
	a[0] = 'H';
	std::cout << "a[0] = H" << std::endl;
	std::cout << "a string: " << a << std::endl;
	a.append('!');
	std::cout << "a.append('!'): " << a << std::endl;
	std::cout << "enter the string: " << std::endl;
	std::cin >> a;
	std::cout << a << std::endl;
	std::cout << a.Length() << std::endl;
	system("pause");

	return 0;
}