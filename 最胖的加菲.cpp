/*
题目描述
有一群猫猫，每只猫都有自己的名称和体重。
用类来描述猫，名称和体重都是私有属性，要求加入属性的get方法。其他函数根据需要自己定义
创建一个动态的猫对象数组，存储各只猫的名称和体重
根据猫的体重对数组做升序排序，并输出排序后每只猫的名称
题目涉及的数值均用整数处理
输入
第一行输入n表示有n只猫
第二行输入一只猫的名称和体重，名称的最大长度为30
依次输入n行
输出
输出一行，输出排序后的猫的名称
*/
#include <iostream>
#include <string>
using namespace std;

class hachimi {
private:
	string m_name;
	double m_weight;
public:
	void set(string name, double weight) {
		m_name = name;
		m_weight = weight;
	}
	void set_name(string name) {
		m_name = name;
	}
	string get_name() {
		return m_name;
	}
	double get_weight() {
		return m_weight;
	}
};
bool cmp(double weight1, double weight2) {
	if (weight1 > weight2) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	int t;
	cin >> t;
	string name;
	double weight;
	hachimi a[100];
	hachimi temp;
	for (int i = 0; i < t; i++)
	{
		cin >> name >> weight;
		a[i].set(name,weight);
	}
    int flag = 3;
    while(flag--) {
        for (int i = 0; i < t-1; i++) {
            if (cmp(a[i].get_weight(), a[i + 1].get_weight())) {
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
    }
	for (int i = 0; i < t; i++)
	{
		cout << a[i].get_name() << ' ';
	}
}