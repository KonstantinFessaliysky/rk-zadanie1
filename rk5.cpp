#include <iostream>
#include <string>
using namespace std;

class BankAccount {
protected:
    int number;
    string name;
    double balance;

public:
    BankAccount(int e_number, string e_name, double e_balance) {
        number = e_number;
        name = e_name;
        balance = e_balance;
    }

    void deposit(double money) {
        if (money > 0) {
            balance +=  money;
            cout << "Поступило: " << money << endl;
            cout << "Текущий баланс: " << balance << endl;
        }
        else {
            cout << "Введите положительное число" << endl;
        }
    }

    void withdraw(double money) {
        if (money > 0 && money <= balance) {
            balance -= money;
            cout << "Снято: " << money << endl;  
            cout << "Текущий баланс: " << balance << endl;
        }
        else if (money < 0) {
            cout << "Недостаточно средств на счёте" << endl;
        }
        else if (money > balance) {
            cout << "Введите положительное число" << endl;
        }
    }

    void displayInfo() const {
        cout << "Номер: " << number << endl;
        cout << "Имя владельца: " << name << endl;
        cout << "Баланс : " << balance << endl;
    }
};

class SavingsAccount : public BankAccount {
private:
    double percent;
public:
    SavingsAccount(int number, string name, double balance, double percent) : BankAccount(number, name, balance), percent(percent) {}

    void addition() {
        double interest = balance * (percent / 100);
        balance += interest;
        cout << "Добавлены проценты: " << interest << endl;
        cout << "Текущий баланс: " << balance << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    BankAccount one(1, "Андрей", 4096.0);
    one.displayInfo();

    one.deposit(100.0);
    one.deposit(-100.0);
    one.withdraw(196.0);
    one.withdraw(-196.0);
    one.withdraw(9000.0);

    SavingsAccount two(2, "Семён", 12000.0, 6.0);
    two.displayInfo();

    two.deposit(1000.0);
    two.withdraw(500.0);
    two.addition();

    return 0;
}