#include <iostream>
#include <stdio.h>
#define len 5 // 크기 5로 고정 ( 5개의 분수 값으로 고정 )
using namespace std;

typedef struct Fraction // 문제 1 : 분수를 표현하는 struct
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

int main() // 문제 4 : 5개의 분자, 분모 따로 입력받는 main 함수
{
	Frac a[len];
	Frac b[len];
	for (int i = 0; i < len; i++)
	{
		scanf_s("%d %d", &a[i].numerator, &a[i].denominator); // array a, b 입력
	}
	copy(a, b);
	Calculation(a, b);

	return 0;
}

void printFrac(Frac m) // 분수 출력
{
	cout << "분자 : " << m.numerator;
	cout << "분모 : " << m.denominator;
}

void reduce(Frac* a) // 문제 2 : 분수를 약분하는 함수
{
	int n = 1;
	int gcd;
	while (a->numerator >= n) // 두 분수의 gcd를 이용해, 기약분수 얻을 수 있음.( -> (화살표 함수) a->b = (*a).b 와 동일 )
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

void copy(Frac a[], Frac b[]) // 문제 5: array a를 복사한 쌍둥이 array b를 만드는 복사 함수
{
	for (int i = 0; i < len; i++)
	{
		b[i] = a[i];
	}
}

void Calculation(Frac a[], Frac b[]) // 문제 6 : 두 개의 array를 이용해 요소끼리 곱하고 더하는 함수
{
	Frac result = { 0, 0 };
	for (int i = 0; i < len; i++)
	{
		// 결과값 변수에 두수의 곱을 계속 더해감
		result = add(result, multi(a[i], b[i]));
	}
	// 기약분수 처리
	reduce(&result);

	cout << result.numerator << '/' << result.denominator << endl;
}




// 문제 3 : 연산자 구현 함수
Frac add(Frac a, Frac b)
{
	// 분모나 분자가 0인 경우 분모 분자를 서로 곱하지 않고 그대로 출력
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
	// 분모나 분자가 0인 경우 분모 분자를 서로 곱하지 않고 그대로 출력
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
