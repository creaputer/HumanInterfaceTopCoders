//
//  main.cpp
//  ThePalindrome
//
//  Created by JunKyo on 2016. 7. 29..
//  Copyright © 2016년 JunKyo. All rights reserved.
//

#include <iostream>
#include <string>
#include <functional>
#include <algorithm>
#include <array>
#include <vector>
#include <numeric>

void TestFind(const std::function<int(std::string)> & find, const int & expected, const std::string & input) {
	auto returns = find(input);
	
	if (expected == returns) std::cout << "Passed" << std::endl;
	else std::cout << "Failed : " << returns << std::endl;
}

int main(int argc, const char * argv[]) {
	auto find = [](const std::string & input) {
		auto reverse = std::string(input.size(), ' ');
		std::reverse_copy(std::begin(input), std::end(input), std::begin(reverse));
		
		if (input.compare(reverse) == 0) {
			return input.size();
		}
		
		auto thePalindrome = std::string{};
		auto iterReverse = reverse.cbegin();
		for (;;) {
			auto tempPalindrome = input + std::string{iterReverse, reverse.cend()};
			if (input.size() == tempPalindrome.size()) break;
			
			auto tempReverse = std::string(tempPalindrome.size(), ' ');
			std::reverse_copy(std::begin(tempPalindrome), std::end(tempPalindrome), std::begin(tempReverse));

			if (tempPalindrome.compare(tempReverse) == 0) {
				thePalindrome = tempPalindrome;
			}
			
			++iterReverse;
		};
		
		return thePalindrome.size();
	};
	
	TestFind(find, 5, "abab");
	TestFind(find, 7, "abacaba");
	TestFind(find, 11, "qwerty");
	TestFind(find, 38, "abdfhdyrbdbsdfghjkllkjhgfds");
	
	return 0;
}
