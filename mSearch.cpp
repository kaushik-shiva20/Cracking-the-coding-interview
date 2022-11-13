//
// Created by kaush on 8/1/2022.
//

//This file contains implementations of different kinds of search algo
/*
 * - Binary Search
 *
 * TODO:
 * - DFS
 * - BFS
 *
 * */

int mBinSearch(int *mArr, int start, int end, int mVal)
{

    if((end - start) == 1)
    {
        if(*mArr == mVal)
        {
            return start;
        }else
        {
            return -1;
        }
    }

    if(mVal == mArr[start + ((end - start)/2)])
    {
        return (start + ((end - start)/2));
    }else if(mVal > (start + ((end - start)/2)))
    {
        return mBinSearch(mArr,start + ((end - start)/2), end, mVal);
    }else
    {
        return mBinSearch(mArr, start, start + ((end - start)/2), mVal);
    }
}