//
//  main.cpp
//  BadNeeghbors
//
//  Created by lee on 2016. 8. 12..
//  Copyright © 2016년 lee. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class BadNeighbors {
    
private:
    vector <int> mDonations;
    int mLength;
    int mMax = 0;
    
    public :
    int maxDonations(vector <int> donations);
    
    int getDonation(int n, int max, string path);
};

int BadNeighbors::maxDonations(vector <int> donations)
{
    mDonations = donations;
    mLength = (int) donations.size();
    
    string path = "";
    for (int i =0; i <mLength; i++)
    {
        path += "N";
    }
    
    mMax = 0;
    for (int i =0; i < mLength; i ++)
    {
        getDonation(i, 0, path);
    }
    
    return mMax;
}

int BadNeighbors::getDonation (int n, int aMax, string path)
{
    aMax += mDonations[n];
    path.at(n) = 'Y';
    
    for (int i =n+2; i < mLength; i ++)
    {
        getDonation (i, aMax, path);
    }
    
    if (path.at(0) == 'Y' && path.at(mLength -1) == 'Y')
        aMax = 0;
    
    mMax = max(aMax, mMax);
    
    return 0;
}


int main(int argc, const char * argv[]) {
    BadNeighbors badNeighbors;
    using input_t = std::vector<int>;
    
    auto donations = input_t{10, 3, 2, 5, 7, 8};
    int max = badNeighbors.maxDonations(donations);
    cout << "0) max: " << max << endl;
    
    donations = input_t{ 11, 15 };
    max = badNeighbors.maxDonations(donations);
    cout << "1) max: " << max << endl;
    
    donations = input_t{ 7, 7, 7, 7, 7, 7, 7 };
    max = badNeighbors.maxDonations(donations);
    cout << "2) max: " << max << endl;
    
    donations = input_t{ 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 };
    max = badNeighbors.maxDonations(donations);
    cout << "3) max: " << max << endl;

    donations = input_t{ 94, 40, 49, 65, 21, 21, 106, 80, 92, 81, 679, 4, 61, 6, 237, 12, 72, 74, 29, 95, 265, 35, 47, 1, 61, 397, 52, 72, 37, 51, 1, 81, 45, 435, 7, 36, 57, 86, 81, 72 };
    max = badNeighbors.maxDonations(donations);
    cout << "4) max: " << max << endl;
    
    return 0;
}
