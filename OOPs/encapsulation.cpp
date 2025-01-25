/*
Encapsulation :
 One of the four pillars of OOPs..this concept helps us to bind the properties/data members  and methods or member functions of the class together  just like wo do with a capsule .

 Advantages:
 1.Data Hiding
 2.Code Reusability
 3. Authentication 
 4.Providing Privacy 
 
 


*/




#include<bits/stdc++.h>
using namespace std;
class BankAccount{

    private:
    double balance;

    public:

    BankAccount(double initialBalance)
    {
        this->balance=initialBalance;
    }

    double getbalance()
    {
        return this->balance;
    }
    void deposit(double amount)
    {
        if(amount>0)
        {
            this->balance+=amount;
            cout<<"Rs"<<amount<<" deposited into your account"<<endl;
        }
        else{
            cout<<"Enter a valid amount to deposit"<<endl;
        }
        return ;
    }
    void withdraw(double amount)
    {
        if(amount<=this->balance)
        {
            
            this->balance-=amount;
            cout<<"Rs"<<amount<<" withdrawn from your account"<<endl;
        }
        else{
            cout<<"Insufficient balance"<<endl;
        }
        return ;
    }
};


int main(){

    BankAccount* account1=new BankAccount(0);
    account1->deposit(1000);
    cout<<"Account Balance is Rs"<<account1->getbalance()<<endl;
    account1->withdraw(400);
    cout<<"Account Balance is Rs"<<account1->getbalance()<<endl;
    return 0;

}