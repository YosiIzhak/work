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


// template<typename T, typename U>

// struct GreaterPairCompare

// {

//       bool operator()(const std::pair<const T,U>* a,const std::pair<const T,U>* b) const

//       {

//             return a->second > b->second;

//       }

// };

// ​

// typedef std::pair<std::string const, size_t>* WordPair;

// typedef std::pair<std::string const, size_t> WordPairInMap;

// typedef std::priority_queue<WordPair, std::vector<WordPair>, GreaterPairCompare<std::string, size_t> > WordFrequencyHeap;

// WordFrequencyHeap topNWords3(std::map<std::string, size_t>& a_map, size_t a_numWords)

// {

//     using std::vector;

//     using std::map;

//     using std::string;

// ​

//     vector<WordPair> v;

// ​

//     map<string, size_t>::iterator itr = a_map.begin();

//     map<string, size_t>::iterator end = a_map.end();

//     const size_t k = std::min(a_map.size(), a_numWords);

//     v.reserve(k);

//     for(size_t i = 0; i < k; ++i){

//         WordPairInMap* w = &*itr;

//         v.push_back(w);

//         ++itr;

//     }

// ​

//     assert(v.size()==3);

// ​

//     GreaterPairCompare<string, size_t> cmp;

//     WordFrequencyHeap minHeap(cmp, v);

//     assert(minHeap.size() == 3);

// ​

    

//     while(itr != end)

//     {

//         WordPairInMap* w = &*itr;

//         if( cmp(w, minHeap.top()))

//         {

//             minHeap.pop();          

//             minHeap.push(w);    

//         }

//         ++itr;

//     }

    

// 	return minHeap;

// }

// ​

// int main(){

//     using std::map;

//     using std::string;

//     std::map<string, size_t> m;

    

//     m["hello"] = 6;

//     m["world"] = 2;

//     m["mars"] = 1;

//     m["C++"] = 9;

//     m["Java"] = 3;

//     m["Fortan"] = 7;

//     assert(m.size() == 6);

// ​

//     WordFrequencyHeap r = topNWords3(m, 3);

//     assert(r.size() == 3);

//     std::cout << r.size() << '\n';

    

//     for(size_t i = 0; i < 3; ++i){

//         WordPair f = r.top();

//         std::cout << f->first << '\n';

//         r.pop();

//     }

// }