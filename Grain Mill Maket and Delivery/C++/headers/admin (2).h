//
// Created by Administrator on 2/14/2023.
//

#ifndef GM_ADMIN_H
#define GM_ADMIN_H

#include "common.h"

string files[4] = {"buyerinfo.txt", "sellerinfo.txt", "products.txt", "order.txt"};

void userlist() {
    clear();
    fstream file;
    file.open("buyerinfo.txt", ios::in);
    string name, email, address, phone, username, password;
    cout << "\n\n\t\t>> Buyer List" << endl;
    cout << "\n\n\t\t" << setw(20) << left << "Name" << setw(30) << left << "Email" << setw(30)
                     << left << "Address" << setw(20) << left << "Phone No." << setw(20) << left << "Password";
    while (file >> name >> email >> address >> phone >> username >> password) {
       cout << "\n\n\t\t" << setw(20) << left << name << setw(30) << left << email << setw(30) << left << address
            << setw(20) << left << phone << setw(20) << left << password;
    }
    file.close();
    cont();
}

void sellerlist() {
    clear();
    fstream file;
    file.open("sellerinfo.txt", ios::in);
    string name, password, address, phone, email;
    cout << "\n\n\t\t>> Seller List" << endl;
    cout << "\n\n\t\t" << setw(20) << left << "Mill House Name" << setw(30) << left << "Email" << setw(30)
                     << left << "Address" << setw(20) << left << "Phone No." << setw(20) << left << "Password";
    while (file >> name >> email >> address >> phone >> password) {
        cout << "\n\n\t\t" << setw(20) << left << name << setw(30) << left << email << setw(30) << left << address
            << setw(20) << left << phone << setw(20) << left << password;
    }
    file.close();
    cont();
}

int counter(int t) {
    int count = 0;
    string getcontent;
    ifstream openfile(files[t]);
    if (openfile.is_open()) {
        while (!openfile.eof()) {
            getline(openfile, getcontent);
            count++;
        }
        openfile.close();
    }
    return count;
}

void inventory(int t = 1) {
    clear();
    cout << "\n\n\t\t----------------- CURRENT INVENTORY AND USER STATUS -----------------\n";
    cout << "\n\t\t   Total Buyers: " << counter(0);
    cout << "\n\t\t  Total Sellers: " << counter(1);
    cout << "\n\t\t Total Products: " << counter(2);
    cout << "\n\t\t   Total Orders: " << counter(3);
    cout << endl;
    cont();
}

#endif //GM_ADMIN_H
