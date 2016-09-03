//
//  main.cpp
//  HandShaking
//
//  Created by lee on 2016. 9. 3..
//  Copyright © 2016년 lee. All rights reserved.
//

#include <iostream>

class HandShaking {
    
public:
    long countPerfect(int n);
};

long HandShaking::countPerfect(int n)
{
    if (n==0 || n==2)
        return 1;

    long count = 0;
    
    for (int i=2 ; i <= n ; i=i+2)
    {
        count += countPerfect(i-2) * countPerfect(n - i);
    }
    
    return count;
}

int main(int argc, const char * argv[]) {
    
    HandShaking handShaking;
    long count = 0;
    
    for(int i =2; i <30 ; i=i+2)
    {
        count = handShaking.countPerfect(i);
        std::cout << "resutl: "<<  i <<" : " << count << std::endl;
    }
    
    return 0;
}
