//
// Created by Administrator on 2/14/2023.
//

#ifndef GM_COMMON_H
#define GM_COMMON_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cstring>
#include <iomanip>
#include <stack>
#include <conio.h>

using namespace std;

struct Product {
    basic_string<char> ProductName;
    float ProductPrice;
    float MillingPrice;
    string millinghousename;
    int amount;
    Product *next;

    Product() {
        ProductName = "";
        ProductPrice = 0;
        MillingPrice = 0;
        amount = 0;
        millinghousename = "";
        next = NULL;
    }
};

struct user {
    string name;
    string email;
    string address;
    string phonenumber;
    string username;
    string password;
};
user currentuser;

struct millinghouse {
    string name;
    string email;
    string address;
    string phonenumber;
    string password;
};
millinghouse miller;

void cont();

bool checkunique(int, string);

bool checkup(string, string);

bool checkmilus(string);

bool checkinorder(int);

float calculateTotalPrice(string p, string mn, int a);

bool checkp(string, string);

void productformillers();

void adminMenu();

void sellerlist();

void userlist();

void deleteaccount(int);

string changetolower(string);

string replace(string, char, char);

void changesetting(int);

void accountsetting(int);

void mainmenu();

void menuchoice(int);

void login(int);

void signup(int);

void buyerSignup();

void sellersignup();

bool loginseller();

bool loginbuyer();

void forgotpassword(int user);

void buyermenu();

void sellermenu();

void addlisting();

void productlist();

void numberofitemstobuy();

void discountprice();

void orders(int);

void makeorder(bool);

void sortbyname();

void sortbyprice();

void search();

void addproducttolinkedlist();

void insertNode(Product *);

void updateproduct();

void updateNode(string, float, float, int, string, int);

bool check(string);

void deleteproduct(string);

void deletefromnode(string, string);

string securePassword(string);

Product *head = nullptr;

// Clear Screen
void clear(int x = 1) {
    if (x == 0) cont();
    system("CLS");
}

void cont() {
    cout << "\n\n\t\tPress Enter to Continue...";
    getch();
    system("cls");
}

string changetolower(string s) {
    for (char &i: s) {
        i = tolower(i);
    }
    return s;
}

string replace(string s, char x = ' ', char y = '_') {
    string v = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == x)
            s[i] = y;
        v += s[i];
    }
    return v;
}

bool checkunique(int x, string username) {
    if (x == 1) {
        string nm, em, ad, ph, un, pw;
        ifstream file("buyerinfo.txt");
        while (file >> nm >> em >> ad >> ph >> un >> pw) {
            if (username == un)
                return true;
        }
        file.close();
        return false;
    } else {
        string nm, em, ad, ph, pw;
        ifstream file("sellerinfo.txt");
        while (file >> nm >> em >> ad >> ph >> pw) {
            if (nm == username)
                return true;
        }
        file.close();
        return false;
    }
}

string securePassword(string word) {
    string reversed;
    stack<char> wordstack;
    for (char c: word) {
        wordstack.push(c);
    }
    while (!wordstack.empty()) {
        reversed += wordstack.top();
        wordstack.pop();
    }
    return reversed;
}

#endif //GM_COMMON_H
