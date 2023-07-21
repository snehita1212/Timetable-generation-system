#include "ds.h"
using namespace std;

bool checkmy_instructor_slot(instructor *Prof, slot* s ){
    if (s==NULL)
    {
        return true;
    }
    
    slot* temp=Prof->first_slot;
    while (temp!=NULL)
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
    if (s==NULL)
    {
        return;
    }
    
    slot* temp=Prof->first_slot;
    if(temp==NULL){
        Prof->first_slot=s;
        s->next=NULL;
        return;
    }
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=s;
    temp=temp->next;
    temp->next=NULL;
    return;
}