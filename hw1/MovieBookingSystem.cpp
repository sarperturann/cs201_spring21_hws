/*
*MovieBookingSystem Implementation
*Author: Sarper Turan
*Student ID: 21903051
*CS201 Section01 Homework01
*/

#include <iostream>
#include "MovieBookingSystem.h"

using namespace std;

//CONSTRUCTORS
MovieBookingSystem::MovieBookingSystem(){
    movies = NULL;
    resCodeArr = NULL;
    movieCount = 0;
    resCount = 0;
}
MovieBookingSystem::~MovieBookingSystem(){
    if( movies != NULL ){ delete[] movies; }
    if( resCodeArr != NULL ){ delete[] resCodeArr; }
    movies = NULL; resCodeArr = NULL;
}

//METHODS
void MovieBookingSystem::addMovie ( const long movieID, const int audienceRadius ){
    if( movieCount == 0){ //Create a new array with size 1 and add the movie
        //Checking the audience radius
        if( audienceRadius < 0 || audienceRadius > 7){
           cout << "Audience radius should be between 0 and 7 inclusive." << endl;
           return;
        }
        movies = new Movie[1];
        movieCount ++;

        (*movies).setId( movieID);
        (*movies).setDate( movieID);
        (*movies).allocate( audienceRadius, numOfRow, numOfColumn ); //Sets the ID and allocating the occupiable seats according to the radius

        cout << "Movie at " << (*movies).getDate() << " has been added. " << endl;
    } else { //DEEP COPY
        if( audienceRadius < 0 || audienceRadius > 7){
           cout << "Audience radius should be between 0 and 7 inclusive." << endl;
           return;
        }
        for( int i = 0; i < movieCount; i++){ //Checking if a movie with the same id exists
           if( movies[i].getId() == movieID ){
               (*movies).setDate( movieID);
               cout << "Movie at " << (*movies).getDate() << " already exists." << endl;
               return;
           }
        }

        movieCount++;
        Movie* temp = new Movie[movieCount];
        for ( int i = 0; i < movieCount - 1; i++){
           temp[i] = movies[i];
        }
        delete[] movies;
        movies = temp;

        movies[ movieCount - 1].setId( movieID);
        movies[ movieCount - 1].allocate( audienceRadius, numOfRow, numOfColumn);
        movies[ movieCount - 1].setDate( movieID);
        cout << "Movie at " << (movies[ movieCount - 1]).getDate() << " has been added. " << endl;
   }
}
void MovieBookingSystem::cancelMovie ( const long movieID){
    (*movies).setDate(movieID);
    if(movieCount == 0){
        cout << "Movie at " << (*movies).getDate() << " does not exist. " << endl; 
       return;
    } else { 
        for( int i = 0; i < movieCount; i++ ){
            if( movies[i].getId() == movieID ){ // DEEP COPY
                cout << "Movie at " << (*movies).getDate() << " has been cancelled. " << endl;

                int index = i;
                movieCount--;
                Movie* temp = new Movie[movieCount];
                for(int i = 0; i < movieCount; i++ ){
                    if( i < index ){
                        temp[i] = movies[i];
                    }else{
                        temp[i] = movies[i+1];
                    }
                }
                delete[] movies;
                movies = temp;
                return;
                // TODO: DELETE THE RESERVATIONS OF THE MOVIE
            } 
        }
        cout << "Movie at " << (*movies).getDate() << " does not exist. " << endl; 
        return;
   }
}
void MovieBookingSystem::showAllMovies (){
    if( movieCount == 0){
        cout << "There aren't any movies at the moment" << endl;
        return;
    }
    cout << "Movies on show: \n" << endl;
    for( int i = 0; i < movieCount; i++){
        movies[i].setId( movies[i].getId());
        cout << "Movie at: " << movies[i].getDate() << " ( " << movies[i].getTotalSeats() << " available seats)" << endl;
    }
    return;
}
void MovieBookingSystem::showMovie ( const long movieID){
    // TODO:
    /*
    * If there isn't a movie with the specified id, display warning
    * If it exists, display the seats in the format in the pdf where O's are available and X's are occupied
    * ONLY SHOW THE OCCUPIABLE SEATS, NOT THE COVID-19 SEATS, RADIUS!!!!
    */
   /*
    for( int i = 0; i < movieCount; i++){
        if( movies[i].getId() == movieID ){

            int* seats = movies[i].getSeatArr();
            int* rowNums = movies[i].getOccupiableRows();
            char* colNums = movies[i].getOccupiableColumns();

            int space = 2;

            for( int k = 0; k < movies[i].getColSize(); k++){
                cout << "  ";
                cout << colNums[k] << " ";
            }

            int count = 0; // this will count the number of columns printed

            for( int k = 0; k < movies[i].getRowSize(); k++){
                int charC = rowNums[k];
                if( charC < 10){
                    cout << " " << charC <<
                }
            }

            for( int k = 0; k < movies[i].getTotalSeats(); k++){
                if( seats[i] ==  0){
                    cout << "O " ;
                } else {
                    cout << "X " ;
                }
            }
        } else {
            movies[i].setDate( movieID);
            cout << "Movie at " << movies[i].getDate() << " does not exist." << endl;
            return;
        }
    }
    */
}
int MovieBookingSystem::makeReservation ( const long movieID, const int row, const char col){
    // TODO:
    /*
    * Make a reservation for only one audience
    * Check if the movie exists, then check if the choosen seat is empty and occupiable
    * Make the reservation by creating a unique resID, this ID will be unique for not only the movie but whole system
    * Thus by using this resID you should be able to identify both the movie and the reservation seat and display a mesg that reservation is done
    * You can assume that row and col inputs are always correct
    * CHECK THE OCCUPIABILITY BEFORE CHECKING AVAILABILITY 
    * Use modular arithmetic to check occupiability
    */
    bool exists = false;
    int index = 0;
    for(int i = 0; i < movieCount; i++){
        if(movies[i].getId() == movieID){
            exists = true;
            index = i;
        }
    }
    //if(exists){
        //movies[i].addReservation( row, col);
    //}
}
void MovieBookingSystem::cancelReservations ( const int numRes, const int * resCode){
    // TODO:
    /*
    * This method will let user to cancel the specified list of resCodes
    * Check if all the resID's exist
    * If they all do exist, cancel them and display the time of the movie and cancelled seats
    * You are expected to preserve order of reservation codes in input when displaying the canceled reservations
    */
}
void MovieBookingSystem::showReservation ( const int resCode){
    //TODO:
    /*
    * Check the resID
    * If exists, display the time of the movie and reserved seats
    */
}
