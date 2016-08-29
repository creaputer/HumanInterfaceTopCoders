//
//  main.cpp
//  HandShaking
//
//  Created by JunKyo on 2016. 8. 29..
//  Copyright © 2016년 JunKyo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

class HandShaking
{
public:
	HandShaking(){}
	
public:
	long countPerfect(int n) {
		if (n % 2 != 0) return 0;
		
		auto hs = std::vector<long>(n + 1, 0);
		hs[1] = hs[2] = 1;
		
		for (auto _1 = 4; _1 <= n; _1 += 2) {
			const auto base = long{_1 / 2};
			const auto a = 3 < base ? base % 2 : 0;
			const auto LOOP = _1 / 2 + a;
			
			for (auto _2 = 0; _2 < LOOP; ++_2) {
				
				hs[_1] += hs[_1 - LOOP + _2 - 1];
			}
			hs[_1 - 1] = hs[_1];
		}
		
		return hs[n];
	};

private:
	HandShaking(const HandShaking &) = delete;
	HandShaking& operator=(const HandShaking &) = delete;
};

int main(int argc, const char * argv[]) {
	HandShaking obj;
	std::cout << obj.countPerfect(2) << "\n";
	std::cout << obj.countPerfect(4) << "\n";
	std::cout << obj.countPerfect(6) << "\n";
	std::cout << obj.countPerfect(8) << "\n";
	std::cout << obj.countPerfect(10) << "\n";
	std::cout << obj.countPerfect(12) << "\n";
	
    return 0;
}
