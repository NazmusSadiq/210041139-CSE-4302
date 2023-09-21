#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
    int Acc_Num;
    string Acc_Holder_Name;
    string Acc_Type;
    int Cur_Bal;
    int Min_Bal;

public:
    BankAccount(int acc_num, string acc_hol_name, string acc_type, int min_bal)
    {
        if (acc_type == "Current" || acc_type == "Savings")
        {
            Acc_Num = acc_num;
            Acc_Holder_Name = acc_hol_name;
            Acc_Type = acc_type;
            Min_Bal = min_bal;
            Cur_Bal = 0;
        }
        else
        {
            cout << "Invalid Account Type";
        }
    }
    BankAccount()
    {
    }
    void set_Acc_Num(int num)
    {
        Acc_Num = num;
        Cur_Bal = 0;
    }
    void set_Acc_Holder_Name(string name)
    {
        Acc_Holder_Name = name;
    }
    void set_Acc_Type(string acc_type)
    {
        if (acc_type == "Current" || acc_type == "Savings")
        {
            Acc_Type = acc_type;
        }
        else
        {
            cout << "Invalid Account Type";
        }
    }
    void set_Min_Bal(int min_bal)
    {
        if (min_bal >= 0)
            Min_Bal = min_bal;
        else
        {
            cout << "Balance Can't Be Negative" << endl;
        }
    }
    void display()
    {
        cout << "Account Holder Name: " << Acc_Holder_Name << endl;
        cout << "Account Number: " << Acc_Num << endl;
        cout << "Account Type: " << Acc_Type << endl;
        cout << "Current Balance: " << Cur_Bal << endl;
    }
    void deposit(int amount)
    {
        if (amount >= 0)
        {
            Cur_Bal += amount;
            cout << "Deposited BDT " << amount <<" in Account Number "<<Acc_Num<<endl;
        }
        else
            cout << "You Can't Deposit Negative Amount";
    }
    void withdrawl(int amount)
    {
        if (amount >= 0)
        {
            Cur_Bal -= amount;
            if (Cur_Bal < Min_Bal)
            {
                cout << "Your Current Balance Is Too Low" << endl;
                Cur_Bal += amount;
            }
            else
            {
                cout<<"Money Withdrawl of BDT "<<amount<<" from Account Number "<<Acc_Num<<endl;
            }
        }
        else
            cout << "You Can't Deposit Negative Amount";
    }
    void giveInterest(int Percent=3)
    {
        if (Percent > 0)
        {
            int InterestPercent = Percent;
            int Interest = Cur_Bal * InterestPercent / 100;
            Interest -= Interest * 10 / 100;
            Cur_Bal += Interest;
        }
        else
        {
            cout << "Negative Interset Is Not Allowed" << endl;
        }
    }
    ~BankAccount()
    {
        cout << "Account of " << BankAccount::Acc_Holder_Name << " with account no " << BankAccount::Acc_Num << " is destroyed with a balance BDT " << BankAccount::Cur_Bal << endl;
    }
};

int main()
{
    BankAccount Acc1;
    Acc1.set_Acc_Num(139);
    Acc1.set_Acc_Holder_Name("Sadiq");
    Acc1.set_Acc_Type("Savings");
    Acc1.set_Min_Bal(300);
    Acc1.deposit(1000);
    Acc1.giveInterest(5);
    Acc1.withdrawl(800);
    Acc1.display();
    BankAccount Acc2(127,"Rafee","Current",100);
    Acc2.deposit(2000);
    Acc2.giveInterest();
    Acc2.withdrawl(900);
    Acc2.display();
}