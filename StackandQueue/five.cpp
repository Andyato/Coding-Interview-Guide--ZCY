/*
【题目】 一个栈中元素的类型为整形，现在想将该栈从顶到底按从大到小的顺序排序，只许申请一个栈。
        除此之外，可以申请新的变量，但不能申请额外的数据结构。如何完成排序？
*/

#include<stack>
#include<iostream>
using namespace std;

void stackSort(stack<int>& st)
{
    stack<int> helper;
    int curr;

    while(!st.empty())
    {
        curr = st.top(); st.pop();
        while(!helper.empty() && curr < helper.top())
        {
            st.push(helper.top()); helper.pop();
        }
        helper.push(curr);    
    }
    st = helper; 
}

int main()
{
    stack<int> st;
    int a[] = {3, 2, 5, 6, 8, 1};
    for (int i = 0;i < 6; ++i)
        st.push(a[i]);
    stackSort(st);
    
    for(int i = 0; i < 6; ++i)
    {
        cout<<st.top()<<" ";
        st.pop();
    }
}