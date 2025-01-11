//NAME : M . OSAMA FAHIM SECTION G ROLL NUM : 21i-0439

#pragma once
#include<iostream>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/opencv.hpp>


using namespace std;
using namespace cv;

int string_to_int(string str)
{
	int priority_val = 0, i = -1;

	while (str[++i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			priority_val = 10 * priority_val + (str[i] - 48);
	}

	return priority_val;
}

int getLength(string str)
{
	int i = -1;
	while (str[++i] != '\0');
	return i;
}

void reverse_str(string& str)
{
	int length = getLength(str);

	for (int i = 0, j = length - 1; i < length / 2 && j >= length / 2; i++, j--)
	{
		char temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}

void allocate_2d(int**& arr, int row, int col)
{
	arr = new int* [row];
	for (int i = 0; i < row; i++)
		arr[i] = new int[col] {};
}

int value_at(Mat& img, int x, int y)
{
	return static_cast<int>(img.at<uchar>(x, y));
}

void set_value(Mat& img, int x, int y, int val)
{
	(img.at<uchar>(x, y)) = val;
}

int** Mat_toarr(Mat& img)
{
	int** arr = nullptr;
	allocate_2d(arr, img.rows, img.cols);

	for (int i = 0; i < img.rows; i++)
		for (int j = 0; j < img.cols; j++)
			arr[i][j] = value_at(img, i, j);

	return arr;
}

void make_white(Mat& img,int rows,int cols)
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			set_value(img, i, j, 0);
}