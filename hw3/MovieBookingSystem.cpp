/*
*Author: Sarper Turan
*Student ID: 21903051
*Spring'21 CS201 Section01 Homework03
*/

#include <iostream>
#include "MovieBookingSystem.h"

using namespace std;

//CONSTRUCTORS
MovieBookingSystem::MovieBookingSystem(){
    movieCount = 0;
    resCount = 0;
    head = NULL;
}
MovieBookingSystem::~MovieBookingSystem(){
    while(!isListEmpty())
        remove(1);
}

//METHODS
void MovieBookingSystem::addMovie ( const long movieID, const int audienceRadius ){

    //dynamically allocated movie object
    //I create it before hand because if I don't it will create a problem if there is a movie with the same ID while printing out the date(ctime)
    Movie* newMovie = new Movie();
    (*newMovie).setId(movieID);
    (*newMovie).setRadius(audienceRadius);
    (*newMovie).setDate( movieID);

    //Allocate method which I use to show which seats are occupiable, does not work properly - although it is necessary to see total seats so I won't comment it
    (*newMovie).allocate( audienceRadius, numOfRow, numOfColumn );

    //Checking the audience radius
    if( audienceRadius < 0 || audienceRadius > 7){
           cout << "Audience radius should be between 0 and 7 inclusive." << endl;
           return;
    }
    //Checking if a movie with same ID exists
    for( int i = 1; i < movieCount+1; i++){
        if((find(i)->m).getId() == movieID){
            cout << "Movie at " << (*newMovie).getDate() << " already exists." << endl;
            delete newMovie;
            return;
        }
    }

    insert( getLength() + 1, *newMovie);
    cout << "Movie at " << (*newMovie).getDate() <<" has been added" <<endl;
    delete newMovie;
}
void MovieBookingSystem::cancelMovie ( const long movieID){
    int index = -1;
    for( int i = 1; i < getLength() + 1; i++){
        if((find(i)->m).getId() == movieID){
            index = i; //holds the index of the specified movie
            i = getLength() + 1; //exit
        }
    }

    Movie* tempMovie = new Movie();
    (*tempMovie).setDate( movieID);
    if ( index == -1) {
        cout << "Movie at " << (*tempMovie).getDate() << " does not exist. " << endl; 
        delete tempMovie;
        return;
    }
    //TODO: CANCEL RESERVATIONS
    remove (index);
    cout << "Movie at " << (*tempMovie).getDate() << " has been cancelled. " << endl;
    delete tempMovie;
}
void MovieBookingSystem::showAllMovies () const {
    if( getLength() == 0){
        cout << "No movie on show" << endl;
        return;
    }
    cout << "Movies on show:" << endl;
    for( int i = 1; i < getLength() + 1; i++){
        cout << "Movie at: " << (find(i)->m).getDate() << " ( " << (find(i)->m).getTotalSeats() << " available seats)" << endl;
    }
    return;
}
//void MovieBookingSystem::showMovie ( const long movieID) const{
    // TODO:
    /*
    * If there isn't a movie with the specified id, display warning
    * If it exists, display the seats in the format in the pdf where O's are available and X's are occupied
    * ONLY SHOW THE OCCUPIABLE SEATS, NOT THE COVID-19 SEATS, RADIUS!!!!
    */
//}
//int MovieBookingSystem::makeReservation ( const long movieID, const int row, const char col){
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
//}
//void MovieBookingSystem::cancelReservations ( ReservationList resCode ){
    // TODO:
    /*
    * This method will let user to cancel the specified list of resCodes
    * Check if all the resID's exist
    * If they all do exist, cancel them and display the time of the movie and cancelled seats
    * You are expected to preserve order of reservation codes in input when displaying the canceled reservations
    */
//}
//void MovieBookingSystem::showReservation ( const int resCode) const{
    //TODO:
    /*
    * Check the resID
    * If exists, display the time of the movie and reserved seats
    */
//}

//Linked List methods from the slides
MovieBookingSystem::MovieNode* MovieBookingSystem::find( int index ) const{
    if( index < 0 || index > getLength()){
        return NULL;
    } else {
        MovieNode* cur = head;
        for( int skip = 1; skip < index; ++skip){
            cur = cur->next;
        }
        return cur;
    }
}
int MovieBookingSystem::getLength() const{
    return movieCount;
}
bool MovieBookingSystem::isListEmpty() const{
    return movieCount == 0;
}

bool MovieBookingSystem::insert( int index, Movie mov){
    int newLength = getLength() + 1;
    if( index < 1 || index > newLength){
        return false;
    }

    MovieNode *newPtr = new MovieNode;
    movieCount = newLength;
    newPtr -> m = mov;

    if(index == 1){
        newPtr->next = head;
        head = newPtr;
    } else {
        MovieNode* prev = find(index - 1);
        newPtr->next = prev->next;
        prev->next = newPtr;
    }
    return true;
}
bool MovieBookingSystem::remove( int index){
    MovieNode* cur;
    if( index < 1 || index > getLength()){
        return false;
    }
    --movieCount;
    if(index == 1){
        cur = head;
        head = head->next;
    } else {
        MovieNode* prev = find(index-1);
        cur = prev->next;
        prev->next = cur->next;
    }
    cur -> next = NULL;
    delete cur;
    cur = NULL;
    return true;
}
bool MovieBookingSystem::retrieve( int index, Movie& movItem) const{ 
    if( index < 1 || index > getLength()){
        return false;
    }

    //getting the pointer to the node and then the data to the node
    MovieNode* cur = find(index);
    movItem = cur->m;
    return true;
}