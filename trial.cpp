//
// Created by kaush on 7/31/2022.
//
#include <iostream>
#include <vector>
#include <map>
using namespace std;
//assuming mArr is sorted (Can be done @O(n) using unsorted using hashmap hint: save the visited num in map)
//template<size_t N>
bool findSumPair(int sum, int mArr[], vector<pair<int,int>> &mPairs, int N)
{
    //unsigned int N = sizeof(mArr) / sizeof(mArr[0]);
    int front_index = 0;
    int back_index = N - 1;
    bool isPairFound = false;
    while(front_index != back_index)
    {
        int tempSum = mArr[front_index] + mArr[back_index];
        if(tempSum > sum)
        {
            back_index--;
        } else if (tempSum < sum)
        {
            front_index++;
        }else
        {
            mPairs.push_back(make_pair(mArr[front_index], mArr[back_index]));
            front_index++;
            isPairFound = true;
        }
    }

    return isPairFound;
}

