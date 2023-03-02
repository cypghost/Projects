//
// Created by Administrator on 2/14/2023.
//

#ifndef GM_LOGIN_H
#define GM_LOGIN_H

#include "common.h"
#include "menu.h"

void login(int user) {

    if (user == 1) {
        if (loginbuyer())
            buyermenu();
        else
            cout << "\n\n\t\tCheck your information and try again." << endl;
        cont();
    }
    if (user == 2) {

        if (loginseller())
            sellermenu();
        else
            cout << "\n\n\t\tcheck you information and try again." << endl;
        cont();
    }
}

bool loginbuyer() {
    string s;
    string p;
    string bn, be, ba, bp, bu, pw;
    ifstream file("buyerinfo.txt");
    cout << "\n\n\t\tEnter your username: ";
    cin.ignore();
    getline(cin, currentuser.username);
    currentuser.username = changetolower(currentuser.username);
    currentuser.username = replace(currentuser.username, ' ', '_');
    cout << "\n\n\t\tEnter password: ";
    cin >> p;
    p = securePassword(p);
    while (file >> bn >> be >> ba >> bp >> bu >> pw) {
        if (currentuser.username == bu && p == pw)
            return true;
    }
    return false;
}

bool loginseller() {
    string s;
    string p;
    string bn, be, ba, bp, pw;
    ifstream file("sellerinfo.txt");
    cout << "\n\n\t\tEnter your millinghouse name: ";
    cin.ignore();
    getline(cin, miller.name);
    miller.name = replace(miller.name, ' ', '_');
    miller.name = changetolower(miller.name);
    cout << "\n\n\t\tEnter password: ";
    cin >> p;
    p = securePassword(p);
    while (file >> bn >> be >> ba >> bp >> pw) {
        if (miller.name == bn && p == pw)
            return true;
    }
    return false;
}

#endif //GM_LOGIN_H
