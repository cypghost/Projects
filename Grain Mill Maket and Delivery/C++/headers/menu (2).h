//
// Created by Administrator on 2/14/2023.
//

#ifndef GM_MENU_H
#define GM_MENU_H

#include "common.h"
#include "buy.h"
#include "orders.h"
#include "account.h"
#include "sell.h"
#include "admin.h"
#include "recommendation.h"

void buyermenu() {
    addproducttolinkedlist();

    int choice = 1000;
    while (choice != 0) {
        system("cls");
        productoftheday();
        cout << "\n\n\t\tWelcome to the GM!" << endl;
        cout << "\n\n\t\t1. Available products list" << endl;
        cout << "\n\n\t\t2. Search" << endl;
        cout << "\n\n\t\t3. View Orders" << endl;
        cout << "\n\n\t\t4. Recommendation" << endl;
        cout << "\n\n\t\t5. Account setting" << endl;
        cout << "\n\n\t\t6. Back" << endl;
        cout << "\n\n\t\t0. Exit" << endl;
        cout << "\n\n\t\tPlease enter your choice:";
        cin >> choice;
        switch (choice) {
            case 1:
                productlist(1);
                break;
            case 2:
                search();
                break;
            case 3:
                orders(1);
                break;
            case 4:
                recommend();
                break;
            case 5:
                accountsetting(1);
                break;
            case 6:
                menuchoice(1);
                break;
            case 0:
                exit(0);
                break;
            default:
                cout << "\n\n\t\tPlease choose from the options only" << endl;
                break;
        }
    }
}

void sellermenu() {
    addproducttolinkedlist();
    int option = 1000;
    while (option != 6) {
        system("cls");
        cout << "\n\n\t\tWelcome to the GM!" << endl;
        cout << "\n\n\t\t1. Add products" << endl;
        cout << "\n\n\t\t2. update product" << endl;
        cout << "\n\n\t\t3. View product" << endl;
        cout << "\n\n\t\t4. View Orders" << endl;
        cout << "\n\n\t\t5. Account setting." << endl;
        cout << "\n\n\t\t6. Back" << endl;
        cout << "\n\n\t\t0. Exit" << endl;
        cout << "\n\n\t\tPlease enter your choice: ";
        cin >> option;
        switch (option) {
            case 1:
                addlisting();
                break;
            case 2:
                updateproduct();
                break;
            case 3:
                productformillers();
                break;
            case 4:
                orders(2);
                break;
            case 5:
                accountsetting(2);
            case 6:
                menuchoice(2);
                break;
            case 0:
                exit(0);
            default:
                break;
        }
    }
}


void adminMenu() {
    addproducttolinkedlist();
    int choice;
    clear();
    do {
        cout << "\n\n\t\tWelcome to the Grain Market and Delivery System";
        cout << "\n\n\t\t1. Sign In as Buyer" << endl;
        cout << "\n\n\t\t2. Sign In as Seller" << endl;
        cout << "\n\n\t\t3. Product List" << endl;
        cout << "\n\n\t\t4. User List" << endl;
        cout << "\n\n\t\t5. Seller List" << endl;
        cout << "\n\n\t\t6. Orders" << endl;
        cout << "\n\n\t\t7. Report" << endl;
        cout << "\n\n\t\t8. Back" << endl;
        cout << "\n\n\t\t0. Exit" << endl;
        cout << "\n\n\t\tPlease enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            buyermenu();
        }

        if (choice == 2) {
            sellermenu();
        }

        if (choice == 3) {
            productlist(2);
        }

        if (choice == 4) {
            userlist();
        }

        if (choice == 5) {
            sellerlist();
        }

        if (choice == 6) {
            orders(3);
        }

        if (choice == 7) {
            inventory();
        }

        if (choice == 8) {
            mainmenu();
        }

        if (choice == 0) {
            exit(0);
        }
    } while (choice != 0);
}

#endif //GM_MENU_H
