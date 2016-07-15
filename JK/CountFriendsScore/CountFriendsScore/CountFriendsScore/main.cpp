//
//  main.cpp
//  CountFriendsScore
//
//  Created by JunKyo on 2016. 7. 15..
//  Copyright © 2016년 JunKyo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <assert.h>
#include <forward_list>

class Counter
{
public:
    int highestScore(const std::vector<std::string> & friends)
    {
        const auto YES = 'Y';
        const auto MAX_SIZE = friends.size();
        
        auto maxFriends = int{0};
        for (auto _1 = 0; _1 < MAX_SIZE; ++_1)
        {
            auto relations = int{0};
            auto myFriends = std::forward_list<int>{};
            for (auto _2 = 0; _2 < MAX_SIZE; ++_2)
            {
                if (_1 == _2) continue;
                
                if (friends.at(_1).at(_2) == YES)
                {
                    for (auto _3 = 0; _3 < MAX_SIZE; ++_3)
                    {
                        auto redundancy = bool{false};
                        for (const auto & my : myFriends)
                        {
                            if (my == _2)
                            {
                                redundancy = true;
                                break;
                            }
                        }
                        
                        if (redundancy == false)
                        {
                            if (friends.at(_3).at(_2) == YES)
                            {
                                ++relations;
                                myFriends.push_front(_3);
                            }
                        }
                    }
                }
            }
            
            maxFriends = std::max(maxFriends, relations);
        }
        
        return maxFriends;
    }
    
};

int main(int argc, const char * argv[]) {
    
    auto pCounter = std::make_shared<Counter>();
    
    
    const auto friends0 = std::vector<std::string>{"NNN", "NNN", "NNN"};
    const auto nFriends0 = pCounter->highestScore(friends0);
    assert(nFriends0 == 0);

    const auto friends1 = std::vector<std::string>{ "NYY", "YNY", "YYN" };
    const auto nFriends1 = pCounter->highestScore(friends1);
    assert(nFriends1 == 2);
    
    const auto friends2 = std::vector<std::string>{
        "NYNNN",
        "YNYNN",
        "NYNYN",
        "NNYNY",
        "NNNYN"
    };
    const auto nFriends2 = pCounter->highestScore(friends2);
    assert(nFriends2 == 4);
    
    const auto friends3 = std::vector<std::string>{
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
    const auto nFriends3 = pCounter->highestScore(friends3);
    assert(nFriends3 == 8);
    
    const auto friends4 = std::vector<std::string>{ "NNNNNNNNNNNNNNY",
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
    const auto nFriends4 = pCounter->highestScore(friends4);
    assert(nFriends4 == 6);
    
    std::cout << "Success" << std::endl;
    
    return 0;
}
