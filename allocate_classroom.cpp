#include "ds.h"

bool allocate(classroom* room, course* c){

    slot * temp = c->first_l;
    c->allocated_classrooms.push_back(room->id);
    while(temp){
        cout<< "running"<<endl;
        room->class_table.table[temp->day][temp->time_slot] = make_pair(1, c);
        // cout<<"allocating room " <<room->id <<" to "<<c->course_code<<endl;
        temp = temp->next;
    }
    temp = c->first_t;
    while(temp){
        room->class_table.table[temp->day][temp->time_slot] = make_pair(2, c);
        // cout<<"allocating room " <<room->id <<" to "<<c->course_code<<endl;
        temp = temp->next;
    }
    return 1;

}

int allocate_classroom_same(vector<course*> ICs){
    sort(room.begin(), room.end(), [](classroom*& lhs, classroom* rhs){return lhs->capacity < rhs->capacity;});
    sort(ICs.begin(), ICs.end(), [](course*& lhs, course* & rhs){return lhs->registered_stu > rhs->registered_stu;});
    
    for(int i=0;i<ICs.size();i++){
        int starting_index;
        int flag(0);
        for(int j=0; j < room.size(); j++){
            if(room[j]->capacity >= ICs[i]->registered_stu){
                starting_index = j;
                break;
            }
        }
        int check = 0;
        for(int j=starting_index;j<room.size();j++){
            flag=0;
            slot* temp = ICs[i]->first_l;
            int twice=0;
            while(temp != NULL && twice !=1){
                if(room[j]->class_table.table[temp->day][temp->time_slot].first==0){
                    temp = temp->next;
                    continue;
                }
                else{
                    flag=1;
                    break;
                }
                if(temp == NULL){
                    twice = 1;
                    temp = ICs[i]->first_t;
                }
            }
            if(flag==0){
                check = allocate(room[j], ICs[i]);
                break;
            }
        }
        if(check){
            // cout<<"CLASROOM ALLOCATED"<<endl;
        }
        else{
            cout<<"allocation not possible for" << ICs[i]->course_code <<endl;
        // call allocate_room_different
        }
    }
    
    return 0;
}