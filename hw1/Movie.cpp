/*
*Movie Implementation
*Author: Sarper Turan
*Student ID: 21903051
*CS201 Section01 Homework01
*/

#include <iostream>
#include "Movie.h"

using namespace std;

//CONSTRUCTORS
Movie::Movie(){
    movieID = 0;
    radius = 0;
    occupiableRow = NULL;
    occupiableColumn = NULL;
    seats = 0;
    rowSize = 0;
    colSize = 0;
    date = "";
    seatArr = NULL;
}
Movie::~Movie(){
    if( occupiableColumn != NULL ){ delete[] occupiableColumn; }
    if( occupiableRow != NULL ){ delete[] occupiableRow; }
    if( seatArr != NULL ){ delete[] seatArr; }
    occupiableRow = NULL; occupiableColumn = NULL; seatArr = NULL;
}

//METHODS
//GETTERS
    long Movie::getId(){
        return movieID;
    }
    int Movie::getRadius(){
        return radius;
    }
    int* Movie::getOccupiableRows(){
        return occupiableRow;
    }
    char* Movie::getOccupiableColumns(){
        return occupiableColumn;
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
    int* Movie::getSeatArr(){
        return seatArr;
    }
    //SETTERS
    void Movie::setId(long id){
        movieID = id;
    }
    void Movie::setRadius(int r){
        radius = r;
    }
    void Movie::setOccupiableRows( int* rows){
        occupiableRow = rows;
    }
    void Movie::setOccupiableColumns( char* cols){
        occupiableColumn = cols;
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
    void Movie::setDate( long d){
        time_t t = (time_t) d; //typecasting because it gives an error otherwise
        string dat = ctime( &t);
        dat.erase(dat.find('\n', 0), 1);
        date = dat;
    }
    void Movie::setSeatArr( int tot){
        seatArr = new int[tot];
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

        int* rows = new int[rowLimit];
        rows[0] = rowN;
        for( int i = 0; i < rowLimit; i++){
            rowN = rowN + 1;
            rows[i] = rowN;
        }
        char* columns = new char[colLimit];
        columns[0] = letter;
        for( int i = 0; i < colLimit; i++){
            letter = letter + (radius + 1);
            columns[i] = letter;
        }

        int totalSeats = rowLimit * colLimit;
        setTotalSeats(totalSeats);
        setOccupiableColumns(columns);
        setOccupiableRows(rows);
    } 

    void Movie::addReservation( int row, char col){
        
    }

    //EACH MOVIE HOLDS ITS OWN RESERVATIONS
    Reservation* Movie::getMovieReservation(){}
    void Movie::setMovieReservation(Reservation* res){}