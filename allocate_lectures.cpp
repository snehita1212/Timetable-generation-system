#include "ds.h"

bool allocate_lecture(course* IC, int l, bool tut, slot *& head){
    // cout<<"allocating lecture for "<< IC->course_code<<" " << l <<endl;
    cout<<l<<endl;
    slot* temp_slot = new slot();
    temp_slot->day = 0;
    temp_slot->time_slot = 0;
    bool flag = 0;
    while(l > 0){
        // cout<<"lecture left "<<l<<endl;
        while(temp_slot->day < working_days || temp_slot->time_slot < no_of_slots){
            bool flag_busy = 0;
            for(int i=0 ; i< dept.size(); i++){
                instructor * x = map_instructor[IC->course_code];
                bool a = checkmy_instructor_slot(x ,temp_slot);
                if( (dept[i]->table[temp_slot->day][temp_slot->time_slot]).first != 0 && a ){
                    
                    flag_busy = 1;
                    if(temp_slot->time_slot < no_of_slots - 1){
                        // cout<<"next slot"<<endl;
                        temp_slot->time_slot += 1;
                        // cout<<temp_slot->day<<" "<<temp_slot->time_slot<<endl;
                    }
                    else{
                        // cout<<"next day"<<endl;
                        temp_slot->day += 1;
                        temp_slot->time_slot = 0;
                        // cout<<temp_slot->day<<" "<<temp_slot->time_slot<<endl;
                    }
                    break;
                }
            }
            if(flag_busy == 0){
                // cout<<"lecture allocated"<<endl;
                flag =1;
                // cout<<"enter"<<temp_slot->day<<" ";
                // cout<<temp_slot->time_slot<<endl;
                if(!head){
                    head = temp_slot;
                    temp_slot = new slot();
                    temp_slot->day = head->day +1;
                }
                else{
                    slot* temp = head;
                    while(temp->next){
                        temp = temp->next;
                    }
                    temp->next = temp_slot;
                    temp_slot = new slot();
                    // cout<<temp->day<<endl;
                    temp_slot->day = temp->next->day +1;
                }
                temp_slot->time_slot = 0;
                l--;

                break;
            }
        }
        if(flag == 0){
            cout << "ERRORRRRR: THE COURSE" << IC->course_code << "COULDN'T GET ALL LECTURES ALLOTED "<< l <<"lectures left"<<endl;
            head = NULL;
            return false;
        }
    }
    slot * temp = head;
    // if(temp){
    //     cout<<"its not null"<<endl;
    // }
    // else{
    //     cout<<"its nulll"<<endl;}
    // 
    while(temp){
        cout<<"allocating "<<IC->course_code<<" "<<temp->day<<" "<<temp->time_slot <<endl;
        for(int i=0; i<dept.size(); i++){
            if(tut){
                dept[i]->table[temp->day][temp->time_slot] = make_pair(2,IC) ;
                cout<<"tutorial" << dept[i]->table[temp->day][temp->time_slot].first<<endl;
            }
            else{
                dept[i]->table[temp->day][temp->time_slot] = make_pair(1,IC) ;
                // dept[i]->table[temp->day][temp->time_slot].second = IC;
            }
        }
        temp = temp->next;
    }
    cout<<endl;
    return true;
}
