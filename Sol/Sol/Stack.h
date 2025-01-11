#pragma once
#include<iostream>

using namespace std;

struct node_img
{
    int row;
    int col;
    node_img* next;
    node_img()
    {
        row = col = 0, next = nullptr;
    }

    node_img(int i, int j)
    {
        this->row = i;
        this->col = j;
        next = nullptr;
    }

    node_img(int i,int j, node_img* next)
    {
        this->row = i;
        this->col = j;
        this->next = next;
    }
};

struct Stack_src
{
    node_img* top;
    Stack_src() { top = nullptr; }
};

bool empty(Stack_src* head)
{
    return (head->top == nullptr);
}

void push(Stack_src* head, int i,int j)
{
    node_img* new_next = head->top;
    head->top = new node_img(i,j, new_next);
}

void pop(Stack_src* head)
{
    if (empty(head))
    {
        cout << "Stack underflow\n";
        return;
    }
    *(&head->top) = head->top->next;
}

node_img* Top(Stack_src* head)
{
    return (!empty(head)) ? head->top : nullptr;
}


