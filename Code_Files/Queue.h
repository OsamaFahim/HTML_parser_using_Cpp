//NAME : M . OSAMA FAHIM SECTION G ROLL NUM : 21i-0439

#pragma once

#include<iostream>

using namespace std;

struct node_src
{
    int row;
    int col;
    node_src* next;
    node_src()
    {
        row = col = 0, next = nullptr;
    }

    node_src(int i, int j)
    {
        this->row = i;
        this->col = j;
        next = nullptr;
    }
};


struct Queue
{
    node_src* front;
    node_src* back;
    Queue();
    bool empty();
    void enque(int row, int col);
    void deque();
    node_src* top();
    void display();
};

Queue::Queue()
{
    front = back = nullptr;
}

bool Queue::empty()
{
    return (!front && !back);
}


void Queue::enque(int row, int col)
{
    node_src* new_node = new node_src(row, col);

    if (!back)
    {
        front = back = new_node;
        return;
    }
    back->next = new_node, back = back->next;
}

void Queue::deque()
{
    if (!front)
    {
        cout << "Queue underflow\n";
        return;
    }
    node_src* temp = front;
    front = front->next;

    if (!front)
        back = nullptr;

    delete temp;
}

node_src* Queue::top()
{
    if (front)
        return front;

    return nullptr;
}

