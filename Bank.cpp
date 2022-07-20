#include<bits/stdc++.h>
using namespace std;
class BankAccount{
private:
    string password;
protected:
    int balance;
public:
    string address;
    int age;
    int account_number;
    string account_holder;

    BankAccount(string account_holder,int age,string address,string password){

        this->account_holder = account_holder;
        this->age = age;
        this->address = address;
        this->password = password;
        this->account_number = rand()%1000000000;
        this->balance = 0;
        cout<<"Account Create Successfully...."<<endl;
        cout<<"Your Account Number is : "<<this->account_number<<endl;


    }
    int get_balance(string password){

        if(this->password == password){

            return this->balance;
        }else{

            cout<<"Wrong password try again..."<<endl;
            return -1;
        }

    }
    void upgrade_balance(string password,int amount){

        if(this->password == password){
            this->balance += amount;
            cout<<"ADD Balance Successfully done.."<<endl<<"Your Account Balance is Now :"<<this->balance<<endl;

        }else{
            cout<<"Wrong password try again..."<<endl;
        }

    }

    void deposit_balance(string password,int amount){
        if(this->password == password){
            this->balance -= amount;
            cout<<"Deposit Balance Successfully done.."<<endl<<"Your Account Balance is Now :"<<this->balance<<endl;

        }else{
            cout<<"Wrong password try again..."<<endl;
        }



    }
friend class Rocket;



};

class Rocket{
protected:
    int amount;
public:
    Rocket(BankAccount *myAccount,string password,int amount){
        this->amount = 0;
        if(myAccount->password == password){
            this->amount += amount;
            myAccount->balance -= amount;
            cout<<"Your Account balance is :"<<this->amount<<endl<<"Your Bank balance is now :"<<myAccount->balance<<endl;
        }
    }


};

void create_rocket(BankAccount *myAccount){
    int amount;
    string password;
    cout<<"Deposit in Rocket ENTER AMOUNT AND PASSWORD"<<endl;
    cin>>amount>>password;
    Rocket rocket(myAccount, password, amount);

}


BankAccount *createAccount(){

string owner_name;
int age;
string password,address;
cout<<"Enter YOUR.............."<<endl<<"NAME AGE ADDRESS AND PASSWRD:"<<endl;
cin>>owner_name>>age>>address>>password;
BankAccount *account = new BankAccount(owner_name,age,address,password);

return account;

}

void add_money(BankAccount *myAccount){

string password;
int amount;
cout<<"Enter Password and Amount for ADD MONEY."<<endl;
cin>>password>>amount;
myAccount->upgrade_balance(password,amount);


}
void deposit_money(BankAccount *myAccount){

string password;
int amount;
cout<<"Enter Password and Amount for DEPOSIT MONEY."<<endl;
cin>>password>>amount;
myAccount->deposit_balance(password,amount);


}





int main(){

BankAccount *myAccount = createAccount();



while(true){
        int opt;
    cout<<"Select Options"<<endl;
    cout<<"1. ADD MONEY."<<endl;
    cout<<"1. DEPOSIT MONEY."<<endl;
    cout<<"3. MY ROCKET"<<endl;
    cin>>opt;
    if(opt==1){
      add_money(myAccount);
    }else if(opt==2){
        deposit_money(myAccount);
    }else if(opt == 3){
        create_rocket(myAccount);
    }else{
        cout<<"No option found.."<<endl;

    }




}

return 0;
}
