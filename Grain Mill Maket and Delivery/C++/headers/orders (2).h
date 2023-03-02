//
// Created by Administrator on 2/14/2023.
//

#ifndef GM_ORDERS_H
#define GM_ORDERS_H

#include "common.h"


void orders(int x) {
    if (x == 1) {
        string n, mhn, st, un;
        float p, m;
        int a;
        if (checkinorder(1)) {

            fstream file;
            file.open("order.txt", ios::in);
            cout << "\n\n\t\t         These are your orders       " << endl;
            cout << "\n\n\t\t" << setw(20) << left << "ProductName" << setw(20) << left << "ProductPrice" << setw(20)
                 << left << "MillingPrice" << setw(10) << left << "amount" << setw(20) << left << "From" << setw(20)
                 << left << "Status" << endl;
            while (file >> n >> p >> m >> a >> mhn >> un >> st) {
                if (un == currentuser.username) {
                    cout << "\t\t" << setw(20) << left << n << setw(20) << left << p << setw(20) << left << m
                         << setw(10) << left << a << setw(20) << left << mhn << setw(20) << left << st << endl;
                }
            }

            file.close();
            cont();
        } else {
            cout << "\n\n\t\tYou haven't ordered Yet" << endl;
            cont();
        }
    } else {
        string n, mhn, st, un;
        float p, m;
        int a;
        if (checkinorder(2)) {
            int option = 100;
            while (option > 3) {
                fstream file;
                file.open("order.txt", ios::in);
                cout << "\n\n\t\t         These are your orders       " << endl;
                cout << "\t\t" << setw(20) << left << "ProductName" << setw(10) << left << "amount" << setw(20) << left
                     << "Ordered by";
                while (file >> n >> p >> m >> a >> mhn >> un >> st) {
                    if (mhn == miller.name && st == "pending...") {
                        cout << "\n\t\t"
                             << setw(20) << left << n << setw(10) << left << a << setw(20) << left << un;
                    }
                }
                cout << endl;
                file.close();

                cout << "\n\n\t\t1.view customer details" << endl;
                cout << "\t\t2.Accept order" << endl;
                cout << "\t\t3.Go back" << endl;
                cout << "\t\tChoose your option: ";
                cin >> option;
                if (option == 1) {
                    string cn;
                    cout << "\t\tEnter the name of customer: ";
                    cin.ignore();
                    getline(cin, cn);
                    cn = changetolower(cn);
                    cn = replace(cn, ' ', '_');
                    if (checkmilus(cn)) {
                        ifstream file("buyerinfo.txt");
                        string n, e, a, p, u, pw;
                        while (file >> n >> e >> a >> p >> u >> pw) {
                            if (u == cn) {
                                cout << "\n\n\t\tHere is a customer info" << endl;
                                cout << "\t\tName: " << n << endl;
                                cout << "\t\temail: " << e << endl;
                                cout << "\t\taddress: " << a << endl;
                                cout << "\t\tphone: " << p << endl;
                            }
                        }
                        file.close();
                    } else {
                        cout << "\n\n\t\tThe username you entered didn't order your product" << endl;
                        cont();
                    }
                } else if (option == 2) {
                    string un, p;
                    cout << "\n\n\t\tEnter the username: ";
                    cin.ignore();
                    getline(cin, un);
                    un = changetolower(un);
                    un = replace(un, ' ', '_');
                    cout << "\n\n\t\tEnter product name: ";
                    getline(cin, p);
                    p = changetolower(p);
                    p = replace(p, ' ', '_');
                    if (checkup(un, p)) {
                        string pn, usn, mhn, st;
                        float pp, mp;
                        int am;
                        ifstream file("order.txt");
                        ofstream file1("temp.txt");
                        while (file >> pn >> pp >> mp >> am >> mhn >> usn >> st) {
                            if (un == usn && p == pn && miller.name == mhn) {
                                st = "Accepted";
                            }
                            file1 << setw(20) << left << pn << setw(20) << left << pp << setw(10) << left << mp
                                  << setw(10) << left << am << setw(20) << left << mhn << setw(20) << left << usn
                                  << setw(20) << left << st << endl;
                        }
                        file.close();
                        file1.close();
                        remove("order.txt");
                        rename("temp.txt", "order.txt");
                        cout << "\n\n\t\tOrder accepted" << endl;
                        cont();
                        return;
                    } else {
                        cout << "\n\n\t\tThat username didn't order that product" << endl;
                    }
                } else if (option == 3) {
                    if(x == 2)
                    {
                        sellermenu();
                    }
                    else if(x == 3)
                    {
                        adminMenu();
                    }
                } else {
                    cout << "\t\t\n\nplease choose from the above choice only." << endl;

                }
            }
        } else {
            cout << "\n\n\t\tNo one has ordered your product" << endl;
            cont();
        }
    }
}


bool checkinorder(int x) {
    if (x == 1) {
        ifstream file("order.txt");
        string pn, mhn, un, st;
        float pp, mp;
        int a;
        while (file >> pn >> pp >> mp >> a >> mhn >> un >> st) {
            if (currentuser.username == un)
                return true;
        }
        return false;
    }
    if (x == 2) {
        ifstream file("order.txt");
        string pn, mhn, un, st;
        float pp, mp;
        int a;
        while (file >> pn >> pp >> mp >> a >> mhn >> un >> st) {
            if (miller.name == mhn && st == "pending...")
                return true;
        }
        return false;
    }
}


bool checkup(string un, string p) {
    string pn, usn, mhn, st;
    float pp, mp;
    int am;
    ifstream file("order.txt");
    while (file >> pn >> pp >> mp >> am >> mhn >> usn >> st) {
        if (pn == p && un == usn && miller.name == mhn) {
            return true;
        }
    }
    file.close();
    return false;
}

bool checkmilus(string s) {
    string pn, mhn, us, st;
    float pp, mp;
    int am;
    ifstream file("order.txt");
    while (file >> pn >> pp >> mp >> am >> mhn >> us >> st) {
        if (s == us && mhn == miller.name)
            return true;
    }
    file.close();
    return false;
}

#endif //GM_ORDERS_H
