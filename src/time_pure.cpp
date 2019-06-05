///Created by Saltykov Illya and Selivanov Danyil

#include "time_pure.h"
#include "date_pure.h"
#include <iostream>



void time_pure::input(int d, int h, int m, int s) {
    if(check_valid(d, h, m, s)) {
        dd = d;
        hh = h;
        mm = m;
        ss = s;
    } else {
        cout << "try again for valid data \n";
    }
    count_seconds();
}


void time_pure::time_from_seconds(int n) {
    int sec_count = 0;
    int min_count = 0;
    int hours_count = 0;
    int days_count = 0;
    while(n != 0) {
        n -= 1;
        sec_count++;
        if(sec_count == 60) {
            sec_count = 0;
            min_count++;
        }
        if(min_count == 60) {
            min_count = 0;
            hours_count++;
        }
        if(hours_count == 24) {
            hours_count = 0;
            days_count++;
        }
    }
    dd = days_count;
    hh = hours_count;
    mm = min_count;
    ss = sec_count;
    cout << dd << "   " << hh << "   " << mm << "   " << ss << endl;
}


void time_pure::count_seconds() {
    int counter = 0;
    counter += 86400*dd;
    counter += 3600*hh;
    counter += 60*mm;
    counter += ss;
    seconds_overall = counter;
}


void time_pure::output() {
    cout << dd << "   " << hh << "   " << mm << "   " << ss << endl;
}


void time_pure::count_days() {
    cout << dd << endl;
}


date_pure time_pure::convertion() {
    date_pure* d = new date_pure;
    d->count_date_by_passed(dd);
    return *d;
}


void time_pure::divide_by(int n) {
    time_from_seconds(seconds_overall / n);
}


void time_pure::multiply_by(int n) {
    time_from_seconds(seconds_overall * n);
}


bool time_pure::check_valid(int d, int h, int m, int s) {
    if (s > 59 || s < 0) {
        cout << "secs" << endl;
        return false;
    }
    if (m > 59 || m < 0) {
        cout << "mins" << endl;
        return false;
    }
    if (h > 24 || h < 0) {
        cout << "hh" << endl;
        return false;
    }
    return true;
}
