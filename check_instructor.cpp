#include "ds.h"
using namespace std;

bool checkmy_instructor_slot(instructor *Prof, slot* s ){
    if (!s)
    {
        return true;
    }
    
    slot* temp=Prof->first_slot;
    while (temp)
    {
        if (temp->day==s->day && temp->time_slot==s->time_slot )
        {
            return false;
        }
        temp=temp->next;
        
    }
    return true;
}

void add_instructor_slot(instructor *Prof, slot* s){
    if (!s)
    {
        return;
    }
    
    slot* temp=Prof->first_slot;
    if(!temp){
        Prof->first_slot=s;
        s->next=NULL;
        return;
    }
    while (temp->next)
    {
        temp=temp->next;
    }
    temp->next=s; //adding slot s to prof's schedule
    temp=temp->next;
    temp->next=NULL;
    return;
}
