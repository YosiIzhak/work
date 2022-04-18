#include <iostream>
#include <fstream>
#include <stddef.h>
#include <vector>
#include <string>
#include <utility>
#include <sstream>
#include <unordered_map>

using namespace std;


 
void setDirections(vector<pair<int, int> >& directionsVec, string directions)
{
      char ch = 'r';
       if (directions.find(ch) != string::npos )
    {
        directionsVec.push_back(make_pair(1,0));
    }
    ch = 'l';
       if (directions.find(ch) != string::npos )
    {
        directionsVec.push_back(make_pair(-1,0));
    }
    ch = 'u';
       if (directions.find(ch) != string::npos )
    {
         directionsVec.push_back(make_pair(0,-1));
    }
    ch = 'd';
       if (directions.find(ch) != string::npos )
    {
         directionsVec.push_back(make_pair(0,1));
    }
     ch = 'x';
       if (directions.find(ch) != string::npos )
    {
         directionsVec.push_back(make_pair(-1,-1));
    }
    ch = 'y';
       if (directions.find(ch) != string::npos )
    {
         directionsVec.push_back(make_pair(1,-1));
    }
    ch = 'z';
       if (directions.find(ch) != string::npos )
    {
         directionsVec.push_back(make_pair(-1,1));
    }
    ch = 't';
       if (directions.find(ch) != string::npos )
    {
         directionsVec.push_back(make_pair(1,1));
    }
}

void printMatrix(std::vector<vector<char> >& a_matrix)
{    
    for(size_t i = 0; i < a_matrix.size(); ++i)
    {
        for(size_t j = 0; j < a_matrix[i].size(); ++j)
        {
            std::cout << a_matrix[i][j];
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

void printWords(vector<string>& a_words)
{    
    for(size_t i = 0; i < a_words.size(); ++i)
    {
        cout << a_words[i] << endl;
    }
}

void fillMatrix(std::ifstream& a_file ,vector<vector<char> >& a_matrix)
{
    while(a_file.good())
    {
        vector<char> row;
        string line;
        getline(a_file, line);
        
        if(line.empty()){ break;}

        for(char c : line) 
        {
            row.push_back(c);

        }
        a_matrix.push_back(row);    
    }
}

void getWords(std::ifstream& a_file, vector<string>& words)
{
    while(a_file.good())
    {
        string line;
        getline(a_file, line);
        
        if(line.empty()){ break;}
        
        words.push_back(line);
    }
}


int scan2D(vector<vector<char> >& a_matrix, string a_word, vector<pair<int, int> >& directionsVec)
 {
     int rows = a_matrix.size();
     int columns = a_matrix[0].size();
     int len = a_word.length();
     int count = 0;
    for (int dir = 0; dir < directionsVec.size(); dir++) 
    {
        for (int col = 0; col < columns; col++)
        {
            for (int row = 0; row < rows; row++)
            {
                int k = 0;
                int rd = row;
                int cd = col;
                //cout  << rd << cd << " rd+ cd" << endl;
               // cout  << cd << " cd" << endl;
                if (a_matrix[rd][cd] != a_word[0])
                {
                    continue;
                }
                    
                for (k = 0; k < len; k++) 
                {
                    if (rd >= rows || rd < 0 || cd >= columns || cd < 0)
                        break;
 
                    if (a_matrix[rd][cd] != a_word[k])
                    {
                        break;
                    }
                   
                    cd += directionsVec[dir].first;
                    rd += directionsVec[dir].second;
                    //cout << rd << cd <<"***rd+cd**" <<endl;
                }
                
                if (k == len)
                    count++;
            }
        }
    }
    //cout << "count" << count << endl;
    return count;
}
 


int main (int argc, char** argv) 
{
   vector<vector<char> > matrix;
   vector<pair<int, int> >directionsVec;
   vector<string> words;
   ifstream matrixFile {argv[1]};
   ifstream wordsFile {argv[2]};
   ofstream resultFile {argv[3]};
   string directions = argv[4];
   
   setDirections(directionsVec, directions);
   fillMatrix(matrixFile, matrix);
   printMatrix(matrix);
   getWords(wordsFile, words);
   printWords(words);
   unordered_map<string, int> mp;
    
    for(auto& w: words)
    { 
        int res = scan2D(matrix, w, directionsVec);
        {
            mp[w] = res;
        }
    }

    for(auto k : mp)
    {
        cout << k.first << " " << k.second << endl;
        resultFile << k.first << " " << k.second << endl;
    }

   return 0;
}










