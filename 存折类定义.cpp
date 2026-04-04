/*
题目描述
定义一个存折类CAccount，存折类具有帐号（account, long）、
姓名（name,char[10])、余额（balance,float）等数据成员，
可以实现存款（deposit,操作成功提示“saving ok!”)、取款（withdraw，
操作成功提示“withdraw ok!”）和查询余额（check）的操作，
取款金额必须在余额范围内，否则提示“sorry! over limit!”。
编写主函数，建立这个类的对象并测试
输入账号、姓名、余额后，按照查询余额、存款、查询余额、取款、查询余额的顺序调用类方法并输出。
输入
第一个存折的账号、姓名、余额
存款金额
取款金额
第二个存折的账号、姓名、余额
存款金额
取款金额
输出
第一个存折的账户余额
存款操作结果
账户余额
取款操作结果
账户余额
第二个存折的账户余额
存款操作结果
账户余额
取款操作结果
账户余额
*/
#include <iostream>
#include <string>
using namespace std;
class m_count
{private:
    double m_account;
    string m_name;
    double m_balance;
public:
    double account;
    string name;
    double balanceValue;
    void set(double account, string name, double balanceValue)
    {
        m_account = account;
        m_name = name;
        m_balance = balanceValue;
    }
    void showBalance()
    {
        cout << m_name << "'s balance is "<< m_balance << endl;
    }
    void deposit(double money)
    {
        m_balance += money;
        cout << "saving ok!" << endl;
    }
    void withdraw(double money)
    {
        if (money > m_balance)
        {
            cout << "sorry! over limit!" << endl;
        }
        else
        {
            m_balance -= money;
            cout << "withdraw ok!" << endl;
        }
    }
};
int main(){
    m_count a[2];
    for (int i = 0; i < 2; i++){
        double account, balance;
        string name;
        cin >> account >> name >> balance;
        a[i].set(account, name, balance);
        a[i].showBalance();
        double money;
        cin >> money;
        a[i].deposit(money);
        a[i].showBalance();
        cin >> money;
        a[i].withdraw(money);
        a[i].showBalance();
    }
}