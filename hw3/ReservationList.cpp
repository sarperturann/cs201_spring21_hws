/*
*Author: Sarper Turan
*Student ID: 21903051
*Spring'21 CS201 Section01 Homework03
*/

#include <iostream>
#include "ReservationList.h"

using namespace std;    
        
        
ReservationList::ReservationList(){
    size = 0;
    head = NULL;
}
ReservationList::ReservationList( const ReservationList& aList ){
    size = 0;
    head = NULL;
}

ReservationList::~ReservationList(){
    while(!isEmpty())
        remove(1);
}
bool ReservationList::isEmpty() const{
    return size == 0;
}
int ReservationList::getLength() const {
    return size;
}
bool ReservationList::retrieve(int index, int& resCode) const{
    if( index < 1 || index > getLength()){
        return false;
    }

    //getting the pointer to the node and then the data to the node
    ReservationNode* cur = find(index);
    resCode = cur->Code;
    return true;
}
bool ReservationList::insert(int index, int resCode){
    int newLength = getLength() + 1;
    if( index < 1 || index > newLength){
        return false;
    }

    ReservationNode *newPtr = new ReservationNode;
    size = newLength;
    newPtr -> Code = resCode;

    if(index == 1){
        newPtr->next = head;
        head = newPtr;
    } else {
        ReservationNode* prev = find(index - 1);
        newPtr->next = prev->next;
        prev->next = newPtr;
    }
    return true;
}
bool ReservationList::remove(int index){
    ReservationNode* cur;
    if( index < 1 || index > getLength()){
        return false;
    }
    --size;
    if(index == 1){
        cur = head;
        head = head->next;
    } else {
        ReservationNode* prev = find(index-1);
        cur = prev->next;
        prev->next = cur->next;
    }
    cur -> next = NULL;
    delete cur;
    cur = NULL;
    return true;
}
ReservationList::ReservationNode* ReservationList::find(int index) const{
    if( index < 0 || index > getLength()){
        return NULL;
    } else {
        ReservationNode* cur = head;
        for( int skip = 1; skip < index; ++skip){
            cur = cur->next;
        }
        return cur;
    }
}