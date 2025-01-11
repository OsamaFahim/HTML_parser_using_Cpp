//NAME : M . OSAMA FAHIM SECTION G ROLL NUM : 21i-0439

#pragma once
#include<iostream>
#include<fstream>
#include"helping.h"
#include"Notations.h"
#include"DEQueue.h"
#include"Queue.h"
#include"Stack.h"
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void takePointer_back(ifstream& current_file, long int positions_back)
{
	if (current_file)
	{
		long int current_location = current_file.tellg();
		current_file.seekg(current_location - positions_back);
	}
}

void readtill(string& str, ifstream& currentFile)
{
	char reading_ch = ' ';

	if (currentFile) reading_ch = currentFile.get();

	while (currentFile && reading_ch != '|')
	{
		str += reading_ch;
		reading_ch = currentFile.get();
	}
}

bool find_priority(DEQueue*& cache, int priority)
{
	doubly_node* traverser = cache->front;

	while (traverser != nullptr && traverser->val != priority)
		traverser = traverser->next;

	if (traverser)
	{
		doubly_node* temp = traverser;
		if (cache->front == cache->back)
			cache->front = cache->back = nullptr;
		else if (temp == cache->front)
			temp->next->prev = nullptr, cache->front = cache->front->next;
		else if (temp == cache->back)
			temp->prev->next = nullptr, cache->back = cache->back->prev;
		else
		{
			doubly_node* new_prev = temp->prev;
			doubly_node* new_next = temp->next;
			new_prev->next = new_next;
			new_next->prev = new_prev;
		}
		delete temp, temp = nullptr;
		cache->size--;
		cache->page_hit++;
		return true;
	}
	return false;
}

void LRU(int priority, DEQueue*& cache)
{
	bool priority_finder = find_priority(cache, priority);

	if (cache->size < 4 && !priority_finder)
	{
		cache->page_fault++;
		cache->enque_front(priority);
	}
	else
	{
		if (!priority_finder)
		{
			cache->page_fault++;
			cache->deque_back();
		}

		cache->enque_front(priority);
	}
}


void label_component(int**& input_arr, int starting_row, int starting_col, int& total_galaxies, Mat& input_image)
{
	Mat output_image = Mat(input_image.rows, input_image.cols, input_image.type());

	make_white(output_image, input_image.rows, input_image.cols);
	string address = "D:/data structures university/Assignment2/Images/out";
	static int cap = 0;


	Queue* location_queue = new Queue();

	location_queue->enque(starting_row, starting_col);

	while (!location_queue->empty())
	{
		int i = location_queue->top()->row, j = location_queue->top()->col;

		if (input_arr[i][j] != 0 && (i != 0 && j != 0 && i != input_image.rows - 1 && j != input_image.cols - 1))
		{
			for (int p = i - 1; p < (i - 1) + 3; p++)
			{
				for (int q = j - 1; q < (j - 1) + 3; q++)
				{
					if (p == i && q == j)
						continue;
					if (input_arr[p][q] == 255)
						location_queue->enque(p, q);
				}
			}
		}
		set_value(output_image, i, j, 255);
		input_arr[i][j] = 0;
		location_queue->deque();
	}
	total_galaxies++;
	cap++;
	address = address + (to_string(cap) + ".png");
	imwrite(address, output_image);
	imshow("Component number" + to_string(total_galaxies), output_image);
	waitKey();

}

int BFS(Mat& input_image)
{
	int total_galaxies = 0;

	int** input_array = Mat_toarr(input_image);


	for (int i = 0; i < input_image.rows; i++)
		for (int j = 0; j < input_image.cols; j++)
			if (input_array[i][j] == 255)
				label_component(input_array, i, j, total_galaxies, input_image);

	return total_galaxies;
}

void label_component_stack(int**& input_arr, int starting_row, int starting_col, int& total_galaxies, Mat& input_image)
{

	Mat output_image = Mat(input_image.rows, input_image.cols, input_image.type());

	make_white(output_image,input_image.rows,input_image.cols);
	
	Stack_src* location_queue = new Stack_src();

	push(location_queue, starting_row, starting_col);
	string address = "D:/data structures university/Assignment2/Images/out";
	static int cap = 0;

	while (!empty(location_queue))
	{
		int i = Top(location_queue)->row, j = Top(location_queue)->col;
		pop(location_queue);

		if (input_arr[i][j] != 0 && (i != 0 && j != 0 && i != input_image.rows - 1 && j != input_image.cols - 1))
		{
			for (int p = i - 1; p < (i - 1) + 3; p++)
			{
				for (int q = j - 1; q < (j - 1) + 3; q++)
				{

					if (p == i && q == j)
						continue;
					if (input_arr[p][q] == 255)
						//push(location_queue, p, q);
						push(location_queue, p, q);
				}
			}
		}
		set_value(output_image, i, j, 255);
		input_arr[i][j] = 0;
	}
	total_galaxies++;
	cap++;
	address = address + (to_string(cap) + ".png");
	imwrite(address, output_image);
	imshow("Component number" + to_string(total_galaxies), output_image);
	waitKey();

}

int DFS(Mat& input_image)
{
	int total_galaxies = 0;

	int** input_array = Mat_toarr(input_image);

	for (int j = 0; j < input_image.cols; j++)
		for (int i = 0; i < input_image.rows; i++)
			if (input_array[i][j] == 255)
				label_component_stack(input_array, i, j, total_galaxies, input_image);

	return total_galaxies;
}

void perform_src(string functionality,string filename,ofstream& output_file)
{
	int length = getLength(functionality);
	functionality = reduce_ambiguity(functionality,length);

	for (int i = 0; i < length; i++)
		if (functionality[i] == '\\')
			functionality[i] = '/';

	string test = filename + functionality + ".png";
	ifstream test_obj(test);

	if (test_obj)
	{
		Mat cimage = imread(filename + functionality + ".png");
		Mat img;
		cvtColor(cimage, img, COLOR_BGR2GRAY);
		output_file << BFS(img);
	}
	else
		output_file << " INVALID PATH OR SYNTAX ERROR ";
}

void perform_head(ifstream& currentFile, string filename, string functionality,ofstream& output_file)
{
	output_file << functionality;
}

void perform_tab(ofstream& output_file)
{
	output_file << '\t';
}

void perform_paragrapgh(string functionality, ofstream& output_file)
{
	output_file << functionality;
}

void perform_priority(string functionality,DEQueue*& cache)
{
	int priority = string_to_int(functionality);

	LRU(priority, cache);
}

string infix_to_postfix(string infix)
{
	int length = getLength(infix);

	if (!infix_validity(infix,length))
		return "INVALID EXPRESSION";

	string postfix = "";
	Stack<string>* operands = new Stack<string>;

	for (int i = 0; i < length; i++)
	{
		string temp = "";

		if (!operand(infix[i]))
			temp = infix[i];
		else
		{
			while (infix[i] != '\0' && operand(infix[i]))
				temp += infix[i++];

			if (!operand(infix[i]) && i > 0) i--;
		}
		prefix_or_postfix(i, operands, infix, postfix, "(", ")", temp);
	}

	while (!empty(operands))
		postfix += Top(operands), pop(operands);

	return postfix;
}

string infix_to_prefix(string infix)
{
	int length = getLength(infix);

	if (!infix_validity(infix,length))
		return "INVALID EXPRESSION";

	Stack<string>* operands = new Stack<string>;
	string prefix = "";
	
	for (int i = length-1; i >= 0; i--)
	{
		string temp = "";

		if (!operand(infix[i]))
			temp = infix[i];
		else
		{
			while (i >= 0 && operand(infix[i]))
				temp += infix[i--];

			if (i>=0 && !operand(infix[i])) i++;
		}
		prefix_or_postfix(i, operands, infix, prefix, ")", "(", temp);
	}

	while (!empty(operands))
		prefix += Top(operands), pop(operands);

	reverse_str(prefix);

	return prefix;
}

string evaluation_postfix(string postfix)
{
	int length = getLength(postfix);

	int start = get_start(postfix), end = get_end(postfix, length);

	if (!postfix_validity(postfix,length,start,end))
		return "INVALID EXPRESSION";

	Stack<string>* operands_stack = new Stack<string>;

	for (int i = start; i <= end; i++)
	{
		string temp = "";

		if (!operand(postfix[i]))
			temp = postfix[i];
		else
		{
			while (postfix[i] != '\0' && !special_character(postfix[i]) && operand(postfix[i]))
				temp += postfix[i++];

			if (!operand(postfix[i]) && i > 0) i--;
		}

		if (temp != "")
		{
			if (operand(temp))
				push(operands_stack, temp);
			else
			{
				if (empty(operands_stack))
					return "INVALID EXPRESSION";
				string opr1 = Top(operands_stack);
				pop(operands_stack);
				if (empty(operands_stack))
					return "INVALID EXPRESSION";
				string opr2 = Top(operands_stack);
				pop(operands_stack);
				push(operands_stack, solve(opr2, opr1, temp));
			}
		}
	}

	return Top(operands_stack);
}

string validate_and_solve(string expression, string notaion(string))
{
	int length = getLength(expression);
	string infix = reduce_ambiguity(expression,length);

	if (valid_paranthesis(infix) && not_continous_operators(infix))
		return notaion(infix);
	else
		return "INVALID EXPRESSION";
}