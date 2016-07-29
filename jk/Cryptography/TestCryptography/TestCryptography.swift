//
//  TestCryptography.swift
//  TestCryptography
//
//  Created by JunKyo on 2016. 7. 27..
//  Copyright © 2016년 JunKyo. All rights reserved.
//

func encrypt(numbers: [Int]) -> Int64
{
	var results: [Int64] = [Int64]()
	
	let denom = numbers.count
	for _1 in 0...numbers.count - 1
	{
		results.append(numbers[_1] + 1)
		
		for _2 in (_1 + 1)...(numbers.count - 1 + _1)
		{
			results[_1] = results[_1] * Int64(numbers[_2 % denom])
		}
	}
	
	return results.max()!
	
}

import XCTest

class TestCryptography: XCTestCase {
    
    override func setUp() {
        super.setUp()
        // Put setup code here. This method is called before the invocation of each test method in the class.
    }
    
    override func tearDown() {
        // Put teardown code here. This method is called after the invocation of each test method in the class.
        super.tearDown()
    }
    
    func testCryptography0() {
		let expected: Int64 = 12
		let returns = encrypt(numbers: [1, 2, 3])
        XCTAssert(expected == returns)
    }
	
	func testCryptography1() {
		let expected: Int64 = 36
		let returns = encrypt(numbers: [1, 3, 2, 1, 1, 3])
		XCTAssert(expected == returns)
	}
	
	func testCryptography2() {
		let expected: Int64 = 986074810223904000
		let returns = encrypt(numbers: [1000, 999, 998, 997, 996, 995])
		XCTAssert(expected == returns)
	}
	
	func testCryptography3() {
		let expected: Int64 = 2
		let returns = encrypt(numbers: [1, 1, 1, 1])
		XCTAssert(expected == returns)
	}
}
