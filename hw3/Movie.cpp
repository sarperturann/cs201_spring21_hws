/*
*Author: Sarper Turan
*Student ID: 21903051
*Spring'21 CS201 Section01 Homework03
*/

#include <iostream>
#include "Movie.h"

using namespace std;

//CONSTRUCTORS
Movie::Movie(){
    movieID = 0;
    radius = 0;
    seats = 0;
    rowSize = 0;
    colSize = 0;
}
Movie::~Movie(){}

//GETTERS
long Movie::getId(){
    return movieID;
}
int Movie::getRadius(){
    return radius;
}
int Movie::getTotalSeats(){
    return seats;
}
int Movie::getRowSize(){
    return rowSize;
}
int Movie::getColSize(){
    return colSize;
}
string Movie::getDate(){
    return date;    
}
//SETTERS
void Movie::setId(long id){
    movieID = id;
}
void Movie::setRadius(int r){
    radius = r;
}
void Movie::setRowSize(int rowNo){
    rowSize = rowNo;
}
void Movie::setColSize(char colNo){
    colSize = colNo;
}
void Movie::setTotalSeats( int tot){
    seats = tot;
}
void Movie::allocate( const int radius, const int row, const int column){
    //Use this to set the properties of the seat - occupiable etc.
    setRadius(radius);

    //Finding what the last row, column will be
    int rowLimit = row / (radius + 1);
    int colLimit = column / (radius + 1);

    if( (row % (radius + 1) > 0) ){
        rowLimit++;
    }
    if( (column % (radius + 1) > 0)){
        colLimit++;
    }

    //Since I've found the limits, I initialize/name the occupiable seats
    int rowN = 1;
    char letter = 'A';

    //This part does not work.
    /*
    SeatNode* newNode = new SeatNode;
    newNode->column = letter;
    newNode->row = rowN;

    for(int i = 1; i < rowLimit + 1; i++){
        rowN++;
        insertRow(getLength() + 1, rowN);
    }
    for(int i = 1; i < colLimit + 1; i++){
        letter = letter + (radius + 1);
        insertCol(getLength()+ 1, letter);
    }
    */
    int totalSeats = rowLimit * colLimit;
    setTotalSeats(totalSeats);
} 
void Movie::setDate( long d){
    time_t t = (time_t) d; //typecasting because it gives an error otherwise
    string dat = ctime( &t);
    dat.erase(dat.find('\n', 0), 1);
    date = dat;
}

int Movie::getLength() const{
    return size;
}
bool Movie::isListEmpty() const{
    return size == 0;
}

bool Movie::insertRow( int index, int num){
    int newLength = getLength() + 1;
    if( index < 1 || index > newLength){
        return false;
    }

    SeatNode *newPtr = new SeatNode;
    size = newLength;
    newPtr -> row = num;

    if(index == 1){
        newPtr->next = head;
        head = newPtr;
    } else {
        SeatNode* prev = find(index - 1);
        newPtr->next = prev->next;
        prev->next = newPtr;
    }
    return true;
}

bool Movie::insertCol( int index, char c){
    int newLength = getLength() + 1;
    if( index < 1 || index > newLength){
        return false;
    }

    SeatNode *newPtr = new SeatNode;
    size = newLength;
    newPtr -> column = c;

    if(index == 1){
        newPtr->next = head;
        head = newPtr;
    } else {
        SeatNode* prev = find(index - 1);
        newPtr->next = prev->next;
        prev->next = newPtr;
    }
    return true;
}

Movie::SeatNode* Movie::find(int index) const{
    if( index < 0 || index > getLength()){
        return NULL;
    } else {
        SeatNode* cur = head;
        for( int skip = 1; skip < index; ++skip){
            cur = cur->next;
        }
        return cur;
    }
}