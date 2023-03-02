#include "headers/common.h"
#include "headers/signup.h"
#include "headers/login.h"


void mainmenu() {
    int choice, pass, pin = 1234;
    system("cls");
    do {
        cout << "\n\n\t\tWelcome to the Grain Market and Delivery System";
        cout << " \n\n\t\t>> I'm a." << endl;
        cout << "\n\n\t\t1. Buyer" << endl;
        cout << "\n\n\t\t2. Seller" << endl;
        cout << "\n\n\t\t3. Admin" << endl;
        cout << "\n\n\t\t0. Exit" << endl;
        cout << "\n\n\t\tPlease enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
            case 2:
                menuchoice(choice);
                break;
            case 3:
                cout << "\n\n\t\tEnter Pin Please: ";
                cin >> pass;

                if (pass == pin) {
                    adminMenu();
                } else
                    cout << "\n\n\t\tIncorrect pin" << endl;
                break;
            case 0:
                exit(0);
                break;
            default:
                cout << "\n\n\t\tInvalid choice" << endl;
                break;
        }
    } while (choice != 0);
}

void menuchoice(int user) {
    int option;

    do {
        system("cls");
        cout << "\n\n\t\tWelcome to the GM!" << endl;
        cout << "\n\n\t\t1. Login" << endl;
        cout << "\n\n\t\t2. Sign up" << endl;
        if (user == 1){ cout << "\n\n\t\t3. Forgot Password" << endl;
            cout << "\n\n\t\t4. Back" << endl;
        }
        else { cout << "\n\n\t\t3. Back" << endl; }
        cout << "\n\n\t\t0. Exit" << endl;
        cout << "\n\n\t\tPlease enter your choice: ";
        cin >> option;
        if (option == 1) {
            login(user);
        }
        if (option == 2) {
            signup(user);
        }
        if (option == 3 and user == 1) {
            forgotpassword(user - 1);
        }
        else if(option == 3 and user == 2)
        {
            mainmenu();
        }
        if (option == 4)
            mainmenu();

        if (option == 0) {
            exit(0);
        }
    } while (option != 0);
}

// Recover Forgotten Password
void forgotpassword(int t = 0) {
    clear();
    char u[50], p[50], n[50];
    cout << "\n\n\t\t----------------- Password Recovery -----------------\n";
    char x[20], y[20];
    if (t == 0)
        cout << "\n\t\tEnter your username: \t";
    else if (t == 1)
        cout << "\n\t\tEnter your milling house name: \t";
    cin.ignore();
    cin.getline(x, 15);
    ifstream file(files[t]);
    bool flag = false;
    while (file >> n >> p >> u >> p >> u >> p) {
        if (strcasecmp(u, x) == 0) {
            flag = true;
            if(t == 0)
            {
                cout << "\n\n\t\tEnter your Full Name: \t";
                cin.getline(y, 50);
            }
            if (n == replace(y)) {
                cout << "\n\n\t\t>> Your password is: \t" << securePassword(p) << endl
                     << "\n\t\tTry Not to forget Again!\n";

            } else
                cout << "\n\n\t\t <!> Who are you?  Try Registering.\n" << endl;
        }
    }
    file.close();
    if (!flag)
        cout << "\n\n\t\tSorry, Can't find your username in the list. Try registering.";
    cont();
}

int main() {


    mainmenu();

    return 0;
}
