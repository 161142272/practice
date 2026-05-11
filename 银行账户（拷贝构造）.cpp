/*
题目描述

银行账户包括余额、利率、号码、类型等属性，其中号是固定8位整数，类型表示个人还是企业账户，如果是个人用P标识，企业用E标识。
账户又分为活期账户和定期账户，活期利率为0.5%，定期利率为1.5%。
账户操作有计息、查询操作。计息操作是根据利率计算利息，并把利息增加到余额中
|，并做相关信息输出。查询操作是输出账户的全部信息。
创建一个活期账户，并通过构造函数初始化各个属性。然后通过拷贝构造来创建一个定期账户，信息与活期账户基本相同，
不同之处包括：定期账户号码是活期账户号码加50000000（7个0）；利率是定期利率。
要求所有数据成员都是私有属性
用C++语言的类与对象思想来编写程序实现上述要求

输入
输入测试个数t，表示有t个活期账户
先输入一个活期账户的账户号码、账户类型、余额（根据输入创建活期账户和定期账户）
接着输入两个操作符，第一个操作符对活期账户操作
，第二个操作符对定期账户进行操作。若输入大写字母C表示计息操作，若输入大写字母P表示查询操作
以此类推输入其他账户的信息和操作

输出
每两行输出一对活期账户和定期账户的操作结果。
*/
#include<iostream>
using namespace std;
class Account {
private:
	double money;
	double rate;
	int num;
	char type;
public:
	Account(double m, double r, int n, char t) : money(m), rate(0.005), num(n), type(t) {}
	Account(const Account& c) : money(c.money), rate(0.015), num(c.num + 50000000), type(c.type) {}
	void interest() {
		money += money * rate;
		cout << "Account=" << num << "--sum=" << money << endl;
	}
	void show() {
		cout << "Account=" << num << "--";
		if (type == 'P')
		{
			cout << "Person";
		}
		else if (type == 'E')
		{
			cout << "Enterprise";
		}
		cout << "--sum=" << money << "--rate=" << rate << endl;
	}
};

void operate(Account& c, char op) {
	if (op == 'C')
	{
		c.interest();
	}
	else if (op == 'P')
	{
		c.show();
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		double m;
		int n;
		char t;
		cin >> n >> t >> m;
		Account c1(m, 0.005, n, t);
		Account c2 = Account(c1);
		char op1, op2;
		cin >> op1 >> op2;
		operate(c1, op1);
		operate(c2, op2);
	}
	return 0;
}