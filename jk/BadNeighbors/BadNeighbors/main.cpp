//
//  main.cpp
//  BadNeighbors
//
//  Created by JunKyo on 2016. 8. 12..
//  Copyright © 2016년 JunKyo. All rights reserved.
//

#include <iostream>
#include <vector>

using input_t = std::vector<int>;

template<typename T>
void TestEqual(const std::function<int(T)> & func, const int & expected, const T & input)
{
	auto returns = func(input);
	
	if (expected == returns) std::cout << "Passed" << std::endl;
	else std::cout << "Failed : " << returns << std::endl;
}

auto total = 0;
auto result = 0;
auto dists = std::vector<int>{};
auto bUseFirstElement = true;

bool getDonations(const input_t & donations, const int idx)
{
	if (donations.size() <= idx) return false;
	if (bUseFirstElement && (idx == donations.size() - 1)) return false;

	total += donations[idx];
	
	for (auto _1 = idx + 2; _1 < donations.size(); ++_1) {
		if (getDonations(donations, _1)) {
		
			total -= donations[_1];
		}
	}
	
	dists.emplace_back(total);
	
	return true;
}

int maxDonations(const input_t & donations)
{
	auto totals = input_t(donations.size(), 0);
	
	for (auto _1 = 0; _1 < donations.size(); ++_1) {
		if (_1 == 0) {
			bUseFirstElement = true;
			dists = {};
		}
		else bUseFirstElement = false;
		
		total = 0;
		getDonations(donations, _1);
	};
	
	return *std::max_element(dists.cbegin(), dists.cend(), [](const auto & lhs, const auto & rhs) {
				return lhs < rhs;
			});
}

int main(int argc, const char * argv[]) {
	
	const auto donataions0 = input_t{ 10, 3, 2, 5, 7, 8 };
	const auto Returns0 = 19;
	TestEqual<input_t>(maxDonations, Returns0, donataions0);
	
	const auto donataions1 = input_t{ 11, 15 };
	const auto Returns1 = 15;
	TestEqual<input_t>(maxDonations, Returns1, donataions1);
	
	const auto donataions2 = input_t{ 7, 7, 7, 7, 7, 7, 7 };
	const auto Returns2 = 21;
	TestEqual<input_t>(maxDonations, Returns2, donataions2);
	
	const auto donataions3 = input_t{ 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 };
	const auto Returns3 = 16;
	TestEqual<input_t>(maxDonations, Returns3, donataions3);
	
	const auto donataions4 = input_t{ 94, 40, 49, 65, 21, 21, 106, 80, 92, 81, 679, 4, 61, 6, 237, 12, 72, 74, 29, 95, 265, 35, 47, 1, 61, 397, 52, 72, 37, 51, 1, 81, 45, 435, 7, 36, 57, 86, 81, 72 };
	const auto Returns4 = 2926;
	TestEqual<input_t>(maxDonations, Returns4, donataions4);
	
	
    return 0;
}
