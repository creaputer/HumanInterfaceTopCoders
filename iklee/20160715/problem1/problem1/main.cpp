//
//  main.cpp
//  problem1
//
//  Created by lee on 2016. 7. 15..
//  Copyright © 2016년 lee. All rights reserved.
//

#include <iostream>
#include <string>
#include <list>
#include <vector>
using namespace std;


int heighestScore(vector<string> friends)
{
    int nMax = 0 ;
    
    for ( auto person : friends)
    {
        list<int> myFriends;
        
        int i = 0;
        for (auto firstfriend : person)
        {
            if (firstfriend == 'Y')
            {
                myFriends.push_front(i);
                
                int j = 0;
                for( auto secondFriend : friends[i])
                {
                    if(secondFriend == 'Y')
                    {
                        myFriends.push_front(j);
                    }
                    j++;
                }
            }
            i++;
        }
        
        myFriends.sort();
        myFriends.unique(); //중복제거
        
        int nNumFriends = (int) myFriends.size();
        
        if (nNumFriends > 0)
            nNumFriends = nNumFriends -1 ; // 자기자신 제거
        
        cout << nNumFriends <<endl;
        
        if (nMax < nNumFriends)
            nMax = nNumFriends;
    }
    
    return nMax;
    
}

int main(int argc, const char * argv[]) {
    
    /* Input Data */
    vector<string> friend0 = {
        "NNN",
        "NNN",
        "NNN"
    };
    
    vector<string> friend1 = {
        "NYY",
        "YNY",
        "YYN"
    };
    
    vector<string> friend2 = {
        "NYNNN",
        "YNYNN",
        "NYNYN",
        "NNYNY",
        "NNNYN"
    };
    
    vector<string> friend3 = {
        "NNNNYNNNNN",
        "NNNNYNYYNN",
        "NNNYYYNNNN",
        "NNYNNNNNNN",
        "YYYNNNNNNY",
        "NNYNNNNNYN",
        "NYNNNNNYNN",
        "NYNNNNYNNN",
        "NNNNNNYNNN",
        "NNNNNYNNNN"
     };
    
    vector<string> friend4 = {
        "NNNNNNNNNNNNNNY",
        "NNNNNNNNNNNNNNN",
        "NNNNNNNYNNNNNNN",
        "NNNNNNNYNNNNNNY",
        "NNNNNNNNNNNNNNY",
        "NNNNNNNNYNNNNNN",
        "NNNNNNNNNNNNNNN",
        "NNYYNNNNNNNNNNN",
        "NNNNNYNNNNNYNNN",
        "NNNNNNNNNNNNNNY",
        "NNNNNNNNNNNNNNN",
        "NNNNNNNNYNNNNNN",
        "NNNNNNNNNNNNNNN",
        "NNNNNNNNNNNNNNN",
        "YNNYYNNNNYNNNNN"};
    
    /* Test Result */
    int nAnswer = 0;
    
    nAnswer = heighestScore (friend0);
    cout << "Max: " << nAnswer << "\n\n";
    
    nAnswer = heighestScore (friend1);
    cout << "Max: " << nAnswer << "\n\n";
    
    nAnswer = heighestScore (friend2);
    cout << "Max: " << nAnswer << "\n\n";
    
    nAnswer = heighestScore (friend3);
    cout << "Max: " << nAnswer << "\n\n";
    
    nAnswer = heighestScore (friend4);
    cout << "Max: " << nAnswer << "\n\n";

    return 0;
}



