#include <iostream>
using namespace std;

int main()
{
	int num, i;
	int cnt = 0;
	
	cout << "주의사항 : 숫자가 3 이상이어야 합니다." << endl;
	cin >> num;

	for (i = 2; i < num; i++) {
		if (num % i == 0)
			cnt++;
	}
	if (cnt == 0)
		cout << 1;
	else
		cout << 0;

	
}