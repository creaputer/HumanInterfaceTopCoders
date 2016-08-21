//
//  main.cpp
//  ChessMetric
//
//  Created by lee on 2016. 8. 20..
//  Copyright © 2016년 lee. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

#define CANDIDATE 1

class ChessMetric {
    
    private:
        int mCount =0;
    
        const std::vector<int> mMoveToX = {-1,  0,  1, -1, 1, -1, 0, 1, -2, -1,  1,  2, -2, -1, 1, 2};
        const std::vector<int> mMoveToY = {-1, -1, -1,  0, 0,  1, 1, 1, -1, -2, -2, -1,  1,  2, 2, 1};
    
        int mCandidateCurrent[100][100];
        int mCandidateNext[100][100];
        long long mChessCurrent[100][100];
        long long mChessNext[100][100];

        void goUseMomory(int size);
        void goRecursive(int size, std::vector<int> start, std::vector<int> end, int numMoves, int hop);
    
    public :
        long long howMany(int size, std::vector <int> start, std::vector <int> end, int numMoves );
    
};


long long ChessMetric::howMany(int size, std::vector<int> start, std::vector<int> end, int numMoves)
{
    int nMode = 1; //0: Recursive, 1: 동적계획
    
    if(nMode == 0)
    {
        mCount = 0;
        goRecursive(size, start, end, numMoves, 0);
        return mCount;
    }
    else
    {
        for(int i = 0; i < size; i ++)
        {
            for(int j=0; j <size; j++)
            {
                mChessCurrent[i][j] = 0;
                mChessNext[i][j] = 0;
                mCandidateCurrent[i][j] = 0;
                mCandidateNext[i][j] = 0;
            }
        }
        
        int startX = start[0];
        int startY = start[1];
        
        mCandidateNext[startX][startY] = 1;
        mChessNext[startX][startY] =1;
        
        for (int k =0 ; k < numMoves; k ++)
        {
            goUseMomory(size);
        }
        
        int endX = end[0];
        int endY = end[1];
        
        return mChessNext[endX][endY];
    }
    
}

void ChessMetric::goUseMomory(int size)
{
        
    for (int i =0; i < size; i++)
    {
        for(int j=0; j < size; j++)
        {
            mChessCurrent[i][j] = mChessNext[i][j];
            mChessNext[i][j] = 0;
            
            mCandidateCurrent[i][j] = mCandidateNext[i][j];
            mCandidateNext[i][j] = 0;
        }
    }
    
    
    for (int i=0 ; i < size; i ++)
    {
        for(int j =0; j < size; j ++)
        {
            if (mCandidateCurrent[i][j] == CANDIDATE )
            {
                for(int k =0; k < mMoveToX.size() ; k++)
                {
                    int nextX = i + mMoveToX[k];
                    int nextY = j + mMoveToY[k];
                    
                    if( nextX < 0 || nextX > size || nextY < 0 || nextY > size)
                        continue;
                    
                    mChessNext[nextX][nextY] += mChessCurrent[i][j];
                    mCandidateNext[nextX][nextY] = CANDIDATE;
                }
                
            }
        }
    }
    
}


void ChessMetric::goRecursive(int size, std::vector<int> start, std::vector<int> end, int numMoves, int hop){
    
    if ( start[0] < 0 ||  start[0] > size || start[1] <0  || start[1] > size)
        return; // fail
    
    if (hop > numMoves)
        return; // fail

    if (start == end)
    {
        if (hop == numMoves)
        {
            mCount++; // sucess
            return;
        }
    }
    
    for(int i=0; i < mMoveToX.size() ; i++)
    {
        std::vector <int> next = {start[0] + mMoveToX[i], start[1] + mMoveToY[i]};
        goRecursive(size, next, end, numMoves, hop + 1);
    }
}


int main(int argc, const char * argv[]) {
    
    ChessMetric chessMetric;
    int size=0;
    std::vector <int> start;
    std::vector <int> end;
    int numMoves = 0;
    long long result = 0;
    
    size = 3;
    start = {0, 0};
    end = {1, 0 };
    numMoves = 1;
    result = chessMetric.howMany(size, start, end, numMoves);
    std::cout << "0: " << result << std::endl;
    
    size = 3;
    start = {0, 0};
    end = {1, 2 };
    numMoves = 1;
    result = chessMetric.howMany(size, start, end, numMoves);
    std::cout << "1: " << result << std::endl;
    
    
    size = 3;
    start = {0, 0};
    end = {2, 2};
    numMoves = 1;
    result = chessMetric.howMany(size, start, end, numMoves);
    std::cout << "2: " << result << std::endl;

    size = 3;
    start = {0, 0};
    end = {0, 0};
    numMoves = 2;
    result = chessMetric.howMany(size, start, end, numMoves);
    std::cout << "3: " << result << std::endl; //5
    
    size = 3;
    start = {0, 0};
    end = {0, 0};
    numMoves = 3;
    result = chessMetric.howMany(size, start, end, numMoves);
    std::cout << "3_1: " << result << std::endl; //16

    size = 100;
    start = {0, 0};
    end = {0, 99};
    numMoves = 50;
    result = chessMetric.howMany(size, start, end, numMoves);
    std::cout << "4: " << result << std::endl; //243097320072600
    
    return 0;
}
