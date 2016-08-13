//
//  main.cpp
//  CorporationSalary
//
//  Created by lee on 2016. 8. 12..
//  Copyright © 2016년 lee. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;


class CorporationSalary{
    
private:
    vector<string> mRelations;
    
public:
    long totalSalary(vector<string> relations);
    long personalSalary(int person);
};

long CorporationSalary::totalSalary(vector <string> relations)
{
    long total = 0;
    
    mRelations = relations;
    
    int size = (int) relations.size();
    
    for (int i =0; i < size; i ++)
    {
        total += personalSalary(i);
    }
    
    
    return total;
}

long CorporationSalary::personalSalary(int person)
{
    long salary = 0;
    
    for (int i=0 ; i < mRelations[person].length() ; i++)
    {
        if(mRelations[person][i] == 'Y')
        {
            salary += personalSalary(i);
        }
    }
    
//    long salary = [&]
//    {
//        long salaryTemp = 0;
//        for (int i=0 ; i < mRelations[person].length() ; i++)
//        {
//            if(mRelations[person][i] == 'Y')
//            {
//                salaryTemp += personalSalary(i);
//            }
//        }
//        
//        return salaryTemp;
//    }();

    return max(long(1), salary);
}


int main(int argc, const char * argv[]) {
    
    CorporationSalary corporationSalary;
    vector <string> relations = {
        "NNYN",
        "NNYN",
        "NNNN",
        "NYYN"
    };
    
    long total = corporationSalary.totalSalary(relations);
    
    cout<< "1) salary: " << total << endl;
    
    
    relations = {
        "NNNNNN",
        "YNYNNY",
        "YNNNNY",
        "NNNNNN",
        "YNYNNN",
        "YNNYNN"
    };
    
    total = corporationSalary.totalSalary(relations);
    
    cout<< "2) salary: " << total << endl;
    
    return 0;
}
