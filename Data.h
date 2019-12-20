//
//  Data.h
//  HappyFarm
//
//  Created by YenJung on 2018/7/8.
//  Copyright © 2018年 YenJung. All rights reserved.
//

#ifndef Data_h
#define Data_h


#include<stdio.h>
#include<iostream>
#include<fstream>
#include<iomanip>
#include<Time.h>
using namespace std;

void Read_data(int &EXPERIENCE,int &MONEY, time_t &GAME_TIME){
    ifstream myfile("Save_data.txt");
    if(myfile){
        myfile>>EXPERIENCE>>MONEY>> GAME_TIME;
    }
    else
        cout<<"unable to read data\n";
    
    myfile.close();
}

void Save_data(int EXPERIENCE,int MONEY,time_t GAME_TIME){
    ofstream myfile("Save_data.txt");
    if(myfile){
        myfile<<EXPERIENCE<<" "<<MONEY<<" "<< GAME_TIME;
    }
    else
        cout<<"unable to save data\n";
    
    myfile.close();
}


#endif /* Data_h */

