#pragma once
//
//  time.hpp
//  time_test
//
//  Created by HowARD-001 on 2018/6/4.
//  Copyright 2018¦~ HowARD-001. All rights reserved.
//

#ifndef time_hpp
#define time_hpp
#define YEAR_SET 1900
#define MON_SET 1

#include <stdio.h>
#include<iostream>
#include<fstream>
#include<iomanip>
#include<time.h>
using namespace std;

class Time
{
private:
    double start;
    double end;
    time_t loc_now;
    
public:
    Time();
    void Start();
    void End();
    
    double Pass();
    
    time_t Now();    // get the current time (unit : seconds)
    
    void Refresh();
    void print();
    
    ~Time() {};
};


#endif /* time_hpp */
