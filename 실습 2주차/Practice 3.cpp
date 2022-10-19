// 최대공약수 구하는 문제
#include <iostream>
using namespace std;

int main()
{
	int a, b, c;

	cin >> a;
	cin >> b;

	if (a > b) {
		while (b != 0) {

			c = a % b;
			a = b;
			b = c;

		}
		cout << a;
	}
	else if (a < b) {
		while (a != 0) {

			c = b % a;
			b = a;
			a = c;

		}
		cout << b;
	}
	else
		cout << 1;

	return 0;
}
