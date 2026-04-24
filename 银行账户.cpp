/*
要求如下：
实现该银行账户类
为账户类Account增加一个友元函数，实现账户结息，要求输出结息后的余额（结息余额=账户余额+账户余额*利率）。友元函数声明形式为 friend void update(Account& a);
在main函数中，定义一个Account类型的指针数组，让每个指针指向动态分配的Account对象，并调用成员函数测试存款、取款、显示等函数，再调用友元函数测试进行结息。
大家可以根据实际需求在类内添加其他方法，也可以修改成员函数的参数设置
输入
第1行：利率
第2行：账户数目n
第3行开始，每行依次输入一个账户的“账号”、“姓名”、“余额”、存款数，取款数。
输出
第1行开始，每行输出一个账户的相关信息，包括账号、姓名、存款后的余额、存款后结息余额、取款后余额。
最后一行输出所有账户的余额。
*/
#include<iostream>
using namespace std;
class Account
{
private:
    static float count; // 账户总余额
    static float interestRate;
    string accno, accname;
    float balance;
public:
    Account(string ac, string na, float ba) {
		accno = ac;
		accname = na;
		balance = ba;
        cout << accno << " " << accname << " ";
    };
    void deposit(float amount) {
        balance += amount;
    }; // 存款
    void withdraw(float amount) {
		balance -= amount;
    }; // 取款
    float getBalance() {
        return balance;
    }; // 获取账户余额
    void show() {
        cout << balance;
    }; // 显示账户所有基本信息
    static float getCount() {
		return count;
    }; // 获取账户总余额
    static void setInterestRate(float rate) {
        interestRate = rate;
    }; // 设置利率
    static float getInterestRate() {
        return interestRate;
    }; // 获取利率
    friend void update(Account& a) {
    a.balance = a.balance + a.balance * Account::interestRate;
    }
};
float Account::count = 0;
float Account::interestRate = 0;
int main() {
    float rate;
    int n;
    cin >> rate >> n;
    Account::setInterestRate(rate);
    Account** accounts = new Account * [n];
    for (int i = 0; i < n; i++) {
        string accno, accname;
        float balance, depositAmount, withdrawAmount;
        cin >> accno >> accname >> balance >> depositAmount >> withdrawAmount;
        accounts[i] = new Account(accno, accname, balance);
        accounts[i]->deposit(depositAmount);
        accounts[i]->show();
		cout << " ";
		update(*accounts[i]);
        accounts[i]->show();
        cout << " ";
		accounts[i]->withdraw(withdrawAmount);
        accounts[i]->show();
        cout << endl;
    }
    float totalBalance = 0;
    for (int i = 0; i < n; i++) {
        totalBalance += accounts[i]->getBalance();
        delete accounts[i];
    }
    delete[] accounts;
    cout << totalBalance << endl;
	return 0;
}