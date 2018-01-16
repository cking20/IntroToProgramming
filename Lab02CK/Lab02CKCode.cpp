/*
 * File:   Lab03CKCode.cpp
 * Author: Christopher King
 *
 * Created on September 18, 2014, 11:15 AM
 * Due on September 25, 2014, 10:00 AM
 * Discription: This labs purpose is to familiarize us new programmers in the
 * proper implementation of basic functions within a program. For example, 
 * for this lab it is required to have a correct prototype, call, and 
 * definition in order to have a working program. The reason such a thing
 * is so useful in programming language is that it allows information to be 
 * protected, and for the code to be recyclable and much more modular. 
 */

#include <iostream>
#include <iomanip>

using namespace std;

const double SALES_TAX_RATE = 0.0815;
const double CLEARING_RATE_MIN = 0.05;

void get_lawn_values_from_cust(int &,int &, double &, char &);
void calc_labor_costs (double &, int, int, double, double &, double &);
void disp_labor_rpt_hdr_to_cust();
void disp_labor_costs_to_cust(char, double, double, double);

int main(void) {
    int lawn_1_lenght_ft, lawn_2_lenght_ft, lawn_1_width_ft, lawn_2_width_ft;

    double min_to_clear_1, min_to_clear_2, clear_price_1, clear_price_2, 
            sales_tax_amt_1, sales_tax_amt_2, clear_cost_1, clear_cost_2;

    char lawn_1_desig, lawn_2_desig;


    get_lawn_values_from_cust(lawn_1_lenght_ft, lawn_1_width_ft, 
            min_to_clear_1, lawn_1_desig);
    get_lawn_values_from_cust(lawn_2_lenght_ft, lawn_2_width_ft, 
            min_to_clear_2, lawn_2_desig);

    calc_labor_costs (clear_price_1, lawn_1_lenght_ft, lawn_1_width_ft, 
            min_to_clear_1, sales_tax_amt_1, clear_cost_1 );
    calc_labor_costs (clear_price_2, lawn_2_lenght_ft, lawn_2_width_ft, 
            min_to_clear_2, sales_tax_amt_2, clear_cost_2 );

    disp_labor_rpt_hdr_to_cust();

    disp_labor_costs_to_cust(lawn_1_desig, clear_price_1, 
            sales_tax_amt_1, clear_cost_1);
    disp_labor_costs_to_cust(lawn_2_desig, clear_price_2, 
            sales_tax_amt_2, clear_cost_2);

    cout << "                   Chris King\n";
    cout << "                   CIS 116 1\n";

    return 0;
}

void get_lawn_values_from_cust(int &lawn_lenght_ft,int &lawn_width_ft, 
        double &min_to_clear, char &lawn_desig)
{
    cout << "Lawn Designation:  ";
    cin >> lawn_desig;
    cout << "\nLawn Length:  ";
    cin >> lawn_lenght_ft;
    cout << "\nLawn Width:  ";
    cin >> lawn_width_ft;
    cout << "\nMinuets to clear:  ";
    cin >> min_to_clear;
    cout << '\n';

}

void calc_labor_costs (double &clear_price, int lawn_lenght_ft, 
        int lawn_width, double min_to_clear, double &sales_tax_amt, 
        double &clear_cost )
{
    clear_price = lawn_lenght_ft * lawn_width * min_to_clear *
            CLEARING_RATE_MIN;
    sales_tax_amt = SALES_TAX_RATE * clear_price;  //define these
    clear_cost = clear_price + sales_tax_amt;

}

void disp_labor_rpt_hdr_to_cust()
{
    cout << "------------------------------------------------------------\n";
    cout << "\n                    OAK KING\n";
    cout << "              Better Than Leaf King\n";
    cout << "Lawn       Price       Tax Amount      Total Cost\n\n";
}

void disp_labor_costs_to_cust(char lawn_desig, double clear_price,
        double sales_tax_amt, double clear_cost)
{
    cout << setprecision(2) << fixed;
    cout << "  " << lawn_desig <<":       "<< clear_price <<"             "
            << sales_tax_amt <<"           "<< clear_cost << '\n';

}


















