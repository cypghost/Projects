//
// Created by Administrator on 2/14/2023.
//

#ifndef GM_SELL_H
#define GM_SELL_H

#include "common.h"


bool check(string p) {
    Product *temp = head;

    while (temp != NULL) {
        if (temp->ProductName == p && temp->millinghousename == miller.name) {
            return true;
        }
        temp = temp->next;
    }

    return false;
}

void addlisting() {

    string productname;
    float productprice;
    float millingprice;

    int Amount;
    cout << "\n\n\t\tPlease fill the information needed about your product" << endl;
    cout << "\n\n\t\tEnter the name of the product: ";
    cin.ignore();
    getline(cin, productname);

    productname = replace(productname, ' ', '_');
    productname = changetolower(productname);
    if (!check(productname)) {
        cout << "\n\n\t\tEnter the price: ";
        cin >> productprice;
        cout << "\n\n\t\tEnter milling price: ";
        cin >> millingprice;
        cout << "\n\n\t\tEnter the amount: ";
        cin >> Amount;
        fstream file;
        file.open("products.txt", ios::app | ios::out);
        file << setw(20) << left << productname << setw(20) << left << productprice << setw(10) << left << millingprice
             << setw(10) << left << Amount << setw(10) << left << miller.name << "\n";
        file.close();
        Product *p = new Product();
        p->ProductName = productname;
        p->ProductPrice = productprice;
        p->MillingPrice = millingprice;
        p->amount = Amount;
        p->millinghousename = miller.name;
        insertNode(p);

        cout << "\n\n\t\tProduct added successfully" << endl;
        cont();
    } else {
        cout << "\n\n\t\tThe product already Exist choose the update option to modify" << endl;
        cont();
    }
}

void updateproduct() {
    string pn;
    float pp;
    float mp;
    int am;
    string pn1, mn1;
    float pp1;
    float mp1;
    int am1;
    cout << "\n\n\t\tEnter the name of the product you wanna update:";
    cin.ignore();
    getline(cin, pn);
    pn = replace(pn, ' ', '_');
    pn = changetolower(pn);

    if (check(pn)) {
        cout << "\n\n\t\tEnter the information below" << endl;
        cout << "\n\n\t\tEnter the price of the product: ";
        cin >> pp;
        cout << "\n\n\t\tEnter the Milling price: ";
        cin >> mp;
        cout << "\n\n\t\tEnter the Amount: ";
        cin >> am;
        ifstream file("products.txt");
        ofstream write("temp.txt");
        while (file >> pn1 >> pp1 >> mp1 >> am1 >> mn1) {
            if (pn1 == pn && miller.name == mn1) {
                write << setw(20) << left << pn << setw(20) << left << pp << setw(10) << left << mp << setw(10) << left
                      << am << setw(20) << left << mn1 << endl;
            } else {
                write << setw(20) << left << pn1 << setw(20) << left << pp1 << setw(10) << left << mp1 << setw(10)
                      << left << am1 << setw(20) << left << mn1 << endl;
            }
        }
        write.close();
        file.close();
        remove("products.txt");
        rename("temp.txt", "products.txt");
        updateNode(pn, pp, mp, am, miller.name, 1);
        cout << "\n\n\t\tProduct updated succesfully" << endl;
        cont();
    } else {
        cout << "\n\n\t\tYou haven't added any product with that name" << endl;
        cont();
    }
}

bool checkmiller() {
    if (head == NULL)
        return false;
    Product *temp = head;
    while (temp != NULL) {
        if (temp->millinghousename == miller.name)
            return true;
        temp = temp->next;
    }
    return false;
}

void productformillers() {
    if (!checkmiller()) {
        cout << "\n\n\t\tYou haven't added any product" << endl;
        cont();
        return;
    }

    cout << "\n\n\t\tHere are the product you've added" << endl;

    Product *temp = head;
    cout << setw(20) << left << "\n\n\t\tproductName" << setw(20) << left << "productPrice" << setw(20) << left
                 << "MillingPrice" << setw(10) << left << "Amount" << endl;
    while (temp != NULL) {
        if (miller.name == temp->millinghousename) {
            cout << "\t\t" << setw(20) << left << temp->ProductName << setw(20) << left << temp->ProductPrice
                 << setw(20) << left << temp->MillingPrice << setw(10) << left << temp->amount << endl;
        }
        temp = temp->next;
    }
    cont();
}

void deleteproduct(string s) {
    string n, mn;
    float p, m;
    int a;
    ifstream file("products.txt");
    ofstream file2("temp.txt");
    while (file >> n >> p >> m >> a >> mn) {
        if (s == n && miller.name == mn) {
            continue;
        }
        file2 << "\n"
              << setw(20) << left << n << setw(20) << left << p << setw(10) << left << m << setw(10) << left << a;
    }
    file.close();
    file2.close();
    remove("products.txt");
    rename("temp.txt", "products.txt");
}


#endif //GM_SELL_H
