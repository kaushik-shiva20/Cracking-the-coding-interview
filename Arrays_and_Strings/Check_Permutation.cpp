/*
 * Page: 90, Que: 1.2 - Check Permutation
 *
 * Notes:
 *
 *
 * Mistakes:
 *
 * */

#include <iostream>
#include <string>
#include <map>

using namespace std;

//This function checks if mStr2 is a permutation of mStr1
bool isPermutation(string mStr1, string mStr2)
{
    map<char,int> mStr1map;
    map<char,int> mStr2map;
    //Length of both strings should be equal for it to be a permutation
    if(mStr1.length() != mStr2.length())
        return false;

    for(int i=0;i<mStr1.length();i++)
    {
        mStr1map[mStr1[i]]++;
        mStr2map[mStr2[i]]++;
    }

    //both maps should have same number of key value pairs if both str are permutation
    if(mStr1map.size() != mStr2map.size())
        return false;

    for(auto item: mStr1map)
    {
        if(item.second != mStr2map[item.first])
            return false;
    }

    return true;
}
