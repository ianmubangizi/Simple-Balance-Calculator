//
//  main.cpp
//  Simple Balance Calculator
//
//  Created by Ian Mubangizi on 2018/03/12.
//  Copyright © 2018 Evlutio (Pty) Ltd. All rights reserved.
//

#include <iostream>
#include <string>
#include <array>
using namespace std;

// Global Variables
double  balance = 0,
_balance = 0;
string  input;
bool    spend = false,
join = false;
int     items,
visit = 0;

// Input Validate Function
    int _inputValidate(string a, bool b) {
        string c;
        bool d = true;
        int e;

        string _yesInput[3] = {"YES", "Yes", "yes"};
        string _noInput[3]  = {"NO","No","no"};
        string _options[3]  = {"1", "2", "3"};

        while (d == true) {
            for (e = 0; e < 3; e++) {
                 if (a == _yesInput[e]) {
                     b = true;
                     d = false;
                     e = 3;
                 } else if (a == _noInput[e]) {
                     b = false;
                     d = false;
                     e = 3;
                 } else if (a == _options[e]) {
                     switch (e) {
                         case 0:
                             if (a == _options[e]) {
                                 b = true;
                                 d = false;
                                 e = 3;
                             }
                             break;
                         case 1:
                             if (a == _options[e]) {
                                 b = true;
                                 d = false;
                                 e = 3;
                             }
                             break;
                         case 2:
                             if (a == _options[e]) {
                                 b = true;
                                 d = false;
                                 e = 3;
                             }
                             break;
                         default:
                             d = true;
                             break;
                     }
                 } else if ((e == 2 ) && (a != _yesInput[e] && a != _noInput[e])){
                     cout << "Invaild Input!\n\nPlease Try Again : ";
                     cin >> c;
                     a = c;
                 }
            }
        }
        return b;
    }
//End

// Main
int main() {

    int _inputValidate(string a, bool b);

    // Main Loop Statment
    do {
        // If Statement for Balance logging
            if (balance == 0 && join == false) {
                cout << "Would you like to buy a Voucher? : ";
                cin >> input;

                if (_inputValidate(input ,join)) {
                    cout << "What is your Voucher Balance? : R";
                    cin >> balance;
                    cout << "Current Balance: R" << balance;
                    cout << "\n\n";
                    join = true;
                } else {

                }

            } else if (balance > 0) {
                cout << "Current Balance: R" << balance << "\n\n";
            }
        //  End

        // If Statement for Shopping
            if (spend == true && balance > 0) {
                double  item_cost = 0,
                total_cost = 0,
                amount_due = 0;
                cout << "How many items Do you want? : ";
                cin >> items;

                // While Loop for Calculating Amount Due
                    while (items != 0) {
                        cout << "Enter Cost of item: R";
                        cin >> item_cost;

                        total_cost = total_cost + item_cost;
                        items = items - 1;
                    }
                //  End

                // Amount Due
                    amount_due = amount_due + total_cost;
                    cout << "Amount Due: R" << amount_due << endl;

                    if (amount_due <= balance) {
                        balance = balance - amount_due;
                        //spend = false;
                    } else {
                        cout << "Insufficient Funds\n";
                    }
                // End

            } else if (spend == false && join == true) {
                cout << "\nWhat can we do for you? :\n1.Add Balance\n2.Buy Something\n3.Close Account\n\n [INPUT] : ";
                bool a = false;
                while (a == false) {
                    cin >> input;
                    if (_inputValidate(input, a)) {
                        a = true;
                    }
                    cout << "\n";
                }

                if (input == "1") {
                    cout << "Add : R";
                    cin >> _balance;
                    balance = balance + _balance;
                    cout << "New Balance R" << balance << endl;
                    _balance = 0;

                } else if (input == "2") {
                    cout << "Want to buy Something? : ";
                    cin >> input;
                    if (_inputValidate(input ,spend)) {
                        spend = true;
                    } else {
                        spend = false;
                    }

                } else if (input == "3") {
                    cout << "Close Account : ";
                    cin >> input;
                    if (_inputValidate(input ,join)) {
                        join = true;
                    } else {
                        cout << "Thank You Have a Nice Day";
                        balance = 0;
                        join = false;
                    }
                }
            }
        //  End

        visit++;
        if (balance == 0 && join == false ) {
            cout << "You Have No Balance\n";
        }

    } while (balance > 0 && join == true);
    // End


    cout << "Do you want to buy anything else? : ";
    cin >> input;

    _inputValidate(input, join);

    cin.get();
}
