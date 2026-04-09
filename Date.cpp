/*
下面是一个日期类的定义，请在类外实现其所有的方法，并在主函数中生成对象测试之。
注意，在判断明天日期时，要加入跨月、跨年、闰年的判断
例如9月30日的明天是10月1日，12月31日的明天是第二年的1月1日
2月28日的明天要区分是否闰年，闰年则是2月29日，非闰年则是3月1日
输入
测试数据的组数t
第一组测试数据的年 月 日
..........
要求第一个日期的年月日初始化采用构造函数，第二个日期的年月日初始化采用setDate方法，第三个日期又采用构造函数，第四个日期又采用setDate方法，以此类推。
输出
输出今天的日期
输出明天的日期
*/
#include<iostream>
#include <iomanip>
using namespace std;
class Date
{
private:
	int year, month, day;
public:
	Date() {
		year = month = day = 0;
	}
	Date(int y, int m, int d) {
		year = y;
		month = m;
		day = d;
	}
	void setYear(int y) {
		year = y;
	}
	void setMonth(int m) {
		month = m;
	}
	void setDay(int d) {
		day = d;
	}
	int getY() {
		return year;
	}
	int getM() {
		return month;
	}
	int getD() {
		return day;
	}
};

int main() {
	int t, cnt = 1;
	cin >> t;
	while (t--) {
		if (cnt % 2 != 0)
		{
			int y, m, d;
			cin >> y >> m >> d;
			Date d1(y, m, d);
			cout << "Today is " << setfill('0') << setw(2) << d1.getY() << "/" << setfill('0') << setw(2) << d1.getM() << "/" << setfill('0') << setw(2) << d1.getD() << endl;
			int after_day = d1.getD() + 1;
			int after_month = d1.getM();
			int after_year = d1.getY();
			if (after_month == 1 || after_month == 3 || after_month == 5 || after_month == 7 || after_month == 8 || after_month == 10 || after_month == 12)
			{
				if (after_day > 31)
				{
					after_day -= 31;
					after_month++;
					if (after_month > 12)
					{
						after_month -= 12;
						after_year++;
					}
				}
			}
			if (after_month == 2)
			{
				if (after_year % 400 == 0 || after_year % 4 == 0 && after_year % 100 != 0)
				{
					if (after_day > 29)
					{
						after_day -= 29;
						after_month++;
					}
				}
				else
				{
					if (after_day > 28)
					{
						after_day -= 28;
						after_month++;
					}
				}
			}
			else
			{
				if (after_day > 30)
				{
					after_month++;
					after_day -= 30;
				}
			}
			cout << "Tomorrow is " << setfill('0') << setw(2) << after_year << "/" << setfill('0') << setw(2) << after_month << "/" << setfill('0') << setw(2) << after_day << endl;
		}
		else {
			int y, m, d;
			cin >> y >> m >> d;
			Date d1;
			d1.setDay(d);
			d1.setMonth(m);
			d1.setYear(y);
			cout << "Today is " << setfill('0') << setw(2) << d1.getY() << "/" << setfill('0') << setw(2) << d1.getM() << "/" << setfill('0') << setw(2) << d1.getD() << endl;
			int after_day = d1.getD() + 1;
			int after_month = d1.getM();
			int after_year = d1.getY();
			if (after_month == 1 || after_month == 3 || after_month == 5 || after_month == 7 || after_month == 8 || after_month == 10 || after_month == 12)
			{
				if (after_day > 31)
				{
					after_day -= 31;
					after_month++;
					if (after_month > 12)
					{
						after_month -= 12;
						after_year++;
					}
				}
			}
			if (after_month == 2)
			{
				if (after_year % 400 == 0 || after_year % 4 == 0 && after_year % 100 != 0)
				{
					if (after_day > 29)
					{
						after_day -= 29;
						after_month++;
					}
				}
				else
				{
					if (after_day > 28)
					{
						after_day -= 28;
						after_month++;
					}
				}
			}
			else
			{
				if (after_day > 30)
				{
					after_month++;
					after_day -= 30;
				}
			}
			cout << "Tomorrow is " << setfill('0') << setw(2) << after_year << "/" << setfill('0') << setw(2) << after_month << "/" << setfill('0') << setw(2) << after_day << endl;
		}
		cnt++;
	}
}