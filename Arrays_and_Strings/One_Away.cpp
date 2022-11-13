/*
 * Page: 91, Que: 1.5 - One Away
 *
 * Notes:
 *  -You did exactly the same way as the solution
 *  -On minor thing is you could copy a,b to new var s1 and s2 such that s1_len > s2_len.
 *   In this way you can eliminate one else if (line 40) at the cost of extra memory.
 *
 * Mistakes:
 *
 * */


#include <iostream>
#include <string>
#include <cmath>

#define MIN(a,b) (a < b ? a:b)

using  namespace std;
bool isOneAway(string a, string b)
{
    if(abs((int)a.size() - (int)b.size()) > 1)
    {
        return false;
    }
    int a_ind = 0;
    int b_ind = 0;
    int mismatch_cnt = 0;
    for(int i=0; i< MIN((int)a.size(), (int)b.size());i++)
    {
        if(a[a_ind] != b[b_ind])
        {
            mismatch_cnt++;
            if((int)a.size() == (int)b.size())
            {
                a_ind++;
                b_ind++;
            }else if((int)a.size() > (int)b.size())
            {
                a_ind++;
            }else if((int)a.size() < (int)b.size())
            {
                b_ind++;
            }
            if(mismatch_cnt > 1)
            {
                return false;
            }
        }else{
            a_ind++;
            b_ind++;
        }
    }
    return true;
}
