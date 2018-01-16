/* 
 * File:   Lab07CKCode.cpp
 * Author: Christopher King
 * Due : November 3rd 2014
 *
 * Created on October 28, 2014, 12:50 PM
 * Description: This program generates a receipt for a hotel user. It takes 
 * input form 2 clerks and generates it on one report. It runs the prompt 
 * multiple times to get input for every charge. Now it prompts for a file
 * name and now reads in strings.
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

const int SIZE = 80;
const double TAX_RATE = 0.0795;

void get_file_names_from_clerc(char [80], char [80]);
void get_cust_info_from_file(char [80], ifstream &,char [SIZE],int &, 
        char [SIZE], char [SIZE], char [SIZE], char [SIZE], char [SIZE], 
        char [SIZE], char [SIZE], char[1], char [SIZE]);
void dist_cust_info_to_cust_reciept(ofstream &,char [SIZE],int ,
        char [SIZE],char [SIZE],char [SIZE],
        char [SIZE],char [1]);
void get_charge_info_from_file(ifstream &,char [SIZE], double &);
void accumulate_charge_info(double &, double);
void disp_charge_info_to_cust_receipt(ofstream &,char [SIZE], double);
void process_each_charge(char [80], ofstream &,char [SIZE], double &);
void calc_total_charges(double &, int, double &, double &, double &);
void disp_total_cost_of_credit_to_cust_reciept(ofstream &,double ,double ,
        double ,double ,char [SIZE],char [SIZE], char [SIZE], char [SIZE]);

int main() {

    char room_num[SIZE], cust_name[SIZE], 
            street_adress[SIZE], csz[SIZE], phone_num[SIZE], 
            credit_type[SIZE], credit_num[SIZE], credit_exp[SIZE], 
            pet_prefer[1], clerk_initals[SIZE], charge_discr[SIZE],
            guest_info_file_name[80], bill_info_file_name[80];
    
    int nights_stayed;
    double total_charges, sub_total_price, sales_tax_amt, total;
    ofstream cust_receipt;
    ifstream guest_info;
    
    get_file_names_from_clerc(guest_info_file_name, bill_info_file_name);
    get_cust_info_from_file(guest_info_file_name, guest_info, room_num, 
            nights_stayed,cust_name, street_adress, csz, phone_num, 
            credit_type, credit_num, credit_exp, pet_prefer, clerk_initals);
    
    dist_cust_info_to_cust_reciept(cust_receipt, room_num, nights_stayed,
            cust_name, street_adress, csz, phone_num, pet_prefer);
   
    process_each_charge(bill_info_file_name, cust_receipt,charge_discr, 
            total_charges);
    
    calc_total_charges(total_charges, nights_stayed, sub_total_price, 
            sales_tax_amt, total);
    
    disp_total_cost_of_credit_to_cust_reciept(cust_receipt,total_charges,
            sub_total_price, sales_tax_amt,total, credit_type, credit_num,
            credit_exp,cust_name);
    
    return 0;
}

void get_file_names_from_clerc(char guest_info_file_name[80], 
        char bill_info_file_name[80])
{
    cout << "Guest Info File: ";
    cin >> guest_info_file_name;
    cout << "Bill Info File: ";
    cin >> bill_info_file_name;
    
            
}

void get_cust_info_from_file(char guest_info_file_name[80], 
        ifstream &guest_info, char room_num[SIZE],int &nights_stayed,
        char cust_name[SIZE],char street_adress[SIZE],char csz[SIZE],
        char phone_num[SIZE],char credit_type[SIZE],char credit_num[SIZE],
        char credit_exp[SIZE],char pet_prefer[1],char clerk_initals[SIZE])
{
    guest_info.open(guest_info_file_name);
    //cout << "\nRoom Number: ";
    guest_info >> room_num;
    //cout << "\nNights Staying: ";
    guest_info >> nights_stayed;
    guest_info.ignore(1000,'\n');
    //cout << "\nCustomer Name: ";
    guest_info.getline(cust_name, 80);
    //cout << "\nStreet Adress: ";
    guest_info.getline(street_adress, 80);
    //cout << "\nCity, State, Zip: ";
    guest_info.getline(csz, 80);
    //cout << "\nPhone Number: ";
    guest_info >> phone_num;
    //cout << "\nCredit Card Type: ";
    guest_info >> credit_type;
    //cout << "\nCard Number: ";
    guest_info >> credit_num;
    //cout << "\nExpiration Date(MM/YY): ";
    guest_info >> credit_exp;
    //cout << "\nPet Room(Y/N): ";
    guest_info >> pet_prefer;
    //cout << "\nClerk Initials: ";
    guest_info >> clerk_initals;
    
    guest_info.close();
}

void dist_cust_info_to_cust_reciept(ofstream &cust_receipt, 
        char room_num[SIZE],int nights_stayed,
        char cust_name[SIZE],char street_adress[SIZE],char csz[SIZE],
        char phone_num[SIZE],char pet_prefer[1])
{
    cust_receipt.open(("Customer_Receipt.txt"));
    cout << setprecision(2) << fixed;
    cust_receipt << setw(8) << "" << "Interruptive House Cleaning Hotel" 
            << endl;
    cust_receipt << setw(15) << "" << "Customer Receipt" << endl << endl;
    cust_receipt << setw(40) <<  cust_name << endl;
    cust_receipt << setw(40) <<  street_adress  << endl;
    cust_receipt << setw(40) <<  phone_num << endl;
    cust_receipt << setw(40) <<  csz << endl;
    cust_receipt << endl << left << setw(5) << "" << setw(30) <<"Room Number:" 
            << right << setw(5) << room_num << endl;
            //the setw(5) is more or less a tab, i wanted the reciept to be 
            //indented on the file
    cust_receipt << endl << left << setw(5) << "" << setw(30) 
            <<"Nights Stayed:" << right << setw(5) << nights_stayed << endl;
    cust_receipt << endl << left << setw(5) << "" << setw(30) 
            <<"Pet Preference:" << right << setw(5)  << pet_prefer << endl;
       
}

void process_each_charge( char bill_info_file_name[80], 
        ofstream &cust_receipt,char charge_discr[SIZE], 
        double &total_charges)
{
    double charge_amt = 0;
    int num_charges, count;
    count = 0;
    num_charges = 3;
    total_charges = 0;
    ifstream bill_info;
    bill_info.open(bill_info_file_name);
    
    for (count; count < num_charges; count++)
    {
        get_charge_info_from_file(bill_info, charge_discr, charge_amt);
        accumulate_charge_info(total_charges, charge_amt);
        disp_charge_info_to_cust_receipt(cust_receipt,charge_discr, 
                charge_amt);
    } 
}

void get_charge_info_from_file(ifstream &bill_info, char charge_discr[SIZE], 
        double &charge_amt)
{
    //cout << "\nCharge description: ";
    bill_info >> charge_discr;
    //cout << "\nCharge amount: ";
    bill_info >> charge_amt;
}
     
void accumulate_charge_info(double &total_charges, double charge_amt) 
{
    total_charges = total_charges + charge_amt;
}

void disp_charge_info_to_cust_receipt(ofstream &cust_receipt,
        char charge_discr[SIZE], double charge_amt)
{
    cust_receipt << endl << left << setw(5) << "" << setw(28) << charge_discr 
            << right<< setw(7)  << charge_amt << endl;
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
            <<"Sales Tax Rate:" << right << setw(5) << "" << setw(14) 
            << TAX_RATE << '%' << endl;
    cust_receipt << setprecision(4) << fixed;
    cust_receipt << endl << left << setw(5) << "" << setw(15) 
            <<"Sales Tax Amt:" << right << setw(5) << "" << setw(15) 
            << sales_tax_amt << endl;
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
            <<"Expiration Date:" << right << setw(5) << "" << setw(15) 
            << credit_exp << endl;
    cust_receipt << endl << left << setw(5) << "" << setw(15) 
            << "Amount Charged to " << setw(9) << credit_num << ":"<< right  
            << setw(8)  << total << endl;
    cust_receipt << endl;
    cust_receipt << endl;
    cust_receipt << endl << left << setw(10) << "" << setw(15)
            <<"____________________________" << endl;
    cust_receipt << endl << left << setw(15) << "" << setw(15) 
            <<"(Signature)" << endl;
    cust_receipt << endl << left << setw(15) << "" << setw(15) <<cust_name;
}

