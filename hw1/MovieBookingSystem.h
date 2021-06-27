/*
*MovieBookingSystem Header File
*Author: Sarper Turan
*Student ID: 21903051
*CS201 Section01 Homework01
*/

#include "Movie.h"

class MovieBookingSystem {
public :

    const static int numOfRow = 30 ;
    const static int numOfColumn = 26 ;

    //CONSTRUCTOR / DESTRUCTOR
    MovieBookingSystem();
    ~MovieBookingSystem();

    void addMovie ( const long movieID, const int audienceRadius );
    void cancelMovie ( const long movieID);
    void showAllMovies ();
    void showMovie ( const long movieID);
    int makeReservation ( const long movieID, const int row, const char col);
    void cancelReservations ( const int numRes, const int * resCode);
    void showReservation ( const int resCode);
private :
// ...
//you may define additional member functions and data members, if necessary.
    Movie* movies; //Movies array
    Reservation* resCodeArr; //Reservations array - used to delete reservations using resID
    int movieCount;
    int resCount;
};