#include <iostream>
#include <vector>
#include <map>
#include <set>
#include "mLinkedList.h"
//smart pointers
#include <memory>
#include "Stacks_and_Queues/mHeap.h"
#include "Stacks_and_Queues/mStack.h"

using namespace std;
bool isUnique(string mStr);
bool isPermutation(string mStr1, string mStr2);
bool isOneAway(string a, string b);
string compressString(string inStr);
void removeDups(mLinkedList<int> &mList);
//template<size_t N>
bool findSumPair(int sum, int mArr[], vector<pair<int,int>> &mPairs, int N);
template<class T>
T kthtolast(mLinkedList<T> &mList, int k);

struct Use_t
{
    long int cycle;                                //cycle at which element is used
    mutable std::vector<unsigned long long int> ES;     //Equivalent Sets of non-masked bits (Empty if all bits are masked)
    mutable std::vector<char> mask;                     //mask gives which bits are masked(0) and not masked(1). Using char vector because faster than bitset and bool vector although more memory
    mutable int numCurrCycleUses;                  //Count used to determine number of uses
    bool operator<(const Use_t& t) const           //Operator required because defined set using use_t
    {
        return (this->cycle < t.cycle);
    }
    Use_t(long int mCycle):cycle(mCycle),ES(0),mask(0),numCurrCycleUses(0){}
    void incrementnumCurrCycleUses(){numCurrCycleUses++;}
};
map<unsigned long long, map<long int, set<Use_t>>> DefUseMap;
int main() {


    //Pg: 90 | Q: 1.1 - is Unique
    //cout << isUnique("abcd") << endl;

    //Pg: 90 | Q: 1.2 - is Permutation
    //cout << isPermutation("abcd","dbac") << endl;

    //Pg: 91 | Q: 1.5 - One Away
    //cout << isOneAway("bake","false");

    //Pg: 91 | Q: 1.6 - String Compression
    //cout << compressString("aabcccccaaa") << endl;

    //Pg: 94 | Q: 2.1 - Remove Dups
    /* mLinkedList<int> mList;
      mList.insertNode(1);
      mList.insertNode(2);
      mList.insertNode(3);
      mList.insertNode(4);
      mList.insertNode(5);
      mList.insertNode(6);
      removeDups(mList);
      cout << mList;*/

    //Pg: 94 | Q: 2.2 - kth to last
    /*  mLinkedList<int> mList;
      mList.insertNode(1);
      mList.insertNode(2);
      mList.insertNode(3);
      mList.insertNode(4);
      mList.insertNode(5);
      mList.insertNode(6);
      cout << kthtolast(mList,3);*/

/*
    int mArr[] = {1,2,3,4,5,6,7,8,9,10};
    int *mPtr = new (&mArr[2]) int(5);
    cout << *mPtr << endl;
    cout << mArr[2] << endl;
    //cout << sizeof(mArr)/sizeof(int) << endl;
    cout << mArr << endl;
    //delete mPtr;
    cout << (mArr==NULL) << endl;
    //cout << sizeof(mArr)/sizeof(int) << endl;
*/
    /* mStack Test
    mStack<int> mObj;
    mObj.push(1);
    mObj.push(2);
    mObj.push(3);
    while(!mObj.empty())
    {
        cout << mObj.pop() << " ";
    }
    */

    /* mHeap Test
    mHeap<char> mHeapObj({'b','d' ,'a', 'e', 'c', 'f'});
    cout << mHeapObj;
    mHeapObj.build_max_heap();
    cout << "Post Build Max Heap: " << endl;
    cout << mHeapObj;

    mHeapObj.sort();
    cout << "Post Heap Sort: " << endl;
    cout << mHeapObj;
     */

/*    //mLinkedList Test;
    mLinkedList<int> mList;
    mList.insertNode(1);
    mList.insertNode(2);
    mList.insertNode(3);
    mList.insertNode(4);
    cout << mList;
    mList.deleteNode(3);
    cout << mList;
    mList.insertNode(5);
    cout << mList;
    mList.tail->next = mList.head;

    mListNode<int>* tortoisePtr = mList.head;
    mListNode<int>* harePtr = mList.head;

    while(harePtr != NULL && harePtr->next != NULL && tortoisePtr != NULL)
    {
        tortoisePtr = tortoisePtr->next;
        harePtr = harePtr->next->next;
        if(tortoisePtr == harePtr)
        {
            cout << "Loop Detected" << endl;
            break;
        }
    }

    if(harePtr->next == NULL)
    {
        cout << "No Loop Detected" << endl;
    }

*/


    /*
    vector<pair<int,int>> mResult;
    int mArr[]{1,2,3,4,5};
    int sum = 7;
    bool isPairFound;

    isPairFound = findSumPair(sum,mArr,mResult,sizeof(mArr)/sizeof(mArr[0]));

    if(isPairFound) {
        cout << "Found " << mResult.size() << " pairs with Sum = " << sum << endl;
        for (auto i: mResult) {
            cout << i.first << " " << i.second << endl;
        }
    }else
    {
        cout << "No Pairs found with Sum = " << sum << endl;
    }
    */

    //Smart Pointer Test

    //unique_ptr<int> mPtr(new int(10));
    //unique_ptr<int> mPtr2;
 /*   int *mPtr = new int(10);
    unique_ptr<int> mPtr2 = (unique_ptr<int>)mPtr;
    //mPtr2 = move(mPtr);
    *mPtr2 = 10;
    cout << *mPtr << endl;
*/

    DefUseMap[1][1].insert({1});
    cout << "Index Map \n" ;
    cout << DefUseMap.size() << endl;
    cout << DefUseMap.max_size() << endl;
    cout << "Def Map \n";
    cout << DefUseMap[1].size() << endl;
    cout << DefUseMap[1].max_size() << endl;
    cout << "Use Set \n";
    cout << DefUseMap[1][1].size() << endl;
    cout << DefUseMap[1][1].max_size() << endl;

    DefUseMap[1][2].insert({2});
    cout << "Index Map \n" ;
    cout << DefUseMap.size() << endl;
    cout << DefUseMap.max_size() << endl;
    cout << "Def Map \n";
    cout << DefUseMap[1].size() << endl;
    cout << DefUseMap[1].max_size() << endl;
    cout << "Use Set \n";
    cout << DefUseMap[1][2].size() << endl;
    cout << DefUseMap[1][2].max_size() << endl;

    cout << "\n sizeof(Use_t)\n" << sizeof(Use_t) << endl;

    auto currUse1 = DefUseMap[1][1].find({1});
    currUse1->mask.push_back(1);
    currUse1->ES.push_back(10);

    cout << "Index Map \n" ;
    cout << DefUseMap.size() << endl;
    cout << DefUseMap.max_size() << endl;
    cout << "Def Map \n";
    cout << DefUseMap[1].size() << endl;
    cout << DefUseMap[1].max_size() << endl;
    cout << "Use Set \n";
    cout << DefUseMap[1][1].size() << endl;
    cout << DefUseMap[1][1].max_size() << endl;

    return 0;
}