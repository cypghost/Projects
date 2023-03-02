//
// Created by Administrator on 2/14/2023.
//

#ifndef GM_SIGNUP_H
#define GM_SIGNUP_H

#include "common.h"

void signup(int user) {
    if (user == 1) {
        buyerSignup();
    }
    if (user == 2) {
        sellersignup();
    }
}

void buyerSignup() {
    system("cls");
    user newUser;

    cout << "\n\n\t\tFill in the following information: " << endl;

    fstream file;
    file.open("buyerinfo.txt", ios::out | ios::app);
    cout << "\n\n\t\tEnter your name: ";

    cin.ignore();
    getline(cin, newUser.name);
    newUser.name = changetolower(newUser.name);
    newUser.name = replace(newUser.name, ' ', '_');

    cout << "\n\n\t\tEnter your email: ";
    cin >> newUser.email;
    newUser.email = changetolower(newUser.email);

    cout << "\n\n\t\tEnter your address: ";
    cin.ignore();
    getline(cin, newUser.address);
    newUser.address = changetolower(newUser.address);
    newUser.address = replace(newUser.address, ' ', '_');

    cout << "\n\n\t\tEnter your phone number: ";
    cin >> newUser.phonenumber;
    cin.ignore();

    usn:
    cout << "\n\n\t\tchoose a username: ";
    getline(cin, newUser.username);
    newUser.username = changetolower(newUser.username);
    newUser.username = replace(newUser.username, ' ', '_');
    if (checkunique(1, newUser.username)) {
        cout << "\n\n\t\tThis username is taken please choose another" << endl;
        goto usn;
    }

    cout << "\n\n\t\tChoose password: ";
    cin >> newUser.password;

    file << "\n"
         << setw(20) << left << newUser.name << setw(30) << left << newUser.email << setw(30) << left << newUser.address
         << setw(20) << left << newUser.phonenumber << setw(20) << left << newUser.username << setw(20) << left
         << securePassword(newUser.password);
    file.close();
}


void sellersignup() {
    system("cls");
    millinghouse newmiller;
    cout << "\n\n\t\tFillout the following information:" << endl;

    fstream file;
    file.open("sellerinfo.txt", ios::out | ios::app);

    cin.ignore();
    mhn:
    cout << "\n\n\t\tEnter your milling house name: ";
    getline(cin, newmiller.name);
    newmiller.name = changetolower(newmiller.name);
    newmiller.name = replace(newmiller.name, ' ', '_');
    if (checkunique(2, newmiller.name)) {
        cout << "\n\n\t\tThere is a milling house with that name please choose different name" << endl;
        goto mhn;
    }

    cout << "\n\n\t\tEnter your email: ";
    cin >> newmiller.email;

    newmiller.name = changetolower(newmiller.name);
    cout << "\n\n\t\tEnter your adress: ";
    cin.ignore();
    getline(cin, newmiller.address);

    newmiller.name = changetolower(newmiller.name);
    newmiller.address = replace(newmiller.address, ' ', '_');

    cout << "\n\n\t\tEnter your phone number: ";
    cin >> newmiller.phonenumber;

    cout << "\n\n\t\tEnter a password: ";
    cin >> newmiller.password;

    file << "\n"
         << setw(20) << left << newmiller.name << setw(30) << left << newmiller.email << setw(30) << left
         << newmiller.address
         << setw(20) << left << newmiller.phonenumber << setw(20) << left << securePassword(newmiller.password);
    file.close();
}


#endif //GM_SIGNUP_H
