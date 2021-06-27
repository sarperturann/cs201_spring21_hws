/*
*Movie Header
*Author: Sarper Turan
*Student ID: 21903051
*CS201 Section01 Homework01
*/

#include "Reservation.h"
#include <ctime>
#include <string>

class Movie {
public:

    //CONSTRUCTORS
    Movie();
    ~Movie();

    //GETTERS
    long getId();
    int getRadius();
    int* getOccupiableRows();
    char* getOccupiableColumns();
    int getTotalSeats();
    int getRowSize();
    int getColSize();
    string getDate();
    int* getSeatArr();

    //SETTERS
    void setId(long id);
    void setRadius(int rad);
    void setOccupiableRows( int* rows);
    void setOccupiableColumns( char* cols);
    void setRowSize(int rowNo);
    void setColSize(char colNo);
    void setTotalSeats( int tot);
    void setDate( long d);
    void setSeatArr( int tot);

    void allocate( const int radius, const int row, const int column);

    void addReservation( int row, char col);

    //EACH MOVIE HOLDS ITS OWN RESERVATIONS
    Reservation* getMovieReservation();
    void setMovieReservation(Reservation* res);

private:
    long movieID;
    int radius;
    int* occupiableRow;
    char* occupiableColumn;
    int seats;
    int rowSize;
    int colSize;
    Reservation movieRes;
    string date;
    int* seatArr;
};