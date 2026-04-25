/*
题目描述
编写程序，统计某旅馆住宿客人的总数和收入总额。要求输入客人的姓名，输出客人编号（2015+顺序号，
顺序号4位，如第1位为0001，第2位为0002，依此类推）、姓名、总人数以及收入总额。
总人数和收入总额用静态成员，其他属性采用普通的数据成员。 旅馆类声明如下：
输入
第1行：输入旅馆单个顾客房租
第2行开始，依次输入顾客姓名，0表示输入结束， 姓名的最大字符长度为20
输出
每行依次输出顾客信息和当前旅馆信息。 包括顾客姓名，顾客编号，旅馆当前总人数，旅馆当前总收入。
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

class Hotel
{
private:
    static int totalCustNum;
    static float totalEarning;
    static float rent;
    char* customerName;
public:
    static void setRent(float r) {
        rent = r;
    }

    Hotel(char* customer) {
        customerName = new char[strlen(customer) + 1];
        strcpy(customerName, customer);

		totalCustNum++;
        totalEarning += rent;
    }

    ~Hotel() {
        delete[] customerName;
    }

    void Display() {
        cout << customerName << " " << 2015 <<
            setfill('0') << setw(4) << totalCustNum << " "
            << totalCustNum << " "
            << totalEarning << endl;
    }
};
int Hotel::totalCustNum = 0;
float Hotel::totalEarning = 0;
float Hotel::rent = 0;

int main() {
    float r;
    cin >> r;
    Hotel::setRent(r);

    char name[21];
    while (true) {
        cin >> name;
        if (strcmp(name, "0") == 0)
        {
            break;
        }
        Hotel temp(name);
        temp.Display();
    }
    return 0;
}