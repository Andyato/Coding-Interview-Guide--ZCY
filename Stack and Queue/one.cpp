/*
【题目】 实现一个特殊的栈，在实现栈的基本功能的基础上，在实现返回栈中最小元素的操作。
【要求】 1. pop、push、getMin操作的时间复杂度都是O(1)。
        2. 设计的栈类型可以使用现成的栈结构。
*/

#include<iostream>
#include<stack>
using namespace std;

class MyStack
{
private:
    stack<int> DataStack;
    stack<int> MinStack;
public:
    void push(int newNum);
    void pop();
    int top();
    int getMin();
};

void MyStack::push(int newNum)
{
    DataStack.push(newNum);
    if (MinStack.empty() || newNum < MinStack.top())
        MinStack.push(newNum);    
}

void MyStack::pop()
{
    int num = DataStack.top(); DataStack.pop();
    if(num == MinStack.top())
        MinStack.pop();
}   

int MyStack::top()
{
    return DataStack.top();
}

int MyStack::getMin()
{
    return MinStack.top();
}

int main()
{
    MyStack stack1;
    for(int i = 0; i < 10; ++i)
        stack1.push(i);
    cout<<"stack1's top number: "<<stack1.top()<<endl;
    cout<<"stack1's minimum number: "<<stack1.getMin()<<endl;
    stack1.pop();
    cout<<"stack1's top number after one pop: "<<stack1.top()<<endl;
}
