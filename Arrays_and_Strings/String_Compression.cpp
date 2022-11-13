/*
 * Page: 91, Que: 1.6 - String Compression
 *
 * Notes:
 *  -While calculating complexity for this, need to consider cost of ostringstream << operation.
 *  -If we had used an output string like ret = "" and append data to it, then complexity would've been
 *  O(n + k^2) n - size of original string and k - number of character sequences Ex: aabccdeeaaa has 6 character sequences
 *  String concatenation takes O(n^2). Everytime new char -> string concatenation happens
 *
 *  -Alternatively a stringbuilder can be used or use one loop to calculate resultant string size
 *  first then create a stringbuilder of required size and start appending. (See Sol for further details)
 *
 * Mistakes:
 *  -Didn't read the question clearly. Made a hash map.
 *  aabcccccaaa --> would've printed as a5b1c5 which is incorrect expected a2b1c5a3.
 *  See commented code below to understand mistake
 *
 *
 * */

#include <iostream>
#include <string>
#include <sstream>
#include <map>
using  namespace std;


string compressString(string inStr) {
    ostringstream out;
    char prevChar = inStr[0];
    int charCount = 0;
    bool isNonOneCharCountPresent = false;
    for(auto currChar: inStr)
    {
        if(prevChar != currChar)
        {
            if(!isNonOneCharCountPresent)
            {
                if(charCount > 1)
                {
                    isNonOneCharCountPresent = true;
                }
            }
            out << prevChar << charCount;
            charCount = 0;
        }
        charCount++;

        prevChar = currChar;
    }
    out << prevChar << charCount;
    if(isNonOneCharCountPresent)
    {
        return out.str();
    }else
    {
        return inStr;
    }

}
/*
string compressString(string inStr)
{
    string mRet;
    map<char,int> charMap;
    bool isNonOne = false;
    for(auto i:inStr)
    {
        charMap[i]++;
        if(!isNonOne) {
            if (charMap[i] > 1) {
                isNonOne = true;
            }
        }
    }
    ostringstream out;
    if(!isNonOne)
    {
        return inStr;
    }else
    {
        for(auto item : charMap)
        {
            out << item.first << item.second;
        }
        return out.str();
    }

}
 */