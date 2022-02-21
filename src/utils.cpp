#include <cstdio>
#include <cstdlib>
#include "utils.hpp"
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <queue>


struct comparPairBySecond
{
    bool operator()(std::pair<std::string, size_t> &a, std::pair<std::string, size_t> &b)
    {
        return a.second < b.second;
    }
};

void topNWords(std::vector<std::string> &a_vector, std::ifstream& a_file, size_t a_numOfWords)
{
    using namespace std;

    if(a_file.peek() == std::ifstream::traits_type::eof() || !a_file.good())
    {
        cout << "problem in file!\n";
        return;
    }
   
    std::map<string, size_t> map;
    string word;
    word.clear();

    while(a_file.good())
    {
        a_file >> word; 
        ++map[word];
        word.clear();
    }
    
    priority_queue<pair<string, size_t> , vector<pair<string, size_t> >, comparPairBySecond> que;
    
    std::map<string, size_t>::iterator it = map.begin();
    while (it != map.end())
    {
        que.push(pair<string, size_t> (it->first, it->second));
        ++it;
    }

    for (size_t i = 0; i < a_numOfWords; i++)
    {
        a_vector[i] = que.top().first;
        que.pop();
        if(que.empty())
        {
            break;
        }
    }
}



void letterFrequency(std::map<char, int> &a_map, std::ifstream& a_file)
{
   char letter;
    while (a_file >> letter) 
    {
       if ( a_file.is_open())
       {
           if (isalpha(letter))
            {
                ++a_map[tolower(letter)];
            }
       }
       
    }
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