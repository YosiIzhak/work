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

bool scan2D(vector<vector<char> >& a_matrix, string a_word, vector<pair<int, int> >& directionsVec)
 {
     int rows = a_matrix.size();
     int columns = a_matrix[0].size();
   
    int len = a_word.length();
     for (int row = 0; row < rows; row++)
     {
        for (int col = 0; col < columns; col++)
        {
            for (int dir = 0; dir < directionsVec.size(); dir++) 
            {
            int k, rd = row + directionsVec[dir].first, cd = col + directionsVec[dir].second;
             
             if (a_matrix[directionsVec[dir].first][directionsVec[dir].second] != a_word[0])
             return false;
                for (k = 1; k < len; k++) 
                {
                if (rd >= rows || rd < 0 || cd >= columns || cd < 0)
                    break;
 
                if (a_matrix[rd][cd] != a_word[k])
                    break;
 
                rd += directionsVec[dir].first, cd += directionsVec[dir].second;
                }
             if (k == len)
            return true;
            }
        }
     }
    return false;
}
 


int main () 
{
   vector<vector<char> > matrix;
   vector<pair<int, int> >directionsVec;
   vector<string> words;
   ifstream matrixFile {"mat.txt"};
   ifstream wordsFile {"words.txt"};
   ofstream result{ "result.txt" };
   string directions = "ud";
   setDirections(directionsVec, directions);
   fillMatrix(matrixFile, matrix);
   getWords(wordsFile, words);
   unordered_map<string, int> mp;
    
    for(auto& w: words)
    { 
        if(scan2D(matrix, w, directionsVec))
        {
            mp[w]++;
        }
    }

    for(auto k : mp)
    {
        cout << k.first << " " << k.second << endl;
        result << k.first << " " << k.second << endl;
    }

   return 0;
}










