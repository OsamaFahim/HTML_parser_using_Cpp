//NAME : M . OSAMA FAHIM SECTION G ROLL NUM : 21i-0439

#include<iostream>

using namespace std;

template<typename type>
struct Node_file
{
	type val;
	Node_file* next;

	Node_file()
	{
		val = "";
		next = nullptr;
	}

	Node_file(type val, Node_file<type>* next)
	{
		this->val = val;
		this->next = next;
	}
};

template<class type>
struct Stack
{
	Node_file<type>* top;
	Stack() { top = nullptr; }
};

template<class type>
bool empty(Stack<type>* head)
{
	return (head->top == nullptr);
}

template<class type>
void push(Stack<type>* head, type val)
{
	Node_file<type>* new_next = head->top;
	head->top = new Node_file<type>(val, new_next);
}

template<class type>
void pop(Stack<type>* head)
{
	if (empty(head))
	{
		cout << "Stack underflow\n";
		return;
	}
	*(&head->top) = head->top->next;
}

template<class type>
type Top(Stack<type>* head)
{
	return (!empty(head)) ? head->top->val : type("-1");
}
