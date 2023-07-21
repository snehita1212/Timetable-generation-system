#include "ds.h"

bool allocate_dc_lecture(course* dc, int l, bool tut, slot *& head, int dept_no){
    slot* temp_slot = new slot();
    temp_slot->day = 0;
    temp_slot->time_slot = 0;
    while(l >0){
        bool flag = 0;
        while(temp_slot->day < working_days || temp_slot->time_slot < no_of_slots){
            if((dept[dept_no]->table[temp_slot->day][temp_slot->time_slot]).first ==0){
                flag = 1;
                if(head == NULL){              // checking if slot is being allocated for the 1st time or not
                    head = temp_slot;
                    temp_slot = new slot();
                    temp_slot->day = head->day +1;
                }
                else{                          // updating Linked List for that course 
                    slot* temp = head;
                    while(temp->next != NULL){
                        temp = temp->next;
                    }
                    temp->next = temp_slot;
                    temp_slot = new slot();
                    // cout<<temp->day<<endl;
                    temp_slot->day = temp->next->day +1;
                }
                temp_slot->time_slot = 0;      // not being done for if statement?
                l--;

                break;
            }
            else{
                if(temp_slot->time_slot< no_of_slots - 1){            // checking if more slots left in temp_slot-> day
                    temp_slot->time_slot += 1;
                }
                else{
                    temp_slot->day += 1;
                    temp_slot->time_slot = 0;
                }
                break;
            }
        }
        if(flag == 0){
            cout <<" ERROR : Course" << dc->course_code<<" COULDN'T ALLOCATE"<<l<<" LECTURES"<<endl;
            head = NULL;
            return false;
        }
    }
    slot * temp = head;
    while(temp){
        cout<<"Allocating"<<dc->course_code<<" "<<temp->day<<" "<<temp->time_slot<<endl;
        if(tut){
            dept[dept_no]->table[temp->day][temp->time_slot] = make_pair(2,dc);
        }
        else{
            dept[dept_no]->table[temp->day][temp->time_slot] = make_pair(1,dc);
        }
        temp = temp->next;
    }
    cout<<endl; 
    return true;

}

bool allocate_dc(vector<DC*> dc){
    
    vector<DC*> :: iterator itr;
    for(itr = dc.begin(); itr != dc.end(); itr++){
        for(int i=0;i<((*itr)->DCs).size();i++){
            if((*itr)->DCs[i]->l!=0){
                allocate_dc_lecture((*itr)->DCs[i], (*itr)->DCs[i]->l, false, (*itr)->DCs[i]->first_l, (*itr)->dept_no);
            }
            if((*itr)->DCs[i]->l!=0){
                allocate_dc_lecture((*itr)->DCs[i], (*itr)->DCs[i]->t, true, (*itr)->DCs[i]->first_t, (*itr)->dept_no);
            }

        }
    }

    
}



