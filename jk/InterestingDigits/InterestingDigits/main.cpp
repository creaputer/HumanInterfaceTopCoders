//
//  main.cpp
//  InterestingDigits
//
//  Created by JunKyo on 2016. 7. 29..
//  Copyright © 2016년 JunKyo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <functional>
#include <numeric>

void RunDigit(std::function<std::vector<int>(int)> digits, const std::vector<int> & expected, const int base)
{
	const auto returns = digits(base);
	
	auto print = [](const std::string & name, const std::vector<int> & data) {
		std::cout << name << " : ";
		for (const auto & _1 : data) {
			std::cout << _1 << " ";
		}
		std::cout << std::endl;
	};
	
	print("expected", expected);
	print("returns", returns);
	std::cout << std::endl;
}

int main(int argc, const char * argv[]) {
	auto digits = [](const int base) {
		auto candidates = std::vector<int>(base - 2, 0);
		std::iota(candidates.begin(), candidates.end(), 2);
		
		auto returns = std::vector<int>{};
		const auto base1 = base - 1;
		for (const auto & _1 : candidates) {
			if (base1 % _1 == 0) {
				returns.emplace_back(_1);
			}
		}
		
		return returns;
	};
	
	RunDigit(digits, {3, 9}, 10);
	RunDigit(digits, {2}, 3);
	RunDigit(digits, {2, 4, 8}, 9);
	RunDigit(digits, {5, 25}, 26);
	RunDigit(digits, {29}, 30);
	
	
    return 0;
}
