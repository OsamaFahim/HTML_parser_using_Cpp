//NAME : M . OSAMA FAHIM SECTION G ROLL NUM : 21i-0439

#pragma once
#pragma once
#include<iostream>

using namespace std;

struct doubly_node
{
	int val;
	doubly_node* next;
	doubly_node* prev;

	doubly_node()
	{
		val = -1;
		next = prev = nullptr;
	}

	doubly_node(int val)
	{
		this->val = val;
		next = prev = nullptr;
	}
};

struct DEQueue
{
	doubly_node* front;
	doubly_node* back;
	int size, page_hit, page_fault;

	DEQueue();
	bool empty();
	void enque_front(int);
	void deque_back();
};

DEQueue::DEQueue()
{
	page_hit = page_fault = size = 0;
	front = back = nullptr;
}

bool DEQueue::empty()
{
	return (front == nullptr && back == nullptr);
}

void DEQueue::enque_front(int val)
{
	doubly_node* new_node = new doubly_node(val);
	if (front == nullptr)
	{
		front = back = new_node;
		this->size++;
		return;
	}

	doubly_node* temp = front, * temp_next = front->next;
	front = new_node;
	front->next = temp, temp->prev = front, temp->next = temp_next;
	this->size++;
}

void DEQueue::deque_back()
{
	if (!empty())
	{
		doubly_node* temp = back;
		back = back->prev;
		back->next = nullptr;
		delete temp, temp = nullptr;
		this->size--;
	}
}