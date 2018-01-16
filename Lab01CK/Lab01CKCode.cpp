/*
 * File:   Lab01CKCode.cpp
 * Author: Christopher King
 *
 * Created on September 11, 2014, 1:05 PM
 * Description: This program is designed to determine the ideal method of 
 * purchasing the materials required to fill a planned court. The program 
 * computes the prices for each method and each material, but it is up to the
 * user to determine what the best choice is. This program also is designed 
 * so that we, as new programmers, can continue to develop our skills of 
 * appropriate use of ints and doubles. 
 */

#include <iostream>
#include <iomanip>

using namespace std;

const double SALES_TAX_RATE =.0825;

int main(void) {

    int court_lgth_ft, court_wdth_ft, gravel_depth_ft, truck_lgth_ft,
            truck_wdth_ft, truck_hdth_ft, gravel_volume_cu_ft,
            truck_volume_cu_ft;
    double sand_depth_ft, truck_load_gravel_price,truck_load_sand_price ,
            cu_yd_gravel_price, cu_yd_sand_price, sand_volume_cu_ft,
            cu_ft_gravel_price, cu_ft_sand_price, gravel_truck_num,
            sand_truck_num, gravel_truck_cost, gravel_truck_tax_amt,
            sand_truck_tax_amt, sand_truck_cost ,gravel_truck_tot,
            sand_truck_tot, gravel_vol_cost, sand_vol_cost,
            gravel_vol_tax_amt, sand_vol_tax_amt, gravel_vol_tot_cost,
            sand_vol_tot_cost;

    //Set Court Dimensions
    court_lgth_ft = 79;
    court_wdth_ft = 50;
    gravel_depth_ft = 2;
    sand_depth_ft = 1.5;

    //Set Material Values
    truck_lgth_ft = 25;
    truck_wdth_ft = 9;
    truck_hdth_ft = 6;
    truck_load_gravel_price = 225.00;
    truck_load_sand_price = 115.00;
    cu_yd_gravel_price = 3.85;
    cu_yd_sand_price = 2.75 ;

    //Calc Material Volumes
    gravel_volume_cu_ft = court_lgth_ft * court_wdth_ft * gravel_depth_ft;
    sand_volume_cu_ft = court_lgth_ft * court_wdth_ft * sand_depth_ft;
    
    truck_volume_cu_ft = truck_lgth_ft * truck_wdth_ft * truck_hdth_ft;
    
    cu_ft_gravel_price = cu_yd_gravel_price / 27;
    cu_ft_sand_price = cu_yd_sand_price / 27;

    //Calc Material Costs
    gravel_truck_num = gravel_volume_cu_ft / truck_volume_cu_ft;
    sand_truck_num = sand_volume_cu_ft / truck_volume_cu_ft;
    
    gravel_truck_cost = gravel_truck_num * truck_load_gravel_price;
    sand_truck_cost = sand_truck_num * truck_load_sand_price;
    
    gravel_truck_tax_amt = gravel_truck_cost * SALES_TAX_RATE;
    sand_truck_tax_amt = sand_truck_cost * SALES_TAX_RATE;
    
    gravel_truck_tot = gravel_truck_cost + gravel_truck_tax_amt;
    sand_truck_tot = sand_truck_cost + sand_truck_tax_amt;
    
    gravel_vol_cost = gravel_volume_cu_ft * cu_ft_gravel_price;
    sand_vol_cost = sand_volume_cu_ft * cu_ft_sand_price;
    
    gravel_vol_tax_amt = gravel_vol_cost * SALES_TAX_RATE;
    sand_vol_tax_amt = sand_vol_cost * SALES_TAX_RATE;
    
    gravel_vol_tot_cost = gravel_vol_cost + gravel_vol_tax_amt;
    sand_vol_tot_cost = sand_vol_cost + sand_vol_tax_amt;

    //Disp Material Costs to Owner
     cout<< setprecision(2) << fixed;
     cout << "        King's Quarry Trucking Co.      \n";
     cout << "              Cost Analysis             \n";
     cout << "----------------------------------------\n";
     cout << "|          Truck load | Square Yard    |\n";
     cout << "|                     |                |\n";
     cout << "| Gravel:     " << gravel_truck_tot << " |     " 
             << gravel_vol_tot_cost << "    |\n";
     cout << "| Sand  :      " << sand_truck_tot << " |      " 
             << sand_vol_tot_cost << "    |\n";
     cout << "----------------------------------------\n";
     cout << "\n               CK CIS116 1\n";

    return 0;
}

