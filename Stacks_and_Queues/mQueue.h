//
// Created by kaush on 8/15/2022.
//

#ifndef CRACK_CODE_INTERVIEW_MQUEUE_H
#define CRACK_CODE_INTERVIEW_MQUEUE_H

template <class T>
class mQueue
{
private:
    typedef struct sElement
    {
        T _val;
        sElement *_next_ptr;
    };
    sElement * _front;
    sElement * _rear;
    int _size=0;
public:
    mQueue(){_front = nullptr;_rear = nullptr;_size=0;};
    void push(T val){
        sElement * temp = new sElement();
        temp->_val = val;
        temp->_next_ptr = nullptr;
        if(_size == 0)
        {
            _front = temp;
            _rear = temp;
        }else
        {
            _rear->_next_ptr = temp;
            _rear = temp;
        }
        _size++;
    }
    T pop(){
        if(_size > 0)
        {
            T ret = _front->_val;
            sElement * temp = _front;
            _front = _front->_next_ptr;
            delete temp;
            _size--;
            return ret;
        }else
        {
            T tmpRet;
            return tmpRet;
        }
    }
    bool empty(){return _size <= 0;}
    int size(){return _size;}
    T operator[](int index)
    {
        if(!empty()) {
            int tmp = 0;
            sElement *ptr;
            ptr = _front;
            while (tmp < index) {
                ptr = ptr->_next_ptr;
                tmp++;
            }
            return ptr->_val;
        }else
        {
            T ret;
            return ret;
        }
    }
};



#endif //CRACK_CODE_INTERVIEW_MQUEUE_H
