#include <iostream>
using namespace std;
double function(double x)
{
	return (x * x + 8 * x - 2);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int i = 1;
	double a = 0, b = 1, eps = pow(10, -8), c1 = 0, c0;
	cout << " eps = " << eps << endl;
	do
	{
		c0 = c1;
		cout << " Шаг " << i << ": [" << a << "; " << b << "], c = ";
		c1 = (a * function(b) - b * function(a)) / (function(b) - function(a));
		cout << c1 << ", f(c) = " << function(c1) << ", f(a)f(c) = " << function(a) * function(c1) << endl;
		if (function(a) * function(c1) < 0)
			b = c1;
		else
			a = c1;
		i++;
		cout << c1 - c0 << endl;
	} while (!(abs(c1 - c0) < eps));
	cout << " x = " << c1;
	return 0;
}