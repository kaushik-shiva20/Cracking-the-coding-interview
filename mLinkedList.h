//
// Created by kaush on 8/1/2022.
//

#ifndef CRACK_CODE_INTERVIEW_MLINKEDLIST_H
#define CRACK_CODE_INTERVIEW_MLINKEDLIST_H
#include <iostream>
using namespace std;

template<class T>
class mLinkedList;
template<class T>
class mListNode{
public:
    T val;
    mListNode* next;
    mListNode* prev;
    mListNode(T mVal): val(mVal),next(nullptr),prev(nullptr){};

    friend class mLinkedList<T>;
    friend ostream& operator<<(ostream& mOut, const mLinkedList<T>& mList);
};

enum Listtype
{
    SINGLE,
    DOUBLE
};
template<class T>
class mLinkedList{
public:
    mListNode<T>* head;
    mListNode<T>* tail;
    int size;
    Listtype _type;

//public:
    mLinkedList(Listtype listType = SINGLE):_type(listType),head(nullptr),tail(nullptr),size(0){};
    void insertNode(T mVal){
        mListNode<T>* temp = new mListNode<T>(mVal);
        insertNode(temp);
    };
    void insertNode(mListNode<T>* mNode){
        if(_type == DOUBLE) {
            mNode->prev = tail;
        }

        if(tail)
            tail->next = mNode;

        tail = mNode;

        if(!head)
            head = mNode;

        size++;
    };
    //This function assumes the linked list contains only one node with value mVal.
    //If there's more than one node with value mVal, then the first node with mVal will be deleted
    void deleteNode(T mVal){

        mListNode<T>* mPrevNode;
        mListNode<T>* mDeleteNode = find(mVal,mPrevNode);
        if(mDeleteNode)
        {
            size--;
            if(mPrevNode)
            {
                mPrevNode->next = mDeleteNode->next;
            }
            if(mDeleteNode == head)
            {
                head = mDeleteNode->next;
            }
            if(mDeleteNode == tail)
            {
                int temp=0;
                mPrevNode = head;
                while(temp < size)
                {
                    mPrevNode = mPrevNode->next;
                    temp++;
                }
                tail = mPrevNode;
                //tail->next = nullptr;
            }
            delete mDeleteNode;
        }
    };
    void deleteNode(mListNode<T>* mNode){
        if(_type == DOUBLE)
        {
            if(mNode->prev) {
                mNode->prev->next = mNode->next;
            }
            if(mNode == head)
            {
                head = mNode->next;
            }
            if(mNode == tail)
            {
                tail = mNode->prev;
                //tail->next = nullptr;
            }
            delete mNode;
            size--;
        }else
        {
            deleteNode(mNode->val);
        }
    };
    mListNode<T>* find(T mVal, mListNode<T>* &prevNode)
    {
        mListNode<T>* mRet = nullptr;
        mListNode<T>* currNode = head;
        int tempSize = 0;
        prevNode = nullptr;

        while((tempSize < size) && (currNode != nullptr))
        {
            if(currNode->val == mVal)
            {
                mRet = currNode;
                break;
            }else
            {
                prevNode = currNode;
                currNode = currNode->next;
                tempSize++;
            }
        }
        return mRet;
    };
    T operator[](int mIndex)
    {
        bool isNeg = false;
        if(mIndex < 0)
        {
            isNeg = true;
            mIndex = size+mIndex;
        }

        int temp = 0;
        mListNode<T>* currNode = head;
        T mRet;
        if(mIndex < size)
        {
            while(temp < mIndex)
            {
                currNode = currNode->next;
                temp++;
            }
            mRet = currNode->val;
        }
        return mRet;
    }
    friend ostream& operator<<(ostream& mOut, const mLinkedList<T>& mList)
    {
        int temp = 0;
        cout << "Linked List" << endl;
        mListNode<T>* currNode = mList.head;
        if(mList._type == SINGLE)
        {
            cout << "Type: SINGLE, Size: " << mList.size << endl;
        }
        if((temp < mList.size) && (currNode != nullptr))
        {
            cout << currNode->val;
            temp++;
            currNode = currNode->next;
        }
        while((temp < mList.size) && (currNode != nullptr))
        {
            cout << " -> " << currNode->val;
            temp++;
            currNode = currNode->next;
        }
        cout << endl;
        return cout;
    };
};

#endif //CRACK_CODE_INTERVIEW_MLINKEDLIST_H
