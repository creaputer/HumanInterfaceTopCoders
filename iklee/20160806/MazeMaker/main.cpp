//
//  main.cpp
//  MazeMaker
//
//  Created by lee on 2016. 7. 27..
//  Copyright © 2016년 lee. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


#define NOT_FOUND -100
#define FOUND 100

class MazeMaker{
    
    private:
        vector<string> mMaze;
        vector<int> mMoveRow;
        vector<int> mMoveCol;
        int mRowSize = 0;
        int mColSize = 0;
    
        int mShortPath;
        int mIsFind;
        void shortestPath(int startRow, int startCol, int endRow, int endCol, int hop);
    
    public :
        int longestPath (vector<string> maze, int startRow, int startCol, vector<int> moveRow, vector <int> moveCol);
};


int MazeMaker::longestPath (vector<string> maze, int startRow, int startCol, vector<int> moveRow, vector <int> moveCol)
{
    
    mMaze = maze;
    mRowSize = (int) maze.size();
    if(mRowSize > 0 )
        mColSize = (int) maze[0].length();
    
    mMoveRow = moveRow;
    mMoveCol = moveCol;
    int MaxSearchCount = mRowSize + mColSize;
 
    int max = 0;
    for(int i =0; i < mRowSize ; i++)
    {
        for(int j=0; j < mColSize; j++)
        {
            mShortPath = MaxSearchCount;
            mIsFind =  NOT_FOUND;
            
            if (startRow == i && startCol ==j)
                continue;
            
            if (mMaze[i][j] == 'X')
                continue;
            
            shortestPath(startRow, startCol, i, j, 0);
            
            if(mIsFind == NOT_FOUND) {
                return -1;
            }
            
            if(mShortPath > max){
                max = mShortPath;
            }
        }
    }
    
    return max;
}


void MazeMaker::shortestPath(int startRow, int startCol, int endRow, int endCol, int hop){
    
    if(hop > mShortPath){
        return; // OVER_MAX_HOP;
    }
    
    if ( startRow < 0 || startCol < 0 || startRow >= mRowSize || startCol >= mColSize){
        return; // OUT_OF_RANGE;
    }
    
    if (mMaze[startRow][startCol] == 'X') {
        return; // REACH_X;
    }
    
    if ( startRow == endRow && startCol == endCol){
        mIsFind = FOUND;
        
        if (mShortPath > hop){
            mShortPath = hop;
        }
        return;
    }
    
    for (int i =0; i < mMoveRow.size(); i++)
    {
        shortestPath(startRow + mMoveRow[i], startCol + mMoveCol[i], endRow, endCol, hop + 1);
    }
    
}


int main(int argc, const char * argv[]) {
    MazeMaker maker;
    int longest = 0;
    
    vector<string> maze = { "...",
                            "...",
                            "..." };
    int startRow = 0;
    int startCol = 1;
    vector<int> moveRow = { 1, 0, -1, 0};
    vector<int> moveCol = { 0, 1, 0, -1};
    longest = maker.longestPath (maze, startRow, startCol, moveRow, moveCol);
    cout << "logest0: "<< longest << endl; //3
    
    //-------------------------------------------------------------------------
    maze = { "...",
            "...",
            "..." };
    startRow = 0;
    startCol = 1;
    moveRow = { 1, 0, -1, 0, 1, 1, -1, -1};
    moveCol = { 0, 1, 0, -1, 1, -1, 1, -1};
    longest = maker.longestPath (maze, startRow, startCol, moveRow, moveCol);
    cout << "logest1: " << longest << endl; //2
    
    //-------------------------------------------------------------------------
    maze = {    "X.X",
                "...",
                "XXX" ,
                "X.X"};
    startRow = 0;
    startCol = 1;
    moveRow = { 1, 0, -1, 0};
    moveCol = { 0, 1, 0, -1};
    longest = maker.longestPath (maze, startRow, startCol, moveRow, moveCol);
    cout << "logest2: " << longest << endl; //-1
    
    //-------------------------------------------------------------------------
    maze = {    ".......",
                "X.X.X..",
                "XXX...X",
                "....X..",
                "X....X.",
                ".......",};
    startRow = 5;
    startCol = 0;
    moveRow = { 1, 0, -1, 0, -2, 1 };
    moveCol = { 0, -1, 0, 1, 3, 0 };
    longest = maker.longestPath (maze, startRow, startCol, moveRow, moveCol);
    cout << "logest3: "<< longest << endl; //7
    
    //-------------------------------------------------------------------------
    maze = { "......."};
    startRow = 0;
    startCol = 0;
    moveRow = { 1, 0, 1, 0, 1, 0 };
    moveCol = { 0, 1, 0, 1, 0, 1 };
    longest = maker.longestPath (maze, startRow, startCol, moveRow, moveCol);
    cout << "logest4: "<< longest << endl; //6
  
    //-------------------------------------------------------------------------
    maze = { "..X.X.X.X.X.X."};
    startRow = 0;
    startCol = 0;
    moveRow = { 2, 0, -2, 0 };
    moveCol = { 0, 2, 0, -2 };
    longest = maker.longestPath (maze, startRow, startCol, moveRow, moveCol);
    cout << "logest5: "<< longest << endl; //-1

    return 0;
}
