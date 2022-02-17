#include <cstdio>
#include <cstdlib>
#include "utils.hpp"
#include <iostream>
#include <fstream>
#include <map>
#include <string>

void letterFrequency(std::map<char, int> &a_map, std::string const& a_file )
{
    FILE* input_file = fopen(a_file.c_str(), "r");
    if (input_file == 0)
    {
       return;
    }
    char c;
    while ((c = fgetc(input_file)) != EOF) 
    {
       if (c == ' ')
       {
           continue;
       }
       ++a_map[c];
    }
    fclose(input_file);
}


void reverseIntArr(int* a_arr, size_t a_arrSize)
{
    size_t begin = 0;
    size_t end = a_arrSize -1;
    while (begin < end)
    {
        swapInt(&a_arr[begin] , &a_arr[end]);
        begin++;
        end--;
    }
}

void swapInt(int* a_first, int* a_second)
{
    int temp = *a_first;
    *a_first = *a_second;
    *a_second = temp;
}

int minInt (int _a , int _b)
{

    if ( _a > _b)
    {
        return _b ;
    }
    return _a ;
}

void arrCopy(int* a_first, int* a_second, size_t n)
{
    for(size_t i = 0; i < n; i++)
    {
        a_first[i] = a_second[i];
    }
}

int* randomIntArray(size_t n)
{
	int* array = new int[n];
	for(size_t i = 0; i < n; i++)
	{
		array[i] = rand();
	}
	
	return array;
}