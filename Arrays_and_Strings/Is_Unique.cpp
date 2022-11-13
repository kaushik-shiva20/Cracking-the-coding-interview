/*
 * Page: 90, Que: 1.1 - Is Unique
 *
 * Notes:
 *  -Each character is denoted using a bit. If a char seen then its bit is set
 *  -This problem can also be solved by using a hash map or by sorting the characters
 *   in string and doing O(N) search to see if it has duplicates
 *
 * Mistakes:
 *
 * */

#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

//Assuming mStr contains only lower case alphabets
bool isUnique(string mStr)
{
    bitset<26> mAlphabets;

    for(auto i: mStr)
    {
        if(mAlphabets[static_cast<int>((i - 'a'))])
            return false;
        else
            mAlphabets[static_cast<int>((i - 'a'))] = true;
    }
    return true;
}