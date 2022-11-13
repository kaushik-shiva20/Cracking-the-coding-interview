//
// Created by kaush on 8/1/2022.
//

#ifndef CRACK_CODE_INTERVIEW_MSTACK_H
#define CRACK_CODE_INTERVIEW_MSTACK_H
template <class T>
class mStack
{
private:
    typedef struct sElement
    {
        T _val;
        sElement *_prev_ptr;
    };

    sElement * _top;
    int _size=0;
public:
    mStack(){_top = nullptr;_size=0;};
    void push(T val){
        sElement * temp = new sElement();
        temp->_val = val;
        temp->_prev_ptr = _top;
        _top = temp;
        _size++;
    }
    T pop(){
        if(_size > 0)
        {
            T ret = _top->_val;
            sElement * temp = _top;
            _top = _top->_prev_ptr;
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
            ptr = _top;
            while (tmp < (_size - index - 1)) {
                ptr = ptr->_prev_ptr;
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
#endif //CRACK_CODE_INTERVIEW_MSTACK_H
