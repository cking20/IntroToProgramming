/*
 * File:   Lab09CKCode.cpp
 * Author: Christopher King
 * Due : Dec. 4th 10:00am
 * Created on December 1, 2014, 10:04 PM
 * Description: This program reads in ships and their data from a file. It 
 * then calculates the distance between each ship and the location of a 
 * ship in distress. It also shows the time it would take to get there.
 */

#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

void disp_distr_ship_info_to_rpt(ofstream &,char [80],char [80],
                    char [80], char [80], char [80], int, char [80]);

void get_distress_ship_data_from_cg_officer(char [80],
            char [80], char [80], char [80],
            int &,int &, int &, char [80], char [80]);

void calc_CG_responce_vals(int , int , int , int , int , double &, double &);

void get_data_from_ship_file(ifstream &, char [80],int &, int &, int &, int&);

void disp_CG_response_vals(ofstream &,
        char [80], int , int , int , int ,
        double , double );
void process_each_coast_gaurd_ship(ifstream &, int &, 
        int &,ofstream &, double &, double &,
        int &, int &, int &, int &, char [80]);

void disp_signature(ofstream &, char [80]);
int main(int argc, char** argv) {

    char distr_ship_name[80], distr_nature[80], date[80], time[80],
            rpt_file_name[80], officer[80], name[80];
    int num_to_rescue, x_pos,  y_pos, cg_x_pos, cg_y_pos, speed, capacity;
    double distance, arrival_time;
    ofstream rpt_file;
    ifstream ships_data;
    get_distress_ship_data_from_cg_officer( distr_ship_name,
             distr_nature,  date,  time,
             num_to_rescue, x_pos,  y_pos,  rpt_file_name, officer);

    disp_distr_ship_info_to_rpt(rpt_file,  rpt_file_name, distr_ship_name,
            distr_nature, date, time, num_to_rescue, officer);
    process_each_coast_gaurd_ship(ships_data, x_pos, y_pos, rpt_file, 
            distance, arrival_time, cg_x_pos, cg_y_pos, speed, capacity,
            name);
    disp_signature(rpt_file, officer);
    
    return 0;
}

void get_distress_ship_data_from_cg_officer(char distr_ship_name[80],
            char distr_nature[80], char date[80], char time[80],
            int &num_to_rescue,int &x_pos, int &y_pos, char rpt_file_name[80],
            char officer[80])
{
    cout << "\nName of Ship: ";
    cin.getline(distr_ship_name,80);
    cout << "\nNature of Distress: ";
    cin.getline(distr_nature,80);
    cout << "\nDate: ";
    cin.getline(date,80);
    cout << "\nTime: ";
    cin.getline(time,80);
    cout << "\nNumber to be Rescued: ";
    cin >> num_to_rescue;
    cout << "\nX position: ";
    cin >> x_pos;
    cout << "\nY position: ";
    cin >> y_pos;
    cout << "\nReport File Name: ";
    cin >> rpt_file_name;
    cout << "Officer: ";
    cin >> officer;

}

void disp_distr_ship_info_to_rpt(ofstream &rpt_file, char rpt_file_name[80],
        char distr_ship_name[80],
        char distr_nature[80], char date[80], char time[80],
        int num_to_rescue,  char officer[80] )
{
    rpt_file.open(rpt_file_name);

    rpt_file << setw(20) << "" << "Emergency Boat Rescue Squad\n"; 
    rpt_file << setw(25) << "" << "Coast Guard Tool\n";
    rpt_file << setw(30) << "" << "Officer on Duty : " << officer << endl;
    rpt_file << setw(30) << "" << "Time: " << time << endl;
    rpt_file << setw(30) << "" << "Date: " << date << endl;
    rpt_file << "\n\n\n";
    rpt_file << setw(15) << left <<"Ship in Distress:" << setw(20) << right 
            << distr_ship_name << endl;
    rpt_file << setw(15) << left << "Population:" << setw(20) << right 
            << num_to_rescue << endl;
    rpt_file << setw(15) << left <<"Nature of Distress:" << setw(20) << right
            <<distr_nature << endl << endl;
    rpt_file << setw(20) << "Ship" << setw(3) << "X" << setw(3) << "Y" 
            << setw(7) << "Speed" << setw(10) << "Capacity" << setw(10) 
            << "Distance" << setw(7) << "Time" << endl;
    rpt_file << setw(20) << "----" << setw(3) << "-" << setw(3) << "-" 
            << setw(7) << "-----" << setw(10) << "--------" << setw(10) 
            << "--------" << setw(7) << "----" << endl;






}

void process_each_coast_gaurd_ship(ifstream &ships_data, int &x_pos, 
        int &y_pos,ofstream &rpt_file, double &distance, 
        double &arrival_time, int &cg_x_pos, int &cg_y_pos, int &speed, 
        int &capacity, char name[80])
{
    
    ships_data.open("CKCG.txt");
    

    //need primer
    
    get_data_from_ship_file(ships_data, name, cg_x_pos, cg_y_pos, speed, 
            capacity);
    while (!ships_data.eof())
    {
        
        calc_CG_responce_vals(x_pos, y_pos, cg_x_pos, cg_y_pos, speed,
                distance, arrival_time);
        disp_CG_response_vals(rpt_file,
         name,  cg_x_pos,  cg_y_pos,  speed,  capacity,
         distance,  arrival_time);
        get_data_from_ship_file(ships_data, name, cg_x_pos, cg_y_pos,
                speed, capacity);
    }
}

void get_data_from_ship_file(ifstream &ships_data, char name[80],
        int &cg_x_pos, int &cg_y_pos, int &speed, int &capacity)
{
    ships_data.getline(name,80);
    //cout << name;
    ships_data >> cg_x_pos;
    ships_data >> cg_y_pos;
    ships_data >> speed;
    ships_data >> capacity;
    ships_data.ignore(1000,'\n');
}

void calc_CG_responce_vals(int x_pos, int y_pos, int cg_x_pos, int cg_y_pos,
        int speed, double &distance, double &arrival_time)
{
    distance = sqrt(pow((x_pos - cg_x_pos), 2) + pow((y_pos - cg_y_pos), 2));
    arrival_time = distance / speed * 60;
    
}

void disp_CG_response_vals(ofstream &rpt_file,
        char name[80], int cg_x_pos, int cg_y_pos, int speed, int capacity,
        double distance, double arrival_time)
{
    rpt_file << setprecision(2) << fixed;
    rpt_file << setw(5) << "" << setw(15) << left << name << setw(3) << right
            << cg_x_pos << setw(3) << cg_y_pos
            << setw(7) << speed << setw(10) << capacity << setw(10) 
            << distance << setw(7) << arrival_time << endl;
}

void disp_signature(ofstream &rpt_file, char officer[80])
{
    rpt_file << "\n\n\n\n";
    rpt_file << "\nSign Here: __________________________\n";
    rpt_file << setw(25) << officer;


}
