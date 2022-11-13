//
// Created by kaush on 8/1/2022.
//

//This file contains implementations of different kinds of sorts

/*
 * - Insertion Sort
 *
 * TODO:
 * - Bubble
 * - Selection
 * - Inserion with binary search
 * - Quick
 * - Merge
 *
 * */

void mInsertionSort(int * mArr, int arrSize)
{
    //int arrSize = sizeof(mArr)/sizeof(int);
    int tempind;
    for(int i=1;i<arrSize;i++)
    {
        tempind = i;
        for(int j=i-1;j>=0;j--)
        {
            if(mArr[tempind] < mArr[j])
            {
                int temp = mArr[tempind];
                mArr[tempind] = mArr[j];
                mArr[j] = temp;
                tempind = j;
            }else
            {
                break;
            }
        }
    }
}