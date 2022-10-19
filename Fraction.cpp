#include <iostream>
#include <stdio.h>
#define len 5 // ũ�� 5�� ���� ( 5���� �м� ������ ���� )
using namespace std;

typedef struct Fraction // ���� 1 : �м��� ǥ���ϴ� struct
{
	int numerator;
	int denominator;

} Frac;

void printFrac(Frac m);
void reduce(Frac* a);
void copy(Frac a[], Frac b[]);
void Calculation(Frac a[], Frac b[]);

Frac add(Frac a, Frac b);
Frac minus(Frac a, Frac b);
Frac multi(Frac a, Frac b);
Frac div(Frac a, Frac b);

int main() // ���� 4 : 5���� ����, �и� ���� �Է¹޴� main �Լ�
{
	Frac a[len];
	Frac b[len];
	for (int i = 0; i < len; i++)
	{
		scanf_s("%d %d", &a[i].numerator, &a[i].denominator); // array a, b �Է�
	}
	copy(a, b);
	Calculation(a, b);

	return 0;
}

void printFrac(Frac m) // �м� ���
{
	cout << "���� : " << m.numerator;
	cout << "�и� : " << m.denominator;
}

void reduce(Frac* a) // ���� 2 : �м��� ����ϴ� �Լ�
{
	int n = 1;
	int gcd;
	while (a->numerator >= n) // �� �м��� gcd�� �̿���, ���м� ���� �� ����.( -> (ȭ��ǥ �Լ�) a->b = (*a).b �� ���� )
	{
		if (a->numerator % n == 0 && a->denominator % n == 0) 
		{
			gcd = n;
		}
		n++;
	}
	a->numerator = a->numerator / gcd;
	a->denominator = a->denominator / gcd;
}

void copy(Frac a[], Frac b[]) // ���� 5: array a�� ������ �ֵ��� array b�� ����� ���� �Լ�
{
	for (int i = 0; i < len; i++)
	{
		b[i] = a[i];
	}
}

void Calculation(Frac a[], Frac b[]) // ���� 6 : �� ���� array�� �̿��� ��ҳ��� ���ϰ� ���ϴ� �Լ�
{
	Frac result = { 0, 0 };
	for (int i = 0; i < len; i++)
	{
		// ����� ������ �μ��� ���� ��� ���ذ�
		result = add(result, multi(a[i], b[i]));
	}
	// ���м� ó��
	reduce(&result);

	cout << result.numerator << '/' << result.denominator << endl;
}




// ���� 3 : ������ ���� �Լ�
Frac add(Frac a, Frac b)
{
	// �и� ���ڰ� 0�� ��� �и� ���ڸ� ���� ������ �ʰ� �״�� ���
	if (a.numerator == 0 && b.numerator == 0)
		return { 0, 0 };
	else if (a.numerator == 0 && b.numerator != 0)
		return b;
	else if (a.numerator != 0 && b.numerator == 0)
		return a;
	else
	{
		Frac c;
		c.denominator = a.denominator * b.denominator;
		c.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
		return c;
	}
}

Frac minus(Frac a, Frac b)
{
	// �и� ���ڰ� 0�� ��� �и� ���ڸ� ���� ������ �ʰ� �״�� ���
	if (a.numerator == 0 && b.numerator == 0)
	{
		return { 0, 0 };
	}
	else if (a.numerator == 0 && b.numerator != 0)
	{
		b.numerator = -1 * b.numerator;
		b.denominator = -1 * b.denominator;
		return b;
	}
	else if (a.numerator != 0 && b.numerator == 0)
		return a;
	else
	{
		Frac c;
		c.denominator = a.denominator * b.denominator;
		c.numerator = a.numerator * b.denominator - b.numerator * a.denominator;
		return c;
	}
}

Frac multi(Frac a, Frac b)
{
	Frac c;
	c.denominator = a.denominator * b.denominator;
	c.numerator = a.numerator * b.numerator;
	return c;
}

Frac div(Frac a, Frac b)
{
	Frac c;
	c.denominator = a.denominator * b.numerator;
	c.numerator = a.numerator * b.denominator;
	return c;
}
