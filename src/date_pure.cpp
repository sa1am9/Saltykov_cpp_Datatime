///Created by Saltykov Illya and Selivanov Danyil
#include "date_pure.h"
#include <iostream>

void date_pure::input(int day, int month, int year) {
    if(check_validity(day, month, year)){
        dd = day;
        mm = month;
        yy = year;
        count_passed();
    } else {
        cout << "try again for valid data \n";
    }
}


void date_pure::check_week_day() {
    cout << days[p_days%7] << endl;
}


void date_pure::count_date_by_passed(int days) {// days to date
    int years_counter = 1;
    int days_counter = 1;
    int month_counter = 1;
    while(days != 0) {
        days -= 1;
        days_counter++;
        if (check_mod(years_counter)) {
            if(days_counter == allowed_days_mod[month_counter-1]+1){
                month_counter++;
                days_counter = 1;
            }
        } else {
            if(days_counter == allowed_days[month_counter-1]+1) {
                month_counter++;
                days_counter = 1;
            }
        }
        if(month_counter == 13) {
            years_counter++;
            month_counter = 1;
        }
    }
    cout << days_counter << "   " << month_counter << "   " << years_counter << endl;
    dd = days_counter;
    mm = month_counter;
    yy = years_counter;
}


void date_pure::out() {
    cout << dd << "   " << mm << "   " << yy << endl;
}


bool date_pure::check_mod(int year){
    if((((year % 4) == 0) && ((year%100) != 0)) || year%400 == 0) {
        return true;
    } else{
        return false;
    }
}


bool date_pure::check_validity(int dd, int mm, int yy) {
    if (yy<1) {
        return false;
    }
    if (1>mm || mm>12) {
        return false;
    }
    if(check_mod(yy)) {
        if(dd>allowed_days_mod[mm-1]) {
            return false;
        }
    } else{
        if(dd>allowed_days[mm-1]) {
            return false;
        }
    }
    return true;
}


void date_pure::count_passed() {
    int counter_days = 0;
    int counter_months = 0;
    int counter_years = yy - 1;
    for (int i = 1; i < yy; i++) {
        if (check_mod(i)) {
            for(int j = 1; j<13; j++) {
                counter_days += allowed_days_mod[j-1];
                counter_months++;
            }
        } else{
            for(int j = 1; j<13; j++) {
                counter_days += allowed_days[j-1];
                counter_months++;
            }
        }
    }
    if(check_mod(yy)){
        for (int f = 1; f<mm; f++) {
            counter_days += allowed_days_mod[f-1];
            counter_months++;
        }
    } else {
        for (int f = 1; f<mm; f++) {
            counter_days += allowed_days[f-1];
            counter_months++;
        }
    }
    counter_days += dd - 1;//// be careful, probably should have written "dd"
    p_days = counter_days;
    p_months = counter_months;
    p_years = counter_years;
}
