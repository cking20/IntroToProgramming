/* 
 * File:   Lab07CKCode.cpp
 * Author: Christopher King
 * Due : November 3rd 2014
 *
 * Created on October 28, 2014, 12:50 PM
 * Description: This program generates a receipt for a hotel user. It take 
 * input form 2 clerks and generates it on one report. It runs the prompt 
 * multiple times to get input for every charge
 */

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

const int SIZE = 80;
const double TAX_RATE = .0795;

void get_cust_info_from_clerc(char [SIZE],int &, char [SIZE],
        char [SIZE],char [SIZE], char [SIZE],char [SIZE],char [SIZE],
        char [SIZE],char [SIZE],char [SIZE]);
void dist_cust_info_to_cust_reciept(ofstream &,char [SIZE],int ,
        char [SIZE],char [SIZE],char [SIZE],
        char [SIZE],char [SIZE]);
void get_charge_info_from_clerc(char [SIZE], double &);
void accumulate_charge_info(double &, double);
void disp_charge_info_to_cust_receipt(ofstream &,char [SIZE], double);
void process_each_charge(ofstream &,char [SIZE], double &, double &);
void calc_total_charges(double &, int, double &, double &, double &);
void disp_total_cost_of_credit_to_cust_reciept(ofstream &,double ,double ,
        double ,double ,char [SIZE],char [SIZE], char [SIZE], char [SIZE]);

int main(int argc, char** argv) {

    char room_num[SIZE], cust_name[SIZE], 
            street_adress[SIZE], csz[SIZE], phone_num[SIZE], 
            credit_type[SIZE], credit_num[SIZE], credit_exp[SIZE], 
            pet_prefer[SIZE], clerk_initals[SIZE], charge_discr[SIZE];
    
    int nights_stayed;
    double charge_amt, total_charges, sub_total_price, sales_tax_amt, total;
    ofstream cust_receipt;
    
    get_cust_info_from_clerc(room_num, nights_stayed,cust_name, 
             street_adress, csz, phone_num, credit_type, credit_num, 
             credit_exp, pet_prefer, clerk_initals);
    
    dist_cust_info_to_cust_reciept(cust_receipt, room_num, nights_stayed,
            cust_name, street_adress, csz, phone_num, pet_prefer);
   
    process_each_charge(cust_receipt,charge_discr, total_charges, charge_amt);
    
    calc_total_charges(total_charges, nights_stayed, sub_total_price, 
            sales_tax_amt, total);
    
    disp_total_cost_of_credit_to_cust_reciept(cust_receipt,total_charges,
            sub_total_price, sales_tax_amt,total, credit_type, credit_num,
            credit_exp,cust_name);
    
    return 0;
}

void get_cust_info_from_clerc(char room_num[SIZE],int &nights_stayed,
        char cust_name[SIZE],char street_adress[SIZE],char csz[SIZE],
        char phone_num[SIZE],char credit_type[SIZE],char credit_num[SIZE],
        char credit_exp[SIZE],char pet_prefer[SIZE],char clerk_initals[SIZE])
{
    cout << "\nRoom Number: ";
    cin >> room_num;
    cout << "\nNights Staying: ";
    cin >> nights_stayed;
    cout << "\nCustomer Name: ";
    cin >> cust_name;
    cout << "\nStreet Adress: ";
    cin >> street_adress;
    cout << "\nCity, State, Zip: ";
    cin >> csz;
    cout << "\nPhone Number: ";
    cin >> phone_num;
    cout << "\nCredit Card Type: ";
    cin >> credit_type;
    cout << "\nCard Number: ";
    cin >> credit_num;
    cout << "\nExpiration Date(MM/YY): ";
    cin >> credit_exp;
    cout << "\nPet Room(Y/N): ";
    cin >> pet_prefer;
    cout << "\nClerk Initials: ";
    cin >> clerk_initals;
}

void dist_cust_info_to_cust_reciept(ofstream &cust_receipt, 
        char room_num[SIZE],int nights_stayed,
        char cust_name[SIZE],char street_adress[SIZE],char csz[SIZE],
        char phone_num[SIZE],char pet_prefer[SIZE])
{
    cout << setprecision(2) << fixed;
    cust_receipt.open(("Customer_Receipt"));
    cust_receipt << setw(10) << "" << "Interruptive House Cleaning Hotel" 
            << endl;
    cust_receipt << setw(15) << "" << "Customer Receipt" << endl;
    cust_receipt << setw(40) << "" << left << setw(30) << cust_name << endl;
    cust_receipt << setw(40) << "" << left << setw(30) << street_adress 
            << endl;
    cust_receipt << setw(40) << "" << left << setw(30) << csz << endl;
    cust_receipt << endl << left << setw(5) << "" << setw(15) <<"Room Number:" 
            << right << setw(5) << room_num << endl;
    cust_receipt << endl << left << setw(5) << "" << setw(15) 
            <<"Nights Stayed:" << right << setw(5) << nights_stayed << endl;
    cust_receipt << endl << left << setw(5) << "" << setw(15) 
            <<"Pet Preference:" << right << setw(5)  << pet_prefer << endl;
       
}

void process_each_charge(ofstream &cust_receipt,char charge_discr[SIZE], 
        double &total_charges, double &charge_amt)
{
    int num_charges = 3;
    total_charges = 0;
    
    for (int count = 0; count < num_charges; count++)
    {
        get_charge_info_from_clerc(charge_discr, charge_amt);
        accumulate_charge_info(total_charges, charge_amt);
        disp_charge_info_to_cust_receipt(cust_receipt,charge_discr, 
                charge_amt);
    } 
}

void get_charge_info_from_clerc(char charge_discr[SIZE], double &charge_amt)
{
    cout << "\nCharge description: ";
    cin >> charge_discr;
    cout << "\nCharge amount: ";
    cin >> charge_amt;
}
     
void accumulate_charge_info(double &total_charges, double charge_amt) 
{
    total_charges = (total_charges + charge_amt);
}

void disp_charge_info_to_cust_receipt(ofstream &cust_receipt,
        char charge_discr[SIZE], double charge_amt)
{
    cust_receipt << endl << left << setw(5) << "" << setw(15) << charge_discr 
            << right<< setw(5)  << charge_amt << endl;
}

void calc_total_charges( double &total_charges, 
        int nights_stayed, double &sub_total_price, double &sales_tax_amt,
        double &total)
{
    double room_cost, room_price;
    room_price = 55.95;
    room_cost = nights_stayed * room_price;
    sub_total_price = room_cost + total_charges;
    sales_tax_amt = sub_total_price * TAX_RATE;
    total = sub_total_price + sales_tax_amt;
}

void disp_total_cost_of_credit_to_cust_reciept(ofstream &cust_receipt,
        double total_charges, double sub_total_price, double sales_tax_amt,
        double total, char credit_type[SIZE],char credit_num[SIZE],
        char credit_exp[SIZE], char cust_name[SIZE])
{
    cust_receipt << endl << left << setw(5) << "" << setw(15) 
            <<"Total Charges:" << right << setw(5) << "" << setw(15) 
            << total_charges << endl;
    cust_receipt << endl << left << setw(5) << "" << setw(15) << "Sub Total:"
            << right << setw(5) << "" << setw(15) << sub_total_price << endl;
    cust_receipt << endl << left << setw(5) << "" << setw(15) 
            <<"Sales Tax Rate:" << right << setw(5) << "" << setw(15) 
            << TAX_RATE << endl;
    cust_receipt << setprecision(4) << fixed;
    cust_receipt << endl << left << setw(5) << "" << setw(15) <<"Sales Tax:" 
            << right << setw(5) << "" << setw(15) << sales_tax_amt << endl;
    cust_receipt << setprecision(2) << fixed;
    cust_receipt << endl << left << setw(5) << "" << setw(15) <<"Total:" 
            << right << setw(5) << "" << setw(15) << total << endl;
    cust_receipt << endl << left << setw(5) << "" << setw(15) 
            <<"----------------------------------" << endl;
    cust_receipt << endl << left << setw(5) << "" << setw(15) 
            <<"Credit Type :" <<  right << setw(5) << "" << setw(15) 
            << credit_type << endl;
    cust_receipt << endl << left << setw(5) << "" << setw(15) 
            <<"Card Number :" << right << setw(5) << "" << setw(15) 
            << credit_num << endl;
    cust_receipt << endl << left << setw(5) << "" << setw(15) 
            <<"Experation Date:" << right << setw(5) << "" << setw(15) 
            << credit_exp << endl;
    cust_receipt << endl << left << setw(5) << "" << setw(15) 
            << "Amount Charged to " << credit_num << ":"<< right  
            << setw(15)  << total << endl;
    cust_receipt << endl;
    cust_receipt << endl;
    cust_receipt << endl << left << setw(10) << "" << setw(15)
            <<"______________________________" << endl;
    cust_receipt << endl << left << setw(15) << "" << setw(15) 
            <<"(Signature)" << endl;
    cust_receipt << endl << left << setw(15) << "" << setw(15) <<cust_name;
}

