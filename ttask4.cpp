#define _USE_MATH_DEFINES // нужно для числа pi
#include <iostream>
#include <locale>
#include <cmath>
using namespace std;

double sumN(double, int, double&);
double sumE(double, double, int&);

int main()
{
	_USE_MATH_DEFINES
		setlocale(LC_ALL, "rus");
	cout << "Вычисление значений функции arctg(x)" << endl;
	double x; // значение аргумента
	double func; // точное значение функции
	double sum; // значение частичной суммы
	int n; // число слагаемых в частичной сумме

	int q = 1;
	while (q)
	{
		cout << "Введите 1, чтобы продложить, 0 , чтобы выйти" << endl;
		cin >> q;
		if (q==1)
		{
			cout << "Задание 1" << endl;
			cout << "Введите значение аргумента x < -1" << endl;;
			cin >> x;

			if (x > -1)// если х>=-1, то вычислить значение не получится, для этого нужен if
			{
				cout << " Вы ввели x > -1, введите x < -1" << endl;

			}

			else
			{
				cout << "Задайте число слагаемых  " << endl;
				cin >> n;
				func = atan(x); // вычисление "точного" значения
				double last;
				sum = sumN(x, n, last);
				cout << "Точное значение функции равно " << func << endl;
				cout << "Частичная сумма ряда равна " << sum << endl;
				cout << "Абсолютная погрешность равна " << fabs(func - sum) << endl;
				cout << "Последнее слагаемое равно " << last << endl << endl;
			}
			cout << "Задание 2" << endl;
			//double E;
			cout << "Введите значение аргумента x < -1 " << endl;
			cin >> x;
			if (x > -1)
			{
				cout << " Вы ввели x > -1, введите x < -1" << endl;
			}
			else
			{
				double E;

				cout << "Задайте точность вычислений " << endl;
				cin >> E;

				func = atan(x);
				sum = sumE(x, E, n);
				cout << "Точное значение функции равно " << func << endl;
				cout << "Частичная сумма ряда c заданной точностью равна " << sum << endl;
				cout << "Учтено " << n << " членов ряда" << endl << endl;
				sum = sumE(x, E / 10, n);
				cout << "Частичная сумма ряда c точностью, большей в 10 раз, равна " << sum << endl;
				cout << "Учтено " << n << " членов ряда" << endl;
				//return 0;

			}

			continue;
		}

	}

}
double sumN(double x, int n, double& last)
{

	// Инициализация переменной last
	last = x;
	double r;
	double k;
	k = -1 / x;
	double sum = last;
	for (int i = 1; i < n; ++i)
	{
		
		r =  - 1 / ((i + 2) * (x * x));
		last = r;
		sum = last;
		sum = sum +k+ (-M_PI / 2);
	}

	return  sum;
}

double sumE(double x, double E, int& n)
{
	double last;
	// Инициализация переменной last
	last = x;
	double k;
	k = -1 / x;
	double r;
	double sum = last;
	for (n = 1; fabs(last) > E; ++n)
	{
		
		r =( - 1 / ((n + 2) * (x * x)));
		last = r;
		sum = last;
		sum = sum +k+ (-M_PI / 2);

	}
	return   sum;
}

