#include <iostream>
#include <fstream>
#include <string.h>
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

bool checkunique(int);

bool checkup(string, string);

bool checkmilus(string);

bool checkinorder(int);

bool calculateTotalPrice(string p, string mn, int a);

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

void buyermenu();

void sellermenu();

void addlisting();

void productlist();

void numberofitemstobuy();

void discountprice();

void orders(int);

void makeorder();

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

Product *head = NULL;

void cont() {
    cout << "\n\n\t\tPress Enter to Continue...";
    getch();
}

string changetolower(string s) {
    for (int i = 0; i < s.size(); i++) {
        s[i] = tolower(s[i]);
    }
    return s;
}

void userlist() {
    fstream file;
    file.open("buyerinfo.txt", ios::in);
    string name, email, address, phone, username, password;
    cout << "\n\n\t\t>> Buyer List" << endl;
    cout << "\n\n\t\tName\t\temail\t\taddress\t\tphone\t\tusername\t\tpassword" << endl;
    while (file >> name >> email >> address >> phone >> username >> password) {
        cout << "\n\n\t\t" << name << "\t\t" << username << "\t\t" << password << "\t\t" << address << "\t\t" << phone
             << "\t\t" << email << endl;
    }
    file.close();
}

void sellerlist() {
    fstream file;
    file.open("sellerinfo.txt", ios::in);
    string name, password, address, phone, email;
    cout << "\n\n\t\t>> Seller List" << endl;
    cout << "\n\n\t\tName\t\temail\t\taddress\t\tphone\t\tpassword" << endl;
    while (file >> name >> email >> address >> phone >> password) {
        cout << "\n\n\t\t" << name << "\t\t" << email << "\t\t" << address << "\t\t" << phone << "\t\t" << password
             << endl;
    }
    file.close();
}

void discountprice() {
    float total = 0;
    fstream file;
    file.open("order.txt", ios::in);
    string name, email, address, phone, username, password, productname, millinghousename;
    int amount;
    float price, millingprice;
    while (file >> name >> email >> address >> phone >> username >> password >> productname >> millinghousename
                >> amount >> price >> millingprice) {
        if (username == currentuser.username) {
            total += (price + millingprice) * amount;
        }
    }
    file.close();
    cout << "\n\n\t\tTotal Price: " << total << endl;
    cout << "\n\n\t\tTotal Price after discount: " << total - (total * 0.1) << endl;
    cout << "\n\n\t\tPress Enter to Continue...";
    getch();
}

void numberofitemstobuy() {
    int n;
    cout << "\n\n\t\tHow many items do you want to buy: ";
    cin >> n;
    if (n >= 3 and n < 10) {
        cout << "\n\n\t\tWe Have an offer for you!" << endl;
        cout << "\n\n\t\tIf you buy more than 3 items you will get 10% discount" << endl;
        cout << "\n\n\t\tDo you want to buy more than 3 items? (y/n): ";
        char ch;
        cin >> ch;
        if (ch == 'y') {

            cout << "How many Items do you want to buy: ";
            cin >> n;

            for (int i = 0; i < n; i++) {
                makeorder();
                discountprice();
            }
        } else {
            for (int i = 0; i < n; i++) {
                makeorder();
            }
        }
    } else if (n >= 10) {
        cout << "You have reached maximum limit of your buying capacity in a day" << endl;
        return;
    } else {
        for (int i = 0; i < n; i++) {
            makeorder();
        }
    }
}

void accountsetting(int user) {
    system("cls");
    if (user == 1) {
        string bn, be, ba, bp, bu, pw;
        fstream file;
        file.open("buyerinfo.txt", ios::in);
        while (file >> bn >> be >> ba >> bp >> bu >> pw) {
            if (bu == currentuser.username) {
                cout << "\n\n\t\tHere is your info" << endl;
                cout << "\n\n\t\t" << setw(20) << left << "name" << setw(30) << left << "email" << setw(30) << left
                     << "address" << setw(20) << left << "phonenumber" << setw(20) << left << "username" << setw(20)
                     << left << "password" << endl;
                cout << "\t\t" << setw(20) << left << bn << setw(30) << left << be << setw(30) << left << ba << setw(20)
                     << left << bp << setw(20) << left << bu << setw(20) << left << securePassword(pw);
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

string replace(string s, char x = ' ', char y = '_') {
    string v = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == x)
            s[i] = y;
        v += s[i];
    }
    return v;
}

void addproducttolinkedlist() {
    string pn;
    float pp;
    float mp;
    int am;
    string mn;
    fstream file;
    file.open("products.txt", ios::in);
    while (file >> pn >> pp >> mp >> am >> mn) {
        Product *p = new Product();
        p->ProductName = pn;
        p->ProductPrice = pp;
        p->MillingPrice = mp;
        p->amount = am;
        p->millinghousename = mn;
        insertNode(p);
    }
    file.close();
}

void insertNode(Product *n) {

    if (head == NULL) {
        head = n;
    } else {
        Product *ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = n;
    }
}

void mainmenu() {
    system("cls");
    int choice = 1000;
    menu:
    cout << "\n\n\t\tWelcome to the Grain Market and Delivery System";
    cout << " \n\n\t\t>> I'm a." << endl;
    cout << "\n\n\t\t1. Buyer" << endl;
    cout << "\n\n\t\t2. Seller" << endl;
    cout << "\n\n\t\t3. Admin" << endl;
    cout << "\n\n\t\t0. Exit" << endl;
    cout << "\n\n\t\tPlease enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        menuchoice(choice);
    }
    if (choice == 2) {
        menuchoice(choice);
    }
    if (choice == 3) {
        int pin = 10;
        int pass;
        cout << "\n\n\t\tEnter Pin Please: ";
        cin >> pass;

        if (pass == pin) {
            adminMenu();
        } else
            cout << "\n\n\t\tIncorrect pin" << endl;
        goto menu;
    }
    if (choice == 0) {
        exit(0);
    }
}

void adminMenu() {
    int choice = 1000;

    cout << "\n\n\t\tWelcome to the Grain Market and Delivery System";
    cout << "\n\n\t\t1. Sign In as Buyer" << endl;
    cout << "\n\n\t\t2. Sign In as Seller" << endl;
    cout << "\n\n\t\t3. Product List" << endl;
    cout << "\n\n\t\t4. User List" << endl;
    cout << "\n\n\t\t5. Seller List" << endl;
    cout << "\n\n\t\t6. Orders" << endl;
    cout << "\n\n\t\t7. Back" << endl;
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
        productlist();
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
        mainmenu();
    }

    if (choice == 0) {
        exit(0);
    }
}

void menuchoice(int user) {
    int option = 1000;

    while (option != 0) {
        system("cls");
        cout << "\n\n\t\tWelcome to the GM!" << endl;
        cout << "\n\n\t\t1. Login" << endl;
        cout << "\n\n\t\t2. Sign up" << endl;
        cout << "\n\n\t\t3. back" << endl;
        cout << "\n\n\t\t0. Exit" << endl;
        cout << "\n\n\t\tPlease enter your choice: ";
        cin >> option;
        if (option == 1) {

            login(user);
        }
        if (option == 2) {
            signup(user);
        }
        if (option == 3)
            mainmenu();
        if (option == 0) {
            exit(0);
        }
    }
}

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

void signup(int user) {
    if (user == 1) {
        buyersignup();
    }
    if (user == 2) {
        sellersignup();
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

void buyerSignup() {

    cout << "\n\n\t\tFillout the following information: " << endl;
    fstream file;
    file.open("buyerinfo.txt", ios::out | ios::app);
    cout << "\n\n\t\tEnter your name: ";
    cin.ignore();
    getline(cin, currentuser.name);
    currentuser.name = changetolower(currentuser.name);
    currentuser.name = replace(currentuser.name, ' ', '_');

    cout << "\n\n\t\tEnter your email: ";
    cin >> currentuser.email;
    currentuser.email = changetolower(currentuser.email);
    cout << "\n\n\t\tEnter your address: ";
    cin.ignore();

    getline(cin, currentuser.address);
    currentuser.address = changetolower(currentuser.address);
    currentuser.address = replace(currentuser.address, ' ', '_');
    cout << "\n\n\t\tEnter your phone number: ";
    cin >> currentuser.phonenumber;
    usn:
    cout << "\n\n\t\tchoose a username: ";
    cin.ignore();
    getline(cin, currentuser.username);
    currentuser.username = changetolower(currentuser.username);
    currentuser.username = replace(currentuser.username, ' ', '_');
    if (checkunique(1)) {
        cout << "\n\n\t\tThis username is taken please choose another" << endl;
        goto usn;
    }
    cout << "\n\n\t\tChoose password: ";
    cin >> currentuser.password;

    file << "\n"
         << setw(20) << left << currentuser.name << setw(30) << left << currentuser.email << setw(30) << left
         << currentuser.address << setw(20) << left << currentuser.phonenumber << setw(20) << left
         << currentuser.username << setw(20) << left << securePassword(currentuser.password);
    file.close();
}

bool checkunique(int x) {
    if (x == 1) {
        string nm, em, ad, ph, un, pw;
        ifstream file("buyerinfo.txt");
        while (file >> nm >> em >> ad >> ph >> un >> pw) {
            if (currentuser.username == un)
                return true;
        }
        file.close();
        return false;
    } else {

        string nm, em, ad, ph, pw;
        ifstream file("sellerinfo.txt");
        while (file >> nm >> em >> ad >> ph >> pw) {
            if (nm == miller.name)
                return true;
        }
        file.close();
        return false;
    }
}

void sellersignup() {
    cout << "\n\n\t\tFillout the following information:" << endl;
    fstream file;
    file.open("sellerinfo.txt", ios::out | ios::app);
    mhn:
    cout << "\n\n\t\tEnter your milling house name: ";
    cin.ignore();
    getline(cin, miller.name);
    miller.name = changetolower(miller.name);
    miller.name = replace(miller.name, ' ', '_');
    if (checkunique(2)) {
        cout << "\n\n\t\tThere is a milling house with that name please choose different name" << endl;
        goto mhn;
    }
    cout << "\n\n\t\tEnter your email: ";
    cin >> miller.email;
    miller.name = changetolower(miller.name);
    cout << "\n\n\t\tEnter your adress: ";
    cin.ignore();
    getline(cin, miller.address);
    miller.name = changetolower(miller.name);
    miller.address = replace(miller.address, ' ', '_');
    cout << "\n\n\t\tEnter your phone number: ";
    cin >> miller.phonenumber;
    cout << "\n\n\t\tEnter a password: ";
    cin >> miller.password;

    file << "\n"
         << setw(20) << left << miller.name << setw(30) << left << miller.email << setw(30) << left << miller.address
         << setw(20) << left << miller.phonenumber << setw(20) << left << securePassword(miller.password);
    file.close();
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

void buyermenu() {

    int choice = 1000;
    while (choice != 0) {
        system("cls");
        cout << "\n\n\t\tWelcome to the GM!" << endl;
        cout << "\n\n\t\t1. Available products list" << endl;
        cout << "\n\n\t\t2. Search" << endl;
        cout << "\n\n\t\t3. View Orders" << endl;
        cout << "\n\n\t\t4. Account setting" << endl;
        cout << "\n\n\t\t5. Back" << endl;
        cout << "\n\n\t\t0. Exit" << endl;
        cout << "\n\n\t\tPlease enter your choice:";
        cin >> choice;
        switch (choice) {
            case 1:
                productlist();
                break;
            case 2:
                search();
                break;
            case 3:
                orders(1);
                break;
            case 4:
                accountsetting(1);
                break;
            case 5:
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

void updateNode(string pn, float pp, float mp, int am, string mn, int x) {
    if (x == 1) {
        Product *temp = head;
        while (temp != NULL) {
            if (temp->ProductName == pn && miller.name == temp->millinghousename) {
                temp->ProductPrice = pp;
                temp->MillingPrice = mp;
                temp->amount = am;
            }
            temp = temp->next;
        }
    } else {
        Product *temp = head;
        while (temp != NULL) {
            if (temp->ProductName == pn && mn == temp->millinghousename) {
                temp->ProductPrice = pp;
                temp->MillingPrice = mp;
                temp->amount = am;
            }
            temp = temp->next;
        }
    }
}

void productlist() {

    int option = 1000;
    while (option != 4) {
        system("cls");
        if (head == NULL) {
            cout << "\n\n\t\tWe have no products yet." << endl;
            cont();
            return;
        }
        Product *temp = head;
        cout << "\n\n\t\t              Products              " << endl;
        cout << setw(20) << left << "\n\n\t\tproductName" << setw(20) << left << "productPrice" << setw(20) << left
             << "MillingPrice" << setw(10) << left << "Amount" << setw(20) << left << "MillingHouse" << endl;
        while (temp != NULL) {
            cout << "\t\t" << setw(20) << left << temp->ProductName << setw(20) << left << temp->ProductPrice
                 << setw(20) << left << temp->MillingPrice << setw(10) << left << temp->amount << setw(20) << left
                 << temp->millinghousename << endl;
            temp = temp->next;
        }

        here:
        cout << "\n\n\t\t1. View product by name order" << endl;
        cout << "\t\t2. view products by price order" << endl;
        cout << "\t\t3. Order product" << endl;
        cout << "\t\t4. Go back" << endl;
        cout << "\t\tEnter your choice: ";
        cin >> option;
        if (option == 1)
            sortbyname();
        else if (option == 2)
            sortbyprice();
        else if (option == 3)
            numberofitemstobuy();
        else if (option == 4)
            buyermenu();
        else {
            cout << "\t\tChoose from these options only." << endl;
            goto here;
        }
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
    while (temp != NULL) {
        if (miller.name == temp->millinghousename) {
            cout << setw(20) << left << "\n\n\t\tproductName" << setw(20) << left << "productPrice" << setw(20) << left
                 << "MillingPrice" << setw(10) << left << "Amount" << endl;
            cout << "\t\t" << setw(20) << left << temp->ProductName << setw(20) << left << temp->ProductPrice
                 << setw(20) << left << temp->MillingPrice << setw(10) << left << temp->amount << endl;
        }
        temp = temp->next;
    }
    cont();
}

bool checkp(string p, string mn) {
    if (head == NULL) {
        return false;
    }
    Product *temp = head;
    while (temp != NULL) {
        if (temp->ProductName == p && temp->millinghousename == mn) {
            return true;
        }

        temp = temp->next;
    }
    return false;
}

bool calculateTotalPrice(string p, string mn, int a) {
    Product *temp = head;
    while (temp != NULL) {
        if (temp->ProductName == p && temp->millinghousename == mn && temp->amount >= a)
            return true;
    }
    return false;
}

void makeorder() {
    string p, mn;
    string pn, mhn;
    float pp, mp;
    int a, am;
    cout << "\n\n\t\tEnter the name of the product You wanna order: ";
    cin.ignore();
    getline(cin, p);
    p = replace(p, ' ', '_');
    p = changetolower(p);
    cout << "\n\n\t\tEnter millinhouse name: ";
    //   cin.ignore();
    getline(cin, mn);
    mn = replace(mn, ' ', '_');
    mn = changetolower(mn);
    if (checkp(p, mn)) {
        cout << "\n\n\t\tEnter the amount of You want: ";
        cin >> a;
        if (checka(p, mn, a)) {
            ifstream file("products.txt");
            ofstream file1("temp.txt", ios::app);
            ofstream file2("order.txt", ios::app);
            while (file >> pn >> pp >> mp >> am >> mhn) {
                if (pn == p && mhn == mn) {
                    am = am - a;
                    file2 << setw(20) << left << pn << setw(20) << left << pp << setw(10) << left << mp << setw(10)
                          << left << a << setw(20) << left << mhn << setw(20) << left << currentuser.username
                          << setw(20) << left << "pending..." << endl;
                    if (am == 0) {
                        deletefromnode(p, mn);
                        continue;
                    }
                    updateNode(pn, pp, mp, am, mn, 2);
                }
                file1 << setw(20) << left << pn << setw(20) << left << pp << setw(10) << left << mp << setw(10) << left
                      << am << setw(20) << left << mhn << endl;
            }

            file.close();
            file1.close();
            file2.close();
            remove("products.txt");
            rename("temp.txt", "products.txt");
        } else {
            cout << "\n\n\t\tThis millingHouse doesn't have that much amount of that product" << endl;
        }
    } else {
        cout << "\n\n\t\tThis milling house doesn't have a product with that name." << endl;
    }
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

void deletefromnode(string s, string mn) {
    if (head->next == NULL) {
        head = NULL;
    } else {
        Product *temp = head->next;
        Product *ptr = head;
        while (temp != NULL) {
            if (temp->ProductName == s && mn == temp->millinghousename)
                break;
            temp = temp->next;
            ptr = ptr->next;
        }
        if (temp == NULL) {
            ptr->next = NULL;
            delete temp;
        } else {
            ptr->next = temp->next;
            delete temp;
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
            while (option != 3) {
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
                choice:

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
                } else if (x == 2) {
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
                } else if (x == 3) {
                    sellermenu();
                } else {
                    cout << "\t\t\n\nplease choose from the above choice only." << endl;
                    goto choice;
                }
            }
        } else {
            cout << "\n\n\t\tNo one has ordered your product" << endl;
            cont();
        }
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

void sortbyname() {
    int pp;
    int mp;
    string pn;
    Product *temp = head;
    Product *ptr = head;

    while (temp != NULL) {
        while (ptr->next != NULL) {
            if ((ptr->ProductName)[0] > (ptr->next->ProductName)[0]) {
                pn = ptr->ProductName;
                ptr->ProductName = ptr->next->ProductName;
                ptr->next->ProductName = pn;
                pp = ptr->ProductPrice;
                ptr->ProductPrice = ptr->next->ProductPrice;
                ptr->next->ProductPrice = pp;
                mp = ptr->MillingPrice;
                ptr->MillingPrice = ptr->next->MillingPrice;
                ptr->next->MillingPrice = mp;
            }
            ptr = ptr->next;
        }
        ptr = head;
        temp = temp->next;
    }
}

void sortbyprice() {
    int pp;
    int mp;
    string pn;
    Product *temp = head;
    Product *ptr = head;

    while (temp != NULL) {
        while (ptr->next != NULL) {
            if (ptr->ProductPrice > ptr->next->ProductPrice) {
                pp = ptr->ProductPrice;
                ptr->ProductPrice = ptr->next->ProductPrice;
                ptr->next->ProductPrice = pp;
                pn = ptr->ProductName;
                ptr->ProductName = ptr->next->ProductName;
                ptr->next->ProductName = pn;
                mp = ptr->MillingPrice;
                ptr->MillingPrice = ptr->next->MillingPrice;
                ptr->next->MillingPrice = mp;
            }
            ptr = ptr->next;
        }
        ptr = head;
        temp = temp->next;
    }
}

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

void search() {
    if (head == NULL) {
        cout << "\n\n\t\tWe Don't Have products in our store Yet." << endl;
        cont();
        return;
    }
    string value;
    cout << "\n\n\t\tEnter the name of the product you wanna search: ";
    cin.ignore();
    getline(cin, value);

    value = replace(value, ' ', '_');
    value = changetolower(value);
    Product *temp = head;
    int a = -1;
    while (temp != NULL) {
        if (temp->ProductName == value) {
            a++;
            cout << "\n\n\t\tHere is the Product details" << endl;
            cout << "\t\t" << setw(20) << left << "productName" << setw(20) << left << "productPrice" << setw(20)
                 << left << "MillingPrice" << setw(10) << left << "amount" << setw(20) << left << "Millinhouse" << endl;
            cout << "\t\t" << setw(20) << left << temp->ProductName << setw(20) << left << temp->ProductPrice
                 << setw(20) << left << temp->MillingPrice << setw(10) << left << temp->amount << setw(20) << left
                 << temp->millinghousename << endl;
            cont();
            break;
        }
        temp = temp->next;
    }
    if (a == -1) {
        cout << "\n\n\t\tThe name of the product you Entered doesn't exist." << endl;
        cont();
    }
}

int main() {
    addproducttolinkedlist();

    mainmenu();

    return 0;
}
