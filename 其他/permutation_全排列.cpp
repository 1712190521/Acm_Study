#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int num[3]={1,2,3};
    do
    {
        cout<<num[0]<<" "<<num[1]<<" "<<num[2]<<endl;
    }while(next_permutation(num,num+3));
    return 0;
}
//next_permutation（start,end），和prev_permutation（start,end）。这两个函数作用是一样的，区别就在于前者求的是当前排列的下一个排列，后一个求的是当前排列的上一个排列。至于这里的“前一个”和“后一个”，我们可以把它理解为序列的字典序的前后，严格来讲，就是对于当前序列pn，他的下一个序列pn+1满足：不存在另外的序列pm，使pn<pm<pn+1.
//当当前序列不存在下一个排列时，函数返回false，否则返回true