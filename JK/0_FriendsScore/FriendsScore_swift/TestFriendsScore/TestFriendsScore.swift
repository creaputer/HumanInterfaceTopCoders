//
//  TestFriendsScore.swift
//  TestFriendsScore
//
//  Created by JunKyo on 2016. 7. 18..
//  Copyright © 2016년 JunKyo. All rights reserved.
//

import XCTest

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

class TestFriendsScore: XCTestCase {
	
    override func setUp() {
        super.setUp()
        // Put setup code here. This method is called before the invocation of each test method in the class.
    }
    
    override func tearDown() {
        // Put teardown code here. This method is called after the invocation of each test method in the class.
        super.tearDown()
    }
    
    func testFriend0() {
		var friend = highestScore(["NNN", "NNN", "NNN"])
		XCTAssert(friend == 0)
    }
	
	func testFriend1() {
		var friend = highestScore(["NYY", "YNY", "YYN"])
		XCTAssert(friend == 2)
	}
	
	func testFriend2() {
		var friend = highestScore(["NYNNN",
			"YNYNN",
			"NYNYN",
			"NNYNY",
			"NNNYN"])
		XCTAssert(friend == 4)
	}
	
	func testFriend3() {
		var friend = highestScore(["NNNNYNNNNN",
			"NNNNYNYYNN",
			"NNNYYYNNNN",
			"NNYNNNNNNN",
			"YYYNNNNNNY",
			"NNYNNNNNYN",
			"NYNNNNNYNN",
			"NYNNNNYNNN",
			"NNNNNNYNNN",
			"NNNNNYNNNN"])
		XCTAssert(friend == 8)
	}
	
	func testFriend4() {
		var friend = highestScore(["NNNNNNNNNNNNNNY",
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
			"YNNYYNNNNYNNNNN"])
		XCTAssert(friend == 6)
	}
}
