/*
*Reservation Header
*Author: Sarper Turan
*Student ID: 21903051
*CS201 Section01 Homework01
*/

class Reservation {
public:
    Reservation();
    int getResCode();
    int getRow();
    char getCol();

    void setResCode( int id);
    void setRowNo( int rowN);
    void setColNo( char colN);
private:
    int resId;
    int row;
    int col;
};