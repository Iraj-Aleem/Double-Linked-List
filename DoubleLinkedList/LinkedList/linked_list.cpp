#include "linked_list.h"
#include<malloc.h>
#include<stdlib.h>
#include <iostream>
using namespace std;
void linked_list::create_list(int data){
    node *q,*tmp;
    tmp=new(struct node);
    tmp->info=data;
    tmp->link=NULL;

    if(start==NULL)	  start=tmp;	/*if list is empty*/
    else    	/*element inserted at end*/
    {
        q=start;
        while(q->link!=NULL)	q=q->link;
        tmp->prev = q;
        q->link = tmp;
        tmp->link = NULL;
    }

}


void linked_list::add_at_beginning(int data){
    node *temp;
    temp->info = data;
    temp->link = start;
    start->prev = temp;
    start = temp;
}

void linked_list::add_after(int data, int pos){
    struct node *tmp,*q;
        int i;
        q=start;
        for(i=0;i<pos;i++)
        {
            q=q->link;
            if(q==NULL)
            {
                cout<<"There are less than "<<pos<<" elements"<<endl;
                return;
            }
        }
        q->link = tmp;
        tmp->prev = q;
        tmp->link = q->link;

}

void linked_list::del(int data){
    struct node *tmp,*q;
        if(start->info==data)
        {
            tmp=start;
            start=start->link;	/*first element deleted*/
            delete(tmp);
            return;
        }
        q=start;
        while(q->link->link!=NULL)
        {
            if(q->link->info==data)	       /*element deleted in between*/
            {
                tmp=q->link;
                q->link=tmp->link;
                free(tmp);
                return;
            }
            q=q->link;
        }
        if(q->link->info==data)		/*last element deleted*/
        {
            tmp=q->link;
            free(tmp);
            q->link=NULL;
            return;
        }
        cout<<"Element "<<data<<" not found"<<endl;
}

void linked_list::display(){

    struct node *q;
        if(start==NULL)
        {
            cout<<"List is empty"<<endl;
            return;
        }
        q=start;
        cout<<"List is:"<<endl;
        while(q!=NULL)
        {
            cout<<q->info<<"   ";
            cout<< "Next: " << q->link<<"   ";
            cout<< "Prev: " << q->prev << endl;
            q=q->link;
        }
        cout<<endl;
}

void linked_list::count(){
    node *q=start;
        int cnt=0;
        while(q!=NULL)
        {
            q=q->link;
            cnt++;
        }
        cout<<"Number of elements are "<<cnt<<endl;
}

void linked_list::rev(){
    node *p1,*p2,*p3;
        if(start->link==NULL)  return;	/*only one element*/

        p1=start;
        p2=p1->link;
        p3=p2->link;
        p1->link=NULL;
        p2->link=p1;
        while(p3!=NULL)
        {
            p1=p2;
            p2=p3;
            p3=p3->link;
            p2->link=p1;
        }
        start=p2;
}

void linked_list::search(int data){
    node *ptr=start;
        int pos=1;
        while(ptr!=NULL)
        {
            if(ptr->info==data)
            {
                cout<<"Item "<<data<<" found at position "<<pos<<endl;
                return;
            }
            ptr=ptr->link;
            pos++;
        }
        if(ptr==NULL)	cout<<"Item "<<data<<" not found in list"<<endl;
}


void linked_list::concatinate(linked_list list){
    node *q = start;
    while (q->link != NULL)
    {
        q = q->link;
    }

    q->link = list.start;

}

void linked_list::clone(linked_list list){

    this->start = list.start;
}


void linked_list::move_start_to_last(){
    if (start == NULL || start->link == NULL) {
        return;
    }
    node *q = start;
    while (q->link != NULL)
    {
        q = q->link;
    }

    q->link = start;
    start = start->link;
    q->link->link = NULL;
}

void linked_list::move_last_to_start(){

    if(start == NULL || start->link == NULL)    return;

    node *q = start;
    
    while(q->link->link != NULL){
        q = q->link;
    }

    q->link->link = start;
    start = q->link;
    q->link = NULL;

}

void linked_list::split_at_center(){

    if(start == NULL || start->link == NULL)    return;

    linked_list list2;

    node *q = start;
    int len = 1, mid;

    while(q->link != NULL){
        q = q->link;
        len++;
    }

    mid = len/2;

    if(mid % 2 != 0)    mid++; 
    
    q = start; // Get back to the start node
    
    for(int i = 1; i < mid; i++){
        q = q->link;
    }
    list2.start = q->link;
    q->link = NULL;


    cout << "First Half: ";
    this->display();
    cout << endl << "Second Half: ";
    list2.display();
    cout << endl;
}


void linked_list::sublist(int startPos, int endPos){

    if(start == NULL || start->link == NULL)    return;

    node *q = start;

    linked_list sublist;
    int i;
    for(i = 1; i < startPos; i++)
        q = q->link;
    
    sublist.start = q;
    q = sublist.start;

    for(i; i < endPos; i++)
        q = q->link;
    q->link = NULL;

    sublist.display();

}
