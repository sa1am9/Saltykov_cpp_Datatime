
///Created by Saltykov Illya and Selivanov Danyil
#ifndef PR_C_24_DATE_PURE_H
#define PR_C_24_DATE_PURE_H

#include <string>

using namespace std;

class date_pure
{
public:
    int dd = 1, mm = 1, yy = 1;
    int p_days = 0, p_months = 0, p_years = 0;//// time passed after 01.01.0001 in days, months and years

    void input(int day, int month, int year); /// input param


    void check_week_day(); /// 


    void count_date_by_passed(int days); /// reference date


    void out(); /// output



private:

    bool check_mod(int year);


    int allowed_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int allowed_days_mod[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string days[7] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };

    bool check_validity(int dd, int mm, int yy); /// 

    void count_passed(); /// 


};


#endif //PR_C_24_DATE_PURE_H
