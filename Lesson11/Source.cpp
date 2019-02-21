#include <iostream>
#include <ctime>
#include <clocale>
#include <cstdlib>
#include <iomanip>
#include <Windows.h>
#include <cmath>
using namespace std;

void FillArray(int *a, int n)
{
	for (size_t i = 0; i < n; i++)
	{
		a[i] = 1 + rand() % 100;
	}
}

void printArray(int *a, int n)
{
	for (int* p = a; p < a + n; p++)
	{
		cout << *p << " " << endl;
	}
	cout << endl;
}

double summa(double a, double b)
{
	return a + b;
}
double substraction(double a, double b)
{
	return a - b;
}
double multiplication(double a, double b)
{
	return a * b;
}
double division(double a, double b)
{
	if (b != 0)
		return a / b;
	else
		return a;
}

int determine(char* operation, char oper)
{
	for (size_t i = 0; i < 4; i++)
		if (operation[i] == oper)
			return 1;
	return -1;
}
double koren(double a, double b)
{
	return sqrt(pow(a,b));
}
double kub(double a, double b)
{
	return pow(a, b);
}
//double sinus(double a, double b)
//{
//	return sin(a, b);
//}

template<typename T>
bool asc(T a, T b)
{
	return a > b;
}
template<typename T>
bool desc(T a, T b)
{
	return a < b;
}

template <typename T>
void bubbleSort(T* a, int n, bool(*func)(T, T))
{
	for (size_t pass = 0; pass < n-1; pass++)
	{
		for (size_t i = 0; i < n - 1; i++)
		{
			if (func(a[i], a[i + 1]) == 1)
			{
				swap(a[i], a[i + 1]);
			}
		}
	}
}

bool isPrime(int n) {
	for (size_t i = 2; i < n; i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}
void PrimeNumbers(int *a, int n)
{
	for (int* p = a; p < a + n; p++)
	{
		if (isPrime(*p))
		{
			cout << *p << " " << " ";
		}
	}
}

void MultiPlicationFor3(int *a, int n)
{
	for (int* p = a; p < a + n; p++)
	{
		if (*p % 3 == 0)
		{
			cout << *p << " " << " ";
		}
	}
}

void MultiPlicationFor2(int *a, int n)
{
	for (int* p = a; p < a + n; p++)
	{
		if (*p % 2 == 0)
		{
			cout << *p << " ";
		}
	}
}

void Menu(int* a, int n, void(*func)(int*, int))
{
	func(a, n);
}

int main()
{	
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));

	/*int a = 5, b = 5;
	int(*ukaz)(int, int) = &summa;
	
	cout << ukaz(a,b) << endl;*/

	/*
	Реализовать 4 функции на простейшие арифметические операции (+,-,*,/).
	Каждая функция должна принимать два вещественных числа и 
	возвращать результат операции в виде вещественного числа.
	В главной функции создайте массив из 4-х указателей на эти функции. 
	Добавьте меню, в котором пользователь может выбрать желаемую операцию.
	Напишите программу без использования операторов if и switch.
	*/

	//12

	//double(*ukaz[4])(double, double) = { summa, substraction, multiplication, division };
	//char oper[4] = { '+', '-', '*', '/' };
	//char operation;
	//int k;
	//double a, b;
	//while (true)
	//{
	//	/*cout << "Enter 0 to summa" << endl;
	//	cout << "Enter 1 to substraction" << endl;
	//	cout << "Enter 2 to multiplication" << endl;
	//	cout << "Enter 3 to division" << endl;*/
	//	
	//	cout << "Enter a and b" << endl;
	//	cin >> a >> operation >> b;
	//	k = determine(oper, operation);
	//	if (k == -1)
	//	{
	//		break;
	//	}
	//	cout << ukaz[k](a, b) << endl;
	//}

	//13
	/*double(*ukaz[3])(double, double) = { koren, kub, sinus };
	char oper[3] = { 'Kor', 'Kub', 'Sin'};
	char operation;
	int k;
	double a, b;
	while (true)
	{
		cout << "Enter a and b" << endl;
		cin >> a >> operation >> b;
		k = determine(oper, operation);
		if (k == -1)
		{
			break;
		}
		cout << ukaz[k](a, b) << endl;
	}*/

	/*int a[10];
	FillArray(a, 10);
	printArray(a, 10);
	bubbleSort(a, 10, asc);
	printArray(a, 10);*/

	/*int *p;
	int n;
	cin >> n;
	p = new int[n];

	delete[] p;*/

	void(*func[3])(int*, int) = { PrimeNumbers, MultiPlicationFor3,  MultiPlicationFor2 };
	int a[10] = { 5,4,1,2,6,7,8,9,10, 56 };
	int choice;
	while (true)
	{
		cin >> choice;
		if (choice < 0 || choice > 2)
		{
			break;
		}
		Menu(a, 10, func[choice]);
	}


	system("pause");
	return 0;
}