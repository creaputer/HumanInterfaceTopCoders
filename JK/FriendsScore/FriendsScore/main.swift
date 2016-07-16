//
//  main.swift
//  FriendsScore
//
//  Created by JunKyo on 2016. 7. 16..
//  Copyright © 2016년 JunKyo. All rights reserved.
//

import Foundation

func highestScore(friends : [String]) -> Int
{
    let FRIEND: Character = "Y"
    
    var relationship = Array(count: friends.count, repeatedValue: Set<Int>())

    for (iMe, me) in friends.enumerate()
    {
        for (iYou, you) in me.characters.enumerate()
        {
            if (you == FRIEND)
            {
                relationship[iMe].insert(iYou)

                for (iYourFriend, yourFriend) in friends[iYou].characters.enumerate()
                {
                    if (yourFriend == FRIEND && iYourFriend != iMe)
                    {
                        relationship[iMe].insert(iYourFriend)
                    }
                }
            }
        }
    }
    
    let maxElement = relationship.maxElement({(left, right) -> Bool in
        return left.count < right.count
    })
    
    return maxElement!.count
}

var friend0 = highestScore(["NNN", "NNN", "NNN"]);
assert(friend0 == 0)

var friend1 = highestScore(["NYY", "YNY", "YYN"]);
assert(friend1 == 2)

var friend2 = highestScore(["NYNNN",
    "YNYNN",
    "NYNYN",
    "NNYNY",
    "NNNYN"]);
assert(friend2 == 4)

var friend3 = highestScore(["NNNNYNNNNN",
    "NNNNYNYYNN",
    "NNNYYYNNNN",
    "NNYNNNNNNN",
    "YYYNNNNNNY",
    "NNYNNNNNYN",
    "NYNNNNNYNN",
    "NYNNNNYNNN",
    "NNNNNNYNNN",
    "NNNNNYNNNN"]);
assert(friend3 == 8)

var friend4 = highestScore(["NNNNNNNNNNNNNNY",
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
    "YNNYYNNNNYNNNNN"]);
assert(friend4 == 6)

print("succeeded")
