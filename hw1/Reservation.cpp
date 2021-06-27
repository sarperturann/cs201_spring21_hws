/*
*Reservation Implementation
*Author: Sarper Turan
*Student ID: 21903051
*CS201 Section01 Homework01
*/

#include <iostream>
#include "Reservation.h"

using namespace std;

//CONSTRUCTORS
Reservation::Reservation(){
    resId = 0;
    row = 0;
    col = 0;
}

//METHODS
    int Reservation::getResCode(){
        return resId;
    }
    int Reservation::getRow(){
        return row;
    }
    char Reservation::getCol(){
        return col;
    }

    void Reservation::setResCode( int id){
        resId = id;
    }
    void Reservation::setRowNo( int rowN){
        row = rowN;
    }
    void Reservation::setColNo( char colN){
        col = colN;
    }

