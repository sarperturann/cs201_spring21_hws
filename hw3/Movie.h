/*
*Author: Sarper Turan
*Student ID: 21903051
*Spring'21 CS201 Section01 Homework03
*/

#include <string>
#include "ReservationList.h"
#include <ctime>

using namespace std;

class Movie {
public:

    //CONSTRUCTORS
    Movie();
    ~Movie();

    //GETTERS
    long getId();
    int getRadius();
    int getTotalSeats();
    int getRowSize();
    int getColSize();
    string getDate();
    //SETTERS
    void setId(long id);
    void setRadius(int rad);
    void setRowSize(int rowNo);
    void setColSize(char colNo);
    void setTotalSeats( int tot);
    void setDate( long d);

    void allocate( const int radius, const int row, const int column);

    //void addReservation( int row, char col);
    int getLength() const;
    bool isListEmpty() const;
    bool insertRow( int index, int num);
    bool insertCol( int index, char c);
    
private:
    struct SeatNode{
        int row;
        char column;
        SeatNode* next;
    };
    int size;
    int row;
    char column;
    SeatNode* head;
    SeatNode *find(int index) const;
    long movieID;
    int radius;
    int seats;
    int rowSize;
    int colSize;
    string date;
};