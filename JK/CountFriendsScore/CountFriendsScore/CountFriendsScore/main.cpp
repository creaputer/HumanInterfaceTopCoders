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
#include <set>

class Counter
{
public:
    int highestScore(const std::vector<std::string> & friends)
    {
        const auto FRIEND = 'Y';
        const auto MAX_SIZE = friends.size();
        auto vFriends = std::vector<std::set<int>>{MAX_SIZE};
        for (auto me = 0; me < MAX_SIZE; ++me)
        {
            for (auto you = 0; you < MAX_SIZE; ++you)
            {
                if (me == you) continue;
                if (friends.at(me).at(you) != FRIEND) continue;
                
                vFriends.at(me).insert(you);
                
                for (auto yourfriend = 0; yourfriend < MAX_SIZE; ++yourfriend)
                {
                    if (me == yourfriend) continue;
                    if (friends.at(you).at(yourfriend) != FRIEND) continue;
                    
                    vFriends.at(me).insert(yourfriend);
                }
            }
        }
        
        const auto mostFamous = std::max_element(vFriends.cbegin(), vFriends.cend(), [](std::set<int> left, std::set<int> right)
         {
             return left.size() < right.size();
         });
        
        return static_cast<int>(mostFamous->size());
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
