//
// Created by Administrator on 2/14/2023.
//

#ifndef GM_ACCOUNT_H
#define GM_ACCOUNT_H

#include "common.h"


void accountsetting(int user) {
    system("cls");

    if (user == 1) {
        string bn, be, ba, bp, bu, pw;
        fstream file;
        file.open("buyerinfo.txt", ios::in);

        while (file >> bn >> be >> ba >> bp >> bu >> pw) {
            if (bu == currentuser.username) {
                cout << "\n\n\t\tHere is your info" << endl;
                cout << "\t\t" << "----------------------------------------" << endl;
                cout << "\t\t" << setw(20) << left << "username" << setw(30) << left << bu << endl;
                cout << "\t\t" << setw(20) << left << "name" << setw(30) << left << bn << endl;
                cout << "\t\t" << setw(20) << left << "email" << setw(30) << left << be << endl;
                cout << "\t\t" << setw(20) << left << "phone number" << setw(30) << left << bp << endl;
                cout << "\t\t" << setw(20) << left << "address" << setw(30) << left << ba << endl;
//                cout << "\t\t" << setw(20) << left << "password" << setw(30) << left << securePassword(pw) << endl;
                break;
            }
        }

        file.close();

        int option = 1000;
        there:
        cout << "\n\n\t\t1.Change setting" << endl;
        cout << "\t\t2.Delete account" << endl;
        cout << "\t\t3.Go back" << endl;
        cout << "\t\tchoose your option: ";
        cin >> option;

        if (option == 1) {
            changesetting(user);
        } else if (option == 2) {
            deleteaccount(user);
        } else if (option == 3) {
            buyermenu();
        } else {
            cout << "\n\n\t\tPlease choose only from the above" << endl;
            goto there;
        }
    }

    if (user == 2) {
        string mn, me, ma, mp, pw;
        fstream file;
        file.open("sellerinfo.txt", ios::in);

        while (file >> mn >> me >> ma >> mp >> pw) {
            if (mn == miller.name) {
                cout << "\n\n\t\tHere is your info" << endl;
                cout << "\n\n\t\t" << setw(20) << left << "MillinHouseName" << setw(30) << left << "email" << setw(30)
                     << left << "address" << setw(20) << left << "phonenumber" << setw(20) << left << "password"
                     << endl;
                cout << "\t\t" << setw(20) << left << mn << setw(30) << left << me << setw(30) << left << ma << setw(20)
                     << left << mp << setw(20) << left << securePassword(pw);
                break;
            }
        }
        file.close();

        int option = 1000;
        here:
        cout << "\n\n\t\t 1.Change setting" << endl;
        cout << "\t\t 2.Delete account" << endl;
        cout << "\t\t 3.Go back" << endl;
        cout << "\t\tchoose your option: ";
        cin >> option;

        if (option == 1) {
            changesetting(user);
        } else if (option == 2) {
            deleteaccount(user);
        } else if (option == 3) {
            sellermenu();
        } else {
            cout << "\n\n\t\tPlease choose only from the above" << endl;
            goto here;
        }
    }
}

void changesetting(int user) {
    if (user == 1) {
        string bn, be, ba, bp, bu, pw;
        string bn1, be1, ba1, bp1, bu1, pw1;

        cout << "\n\n\t\tEnter your information";
        cout << "\n\n\t\tEnter your name: ";
        cin.ignore();
        getline(cin, bn);
        bn = changetolower(bn);
        bn = replace(bn, ' ', '_');

        cout << "\n\n\t\tEnter your email: ";
        cin >> be;
        be = changetolower(be);

        cout << "\n\n\t\tEnter your adress: ";
        cin.ignore();
        getline(cin, ba);
        ba = changetolower(ba);
        ba = replace(ba, ' ', '_');

        cout << "\n\n\t\tEnter your phone number: ";
        cin >> bp;

        cout << "\n\n\t\tchoose a username: ";
        cin.ignore();
        getline(cin, bu);
        bu = changetolower(bu);
        bu = replace(bu, ' ', '_');

        cout << "\n\n\t\tChoose password: ";
        cin >> pw;

        ifstream file("buyerinfo.txt");
        ofstream write("temp.txt");

        while (file >> bn1 >> be1 >> ba1 >> bp1 >> bu1 >> pw1) {
            if (bu1 == currentuser.username) {
                bn1 = bn;
                be1 = be;
                ba1 = ba;
                bp1 = bp;
                bu1 = bu;
                pw1 = pw;
                currentuser.username = bu;
            }

            write << "\n"
                  << setw(20) << left << bn1 << setw(30) << left << be1 << setw(30) << left << ba1 << setw(20) << left
                  << bp1 << setw(20) << left << bu1 << setw(20) << left << securePassword(pw1);
        }

        write.close();
        file.close();
        remove("buyerinfo.txt");
        rename("temp.txt", "buyerinfo.txt");

        cout << "\n\n\t\tAccount information changed succefully" << endl;
        cont();
    }

    if (user == 2) {
        string mn1, me1, ma1, mp1, pw1;
        string mn, me, ma, mp, pw;

        cout << "\n\n\t\tFillout the following information" << endl;
        cout << "\n\n\t\tEnter your milling house name: ";
        cin.ignore();
        getline(cin, mn);
        mn = changetolower(mn);
        mn = replace(mn, ' ', '_');

        cout << "\n\n\t\tEnter your email: ";
        cin >> me;
        me = changetolower(me);

        cout << "\n\n\t\tEnter your adress: ";
        cin.ignore();
        getline(cin, ma);
        ma = changetolower(ma);
        ma = replace(ma, ' ', '_');

        cout << "\n\n\t\tEnter your phone number: ";
        cin >> mp;

        cout << "\n\n\t\tEnter a password: ";
        cin >> pw;

        ifstream file("sellerinfo.txt");
        ofstream write("temp.txt");

        while (file >> mn1 >> me1 >> ma1 >> mp1 >> pw1) {
            if (mn1 == miller.name) {
                mn1 = mn;
                me1 = me;
                ma1 = ma;
                mp1 = mp;
                pw1 = pw;
                miller.name = mn;
            }
            write << "\n"
                  << setw(20) << left << mn1 << setw(30) << left << me1 << setw(30) << left << ma1 << setw(20) << left
                  << mp1 << setw(20) << left << securePassword(pw1);
        }

        write.close();
        file.close();
        remove("sellerinfo.txt");
        rename("temp.txt", "sellerinfo.txt");

        cout << "\n\n\t\tAccount information changed succefully" << endl;
        cont();
    }
}

void deleteaccount(int user) {
    if (user == 1) {
        string bn, be, ba, bp, bu, pw;
        ifstream file("buyerinfo.txt");
        ofstream write("temp.txt");

        while (file >> bn >> be >> ba >> bp >> bu >> pw) {
            if (bu == currentuser.username) {
                continue;
            }
            write << "\n"
                  << setw(20) << left << bn << setw(30) << left << be << setw(30) << left << ba << setw(20) << left
                  << bp << setw(20) << left << bu << setw(20) << left << securePassword(pw);
        }

        write.close();
        file.close();
        remove("buyerinfo.txt");
        rename("temp.txt", "buyerinfo.txt");

        cout << "\n\n\t\tAccount Deleted Succesfully" << endl;
        cont();
        mainmenu();
    }

    if (user == 2) {
        string mn, me, ma, mp, pw;
        ifstream file("sellerinfo.txt");
        ofstream write("temp.txt");

        while (file >> mn >> me >> ma >> mp >> pw) {
            if (mn == miller.name) {
                continue;
            }
            write << "\n"
                  << setw(20) << left << mn << setw(30) << left << me << setw(30) << left << ma << setw(20) << left
                  << mp << setw(20) << left << securePassword(pw);
        }
        write.close();
        file.close();

        remove("sellerinfo.txt");
        rename("temp.txt", "sellerinfo.txt");
        cout << "\n\n\t\tAccount Deleted Succesfully" << endl;
        cont();
        mainmenu();
    }
}


#endif //GM_ACCOUNT_H
