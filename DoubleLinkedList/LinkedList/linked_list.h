#ifndef linked_list_H
#define linked_list_H
#include <iostream>

#include "node.h"

struct linked_list{

    node *start = NULL;

    void create_list(int);
    void add_at_beginning(int);
    void add_after(int, int);
    void del(int);
    void display();
    void count();
    void rev();
    void search(int);
    void concatinate( linked_list list );
    void clone(linked_list list);
    void move_start_to_last();
    void move_last_to_start();
    void split_at_center();
    void sublist(int, int);
};

#endif