//NAME : M . OSAMA FAHIM SECTION G ROLL NUM : 21i-0439

#include<iostream>
#include"Parsing.h"

using namespace std;

int main()
{
	DEQueue* cache = new DEQueue;
	string filename = "D:/data structures university/Assignment2/";
	ofstream output_file(filename + "/Output_files/Result.txt");

	for (int i = 0; i < 8; i++)
	{
		Parsing(filename, cache,i,output_file);
		output_file << "\n*******************************************END******************************************\n";
	}

	output_file << "\nTOTAL HITS : " << cache->page_hit << "     TOTAL FAULTS : " << cache->page_fault << '\n';
}

