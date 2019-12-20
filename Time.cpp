//
//  time.cpp
//  time_test
//
//  Created by HowARD-001 on 2018/6/4.
//  Copyright 2018¦~ HowARD-001. All rights reserved.
//

#include "Time.h"
Time::Time() {
    start = 0;
    end = 0;
    loc_now = 0;
}

void Time::Start() {
    start = clock() / CLOCKS_PER_SEC;
}

void Time::End() {
    end = clock() / CLOCKS_PER_SEC;
}

double Time::Pass() {
    return end - start;
}

void Time::Refresh() {
    start = 0;
    end = 0;
    loc_now = 0;
}

time_t Time::Now() {
    time(&loc_now);
    
    return loc_now;
}

void Time::print() {
    tm *ptrnow;
    //time(&loc_now);//seconds from 1970/01/01
    ptrnow = localtime(&loc_now);//get local time
    cout << "#Local time: " << endl;
    cout << setw(10) << "year: " << ptrnow->tm_year + YEAR_SET << endl;
    cout << setw(10) << "month: " << ptrnow->tm_mon + MON_SET << endl;
    cout << setw(10) << "mday: " << ptrnow->tm_mday << endl;
    cout << setw(10) << "wday: " << ptrnow->tm_wday << endl;
    cout << setw(10) << "yday: " << ptrnow->tm_yday << endl;
    cout << setw(10) << "hour: " << ptrnow->tm_hour << endl;
    cout << setw(10) << "minute: " << ptrnow->tm_min << endl;
    cout << setw(10) << "second: " << ptrnow->tm_sec << endl;
    cout << asctime(ptrnow) << endl;//transform to string
}
