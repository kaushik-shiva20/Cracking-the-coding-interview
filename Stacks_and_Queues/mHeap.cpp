//
// Created by kaush on 8/1/2022.
//

#ifndef CRACK_CODE_INTERVIEW_MHEAP_H
#define CRACK_CODE_INTERVIEW_MHEAP_H
#include <vector>
#include <list>
#include <iostream>
using namespace std;

template <class T>
class mHeap{
private:
    vector<T> _heap;
    int _size;
public:
    mHeap(vector<T> mArr): _heap(mArr.begin(),mArr.end()),_size(_heap.size()){};
    mHeap(T (&mArr)[1]): _heap(begin(mArr),end(mArr)),_size(_heap.size()){};

    void max_heapify(int index, int size = -1){
        if(size == -1)
            size = _size;
        int largest_index = index;
        int left_index = 2*index + 1;
        int right_index = 2*index + 2;

        if((left_index < size) && (_heap[left_index] > _heap[largest_index]))
            largest_index = left_index;
        if((right_index < size) && (_heap[right_index] > _heap[largest_index]))
            largest_index = right_index;

        if(largest_index != index)
        {
            T temp = _heap[index];
            _heap[index] = _heap[largest_index];
            _heap[largest_index] = temp;
            max_heapify(largest_index, size);
        }
    };

    void build_max_heap(){
        for(int i = _size/2; i >= 0; i--)
        {
            max_heapify(i);
        }
    }

    void sort(){
        build_max_heap();
        for(int i=0;i<_size-1;i++)
        {
            T temp = _heap[0];
            _heap[0] = _heap[_size - i - 1];
            _heap[_size - i - 1] = temp;
            max_heapify(0, _size - i - 1);
        }
    }

    friend ostream& operator<<(const ostream& mout, const mHeap& mObj)
    {
        for(int i=0;i<mObj._size;i++)
        {
            cout << mObj._heap[i] << ", ";
        }
        cout << endl;
        return cout;
    }
};

#endif //CRACK_CODE_INTERVIEW_MHEAP_H
