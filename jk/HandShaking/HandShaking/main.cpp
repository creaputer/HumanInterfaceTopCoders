//
//  main.cpp
//  HandShaking
//
//  Created by JunKyo on 2016. 8. 29..
//  Copyright © 2016년 JunKyo. All rights reserved.
//

#include <iostream>
#include <vector>

template<typename T1, typename T2>
void TestEqual(const T1 && expected, const T2 && returns)
{
	if (expected == returns) std::cout << "Passed" << std::endl;
	else std::cout << "Failed: " << returns << ", not: " << expected << std::endl;
}

class HandShaking
{
public:
	HandShaking(){}
	
public:
	long countPerfect(int n) {
		if (n % 2 != 0) return 0;
		
		const auto MAX_LOOP = n / 2;
		auto hs = std::vector<long>(MAX_LOOP + 1, 0);
		hs[0] = hs[1] = 1;
		
		for (auto _1 = 2; _1 <= MAX_LOOP; ++_1) {
			for (auto _2 = 0; _2 < _1; ++_2) {
				hs[_1] += hs[_2] * hs[_1 - _2 - 1];
			}
		}
		
		return hs[n / 2];
	};
	
private:
	HandShaking(const HandShaking &) = delete;
	HandShaking& operator=(const HandShaking &) = delete;
};

int main(int argc, const char * argv[]) {
	auto obj = std::make_shared<HandShaking>();
	TestEqual(obj->countPerfect(2), 1);
	TestEqual(obj->countPerfect(4), 2);
	TestEqual(obj->countPerfect(6), 5);
	TestEqual(obj->countPerfect(8), 14);
	TestEqual(obj->countPerfect(10), 42);
	TestEqual(obj->countPerfect(16), 1430);
	
    return 0;
}
