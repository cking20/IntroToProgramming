/*
 * File:   Lab03CKcode.cpp
 * Author: Christopher
 * Due: October 2, 2014, 10:10 AM
 * Created on September 25, 2014, 10:36 AM
 * Description: This program aides the designed user(painters) in calculating
 * out paint estimates. This program is designed to allow the painters to 
 * take more time to do their job and less time calculating and worrying
 * about  ordering too much paint. This program also displays the information
 * neatly to the painters
 */
#include <iostream>

using namespace std;

/*
 *
 */

void set_building_dim(int &, int &, int &, int &, int &, int &, int &);
void set_trim_dim(int &, int &, int &, int &, int &, int &, int &, int &, 
        int &, int &, int &, int &, int &, double &);
void set_paint_vals(int &);
void calc_unpainted_area(int &, int, int, int, int &, int, int, int,
        int, int, int, int, int &);
void calc_trim_area(int, int, int, int &, int, int, double, double,
        double, int, int, int, double, int, int, int, double, int, int,
        int, double &);
void calc_wall_area(int, int, int, int ,int, int, int, double,
        int, int, double &, double, double);
void calc_paint_amts(int &, double , int , double , int &);
void disp_paint_amts_to_painters(int, int);



int main() {
    //vals for set_building_dim
    int wall_front_width, wall_side_width, wall_height, wall_gable_height,
            wall_front_num, wall_side_num, wall_gable_num;
    //vals for set_trim_dim
    int win_sm_width, win_sm_height, win_sm_num, win_lg_width, win_lg_height,
            win_lg_num, door_width, door_height, door_num, trim_gable_lenght,
            trim_gable_num, trim_wall_side_lenght, trim_wall_side_num;
    double trim_width;
    //defs for set_paint_vals
    int paint_gal_coverage;
    //defs for calc_unpainted_area
    int win_sm_area, win_lg_area, door_area, unpainted_area;
    //defs for calc_trim_area
    double trim_roof_tot_area, trim_win_sm_area, trim_win_lg_area, 
            trim_door_area, trim_tot_area;
    int trim_wall_side_tot, trim_gable_lenght_tot;
    //defs for calc_wall_area
    int wall_front_area, wall_side_area;
    double wall_gable_area, wall_area;
    //defs for calc_paint_amts
    int trim_paint_gal, wall_paint_gal;

    set_building_dim(wall_front_width, wall_side_width, wall_height,
            wall_gable_height, wall_front_num, wall_side_num, wall_gable_num);

    set_trim_dim(win_sm_width, win_sm_height, win_sm_num, win_lg_width,
            win_lg_height, win_lg_num, door_width, door_height, door_num,
            trim_gable_lenght, trim_gable_num, trim_wall_side_lenght, 
            trim_wall_side_num, trim_width);
    set_paint_vals(paint_gal_coverage);

    calc_unpainted_area(win_sm_area,  win_sm_width,  win_sm_height,
            win_sm_num,  win_lg_area,  win_lg_width,  win_lg_height,  
            win_lg_num, door_area,  door_width,  door_height,  door_num,  
            unpainted_area);

    calc_trim_area(trim_wall_side_tot, trim_wall_side_lenght, 
            trim_wall_side_num, trim_gable_lenght_tot,trim_gable_lenght, 
            trim_gable_num, trim_roof_tot_area, trim_width, trim_win_sm_area,
            win_sm_width, win_sm_height, win_sm_num, trim_win_lg_area,
            win_lg_width, win_lg_height, win_lg_num, trim_door_area, 
            door_width, door_height, door_num, trim_tot_area);

    calc_wall_area(wall_front_area, wall_front_width, wall_height, 
            wall_front_num, wall_side_area, wall_side_width, wall_side_num,
            wall_gable_area, wall_gable_height, wall_gable_num, 
            wall_area, trim_tot_area, unpainted_area);
    
    calc_paint_amts(trim_paint_gal, trim_tot_area, paint_gal_coverage, 
            wall_area, wall_paint_gal);
    
    disp_paint_amts_to_painters(wall_paint_gal, trim_paint_gal);

    //diagnostic writes
    //cout << wall_front_width;
    //cout << win_sm_width;
    return 0;
}

void set_building_dim(int &wall_front_width, int &wall_side_width,
        int &wall_height, int &wall_gable_height, int &wall_front_num,
        int &wall_side_num, int &wall_gable_num)
{
    wall_front_width = 14;
    wall_side_width = 20;
    wall_height = 20;
    wall_gable_height = 16;
    wall_front_num = 2;
    wall_side_num = 2;
    wall_gable_num = 2;

}

void set_trim_dim(int &win_sm_width,int &win_sm_height,int &win_sm_num,
        int &win_lg_width,int &win_lg_height,int &win_lg_num, int &door_width,
        int &door_height, int &door_num, int &trim_gable_lenght,
        int &trim_gable_num,int &trim_wall_side_lenght,
        int &trim_wall_side_num, double &trim_width)
{
    win_sm_width = 3;
    win_sm_height = 4;
    win_sm_num = 10;
    win_lg_width = 9;
    win_lg_height = 4;
    win_lg_num = 1;//*
    door_width = 3;
    door_height = 6;
    door_num = 1;
    trim_gable_lenght = 10;
    trim_gable_num = 4;
    trim_wall_side_lenght = 20;
    trim_wall_side_num = 2;
    trim_width = 0.5;
}

void set_paint_vals(int &paint_gal_coverage)
{
    paint_gal_coverage = 100;
}

void calc_unpainted_area(int &win_sm_area, int win_sm_width, 
        int win_sm_height, int win_sm_num, int &win_lg_area, int win_lg_width,
        int win_lg_height, int win_lg_num, int door_area, int door_width, 
        int door_height, int door_num, int &unpainted_area)
{
    win_sm_area = win_sm_width * win_sm_height * win_sm_num;
    win_lg_area = win_lg_width * win_lg_height * win_lg_num;
    door_area = door_width * door_height * door_num;
    unpainted_area = win_sm_area + win_lg_area + door_area;
}

void calc_trim_area(int trim_wall_side_tot, int trim_wall_side_lenght, 
        int trim_wall_side_num, int &trim_gable_lenght_tot,
        int trim_gable_lenght, int trim_gable_num, double trim_roof_tot_area, 
        double trim_width, double trim_win_sm_area,
        int win_sm_width, int win_sm_height, int win_sm_num, 
        double trim_win_lg_area, int win_lg_width, int win_lg_height, 
        int win_lg_num, double trim_door_area, int door_width, 
        int door_height, int door_num, double &trim_tot_area)
{
    trim_wall_side_tot = trim_wall_side_lenght * trim_wall_side_num;
    trim_gable_lenght_tot = trim_gable_lenght * trim_gable_num;
    trim_roof_tot_area = static_cast<double> (trim_wall_side_tot 
            + trim_gable_lenght_tot) * trim_width;
    trim_win_sm_area = static_cast<double> (2 * (win_sm_width + win_sm_height
            + (2 * trim_width)) * win_sm_num) * trim_width;
    trim_win_lg_area = static_cast<double> (2 * (win_lg_width + win_lg_height
            + (2 * trim_width)) * win_lg_num) * trim_width;
    trim_door_area = static_cast<double> (2 * (door_width + door_height
            + (2 * trim_width)) * door_num) * trim_width;
    trim_tot_area = trim_roof_tot_area + trim_win_sm_area + trim_win_lg_area
            + trim_door_area;

}

void calc_wall_area(int wall_front_area, int wall_front_width, 
        int wall_height, int wall_front_num, int wall_side_area, 
        int wall_side_width, int wall_side_num, double wall_gable_area,
        int wall_gable_height, int wall_gable_num, double &wall_area, 
        double trim_tot_area, double unpainted_area)
{
    wall_front_area = wall_front_width * wall_height * wall_front_num;
    wall_side_area = wall_side_width * wall_height * wall_side_num;
    wall_gable_area = 0.5 * wall_front_width * wall_gable_height 
            * wall_gable_num;
    wall_area = (wall_front_area + wall_side_area + wall_gable_area) 
            - (trim_tot_area + unpainted_area);
}

void calc_paint_amts(int &trim_paint_gal, double trim_tot_area, 
        int paint_gal_coverage, double wall_area, int &wall_paint_gal)
{
    trim_paint_gal = static_cast<int>((trim_tot_area / 
            paint_gal_coverage) + 0.5) + 1;
    
    wall_paint_gal = static_cast<int>((wall_area /
            paint_gal_coverage) + 0.5) + 1;
}

void disp_paint_amts_to_painters(int wall_paint_gal, int trim_paint_gal)
{
    cout << "       King Painters\n";
    cout << "      Paint Estimates\n";
    cout << "-----------------------------\n";
    cout << "Color                 Gallons\n\n";
    cout << "Yellow Wall Paint :       " << wall_paint_gal << '\n';
    cout << "Purple Trim Paint :        " << trim_paint_gal << '\n';
    
    cout << "\n\n          C King\n";
    cout << "          CIS 116\n\n";
            
    
}
    




















