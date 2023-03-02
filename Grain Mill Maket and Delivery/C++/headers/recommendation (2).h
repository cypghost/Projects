//
// Created by Administrator on 2/16/2023.
//

#ifndef GM_RECOMMENDATION_H
#define GM_RECOMMENDATION_H

#include "common.h"

void recommend() {
    float budget;
    int random = rand() % 10;
    cout << "\n\n\t\tEnter your Budget: ";
    cin >> budget;

    Product *temp = head;
    for (int i = 0; i < random && temp->next != nullptr; i++) {
        temp = temp->next;
    }
    int kg = budget / (temp->ProductPrice + temp->MillingPrice);

    if(budget > 0)
    {
        cout << "\n\n\t\tWe recommend you to buy " << temp->ProductName << " for " << temp->ProductPrice << "birr" << endl;
        cout << "\n\t\tYou can buy " << kg << "kgs of "
         << temp->ProductName << " with " << (temp->ProductPrice + temp->MillingPrice) * kg << "Birr" << endl;
    }
    else
    {
        cout << "\t\t Budget Underflow";;
    }
    cont();
}

void productoftheday()
{
    int random = rand() % 5;
    Product *temp = head;
    for (int i = 0; i < random && temp->next != nullptr; i++) {
        temp = temp->next;
    }
    cout << "\n\n\t\t--------------------------------------------------------------------------------------" << endl;
    cout << "\t\t Product of the Day (Special Offer)" << endl;
    cout << "\t\t--------------------------------------------------------------------------------------" << endl;
    cout << "\t\t Order: " << temp->ProductName << " for Only: " << temp->ProductPrice << "Birr Per Kg (20% discount & free delivery)" << endl;
    cout << "\t\t--------------------------------------------------------------------------------------" << endl;
}

#endif //GM_RECOMMENDATION_H
