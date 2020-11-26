// Lab_05_4.cpp
// < Кузів Назар >
// Лабораторна робота № 5.4
// Обчислення сум та добутків за допомогою рекурсії
// Варіант 6

#include <iostream>
#include <cmath>

using namespace std;

double S0(const int k, const int N);
double S1(const int N, const int k);
double S2(const int N, const int k);
double S3(const int N, const int k, double t);
double S4(const int N, const int k, double t);

int main()
{
	int k, N;
	cout << "N = "; cin >> N;

	k = N;

	cout << "(iter) S0 = " << S0(k, N) << endl;
	cout << "(rec up ++) S1 = " << S1(N, k) << endl;
	cout << "(rec up --) S2 = " << S2(N, 19) << endl;
	cout << "(rec down ++) S3 = " << S3(N, k, 1) << endl;
	cout << "(rec down --) S4 = " << S4(N, 19, 1) << endl;
	return 0;
}

double S0(const int k, const int N)
{
	double s = 1;
	for (int i = k; i <= 19; i++)
		s *= (1.0 * i - N) / (1.0 * i + N) + 1;
	return s;
}

double S1(const int N, const int k)
{
	if (k > 19)
		return 1;
	else
		return ((1.0 * k - N) / (1.0 * k + N) + 1) * S1(N, k + 1);
}

double S2(const int N, const int k)
{
	if (k < N)
		return 1;
	else
		return ((1.0 * k - N) / (1.0 * k + N) + 1) * S2(N, k - 1);
}

double S3(const int N, const int k, double t)
{
	t = t * ((1.0 * k - N) / (1.0 * k + N) + 1);

	if (k >= 19)
		return t;
	else
		return S3(N, k + 1, t);
}

double S4(const int N, const int k, double t)
{
	t = t * ((1.0 * k - N) / (1.0 * k + N) + 1);

	if (k <= N)
		return t;
	else
		return S4(N, k - 1, t);
}

