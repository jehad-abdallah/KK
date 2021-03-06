#include "stdafx.h"
#include <clocale>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool NotEnoughArg(int argc)
{
	return (argc != 4);
}

bool CorrectArg(int argc)
{
	return(argc == 4);
}

bool IsTriangle(double a,double b,double c)
{

	return (a + b > c && a + c > b && b + c > a);
}

bool IsEquilateral(double a, double b, double c)
{
	return (a == b && b == c);
}

bool IsIsosceles(double a, double b, double c)
{
	return ((a == b && b != c) || ( a == c && a != b) || (b == c && a != c));
}

double StringToDouble(const char* str, bool & err)
{
	char* pLastChar = NULL;
	try
	{
		string a = str;
		std::replace(a.begin(), a.end(), '.', ',');
		double doubleFromStr = stod(a);
		return doubleFromStr;
	}
	catch (const invalid_argument)
	{
		err = true;
		return 0;
	}
}

int main(int argc, char * argv[])
{
	double a, b, c;
	if (NotEnoughArg(argc))
	{
		cout << "This is not right Arguments you should right 3 Arguments \n";
		return 1;

	}

	bool error, error2, error3;
	error = false;
	error2 = false;
	error3 = false;
	a = StringToDouble(argv[1], error);
	b = StringToDouble(argv[2], error2);
	c = StringToDouble(argv[3], error3);

	
	if (error || error2 || error3)
	{
		cout << "You must write a number \n";
		return 1;
	}
	if (IsTriangle(a, b, c))
	{
		if (IsEquilateral(a, b, c))
		{
			cout << "this is IsEquilateral triangle \n";
			return 0;
		}
		else if (IsIsosceles(a, b, c))
		{
			cout << "This is IsISosceles Triangle \n";
			return 0;
		}
		cout << "This is common Triangle \n";
	}
	else
	{
		cout << "This is not Trianlge";
	}

	return 0;
}


