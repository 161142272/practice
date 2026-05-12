/*
题目描述
虚拟电话包含属性：电话号、状态、机主姓名。
1、电话号是一个类，它包含号码和类型，其中号码是整数类型，类型用单个字母表示用户类别，A表示政府，B表示企业、C表示个人。类操作包括构造、属性的获取和设置等方法，根据需要自行编写。
2、状态用一个数字表示，1表示在用，0表示未用，
3、机主姓名是一个字符串

电话操作包括：构造、析构、打印和查询。
1、构造函数需要考虑复合类成员的构造，并且输出提示信息。假设电话号码为12345678，则构造函数输出"12345678 constructed."
2、打印是输出电话的相关信息，其中如果电话状态是在用则输出use；状态是未用则输出unuse，输出格式看示例。
3、析构函数是输出提示信息。假设电话号为12345678，则析构函数输出"12345678 destructed. "
4、查询操作是根据给定的号码查询电话，如果电话自身号码和给定号码不相同，则返回0；如果电话自身号码和给定号码相同，则返回1

用C++和面向对象思想实现以下要求：
1、输入相关数据，创建三个电话对象，并通过构造方法初始化。
2、输入若干个电话号码，通过查询操作查询这些号码是否在三个电话对象中，如果不存在输出"wrong number."，存在则调用打印操作输出电话信息，具体看输出样例。

输入

头三行输入三个电话信息，每行包括电话号码、电话类型、状态、机主姓名，机主姓名最大长度为20
接着一行输入t，表示有t个号码要查询
接着t行输入t个电话号码
输出
t行输出t个号码的查询结果
*/
#include<iostream>
#include<cstring>
using namespace std;
class PhoneNumber {
private:
	int number;
	char type;
	int status;
	string state;
	string userName;
public:
	PhoneNumber(int number, char type,int status,string name) : number(number), type(type),status(status),userName(name) {

		cout << number << " constructed." << endl;
		if (status == 1)
		{
			state = "use";
		}
		else if (status == 0)
		{
			state = "unuse";
		}
	}
	~PhoneNumber()
	{
		cout << number << " destructed." << endl;
	}
	int getNumber() const {
		return number;
	}
	char getType() const {
		return type;
	}
	string getStatus() const {
		return state;
	}
	string getTuserName() const {
		return userName;
	}
};

int main() {
	PhoneNumber* phones[3];
	for (int i = 0; i < 3; i++) {
		int number;
		char type;
		int status;
		string owner;
		cin >> number >> type >> status >> owner;
		phones[i] = new PhoneNumber(number, type,status,owner);
	}
	int t;
	cin >> t;
	while (t--) {
		int queryNumber;
		cin >> queryNumber;
		bool found = false;
		for (int i = 0; i < 3; i++) {
			if (phones[i]->getNumber() == queryNumber) {
				found = true;
				cout << "Phone=" << queryNumber << "--Type=" << phones[i]->getType() << "--State=" << phones[i]->getStatus() << "--Owner=" << phones[i]->getTuserName() << endl;
				break;
			}
		}
		if (!found) {
			cout << "wrong number." << endl;
		}
	}
	for (int i = 2; i >= 0; i--) {
		delete phones[i];
	}
	return 0;
}