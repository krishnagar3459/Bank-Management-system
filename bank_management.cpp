#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;
class bank_management
{
    string name;
    int account_num;
    int PIN;
    int initial_balance;
    string account_type;
    double balance;

public:
    void setdata();
    void showdata();
    void saveinfile();
    int findaccount(vector<bank_management> &vec, int acNUM);
    void deletingdata(vector<bank_management> &person, int accountNum);
    void updatedata(vector<bank_management> &person, int accountNum);
    void withdraw(vector<bank_management> &person, int accountNUM);
    void deposite(vector<bank_management> &person, int accountNUM);
    void transaction(vector<bank_management> &person, int accountNUM1, int accountNUM2);
};
void bank_management::setdata()
{
    getchar();
    cout << "Name: ";
    getline(cin, name);
    cout << "Account number: ";
    cin >> account_num;
    cout << "PIN: ";
    cin >> PIN;
    cout << "initial balance: ";
    cin >> initial_balance;
    cout << "account type saving or current: ";
    getchar();
    getline(cin, account_type);
    cout << "bank balance";
    cin >> balance;
}
void bank_management::showdata()
{
    cout << "Name: " << this->name << endl;
    cout << "account number: " << this->account_num << endl;
    cout << "initial balance: " << this->initial_balance << endl;
    cout << "account type: " << this->account_type << endl;
    cout << "balance: " << this->balance << endl;
    cout << "------------------------" << endl;
}
void bank_management::saveinfile()
{
    FILE *ptr = NULL;
    ptr = fopen("bank_data.txt", "a");
    if (ptr==NULL)
    {
        cout<<"due to some reason file doesn't open";
    }
    else{
    fprintf(ptr, "%s %s\n", "Name:", this->name.c_str());
    fprintf(ptr, "%s %d\n", "account number:", this->account_num);
    fprintf(ptr, "%s %d\n", "initial balance:", this->initial_balance);
    fprintf(ptr, "%s %s\n", "account type:", this->account_type.c_str());
    fprintf(ptr, "%s %f\n", "balance:", this->balance);
    fprintf(ptr, "%s\n", "------------------------");
    fclose(ptr);
    }
}
void bank_management::deletingdata(vector<bank_management> &person, int accountNum)
{
    int i = findaccount(person, accountNum);
    if (i == -1)
    {
        cout << "account not found!!" << endl;
        return;
    }
    if (i == (person.size() - 1))
    {
        person.pop_back();
        return;
    }
    for (int j = i; j < person.size() - 1; j++)
    {
        person[j] = person[j + 1];
    }
    person.pop_back();
}
void bank_management::updatedata(vector<bank_management> &person, int accountNum)
{
    int i = findaccount(person, accountNum);
    if (i == -1)
    {
        cout << "account not found!!" << endl;
        return;
    }
    cout << "what do you want to change" << endl;
    string thing;
    getline(cin, thing);
    if (thing == "name")
    {
        cout << "enter the new name" << endl;
        getline(cin, person[i].name);
    }
    else if (thing == "account number")
    {
        cout << "you can't change the account number" << endl;
    }
    else if (thing == "initial balance")
    {
        cout << "enter the new initial balance" << endl;
        cin >> person[i].initial_balance;
        getchar();
    }
    else if (thing == "account type")
    {
        cout << "enter the new account type" << endl;
        getline(cin, person[i].account_type);
    }
    else if (thing == "balance")
    {
        cout << "enter the new balance" << endl;
        cin >> person[i].balance;
        getchar();
    }
}
void bank_management::withdraw(vector<bank_management> &person, int accountNUM)
{
    int i = findaccount(person, accountNUM);
    if (i == -1)
    {
        cout << "account not found!!" << endl;
        return;
    }
    cout << "enter the ammount of withdraw" << endl;
    double n;
    cin >> n;
    if (n <= 0)
    {
        cout << "enter valid amount";
        return;
    }

    if (n <= person[i].balance)
    {
        cout << "enter your PIN" << endl;
        int pin;
        cin >> pin;
        if (pin != person[i].PIN)
        {
            cout << "invalid PIN" << endl;
            return;
        }
        cout << n << "₹ ammount has been withdraw" << endl;
        person[i].balance = person[i].balance - n;
        remove("bank_data.txt");
        return;
    }
    else
    {
        cout << "be in your limit " << person[i].name << endl;
        return;
    }
}
void bank_management::deposite(vector<bank_management> &person, int accountNUM)
{
    int i = findaccount(person, accountNUM);
    if (i == -1)
    {
        cout << "account not found!!" << endl;
        return;
    }
    cout << "enter the ammount of deposite" << endl;
    double n;
    cin >> n;
    if (n <= 0)
    {
        cout << "Enter valid ammount";
        return;
    }

    cout << "enter your PIN" << endl;
    int pin;
    cin >> pin;
    if (pin != person[i].PIN)
    {
        cout << "invalid PIN" << endl;
        return;
    }
    cout << n << "₹ ammount has been deposited" << endl;
    person[i].balance = person[i].balance + n;
    remove("bank_data.txt");
    return;
}
void bank_management::transaction(vector<bank_management> &person, int accountNUM, int accountNUM2)
{
    if (accountNUM==accountNUM2){
        cout<<"both the accounts one and two are same";
        return;
    }
    {
        /* code */
    }
    
    double n;
    int i = findaccount(person, accountNUM);
    if (i == -1)
    {
        cout << "account not found!!" << endl;
        return;
    }
    int j = findaccount(person, accountNUM2);
    if (j == -1)
    {
        cout << "you type the wrong account number" << endl;
        return;
    }
    else
    {
        cout << "enter the ammount of transaction" << endl;
        cin >> n;
        if (n <=0)
        {
            cout << "Enter positive ammount";
            return;
        }

        if (n <= person[i].balance)
        {
            cout << "enter your PIN" << endl;
            int pin;
            cin >> pin;
            if (pin != person[i].PIN)
            {
                cout << "invalid PIN" << endl;
                return;
            }
            person[i].balance = person[i].balance - n;
            cout << n << "₹ ammount has been transfer to account number " << accountNUM2 << endl;
            person[j].balance = person[j].balance + n;
            remove("bank_data.txt");
            return;
        }
        else
        {
            cout << "be in your limit " << person[i].name;
            return;
        }
    }
}
int bank_management::findaccount(vector<bank_management> &vec, int acNUM)
{
    int i = 0;
    for (i = 0; i < vec.size(); i++)
    {
        if (vec[i].account_num == acNUM)
        {
            return i;
        }
    }
    return -1;
};

int main()
{
    vector<bank_management> vec;
    cout << "enter the number of peoples" << endl;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the details of the"<<i+1<< "person";
        bank_management s;
        vec.push_back(s);
        vec[i].setdata();
    }
    for (int i = 0; i < vec.size(); i++)
    {
        vec[i].showdata();
        vec[i].saveinfile();
    }
    int k;
    cout << "for deleting data, enter 1" << endl;
    cout << "for updating data, enter 2" << endl;
    cout << "if you want to use the ATM, enter 3" << endl;
    cin >> k;
    if (k == 1)
    {
        int num;
        cout << "enter account number of the person" << endl;
        cin >> num;
        cout << "deleting data..." << endl;
        remove("bank_data.txt");
        bank_management().deletingdata(vec, num);
        for (int i = 0; i < vec.size(); i++)
        {
            vec[i].showdata();
            vec[i].saveinfile();
        }
    }
    if (k == 2)
    {
        int num;
        cout << "enter account number of the person" << endl;
        cin >> num;
        getchar();
        remove("bank_data.txt");
        bank_management().updatedata(vec, num);
        cout << "updating data..." << endl;
        for (int i = 0; i < n; i++)
        {
            vec[i].showdata();
            vec[i].saveinfile();
        }
    }
    if (k == 3)
    {
        cout << "what do you want to do" << endl;
        string use;
        cin >> use;
        getchar();
        cout << "transaction";
        cout << "withdrawn";
        cout << "deposite";
        if (use == "transaction")
        {
            cout << "enter your account number" << endl;
            int num;
            cin >> num;
            cout << "enter the account number of second person" << endl;
            int num2;
            cin >> num2;
            bank_management().transaction(vec, num, num2);
            for (int i = 0; i < n; i++)
            {
                vec[i].showdata();
                vec[i].saveinfile();
            }
        }
        if (use == "deposite")
        {
            cout << "enter the your account number" << endl;
            int num;
            cin >> num;
            bank_management().deposite(vec, num);
            for (int i = 0; i < n; i++)
            {
                vec[i].showdata();
                vec[i].saveinfile();
            }
        }
            if (use == "withdraw")
            {
                cout << "enter the your account number" << endl;
                int num;
                cin >> num;
                bank_management().withdraw(vec, num);
                for (int i = 0; i < n; i++) 
                {
                    vec[i].showdata();
                    vec[i].saveinfile();
                }
            }
        }

    return 0;
}
