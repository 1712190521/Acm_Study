//根据日期计算是星期几，只适合于1582年10月15日之后的情形
//闰年共有366天（1-12月分别为31天，29天，31天，30天，31天，30天，31天，31天，30天，31天，30天，31天）
#include<iostream>
using namespace std;
int main() {
	int year, month, day;
	while (cin >> year >> month >> day)
	{
		if (month < 3)
		{
			year -= 1;
			month += 12;
		}
		char b[7][10] = { "sunday","monday","tuesday","wednesday","thursday","friday","saturday" };
		int c = int(year / 100), y = year - 100 * c;
		int w = int(c / 4) - 2 * c + y + int(y / 4) + (26 * (month + 1) / 10) + day - 1;
		w = (w % 7 + 7) % 7;
		cout << b[w] << endl;
	}return 0;
}