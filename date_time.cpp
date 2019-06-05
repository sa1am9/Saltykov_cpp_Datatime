#include <iostream>
#include <string>
#include "src/date_pure.h"
#include "src/time_pure.h"


using namespace std;


void compare_date(date_pure d1, date_pure d2){
    if (d1.p_days ==  d2.p_days){
        cout << "equal \n";
    }
    if (d1.p_days > d2.p_days) {
        cout << "1 is greater \n";
    } else if(d1.p_days < d2.p_days){
        cout << "2 is greater \n";
    }
};


void compare_time(time_pure t1, time_pure t2) {
    if(t1.seconds_overall > t2.seconds_overall) {
        cout << "t1 > t2 \n";
    } else if(t1.seconds_overall < t2.seconds_overall){
        cout << "t1 < t2 \n";
    } else {
        cout << "t1 == t2 \n";
    }
}


void next(date_pure d) {
    d.count_date_by_passed(d.p_days + 1);
}


void previous(date_pure d) {
    if (d.p_days != 0) {
        d.count_date_by_passed(d.p_days - 1);
    } else{
    cout << d.dd<< "   " << d.mm << "   " << d.yy <<endl;
    }
}


void add_day(date_pure d, int n) {
    d.count_date_by_passed(d.p_days + n);
}


void minus_day(date_pure d, int n) {
    if (d.p_days >= n) {
        d.count_date_by_passed(d.p_days - n);
    } else {
        cout << d.dd << "   " << d.mm << "   " << d.yy << endl;
    }
}


void days(date_pure d1, date_pure d2) {
    cout << d1.p_days - d2.p_days<< endl;
}

time_pure minus_time(time_pure t1, time_pure t2) {
    time_pure res;
    int n;
    n = t1.seconds_overall - t2.seconds_overall;
    res.time_from_seconds(n);
    return res;
}


time_pure add_time(time_pure t1, time_pure t2) {
    time_pure res;
    int n;
    n = t1.seconds_overall + t2.seconds_overall;
    res.time_from_seconds(n);
    return res;
}

date_pure date_minus_time(date_pure d, time_pure t) {
    date_pure res;
    if (t.dd <= d.p_days){
        res.count_date_by_passed(d.p_days - t.dd);
    } else {
        cout << "wrong data\n";
    }
    return res;
}


date_pure date_plus_time(date_pure d, time_pure t) {
    date_pure res;
    res.count_date_by_passed(d.p_days + t.dd);
    return res;
}


date_pure date_minus_date(date_pure d1, date_pure d2) {
    if (d1.p_days > d2.p_days){
        d1.count_date_by_passed(d1.p_days - d2.p_days);
    } else {
        cout << "wrong data\n";
    }
    return d1;
}

date_pure date_plus_date(date_pure d1, date_pure d2) {
    d1.count_date_by_passed(d1.p_days + d2.p_days);
    return d1;
}



int main() {
    date_pure d1, d2, d3, d4, d5;
    time_pure t1, t2, t3, t4, t5;

    d1.input(31, 5, 2019);
    d1.out();

    d1.check_week_day();

    d2.input(11, 12, 2001);
    d2.out();

    compare_date(d1, d2);

    t1.input(1, 21, 21, 13);
    t1.output();

    t2.input(11, 20, 21, 22);
    t2.output();

    compare_time(t1, t2);//////////////

    next(d1);////////////

    previous(d1);/////////

    add_day(d1, 31);///////////

    minus_day(d2, 321);/////////

    days(d1, d2);////////

    minus_time(t2, t1);//////////

    add_time(t2, t1);////////////

    date_minus_time(d1, t2);///////

    date_plus_time(d1, t1);////////

    date_minus_date(d1, d2);//////

    date_plus_date(d1, d2);/////////
    return 0;
}
