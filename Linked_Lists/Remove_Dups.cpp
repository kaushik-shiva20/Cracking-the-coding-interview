/*
 * Page: 94, Que: 2.1 - Remove Dups
 *
 * Notes:
 *
 *
 * Mistakes:
 *
 * */

#include <iostream>
#include "..\mLinkedList.h"
#include <unordered_set>
#include <vector>

using namespace std;

void removeDups(mLinkedList<int> &mList)
{
    vector<int> mVec;
    mVec.resize(10);
    //remove duplicates from unsorted linked list
    mListNode<int> *current = mList.head;
    cout << mList;
    unordered_set<int> mset;
    while(current)
    {
        auto m = mset.find(current->val);

        if(mset.find(current->val) != mset.end())
        {
            mList.deleteNode(current->val);
        }
        else
        {
            mset.insert(current->val);
        }
        current = current->next;
    }
    cout << mList;
}



