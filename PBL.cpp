#include <iostream>
#include <string>
#include <chrono>//use to apply sleep function
#include <thread>//use to apply sleep function
#include <cstdlib>//use to create rendom number
#include <ctime>//use to create rendom number
using namespace std;

struct Account {
    string name;
    string address;
    long long int contact;
    long long int addhar_no;
    long long int account_no;
    double balance=0;


};

class Bank {
    private:
        Account* customers[100];
        int numCustomers;

    public:
        Bank() {
            numCustomers = 0;
        }

        void crateAccount() {
            if (numCustomers >= 100)
            {
                cout << "Maximum number of customers reached." << endl;
                return;
            }

            string name, address;
            long long int contact,addhar_no;
            // long long int account_no;


            // cout <<"Enter name: ";
            cout<<"Enter the details correctly to create your account"<<endl;
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Enter address: ";
            cin.ignore();
            getline(cin, address);

            cout << "Enter Contact: ";
            cin >> contact;

            cout << "Enter Addhar no.: ";
            cin >> addhar_no;

             string str_arr[] = {"Verification is under process"," ."," ."," ."," ."};
              for (const string& str : str_arr)
              {
                cout << str ;
                this_thread::sleep_for(chrono::seconds(1));
               }

             //    code to create account no.
               srand(time(nullptr)); // initialize random seed
               long long int account_no = rand() % 1000000000000 + 1000000000000; // generate 11-digit number
               cout << "\nYour account no. is : " << account_no << endl << endl;

              string str_arr1[] = {"Your account is created successfully "};
              for (const string& str : str_arr1)
              {
                cout << str ;
                this_thread::sleep_for(chrono::seconds(1));
               }
            customers[numCustomers] = new Account {name,address,contact,addhar_no,account_no};
            numCustomers++;


        }

       void updateAccount()
        {
            string name;
            long long int addhar_no;
            cout << "Enter name of customer to update account: ";
            cin.ignore();
            getline(cin, name);
            for (int i = 0; i < numCustomers; i++)
            {
                if (customers[i]->name == name)
                {
                    cout<<"Enter your addhar_no.";
                    cin>>addhar_no;
                    for(int i=0;i< numCustomers;i++)
                    {
                        if(customers[i]->addhar_no==addhar_no)
                        {
                            string address,name;
                    double contact;
                    cout<<"Enter new name: ";
                    cin.ignore();
                    getline(cin, name);
                    customers[i]->name = name;


                    cout << "Enter new address: ";
                    cin.ignore();
                    getline(cin, address);
                    customers[i]->address = address;

                    cout << "Enter new contact: ";
                    cin >> contact;
                    customers[i]->contact = contact;

                    cout << "Account updated successfully." << endl;
                    return;

                        }
                    }


                }
            }

            cout << "Customer not found." << endl;
        }



        void deposit() {
    string name;
    double amount;

    cout << "Enter account holder name: ";
    cin.ignore();
    getline(cin, name);

    for (int i = 0; i < numCustomers; i++) {
         if (customers[i]->name == name) {
            cout << "Enter amount to deposit: ";
            cin >> amount;

           customers[i]->balance += amount;

           string str_arr3[] = {"LOADING"," ."," ."," ."," ."};
              for (const string& str : str_arr3)
              {
                cout << str ;
                this_thread::sleep_for(chrono::seconds(1));
               }

            cout << "\n\nDeposit successful!"<<"\n\nNew balance is: " << customers[i]->balance << endl;
            return;
        }
    }

    cout << "Account not found!" << endl;
}

// Function to withdraw money from account
void withdraw() {
    string name;
    double amount;

    cout << "Enter account holder name: ";
    cin.ignore();
    getline(cin, name);

    for (int i = 0; i <numCustomers; i++)
     {
        if (customers[i]->name == name)
       {
            cout << "Enter amount to withdraw: ";
            cin >> amount;

            if (amount > customers[i]->balance) {
                cout << "Insufficient Balance!" << endl;
                cout<<"Your Current Balance is: "<<customers[i]->balance;
                return;
            }

            customers[i]->balance -= amount;

            string str_arr4[] = {"LOADING"," ."," ."," ."};
              for (const string& str : str_arr4)
              {
                cout << str ;
                this_thread::sleep_for(chrono::seconds(1));
               }

            cout << "\n\nWithdrawal successful! "<<"\n\nNew balance is: " << customers[i]->balance << endl;


        }
        else
        {
            cout << "Account not found!" << endl;
        }

    }


}
         void displayCustomers()
       {
            if (numCustomers == 0)
            {
                cout << "No customers added yet." << endl;
                return;
            }

            cout << "Customers:" << endl;
            for (int i = 0; i < numCustomers; i++)
             {
                cout << "Name: " << customers[i]->name << endl;
                cout << "Address: " << customers[i]->address << endl;
                cout << "Contact: " << customers[i]->contact  << endl;
                cout << "Addhar No.: " << customers[i]->addhar_no<< endl;
                cout << "Account No.: " << customers[i]->account_no << endl;
                cout << "Balance: " << customers[i]->balance<< endl;
                cout << endl;
            }
        }
};

int main()
 {
    Bank bank;
    int choice;
    int i;
    for(i=0;i<=118;i++)
    {
    cout<<"*";
    }
    cout<<"*\n*";
    for(i=0;i<35;i++)
    {
        cout<<" ";
    }
    cout<<"Programming Technogies And Tool Laboratory - II";
    for(i=0;i<=35;i++)
    {
        cout<<" ";
    }
    cout<<"*\n*";
    for(i=0;i<=46;i++)
    {
        cout<<" ";
    }
     cout<<"BANK MANAGEMENET SYSTEM ";

    for(i=0;i<=46;i++)
    {
        cout<<" ";
    }
    cout<<"*";
    for(i=0;i<=118;i++)
    {
    cout<<"*";
    }

    cout<<endl<<endl;


    while (true) {

        for(i=0;i<=118;i++)
    {
    cout<<"*";
    }
        cout << "\nEnter 1 to create account." << endl;
        cout << "Enter 2 to update account." << endl;
        cout << "Enter 3 to withdraw money." << endl;
        cout << "Enter 4 to deposit money" << endl;
        cout << "Enter 5 to display customers" << endl;
        cout << "Enter 6 to exit." << endl;

         for(i=0;i<=119;i++)
    {
    cout<<"*";
    }

        cout<<"\nEnter Your Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                bank.crateAccount();
                break;
            case 2:
                bank.updateAccount();
                break;
            case 3:
                bank.withdraw();

                break;
            case 4:
                bank.deposit();
                break;
            case 5:
                bank.displayCustomers();
               break;
            case 6:
                cout<<"exiting program";
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout<<endl;
    }
}
