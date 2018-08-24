/*
【题目】 一个栈依此压入1、2、3、4、5，那么从栈顶到栈底分别为5、4、3、2、1。将这个栈转置后，从栈顶到栈底为1、2、3、4、5，
        也就是实现栈中元素的逆序，只能借助递归来实现，不能用其它数据结构。
//
    PS: To Iterate is Human, to Recurse, Divine. 
*/

#include<iostream>
#include<stack>
using namespace std;

int getAndRemoveLastElement(stack<int>& st);
void reverse(stack<int>& st)
{
    if(st.empty()) return;

    int last = getAndRemoveLastElement(st);
    reverse(st);
    st.push(last);
}

int getAndRemoveLastElement(stack<int>& st)
{
    int elem = st.top(); st.pop();
    if(st.empty()) 
        return elem;
    int last = getAndRemoveLastElement(st);
    st.push(elem);
    return last;
}

int main()
{
    stack<int> st;
    for(int i = 1; i < 6; ++i)
        st.push(i);
    stack<int> print;
    print = st;
    while(!print.empty())
    {
        cout<<print.top()<<" ";
        print.pop();
    }
    cout<<endl;

    reverse(st);
    print = st;
    cout << "After reversing: "<<endl;
    while (!print.empty())
    {
        cout << print.top() << " ";
        print.pop();
    }
}

