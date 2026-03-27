/*
题目描述
定义一个结构体，包含年月日，表示一个学生的出生日期。然后在一群学生的出生日期中找出谁的出生日期排行第二
要求：出生日期的存储必须使用结构体，不能使用其他类型的数据结构。
要求程序全过程对出生日期的输入、访问、输出都必须使用结构。
输入
第一行输入t表示有t个出生日期
每行输入三个整数，分别表示年、月、日
依次输入t个实例
输出
输出排行第二老的出生日期，按照年-月-日的格式输出
*/
#include <iostream>
using namespace std;
struct Stu
{
    int year;
    int month;
    int day;
};

int main() {
    int t;
    cin >> t;
    int minIndex = 0;
    Stu s[5000];
    int min2Index = 0, temp = 0;
    for (int i = 0; i < t; i++)
    {
        cin >> s[i].year >> s[i].month >> s[i].day;
    }
    for (int i = 1; i < t; i++)
    {
        if (s[i].year < s[minIndex].year) {
            minIndex = i;
        }
        else if (s[i].year == s[minIndex].year) {
            if (s[i].month < s[minIndex].month) {
                minIndex = i;
            }
            else if (s[i].month == s[minIndex].month) {
                if (s[i].day < s[minIndex].day) {
                    minIndex = i;
                }
            }
        }
    }
        
    for (int i = 0; i < t; i++) {
        if (i != minIndex) {
            min2Index = i;
            break;
        }
    }



    for (int i = 0; i < t; i++)
    {
        if (i == minIndex) continue;

        if (s[i].year < s[min2Index].year) {
            min2Index = i;
        }
        else if (s[i].year == s[min2Index].year) {
            if (s[i].month < s[min2Index].month) {
                min2Index = i;
            }
            else if (s[i].month == s[min2Index].month) {
                if (s[i].day < s[min2Index].day) {
                    min2Index = i;
                }
            }
        }
    }


    cout << s[min2Index].year << '-' << s[min2Index].month << '-' << s[min2Index].day;
}