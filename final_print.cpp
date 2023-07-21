#include "ds.h"

void debug_print(){
    cout<<"PRINT CALLED"<<endl;
    for(int i=0; i< dept.size(); i++){
        cout<<"TABLE FOR "<<dept[i]->name<<endl;
        for(int j=0; j< 5; j++){
            for(int k=0; k< 11; k++){
                // cout<<dept[i]->table[j][k].first<<" ";
                if( dept[i]->table[j][k].first == 0 ){
                    cout << "empty           ";
                }
                else{
                    cout<< dept[i]->table[j][k].second->course_code;
                    int le = dept[i]->table[j][k].second->course_code.length();
                    if(dept[i]->table[j][k].first == 2){
                        cout<<"(TUT)";
                        le += 5;
                    }
                    if(dept[i]->table[j][k].first == 3){
                        cout<<"(PRA)";
                        le += 5;
                    }
                    for(int letters=0; letters< 16-le; letters++){
                        cout<<" ";
                    }
                }
            }
            cout<<endl;
        }
    }
    cout << "COURSES AND CLASSROOMS ALLOCATED TO THEM:"<<endl;
    for(int i=0; i<ICs.size(); i++){
        cout<<ICs[i]->course_code<<"  -  ";
        for(int j=0; j<ICs[i]->allocated_classrooms.size(); j++){
            cout<<ICs[i]->allocated_classrooms[j]<<" / ";
        }
        cout<<endl;
    }
}

void classroom_print(){
    cout<<"CLASSROOM INFO"<<endl;
    for(int i=0; i< room.size(); i++){
        cout<<"TABLE FOR "<<room[i]->id<<endl;
        for(int j=0; j< 5; j++){
            for(int k=0; k< 11; k++){
                if( room[i]->class_table.table[j][k].first == 0 ){
                    cout << "empty           ";
                }
                else{
                    cout<< room[i]->class_table.table[j][k].second->course_code;
                    int le = room[i]->class_table.table[j][k].second->course_code.length();
                    if(room[i]->class_table.table[j][k].first == 2){
                        cout<<"(TUT)";
                        le += 5;
                    }
                    if(room[i]->class_table.table[j][k].first == 3){
                        cout<<"(PRA)";
                        le += 5;
                    }
                    for(int letters=0; letters< 16-le; letters++){
                        cout<<" ";
                    }
                }
            }
            cout<<endl;
        }
    }
}