#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Account {
    string name;
    string address;
    long long int contact;
    long long int addhar_no;
    long long int account_no;
    double balance = 0;
};

class Bank {
private:
    vector<Account*> customers;

public:
    Bank() {}

    void createAccount() {
        if (customers.size() >= 100) {
            cout << "Maximum number of customers reached." << endl;
            return;
        }

        string name, address;
        long long int contact, addhar_no;

        cout << "Enter the details correctly to create your account" << endl;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter address: ";
        getline(cin, address);

        cout << "Enter Contact: ";
        cin >> contact;

        cout << "Enter Aadhar no.: ";
        cin >> addhar_no;

        // Code to create account no.
        srand(time(nullptr)); // initialize random seed
        long long int account_no = rand() % 1000000000000 + 1000000000000; // generate 11-digit number
        cout << "\nYour account no. is : " << account_no << endl;

        customers.push_back(new Account{ name, address, contact, addhar_no, account_no });

        cout << "Your account is created successfully " << endl;
    }

    void updateAccount() {
        string name;
        long long int addhar_no;
        cout << "Enter name of customer to update account: ";
        cin.ignore();
        getline(cin, name);

        for (int i = 0; i < customers.size(); i++) {
            if (customers[i]->name == name) {
                cout << "Enter your addhar_no.";
                cin >> addhar_no;
                if (customers[i]->addhar_no == addhar_no) {
                    string address, name;
                    double contact;
                    cout << "Enter new name: ";
                    cin.ignore();
                    getline(cin, name);
                    customers[i]->name = name;

                    cout << "Enter new address: ";
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

        cout << "Customer not found." << endl;
    }

    void deposit() {
        string name;
        double amount;

        cout << "Enter account holder name: ";
        cin.ignore();
        getline(cin, name);

        for (int i = 0; i < customers.size(); i++) {
            if (customers[i]->name == name) {
                cout << "Enter amount to deposit: ";
                cin >> amount;

                customers[i]->balance += amount;

                loadingAnimation("Deposit successful!");
                cout << "New balance is: " << customers[i]->balance << endl;
                return;
            }
        }

        cout << "Account not found!" << endl;
    }

    void withdraw() {
        string name;
        double amount;

        cout << "Enter account holder name: ";
        cin.ignore();
        getline(cin, name);

        for (int i = 0; i < customers.size(); i++) {
            if (customers[i]->name == name) {
                cout << "Enter amount to withdraw: ";
                cin >> amount;

                if (amount > customers[i]->balance) {
                    cout << "Insufficient Balance!" << endl;
                    cout << "Your Current Balance is: " << customers[i]->balance << endl;
                    return;
                }

                customers[i]->balance -= amount;

                loadingAnimation("Withdrawal successful!");
                cout << "New balance is: " << customers[i]->balance << endl;
                return;
            }
        }

        cout << "Account not found!" << endl;
    }

    void displayCustomers() {
        if (customers.empty()) {
            cout << "No customers added yet." << endl;
            return;
        }

        cout << "Customers:" << endl;
        for (const auto& customer : customers) {
            cout << "Name: " << customer->name << endl;
            cout << "Address: " << customer->address << endl;
            cout << "Contact: " << customer->contact << endl;
            cout << "Addhar No.: " << customer->addhar_no << endl;
            cout << "Account No.: " << customer->account_no << endl;
            cout << "Balance: " << customer->balance << endl;
            cout << endl;
        }
    }

    void loadingAnimation(const string& message) {
        cout << "LOADING";
        for (int i = 0; i < 4; i++) {
            cout << ".";
            this_thread::sleep_for(chrono::milliseconds(500));
        }
        cout << endl << message << endl;
    }
};

int main() {
    Bank bank;

    cout << "******************************************************" << endl;
    cout << "*                  Programming Technogies            *" << endl;
    cout << "*         And Tool Laboratory - II                   *" << endl;
    cout << "*                 BANK MANAGEMENT SYSTEM             *" << endl;
    cout << "******************************************************" << endl << endl;

    while (true) {
        cout << "Enter 1 to create an account." << endl;
        cout << "Enter 2 to update an account." << endl;
        cout << "Enter 3 to withdraw money." << endl;
        cout << "Enter 4 to deposit money." << endl;
        cout << "Enter 5 to display customers." << endl;
        cout << "Enter 6 to exit." << endl;

        int choice;
        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            bank.createAccount();
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
            cout << "Exiting program.";
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    }
}
