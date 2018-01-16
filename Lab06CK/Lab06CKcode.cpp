/* 
 * File:   Lab06CKcode.cpp
 * Author: Christopher
 * Due: Oct 23 2014 @ 10:10
 * Created on October 16, 2014, 1:05 PM
 * Description: This program takes in the students grades and writes the 
 * computed values to a file. If there isnt a file for it to write to, 
 * it makes a new one. It also accepts my sarcastic classes as input without 
 * arguing with me, which it shouldn't. */
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

void set_sem_pricing(double &, double &, double &, double &, double &);
void get_stu_info_from_stu(char [80], char [80], char [80]);
void disp_stu_info_to_stu_rpt(ofstream &, char [80],char [80], char [80]);
void process_each_course(ofstream &, int &, int &, int &,
        char [80], char [80], int , 
        char [80], int , int); 
void get_course_info_from_stu(char [80],char [80], int &, char [80], int &);
void calc_qual_pnts(int &, int , int );
void accum_course_GPI_vals(int &, int, int &, int);
void disp_course_info_to_stu_rpt(ofstream &, char [80],char [80], int, 
        char [80]);
void calc_sem_fees(double &, double, double, double, double, double, int);
void calc_GPI(double &, int, int);
void disp_GPI_to_stu_rpt(ofstream &, double);
void disp_sem_fees_to_stu_rpt(ofstream &, double );

int main(int argc, char** argv) {
    ofstream stu_rpt;
    double tuition_per_crhr, stu_life_fee_per_crhr, tech_fee_per_crhr,
            alumni_fee,insurance_price, sem_fees, stu_GPI;
    char stu_j_num[80], stu_name[80], stu_major[80], course_id[80],
            course_name[80], course_grade[80];
    int num_courses, tot_crhr, tot_qual_pnts, course_num_eq, course_crhr,
            qual_pnts;
    
    set_sem_pricing(tuition_per_crhr, stu_life_fee_per_crhr, 
            tech_fee_per_crhr, alumni_fee, insurance_price);
    get_stu_info_from_stu( stu_j_num, stu_name, stu_major);
    disp_stu_info_to_stu_rpt(stu_rpt, stu_j_num, stu_name, stu_major);
    
    process_each_course(stu_rpt, num_courses, tot_crhr, tot_qual_pnts,
         course_id, course_name, course_crhr, 
         course_grade,  course_num_eq, qual_pnts); 
    
    calc_sem_fees( sem_fees,  tuition_per_crhr, stu_life_fee_per_crhr,  
            tech_fee_per_crhr, alumni_fee, insurance_price, tot_crhr);
    calc_GPI(stu_GPI, tot_qual_pnts, tot_crhr);
    disp_GPI_to_stu_rpt(stu_rpt, stu_GPI);
    disp_sem_fees_to_stu_rpt(stu_rpt, sem_fees);

    stu_rpt.close();
    return 0;
}

void set_sem_pricing(double &tuition_per_crhr, double &stu_life_fee_per_crhr,
        double &tech_fee_per_crhr, double &alumni_fee, 
        double &insurance_price)
{
    tuition_per_crhr = 152.00;
    stu_life_fee_per_crhr = 13.50;
    tech_fee_per_crhr = 8.75; 
    alumni_fee = 15.50;
    insurance_price = 19.25;
}

void get_stu_info_from_stu(char stu_j_num[80],char stu_name[80],
        char stu_major[80])
{
    cout << "\nJ Number: ";
    cin >> stu_j_num;
    cout << "\nName: ";
    cin >> stu_name;
    cout << "\nMajor: ";
    cin >> stu_major;
    
}

void disp_stu_info_to_stu_rpt(ofstream &stu_rpt, char stu_j_num[80],
        char stu_name[80], char stu_major[80])
{
    stu_rpt.open("Student_Report.txt");
    stu_rpt << setprecision(1) << fixed;
    stu_rpt << right << setw(25) << "SUNY JEFFERSON\n";
    stu_rpt << right << setw(23) << "Fall 2014\n";
    stu_rpt << left << setw(10)<< "J Number" << ':' << right << setw(20) 
            << stu_j_num << endl;
    stu_rpt << left << setw(10)<< "Student" << ':'<< right << setw(20)
            << stu_name << endl;
    stu_rpt << left << setw(10)<< "Major" << ':' << right << setw(20)
            << stu_major << endl << endl;
    stu_rpt << setw(6) << "Course" << "    " << setw(6) << "Course"
            << "               " << setw(6) << "Credit" << "    " << setw(6) 
            << "Letter" << endl;
    stu_rpt << setw(6) << "ID" << "    " << setw(6) << "Name" 
            << "               " << setw(6) << "Hour" << "    " << setw(6) 
            << "Grade" << endl;
    
}

void process_each_course(ofstream &stu_rpt, int &num_courses, int &tot_crhr,
        int &tot_qual_pnts, char course_id[80], char course_name[80],
        int course_crhr, char course_grade[80], int course_num_eq, 
        int qual_pnts 
        )
{
    
    num_courses = 3;
    tot_crhr = 0;
    tot_qual_pnts = 0;
    int count;
    for(count = 0; count < num_courses;count++)
    {
        get_course_info_from_stu( course_id, course_name, course_crhr,
                course_grade, course_num_eq);
        calc_qual_pnts(qual_pnts, course_crhr, course_num_eq);
        accum_course_GPI_vals(tot_qual_pnts, qual_pnts, tot_crhr, 
                course_crhr);
        disp_course_info_to_stu_rpt(stu_rpt, course_id, course_name, 
                course_crhr, course_grade);
    }
}

void get_course_info_from_stu(char course_id[80],char course_name[80],
        int &course_crhr, char course_grade[80], int &course_num_eq)
{
    cout << "\nCourse ID:";
    cin >> course_id;
    cout << "\nCourse Name:";
    cin >> course_name;
    cout << "\nCourse Credit Hours:";
    cin >> course_crhr;
    cout << "\nCourse Letter Grade:";
    cin >> course_grade;
    cout << "\nCourse Number Equivalent:";
    cin >> course_num_eq;
}

void calc_qual_pnts(int &qual_pnts, int course_crhr, int course_num_eq)
{
    qual_pnts = course_crhr * course_num_eq;
}

void accum_course_GPI_vals(int &tot_qual_pnts, int qual_pnts, int &tot_crhr,
        int course_crhr)
{
    tot_qual_pnts = tot_qual_pnts + qual_pnts;
    tot_crhr = tot_crhr + course_crhr;
}

void disp_course_info_to_stu_rpt(ofstream &stu_rpt, char course_id[80],
        char course_name[80], int course_crhr, char course_grade[80])
{
    stu_rpt << right << setw(6) << course_id << "     " <<right << setw(15)  
            << course_name << "         " << left << setw(4)  << course_crhr 
            << "     " << setw(4) << course_grade << "     "<< endl;
}

void calc_sem_fees(double &sem_fees, double tuition_per_crhr, 
        double stu_life_fee_per_crhr, double tech_fee_per_crhr, 
        double alumni_fee, double insurance_price, int tot_crhr)
{
    sem_fees = (tuition_per_crhr + stu_life_fee_per_crhr + tech_fee_per_crhr)
            * tot_crhr + alumni_fee + insurance_price;
}

void calc_GPI(double &stu_GPI, int tot_qual_pnts, int tot_crhr)
{
    stu_GPI = static_cast<double>(tot_qual_pnts) / tot_crhr;
}

void disp_GPI_to_stu_rpt(ofstream &stu_rpt, double stu_GPI)
{
    stu_rpt << endl << right << setw(20) << "\nGPI: " << stu_GPI;
}

void disp_sem_fees_to_stu_rpt(ofstream &stu_rpt, double sem_fees)
{
    stu_rpt << setprecision(2) << fixed;
    stu_rpt << endl << right << setw(20) << "\nSemester Fees: " << sem_fees;
}