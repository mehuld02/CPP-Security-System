#include <iostream>
#include <cctype>
#include <string>
#include <cstdlib>
using namespace std;

const int MAX_USERS = 25;

struct Register {
    int id;
    string name, email, password, pin;
} R[MAX_USERS];

int userCount = 0;

void registerAccount() {
    system("cls");
    if (userCount >= MAX_USERS) {
        cout << "Cannot register more users. Limit reached." << endl;
        return;
    }

    cout << "\n ENTER USER ID: ";
    cin >> R[userCount].id;

    cout << "\n ENTER USER NAME: ";
    cin >> R[userCount].name;

    cout << "\n ENTER USER EMAIL: ";
    cin >> R[userCount].email;

    cout << "\n ENTER USER PASSWORD: ";
    cin >> R[userCount].password;

    cout << "\n ENTER USER PIN (4 digits): ";
    cin >> R[userCount].pin;

    cout << "User registered successfully!" << endl;
    userCount++;
}

int findUserByEmail(const string& email) {
    for (int i = 0; i < userCount; ++i) {
        if (R[i].email == email) {
            return i;
        }
    }
    return -1;
}

void loginAccount() {
    string email, password, pin;
    cout << "Enter Email: ";
    cin >> email;
    cout << "Enter Password: ";
    cin >> password;
    cout << "Enter PIN: ";
    cin >> pin;

    int userIndex = findUserByEmail(email);
    if (userIndex != -1 && R[userIndex].password == password && R[userIndex].pin == pin) {
        cout << "Login successful! Welcome, " << R[userIndex].name << "!" << endl;
    } else {
        cout << "Login failed. Invalid email, password, or PIN." << endl;
    }
}

void forgotEmail() {
    string name, password, pin;
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter Password: ";
    cin >> password;
    cout << "Enter PIN: ";
    cin >> pin;

    for (int i = 0; i < userCount; ++i) {
        if (R[i].name == name && R[i].password == password && R[i].pin == pin) {
            cout << "Your email is: " << R[i].email << endl;
            return;
        }
    }
    cout << "No matching record found." << endl;
}

void forgotPassword() {
    string email, name, pin;
    cout << "Enter Email: ";
    cin >> email;
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter PIN: ";
    cin >> pin;

    int userIndex = findUserByEmail(email);
    if (userIndex != -1 && R[userIndex].name == name && R[userIndex].pin == pin) {
        cout << "Your password is: " << R[userIndex].password << endl;
    } else {
        cout << "No matching record found." << endl;
    }
}

int main() {
    while (true) {
        system("cls");
        int choice;
        cout << " >>>>>>>>SECURITY SYSTEM<<<<<<<" << endl;
        cout << "1. REGISTER ACCOUNT" << endl;
        cout << "2. LOGIN ACCOUNT" << endl;
        cout << "3. FORGOT EMAIL" << endl;
        cout << "4. FORGOT PASSWORD" << endl;
        cout << "5. EXIT" << endl;

        cout << "\n ENTER YOUR CHOICE: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerAccount();
                break;
            case 2:
                loginAccount();
                break;
            case 3:
                forgotEmail();
                break;
            case 4:
                forgotPassword();
                break;
            case 5:
                exit(0);
            default:
                cout << "PLEASE SELECT A CORRECT OPTION" << endl;
        }
        cin.ignore();
        cout << "\nPress Enter to continue...";
        cin.get();
    }

    return 0;
}
