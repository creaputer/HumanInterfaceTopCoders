//
//  KiwiJuiceEasy.swift
//  KiwiJuiceEasy
//
//  Created by JunKyo on 2016. 7. 24..
//  Copyright © 2016년 JunKyo. All rights reserved.
//

import Foundation

func thePouring(capacities: [Int], bottles: [Int], fromId: [Int], toId: [Int]) -> [Int]
{
	assert(capacities.count == bottles.count)
	assert(fromId.count == toId.count)
	
	var pouredBottles = bottles
	
	for (i, left) in fromId.enumerated()
	{
		let right = toId[i]
		let rightCapacity = capacities[right] - pouredBottles[right]
		let movable = min(pouredBottles[left], rightCapacity)
		
		pouredBottles[left] = pouredBottles[left] - movable
		pouredBottles[right] = pouredBottles[right] + movable
	}
	
	return pouredBottles
}
