//
//  main.cpp
//  InterestingParty
//
//  Created by lee on 2016. 7. 27..
//  Copyright © 2016년 lee. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


class InterestingParty{
    
public:
    int bestInvitation(vector <string> first, vector<string> second);
};

int InterestingParty::bestInvitation(vector <string> first, vector<string> second) {
    
    
    int firstSize = (int)first.size();
    int secondSize = (int)second.size();
    
    if(firstSize != secondSize){
        cout << "Input Error \n";
        exit(1);
    }
    
    int nMax = 0;
    for (int i=0; i < firstSize; i ++)
    {
        int firstCount = 0;
        int secondCount = 0;
        
        for(int j=0; j < secondSize; j++)
        {
            if (first[i] == first[j])
                firstCount ++;
            if (first[i] == second[j])
                firstCount ++;
            
            if (second[i] == first[j])
                secondCount ++;
            if (second[i] == second[j])
                secondCount ++;
        }
        
        if (firstCount > nMax)
            nMax = firstCount;
        if (secondCount > nMax)
            nMax = secondCount;
    }
    
    return nMax;
}


int main(int argc, const char * argv[]) {
    
    InterestingParty party;
    int result  = 0;
    
    vector<string> first = { "fishing", "gardening", "swimming", "fishing"};
    vector<string> second = { "hunting", "fishing", "fishing", "biting"};
    result = party.bestInvitation(first, second);
    cout << result << endl;  // 4
    
    
    first = { "variety", "diverity", "loquacity", "courtesy" };
    second = { "talking", "speaking", "discussion", "meeting"};
    result = party.bestInvitation(first, second);
    cout << result << endl;  //1
    
    first = { "snakes", "programming", "cobra", "mothy"};
    second = { "python", "python", "anaconda", "python"};
    result = party.bestInvitation(first, second);
    cout << result << endl;  //3
    
    first = { "t", "o", "p", "c", "o", "d", "e", "r", "s", "i", "n", "g", "l", "e", "r", "o", "u", "n", "d", "m", "a", "t", "c", "h", "f", "o", "u", "r", "n", "i"};
    second = { "n", "e", "f", "o", "u", "r", "j", "a", "n", "u", "a", "r", "y", "t", "w", "e", "n", "t", "y", "t", "w", "o", "s", "a", "t", "u", "r", "d", "a", "y"};
    result = party.bestInvitation(first, second);
    cout << result << endl;  //6
    
   
    return 0;
}


