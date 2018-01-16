/* 
 * File:   Lab00CK.cpp
 * Programmer: Christopher
 * Due: Thursday, September 11, 2014 at 10:10 am
 * Created on September 4, 2014, 11:41 AM
 * Description: This lab will show us how to do minor calculations 
 *              and gain a better understanding of cout. It is also laying 
 *              down a basis of how to properly use net beans for future labs 
 *              and the format in which we should use. This will also provide 
 *              good feedback in which we can improve upon in future labs.
 */
#include <iostream>
#include <iomanip>

using namespace std;

const double SALES_TAX_RATE = 0.0775;

int main(void) {
    
    double TabletPrice, EBookAvgPrice, EBookNum, EBookCost, SubTotalCost, 
           SalesTaxAmount, TotalCost;
    
    //Set Supply Values
    TabletPrice = 225.25;
    EBookAvgPrice = 80;
    EBookNum = 5;
    
    //Calc Total Costs
    EBookCost = EBookAvgPrice * EBookNum;
    SubTotalCost = EBookCost + TabletPrice;
    SalesTaxAmount = SALES_TAX_RATE * SubTotalCost;
    TotalCost = SubTotalCost + SalesTaxAmount;
    
    //Disp Total Costs to Student
    cout << setprecision(2) << fixed;
    cout << "       King Co." << endl;
    cout << "    Cost Summery" << endl;
    cout << "Tablet    :   " << TabletPrice << endl;
    cout << "Books     :   " << EBookCost << endl;
    cout << "Sub-Total :   " << SubTotalCost << endl;
    cout << "Tax amount:    " << SalesTaxAmount << endl;
    cout << "Total     :   " << TotalCost << endl;
    cout << "      CK King " << endl;
    cout << "      CIS 116 " << endl << endl;
    return 0;
}

