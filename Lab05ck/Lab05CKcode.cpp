/*File:   Lab05CKcode.cpp
 * Author: Christopher
 * Created on October 9, 2014, 11:40 AM
 * This program calculates the midterm grade for a student. It asks for input
 * then takes the values and displays the results to the user. It even shows
 * the weight of each type of assignment.
 */
#include <iomanip>
#include <iostream>
#include <cstring>

using namespace std;

void set_grade_data(char [80], int &, int &, int &, double &, double &,
        double &);
void get_stu_info_from_stu(char [80], char [80], int &, int &, int &, int &,
        int &, int &, int &, int &);
void calc_weighted_averages(int, int, int, double, double, double, int,
        int, int, int, int, int, int, int, double &, double &, double &, 
        int &);
void disp_stu_info_to_stu(char [80], char [80]);
void disp_grades_to_stu(int , int , int, double, double, double, int, int,
        int, int, int, int, int, int, double, double, double, int);

int main() {
    char class_name[80], stu_name[80], stu_major[80];
    double assn_wt, quiz_wt, exam_wt, assn_avg, quiz_avg, exam_avg;
    int assn_max_pnts, quiz_max_pnts, exam_max_pnts,
            assn1, assn2, assn3, quiz1, quiz2, quiz3, quiz4, exam1,  
            mid_term_grade;

    set_grade_data(class_name, assn_max_pnts, quiz_max_pnts, exam_max_pnts,
            assn_wt, quiz_wt, exam_wt);
    get_stu_info_from_stu(stu_name,  stu_major, assn1, assn2,  assn3, quiz1,
            quiz2, quiz3, quiz4, exam1);
    calc_weighted_averages( assn_max_pnts, quiz_max_pnts, exam_max_pnts,
            assn_wt, quiz_wt, exam_wt,assn1,  assn2,  assn3, quiz1, quiz2,
            quiz3, quiz4, exam1, assn_avg, quiz_avg, exam_avg,
            mid_term_grade);
    disp_stu_info_to_stu(stu_name, stu_major);
    disp_grades_to_stu(assn_max_pnts, quiz_max_pnts,
        exam_max_pnts, assn_wt, quiz_wt, exam_wt, assn1, assn2, assn3, quiz1,
            quiz2, quiz3, quiz4, exam1, assn_avg, quiz_avg, exam_avg,
            mid_term_grade);
    return 0;
}
void set_grade_data(char class_name[80], int &assn_max_pnts, 
        int &quiz_max_pnts, int &exam_max_pnts, double &assn_wt, 
        double &quiz_wt, double &exam_wt)
{
    strcpy(class_name,"Intro to Programming");
    assn_max_pnts = 100;
    quiz_max_pnts = 40;
    exam_max_pnts = 150;
    assn_wt = .56;
    quiz_wt = .13;
    exam_wt = .31;
}

void get_stu_info_from_stu(char stu_name[80], char stu_major[80], int &assn1,
        int &assn2, int &assn3, int &quiz1, int &quiz2, int &quiz3, 
        int &quiz4, int &exam1)
{
    
    cout << setw(10) << "Name" << ":";
    cin >> stu_name;
    cout << endl << setw(10) << "Major" << ":";
    cin >> stu_major;
    cout << endl << "Assignment Grades\n";
    cout << "1: ";
    cin >> assn1;
    cout << endl << "2: ";
    cin >> assn2;
    cout << endl << "3: ";
    cin >> assn3;
    cout << endl << "Quiz Grades\n";
    cout << "1: ";
    cin >> quiz1;
    cout << endl << "2: ";
    cin >> quiz2;
    cout << endl << "3: ";
    cin >> quiz3;
    cout << endl << "4: ";
    cin >> quiz4;
    cout << endl << "Exam Grades\n";
    cout << "1: ";
    cin >> exam1;
}

void calc_weighted_averages(int assn_max_pnts, int quiz_max_pnts,
        int exam_max_pnts, double assn_wt, double quiz_wt, double exam_wt,
        int assn1, int assn2, int assn3, int quiz1, int quiz2, int quiz3,
        int quiz4, int exam1, double &assn_avg, double &quiz_avg,
        double &exam_avg, int &mid_term_grade)
{
    double assn_wt_avg, quiz_wt_avg, exam_wt_avg;
    assn_avg = static_cast<double>(assn1 + assn2 + assn3) / assn_max_pnts 
            * 100;
    quiz_avg = static_cast<double>(quiz1 + quiz2 + quiz3 + quiz4) 
            / quiz_max_pnts *100;
    exam_avg = static_cast<double>(exam1) / exam_max_pnts * 100;
    assn_wt_avg = assn_avg * assn_wt;//needs b def as double too
    quiz_wt_avg = quiz_avg * quiz_wt;
    exam_wt_avg = exam_avg * exam_wt;
    mid_term_grade = static_cast<int>((assn_wt_avg + quiz_wt_avg +
            exam_wt_avg)+.5);

}
void disp_stu_info_to_stu(char stu_name[80], char stu_major[80])
{
    cout << setw(30) << "----------------------------------------------------"
            "\n";
    cout << setw(30) << " SUNY Jefferson" << endl;
    cout << setw(28) << "Semester 1" << endl;
    cout << setw(26) << stu_name << endl;
    cout << setw(26) << stu_major << endl << endl;
    cout << setprecision(2) << fixed;
}

void disp_grades_to_stu(int assn_max_pnts, int quiz_max_pnts,
        int exam_max_pnts, double assn_wt, double quiz_wt, double exam_wt, 
        int assn1, int assn2, int assn3, int quiz1, int quiz2, int quiz3, 
        int quiz4, int exam1, double assn_avg, double quiz_avg, 
        double exam_avg, int mid_term_grade)
{
    cout << right << setw(13) << "" <<setw(40) << "|  1|  2|  3|  4|"
            "  Max Points|  Average|  Weight|" << endl;
    cout << right << setw(13) << "Assignments:" << "|" << setw(3)<< assn1 <<
            "|" << setw(3)<< assn2 << "|" << setw(3)<< assn3 << "|" << setw(3)
            << "Nul" << "|" << setw(12)<< assn_max_pnts << "|" << setw(9)
            << assn_avg << "|" << setw(8)<< assn_wt << "|" << endl;
    cout << right << setw(13) << "Quizes:"<<  "|" << setw(3)<< quiz1 << "|"
            << setw(3)<< quiz2 << "|" << setw(3)<< quiz3 << "|" << setw(3)
            << quiz4 << "|" << setw(12)<< quiz_max_pnts << "|" << setw(9)
            << quiz_avg << "|" << setw(8)<< quiz_wt << "|" << endl;
    cout << right << setw(13) << "Exams:" << "|" << setw(3)<< exam1 <<
            "|" << setw(3)<< "Nul" << "|" << setw(3)<< "Nul" << "|" << setw(3)
            << "Nul" << "|" << setw(12)<< exam_max_pnts << "|" << setw(9)
            << exam_avg << "|" << setw(8)<< exam_wt << "|" << endl << endl;
    cout << setw(30) << "Midterm Grade :" << mid_term_grade << endl;
}
