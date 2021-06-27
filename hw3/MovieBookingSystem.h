/*
*Author: Sarper Turan
*Student ID: 21903051
*Spring'21 CS201 Section01 Homework03
*/

#include "Movie.h"

class MovieBookingSystem{
    public:
        const static int numOfRow = 30;
        const static int numOfColumn = 26;
        MovieBookingSystem();
        ~MovieBookingSystem();
        void addMovie( const long movieID, const int audienceRadius );
        void cancelMovie( const long movieID);
        void showAllMovies() const;
        //void showMovie( const long movieID) const;
        //int makeReservation( const long movieID, const int row, const char col);
        //void cancelReservations( ReservationList resCode);
        //void showReservation( const int resCode) const;

        int getLength() const;
        bool isListEmpty() const;
        bool insert( int index, Movie mov);
        bool remove( int index);
        bool retrieve( int index, Movie& movItem) const;

    private:
        ReservationList reservationCodes;

        struct MovieNode{
            Movie m;
            MovieNode* next;
        };
        int size;
        MovieNode *head;

        MovieNode *find (int index) const;


        int movieCount;
        int resCount;

    // ...
    //you may define additional member functions and data members, if necessary.
};