#include<iostream>
using namespace std;

void elevator(int floor);
long long Factorial(int n);
double Power(double a, int b);
int Fibonacci(int n);

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите номер этажа: "; cin >> n;
	elevator(n);
	//cout << "Recusion";
	//main();

	cout << "Введите число: "; cin >> n;
	cout << n << "! = " << Factorial(n) << endl;

	double a;
	int b;

	cout << "Введите основание: "; cin >> a;
	cout << "Введите степень: "; cin >> b;
	cout << a << " в степени " << b << " = " << Power(a, b) << endl;

	cout << "Введите колличество чисел Фибоначи: "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << Fibonacci(i) << " ";
	}
	cout << endl;
}
void elevator(int floor)
{
	if (floor == 0)
	{
		cout << "Вы в подвале" << endl;
		return;
	}
	cout << "Вы на " << floor << " этаже" << endl;
	elevator(floor - 1);
	cout << "Вы на " << floor << " этаже" << endl;
}


long long Factorial(int n)
{
	if (n <= 1)return 1;

	return n * Factorial(n - 1);
}

double Power(double a, int b)
{
	if (b == 0)return 1;

	return a * Power(a, b - 1);

}

int Fibonacci(int n)
{
	if (n <= 0)
	{
		return 0;
	}
	else if (n == 1)
	{
		return 1;
	}
	else
	{
		return Fibonacci(n - 1) + Fibonacci(n - 2);
	}
}
