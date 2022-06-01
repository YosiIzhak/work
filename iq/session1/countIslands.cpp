//leetcode 200
#include <iostream>
#include <algorithm>
#include <stddef.h>
#include <vector>

using namespace std;

void dfs(vector<vector<char>>& grid, const int& i, const int& j)
{
    if (i<0 or j<0 or i>grid.size() or j>grid[0].size() or grid[i][j] !='1')
        return;
    
    grid[i][j] = 'x';
    dfs(grid, i+1, j);
    dfs(grid, i-1, j);
    dfs(grid, i, j+1);
    dfs(grid, i, j-1);
}

int numIslands(vector<vector<char>>& grid) 
{
    if (grid.empty())
        return 0;
    int count = 0;

    for(size_t i = 0; i < grid.size(); ++i)
    {
        for (size_t j = 0; j < grid[0].size(); ++j)
        {
            if(grid[i][j] == '1')
            {
                count++;
                dfs(grid, i, j);
            }
        }
    }   
    return count;
}



int main () 
{
 vector<vector<char> >  input { {'1','1','1','1','0'},
                                {'1','1','0','1','0'},
                                {'1','1','0','0','0'},
                                {'0','0','0','0','0'} };
 
    int res = numIslands(input);
    cout <<res << endl;
    
   return 0;
}