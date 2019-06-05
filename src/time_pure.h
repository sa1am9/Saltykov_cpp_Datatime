///Created by Saltykov Illya and Selivanov Danyil
#ifndef PR_C_24_TIME_PURE_H
#define PR_C_24_TIME_PURE_H

#include "date_pure.h"

using namespace std;

class time_pure{
public:
    int dd = 0;
    int hh = 0;
    int mm = 0;
    int ss = 0;
    int seconds_overall = 0;


    void input(int d, int h, int m, int s);


    void time_from_seconds(int n);


    void count_seconds();


    void output();


    void count_days();


    date_pure convertion();


    void divide_by(int n);


    void multiply_by(int n);


private:
    bool check_valid(int d, int h, int m, int s);
};

#endif //PR_C_24_TIME_PURE_H
