//
//  TestKiwiJuiceEasy.swift
//  TestKiwiJuiceEasy
//
//  Created by JunKyo on 2016. 7. 24..
//  Copyright © 2016년 JunKyo. All rights reserved.
//

import XCTest
import KiwiJuiceEasy

class TestKiwiJuiceEasy: XCTestCase {
    
    override func setUp() {
        super.setUp()
        // Put setup code here. This method is called before the invocation of each test method in the class.
    }
    
    override func tearDown() {
        // Put teardown code here. This method is called after the invocation of each test method in the class.
        super.tearDown()
    }
    
    func testPouring0() {
		let expected = [0, 13]
		let results = thePouring(capacities: [20, 20], bottles: [5, 8], fromId: [0], toId: [1])

        XCTAssert(expected == results)
    }
	
	func testPouring1() {
		let expected = [3, 10]
		let results = thePouring(capacities: [10, 10], bottles: [5, 8], fromId: [0], toId: [1])
		
		XCTAssert(expected == results)
	}
	
	func testPouring2() {
		let expected = [10, 10, 0]
		let results = thePouring(capacities: [30, 20, 10], bottles: [10, 5, 5], fromId: [0, 1, 2], toId: [1, 2, 0])
		
		XCTAssert(expected == results)
	}
	
	func testPouring3() {
		let expected = [0, 14, 65, 35, 25, 35]
		let results = thePouring(capacities: [14, 35, 86, 58, 25, 62], bottles: [6, 34, 27, 38, 9, 60], fromId: [1, 2, 4, 5, 3, 3, 1, 0], toId: [0, 1, 2, 4, 2, 5, 3, 1])
		
		XCTAssert(expected == results)
	}
	
	func testPouring4() {
		let expected = [0, 156956, 900000, 856956]
		let results = thePouring(capacities: [700000, 800000, 900000, 1000000], bottles: [478478, 478478, 478478, 478478], fromId: [2, 3, 2, 0, 1], toId: [0, 1, 1, 3, 2])
		
		XCTAssert(expected == results)
	}
}
