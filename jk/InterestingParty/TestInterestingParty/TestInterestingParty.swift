//
//  TestInterestingParty.swift
//  TestInterestingParty
//
//  Created by JunKyo on 2016. 7. 25..
//  Copyright © 2016년 JunKyo. All rights reserved.
//

import XCTest
@testable import InterestingParty

class TestInterestingParty: XCTestCase {
    
    override func setUp() {
        super.setUp()
        // Put setup code here. This method is called before the invocation of each test method in the class.
    }
    
    override func tearDown() {
        // Put teardown code here. This method is called after the invocation of each test method in the class.
        super.tearDown()
    }
    
    func testInterestingParty0() {
		let expected = 4
		let returns = bestInvitation(first: ["fishing", "gardening", "swimming", "fishing"], second: ["hunting", "fishing", "fishing", "biting"])
        XCTAssert(expected == returns)
    }
	
	func testInterestingParty1() {
		let expected = 1
		let returns = bestInvitation(first: ["variety", "diverity", "loquacity", "courtesy"], second: ["talking", "speaking", "discussion", "meeting"])
		XCTAssert(expected == returns)
	}
	
	func testInterestingParty2() {
		let expected = 3
		let returns = bestInvitation(first: ["snakes", "programming", "cobra", "mothy"], second: ["python", "python", "anaconda", "python"])
		XCTAssert(expected == returns)
	}
	
	func testInterestingParty3() {
		let expected = 6
		let returns = bestInvitation(first: ["t", "o", "p", "c", "o", "d", "e", "r", "s", "i", "n", "g", "l", "e", "r", "o", "u", "n", "d", "m", "a", "t", "c", "h", "f", "o", "u", "r", "n", "i"], second: ["n", "e", "f", "o", "u", "r", "j", "a", "n", "u", "a", "r", "y", "t", "w", "e", "n", "t", "y", "t", "w", "o", "s", "a", "t", "u", "r", "d", "a", "y"])
		XCTAssert(expected == returns)
	}
}
