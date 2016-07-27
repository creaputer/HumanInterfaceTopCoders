//
//  InterestingParty.swift
//  InterestingParty
//
//  Created by JunKyo on 2016. 7. 25..
//  Copyright © 2016년 JunKyo. All rights reserved.
//

import Foundation

func bestInvitation(first: [String], second: [String]) -> Int
{
	var obj: [String: Int] = [String: Int]()

	for _1 in 0...first.count - 1
	{
		obj[first[_1]] = 0
		obj[second[_1]] = 0
	}
	
	for _1 in 0...first.count - 1
	{
		obj[first[_1]] = obj[first[_1]]! + 1
		obj[second[_1]] = obj[second[_1]]! + 1
	}

	return obj.values.max()!
}
