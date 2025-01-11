//NAME : M . OSAMA FAHIM SECTION G ROLL NUM : 21i-0439

#pragma once
#include<iostream>
#include"FileRead_Stack.h"

int get_precedence(char ch)
{
	return (ch == '$')  ? 4 : (ch == '^') ? 3 : (ch == '*' || ch == '/') ? 2 : (ch == '+' || ch == '-') ? 1 : 0;
}

bool operand(char ch)
{
	return ((ch != '$') && ch != '^' && ch != '*' && ch != '/' && ch != '+' && ch != '-' && ch != '(' && ch != ')');
}

int get_precedence(string str)
{
	return  (str == "$") ? 4 : (str == "^") ? 3 : (str == "*" || str == "/") ? 2 : (str == "+" || str == "-") ? 1 : 0;
}

bool operand(string  str)
{
	return (str != "$" && str != "^" && str != "*" && str != "/" && str != "+" && str != "-" && str != "(" && str != ")");
}

bool validity_check_braces(Stack<char>* paranthesis, char ch)
{
	return  (!empty(paranthesis) && ch == ')' && Top(paranthesis) == '(');
}

bool infix_validity(string infix,int length)
{
	return ((operand(infix[0]) || infix[0] == '(') && operand(infix[length - 1]) || infix[length-1] == ')');
}

bool special_character(char ch)
{
	return (ch == '\n' || ch == '\t' || ch == '.' || ch == ' ');
}

bool check_for_braces(string postfix,int length)
{
	for (int i = 0; i < length; i++)
		if (postfix[i] == '(' || postfix[i] == ')')
			return false;
	
	return true;
}

int get_start(string expression)
{
	int i = 0 , length = getLength(expression);
	while (i < length && special_character(expression[i++]));
	return --i;
}

int get_end(string expression, int length)
{
	int i = length - 1;
	while (i>=0 && special_character(expression[i--]));
	return ++i;
}


bool postfix_validity(string postfix,int length,int start,int end)
{
	return (check_for_braces(postfix,length) && operand(postfix[start]) && !operand(postfix[end]));
}

bool basic_airthmetic_operator(char ch)
{
	return (ch == '$' || ch == '+' || ch == '*' || ch == '/' || ch == '^');
}

bool valid_paranthesis(string expression)
{
	int len = getLength(expression);
	Stack<char>* paranthesis = new Stack<char>;

	for (int i = 0; i < len; i++)
	{
		if (expression[i] == '(')
			push(paranthesis, expression[i]);
		else if (expression[i] == ')')
		{
			if (validity_check_braces(paranthesis, expression[i]))
				pop(paranthesis);
			else
				return false;
		}
	}
	return (empty(paranthesis)) ? true : false;
}

bool not_continous_operators(string expression)
{
	int len = getLength(expression);

	for (int i = 0; i < len; i++)
	{
		char chk = expression[i];
		if (basic_airthmetic_operator(expression[i]) || expression[i] == '(')
		{
			if (expression[i + 1] == '\0') return false;
			i++;

			if (chk == '(')
			{
				if (basic_airthmetic_operator(expression[i]))
					return false;
			}
			else if (basic_airthmetic_operator(chk))
			{
				if (basic_airthmetic_operator(expression[i]) || expression[i] == ')')
					return false;
			}
		}
	}
	return true;
}

string reduce_ambiguity(string str,int length)
{
	string temp = "";
	for (int i = 0; i < length; i++)
		if(!special_character(str[i]))
			temp += str[i];

	return temp;
}

void prefix_or_postfix(int i, Stack<string>*& operands, string infix, string& result, string opening_bracket, string closing_bracket, string temp)
{
	if (temp != "")
	{
		if (operand(temp))
			result += temp;
		else
		{
			if (temp != closing_bracket && (empty(operands) || temp == opening_bracket || get_precedence(Top(operands)) < get_precedence(temp)))
				push(operands, temp);
			else
			{
				while (!empty(operands) && Top(operands) != opening_bracket && (get_precedence(Top(operands)) >= get_precedence(temp)))
				{
					result += Top(operands);
					pop(operands);
				}

				if (!empty(operands) && Top(operands) == opening_bracket && temp == closing_bracket) pop(operands);
				else push(operands, temp);
			}
		}
	}
}


string solve(string opr1, string opr2, string Operator)
{
	if (Operator == "+")
		return "(" + opr1 + "+" + opr2 + ")";
	else if (Operator == "*")
		return  "(" + opr1 + "*" + opr2 + ")";
	else if (Operator == "/")
		return  "(" + opr1 + "/" + opr2 + ")";
	else if (Operator == "-")
		return  "(" + opr1 + "-" + opr2 + ")";
	else if (Operator == "^")
		return  "(" + opr1 + "^" + opr2 + ")";
}