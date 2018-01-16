/*
 * File:   Lab04CKcode.cpp
 * Author: Christopher
 * Due : October 8, 2014, 10:10 AM
 * Created on October 2, 2014, 11:54 AM
 * Description: This program is designed for the less than average store clerk
 *          who can not do one of the prerequisites of actually being employ
 *          -ed as a store clerk. It makes change for the ignorant cashier,
 *          and even tells them the number of each type of bill and coin they
 *          should give back. 
 */

#include <iostream>
#include <iomanip>

using namespace std;


void get_check_out_vals_from_clerk(char &, double &, double &);
void calc_change_amt(double &, double , double, double &, double &);
void clac_bill_dimon(int &, int &, int &, int &, int &, int &, int );
void calc_change_dinom(int &, int &, int &, int &, int &, int );
void disp_reciept_vals_to_clerk(char, double, double, double,
        int, int, int, int, int, int, int, int, int, int, int);


int main() {
    char isle_letter;
    double item_price, amt_paid, change_amt, dollar_amt, coin_amt;
    int hundered_num, fifty_num, twenty_num, ten_num, five_num, one_num, 
            fifty_cent_num, quarter_num, dime_num, nickel_num, penny_num;

    cout << setprecision(2) << fixed;

    get_check_out_vals_from_clerk(isle_letter, item_price, amt_paid);
    calc_change_amt(change_amt, amt_paid, item_price, dollar_amt, coin_amt);
    clac_bill_dimon(hundered_num,fifty_num,twenty_num, ten_num, five_num,
            one_num, dollar_amt);
    calc_change_dinom(fifty_cent_num, quarter_num, dime_num, nickel_num, 
            penny_num, coin_amt);
    disp_reciept_vals_to_clerk( isle_letter,  item_price,  amt_paid,  
            change_amt, hundered_num,  fifty_num,  twenty_num,  ten_num,  
            five_num, one_num,  fifty_cent_num,  quarter_num,  dime_num,  
            nickel_num,  penny_num);

    //diagnostic


    return 0;
}

void get_check_out_vals_from_clerk(char &isle_letter, double &item_price,
        double &amt_paid)
{
    cout << "Aisle Letter : ";
    cin >> isle_letter;
    cout << "\nItem Price : ";
    cin >> item_price;
    cout << "\nAmount Paid : ";
    cin >> amt_paid;
}

void calc_change_amt(double &change_amt, double amt_paid, double item_price,
        double &dollar_amt, double &coin_amt)
{
    change_amt = amt_paid - item_price;
    dollar_amt = static_cast<int>(change_amt);
    coin_amt = static_cast<int>(((change_amt - dollar_amt) * 100) + .5);
}

void clac_bill_dimon(int &hundered_num, int &fifty_num, int &twenty_num,
        int &ten_num, int &five_num, int &one_num, int dollar_amt)
{
    int amt_left;
    hundered_num = dollar_amt / 100;
    amt_left = dollar_amt % 100;
    fifty_num = amt_left / 50;
    amt_left = amt_left % 50;
    twenty_num = amt_left / 20;
    amt_left = amt_left % 20;
    ten_num = amt_left / 10;
    amt_left = amt_left %10;
    five_num = amt_left / 5;
    one_num = amt_left % 5;
}

void calc_change_dinom(int &fifty_cent_num, int &quarter_num, int &dime_num,
        int &nickel_num, int &penny_num, int coin_amt)
{
    int amt_left;
    fifty_cent_num = coin_amt / 50;
    amt_left = coin_amt % 50;
    quarter_num = amt_left / 25;
    amt_left = amt_left % 25;
    dime_num = amt_left / 10;
    amt_left = amt_left % 10;
    nickel_num = amt_left / 5;
    penny_num = amt_left % 5;
}

void disp_reciept_vals_to_clerk(char isle_letter, double item_price, 
        double amt_paid, double change_amt,
        int hundered_num, int fifty_num, int twenty_num, int ten_num, 
        int five_num, int one_num, int fifty_cent_num, int quarter_num, 
        int dime_num, int nickel_num, int penny_num)
{
    cout << "\n\n" << setw(27) << "SUPER COSTUME STORE\n";
    cout << "             RECIEPT\n\n";
    cout << left << setw(20) << "Item Isle" << right << setw(7) 
            << isle_letter << '\n';
    cout << left << setw(20) << "Total" << right << setw(7) 
            << item_price << '\n';
    cout << left << setw(20) << "Amount Tendered" << right << setw(7) 
            << amt_paid << '\n';
    cout << left << setw(20) << "Change"  << right << setw(7)  
            << change_amt << "\n\n";
    cout << "Bills: 100 50 20 10  5  1" << '\n';
    cout << "Number: " << right << setw(2) << hundered_num << " " << setw(2) 
            << fifty_num << " " << right << setw(2) << twenty_num << " " 
            << right << setw(2) << ten_num << " " << right << setw(2) 
            << five_num << " " << right << setw(2) << one_num << '\n' ;
    cout << "Coins: 50  25  10  5   1\n";
    cout << "Number: " << fifty_cent_num << "   " << quarter_num << "   " << 
            dime_num << "  " << nickel_num << "   " <<
            penny_num << '\n' ;
    cout << "        CKing\n";
    cout << "       CIS 116";

}












