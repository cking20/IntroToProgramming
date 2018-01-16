/* 
 * File:   main.cpp
 * Author: Christopher
 * Due:
 * Created on December 8, 2014, 9:42 PM
 * Description: This program asks for user info. It then goes into a
 *  file and checks to see that the car data pulled form the file is what the
 *  user wants. It then generates a repot including all the cars that match
 *  the description
 * 
 * 
 * 
 * 
 */

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void process_each_consumer();
void get_run_again( char [80]);
void get_user_bill_info(char [80], char [80], char [80], char [80]);
void get_car_preferances_from_consumer(int &, int &, double &, double &, 
        char [80]);
void disp_searcher_info_to_rpt_file(ofstream &, int , int , double , double , 
        char [80], char [80], char [80], 
        char [80], char [80]);
void process_each_car(ifstream &, ofstream &, int ,  int , double , 
        double , char [80], int &);
void get_dealer_car_data_from_sales_file(ifstream &, 
        char [80], char [80], double &, int &);
void disp_match_car(ofstream &rpt_file, int , char [80], char [80], double );
void accum_matching_car_num(int &);
void disp_match_num(int , ofstream &, ifstream &);

int main(int argc, char** argv) {

    char  run_again[80];
    strcpy(run_again, "Yes");
    
    while (strcmp(run_again, "Yes") == 0)
    {
        
        process_each_consumer();
        get_run_again(run_again);    
    }
    
    return 0;
}

void process_each_consumer()
{
    int upper_year, lower_year, car_num;
    char car_class[80], cust_name[80], street_adress[80], csz[80],
            phone_num[80];
    double upper_price, lower_price;
    ifstream sales_file;
    ofstream rpt_file;
    
    rpt_file.open("Car_rpt.txt");
    get_user_bill_info( cust_name, street_adress, csz, phone_num);
    get_car_preferances_from_consumer(upper_year, lower_year, 
         upper_price, lower_price, car_class);
    disp_searcher_info_to_rpt_file(rpt_file, upper_year, 
         lower_year, upper_price, lower_price, 
         car_class, cust_name, street_adress, 
         csz, phone_num);
    cout << "Starting process each car";
    process_each_car(sales_file, rpt_file, 
         upper_year,  lower_year,  upper_price, 
         lower_price,  car_class,  car_num);
    disp_match_num( car_num, rpt_file, sales_file);
}

void get_run_again( char run_again[80])
{
    cout << "Run Again? (Yes/No)\n";
    cin >> run_again;
}

void get_user_bill_info(char cust_name[80], char street_adress[80], 
        char csz[80], char phone_num[80])
{
    cout << "What is your name: ";
    cin.getline(cust_name, 80);
    cout << "\nStreet Adress: ";
    cin.getline(street_adress, 80);
    cout << "\nCity, State, Zip: ";
    cin.getline(csz, 80);
    cout << "\nPhone Number: ";
    cin.getline(phone_num, 80);
}
void get_car_preferances_from_consumer(int &upper_year, int &lower_year, 
        double &upper_price, double &lower_price, char car_class[80])
{
    cout << "\nUpper Year Range: ";
    cin >> upper_year;
    cout << "\nLower Year Range: ";
    cin >> lower_year;
    cout << "\nUpper Price Range: ";
    cin >> upper_price;
    cout << "\nLower Price Range: ";
    cin >> lower_price;
    cin.ignore(1000,'\n');
    cout << "\nType(Diesel, Electric, Gas, or Hybrid): ";
    cin.getline(car_class, 80);    
    cout << "it got to past the .getline";
}

void disp_searcher_info_to_rpt_file(ofstream &rpt_file, int upper_year, 
        int lower_year, double upper_price, double lower_price, 
        char car_class[80], char cust_name[80], char street_adress[80], 
        char csz[80], char phone_num[80])
{
    rpt_file << setw(30) << "King's Automotive Emporium ";
    rpt_file << setw(25) << "\nConsumer Search Report\n";
    rpt_file << setw(40) <<  cust_name << endl;
    rpt_file << setw(40) <<  street_adress  << endl;
    rpt_file << setw(40) <<  csz << endl;
    rpt_file << setw(40) <<  phone_num << endl;
    rpt_file << setw(25) << "\nBuyer Preferences ";
    rpt_file << "\nUpper Year Range : ";
    rpt_file << setw(10) << upper_year;
    rpt_file << "\nLower Year Range : ";
    rpt_file << setw(10) << lower_year;
    rpt_file << "\nUpper Price Range: ";
    rpt_file << setw(10) << upper_price;
    rpt_file << "\nLower Price Range: ";
    rpt_file << setw(10) << lower_price;
    rpt_file << "\nCar Fuel Type    : ";
    rpt_file << setw(10) << car_class; 
    rpt_file << setw(5) << "\nYear" << setw(21) << right <<"Name" << setw(10) 
            <<"Class" << setw(10) << "Price" << endl;
}

void process_each_car(ifstream &sales_file, ofstream &rpt_file, 
        int upper_year, int lower_year, double upper_price, 
        double lower_price, char car_class[80], int &car_num)
{
    char car_name[80], dlr_car_class[80];
    double car_price; 
    int car_year;
    car_num = 0;
    sales_file.open("CK Car Inv.txt");
    get_dealer_car_data_from_sales_file(sales_file, car_name, 
            dlr_car_class, car_price, car_year); 
    
    cout << "starting loop";
    while (!sales_file.eof()) { 
        
        if (car_year <= upper_year && car_year >= lower_year && 
                car_price <= upper_price && car_price >= lower_price && 
                strcmp(car_class, dlr_car_class) == 0)
        {
            
          
            disp_match_car(rpt_file, car_year, car_name, dlr_car_class, 
                    car_price);
            rpt_file << setw(5) << left << car_year << right << setw(20) 
                    << car_name << setw(10) << dlr_car_class << setw(10) 
                    << car_price << endl; 
             get_dealer_car_data_from_sales_file(sales_file, 
               car_name, dlr_car_class, car_price, car_year);
        }
        
            
       accum_matching_car_num(car_num);
       get_dealer_car_data_from_sales_file(sales_file, 
               car_name, dlr_car_class, car_price, car_year);
    }
}

void get_dealer_car_data_from_sales_file(ifstream &sales_file, 
        char car_name[80], char dlr_car_class[80], double &car_price, 
        int &car_year)
{
    sales_file.getline(car_name, 80);
    sales_file >> dlr_car_class;
    sales_file >> car_price;
    sales_file >> car_year;
    sales_file.ignore(1000, '\n');
            
}
void disp_match_car(ofstream &rpt_file, int car_year, char car_name[80], 
        char dlr_car_class[80], double car_price){
    rpt_file << setw(5) << left << car_year << right << setw(20) 
                    << car_name << setw(10) << dlr_car_class << setw(10) 
                    << car_price << endl; 
}
void disp_match_num(int car_num, ofstream &rpt_file, ifstream &sales_file)
{
    rpt_file << "\nTotal Matches: " << car_num;
    rpt_file.close();
    sales_file.close();
            
}
void accum_matching_car_num(int &car_num){
    car_num = car_num + 1;
}
    