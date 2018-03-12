//
//  main.cpp
//  Simple Balance Calculator
//
//  Created by Ian Mubangizi on 2018/03/12.
//  Copyright © 2018 Evlutio (Pty) Ltd. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;


// Variables
double  balance = 0,
_balance = 0;
string  input;
bool    spend,
join;
int     items,
visit = 0;

// Input function
int _input(string a, bool b) {
    string c;
    bool d = true;

    while (d == true) {
        if ((a == (string)"Yes") or (a == (string)"yes")) {
            b = true;
            d = false;
        } else if ((a == (string)"No") or (a == (string)"no")) {
            b = false;
            d = false;
        } else {
            cout << "Invaild Input!\n\nPlease Try Again : ";
            cin >> c;
            a = c;
        }
    }
    return b;
}

// Main
int main() {
    int _input(string a, bool b);
    
    // Main Loop Statment
    do {
        // If Statement for Balance logging
        if (balance == 0) {
            cout << "What is your Voucher Balance? : R";
            cin >> balance;
        } else {
            cout << "Current Balance: R" << balance;
            cout << "\n\n";
            
            cout << "Do you want to buy Something? : ";
            cin >> input;
            
            
            if (_input(input ,spend)) {
                spend = true;
            } else {
                spend = false;
            }
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
            
        } else if (spend == false && visit > 0) {
            cout << "\nWhat can we do for you? :\n1. Add Balance\n2. Something\n3. Else\n\n [INPUT] : ";
            cin >> input;
            
            cout << "\n";
            
            if (input == "1") {
                cout << "Add : R";
                cin >> _balance;
                
                balance = balance + _balance;
                
                cout << "New Balance R" << balance << endl;
                _balance = 0;
            } else if (input == "2") {
                cout << "Something : R";
                cin >> _balance;
                
                balance = balance + _balance;
                
                cout << "New Balance R" << balance << endl;
                _balance = 0;
            } else if (input == "3") {
                cout << "Close Account";
                cin >> input;
            }
        }
        //  End
        
        visit++;
        
    } while (balance > 0);
    
    cout << "You have finisded your Vocuher Balance";
    cout << "\n";
    cout << "Do you want to buy a New Vocucher? : ";
    cin >> input;
    _input(input, join);
    
    // End
    
    cin.get();
}



