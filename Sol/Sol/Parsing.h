//NAME : M . OSAMA FAHIM SECTION G ROLL NUM : 21i-0439

#pragma once
#include"tag_functions.h"

using namespace std;

bool common_tags(string tagname)
{
	return (tagname == "head" || tagname == "paragraph" || tagname == "priorty" ||
		tagname == "post_exp" || tagname == "sol_exp" || tagname == "post_exp" ||
		tagname == "tab" || tagname == "src" || tagname == "start" || tagname == "In_exp");
}

void check_tag(ifstream& currentFile, Stack<string>*& tags,ofstream& output_file)
{
	char chk_tag = ' ';
	string tagname = "" ;

	if (currentFile)  chk_tag = currentFile.get();

	if (chk_tag != '\\')
		tagname += chk_tag;

	readtill(tagname, currentFile);


	if (chk_tag != '\\')
	{
		if (Top(tags) == "sol_exp" || Top(tags) == "pre_exp" ||
			Top(tags) == "post_exp" || Top(tags) == "src"    || 
			Top(tags) == "priorty"  || Top(tags) == "tab"	  ||
			Top(tags) ==  "priorty")
		{
			output_file << "  SYNTAX ERROR";
			pop(tags);
		}
		push(tags, tagname);

	}
	else
	{
		if (Top(tags) == tagname)
			pop(tags);
		else
		{
			output_file << " SYNTAX ERROR";
			if (Top(tags) != "paragrapgh" && Top(tags) != "start")
				if (!empty(tags)) pop(tags);
		}
	}
}

void perform_tag(Stack<string>*& tags, ifstream& currentFile, string filename,DEQueue*& cache,bool start,ofstream& output_file)
{
	string functionality = "";

	readtill(functionality, currentFile);
	takePointer_back(currentFile, 1);

	if (start && Top(tags) == "head")
		perform_head(currentFile, filename, functionality,output_file);
	else if (start && Top(tags) == "tab")
		perform_tab(output_file);
	else if (start && Top(tags) == "paragraph")
		perform_paragrapgh(functionality, output_file);
	else if (start && Top(tags) == "post_exp" || start && Top(tags) == "In_exp")
		output_file << validate_and_solve(functionality, infix_to_postfix);
	else if (start && Top(tags) == "pre_exp")
		output_file << validate_and_solve(functionality, infix_to_prefix);
	else if (start && Top(tags) == "sol_exp")
		output_file << evaluation_postfix(functionality);
	else if (start && Top(tags) == "priorty")
		perform_priority(functionality, cache);
	else if (start && Top(tags) == "src")
		perform_src(functionality, filename,output_file);
	else if(!common_tags(Top(tags)))
		perform_paragrapgh(functionality, output_file);
}

void Parsing(string filename,DEQueue*& cache,int i,ofstream& output_file)
{
	ifstream current_file(filename+"Test_files/Test-" + to_string(i+1) + ".txt");
	Stack<string>* tags = new Stack<string>;
	char reading_ch = ' ';
	bool start = false;

	while (current_file)
	{
		if (!empty(tags) && Top(tags) == "start")
			start = true;

		if (!empty(tags))
			perform_tag(tags, current_file, filename,cache,start,output_file);

		reading_ch = current_file.get();

		if (reading_ch == '|')
			check_tag(current_file, tags,output_file);
	}
	if (!empty(tags))
		output_file << "\nError due to invalid tag matches/match\n";
	else
		output_file << "\nNo dangling tag remains\n";
}