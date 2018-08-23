/*
【题目】 编写一个类，用两个栈实现队列，支持队列的基本操作(push、pop、back、front)。
*/
/*
【注意事项】
* 1. 如果pushStack要往popStack中压入数据， 那么必须一次性把pushStack中的数据全部压入。
* 2. 如果popStack不为空，pushStack绝对不能向popStack中压入数据。
*/

#include<iostream>
#include<stack>
using namespace std;

class MyTwoStackQueue
{
private:
    stack<int> popStack;
    stack<int> pushStack;
    int backInt;
    void adjust();

public:
    // MyTwoStackQueue() : popStack(new stack<int>()), pushStack(new stack<int>()) {}
    // ~MyTwoStackQueue() { delete popStack; delete pushStack; }
    void push(int newNum);
    void pop();
    int front();
    int back();
};

void MyTwoStackQueue::adjust()  
{
    while(!pushStack.empty())
    {   
        popStack.push(pushStack.top()); 
        pushStack.pop();
    }
}

void MyTwoStackQueue::push(int newNum)
{
    backInt = newNum;
    pushStack.push(newNum); 
}

void MyTwoStackQueue::pop()
{
    if (popStack.empty())
        adjust();
    if (popStack.empty())
    {
        cout << "The queue is empty! Can't pop!" << endl;
        return;
    }
    popStack.pop();
}

int MyTwoStackQueue::front()
{
    if (popStack.empty())
        adjust();
    return popStack.top();
}

int MyTwoStackQueue::back()
{
    return backInt;
}

int main()
{
    MyTwoStackQueue queue1;
    for(int i = 0; i < 10; ++i)
        queue1.push(i);
    cout << "front: " << queue1.front() << " back: "<< queue1.back() << endl;
    queue1.pop();
    cout<< "pop!" <<endl;
    cout << "front: " << queue1.front() << " back: " << queue1.back() << endl;
    queue1.push(10);
    cout<<"push 10!" <<endl;
    cout << "front: " << queue1.front() << " back: " << queue1.back() << endl;
    for(int i = 0; i < 9; ++i)
        queue1.pop();
    cout<< "pop*8" <<endl;
    cout << "front: " << queue1.front() << " back: " << queue1.back() << endl;
    queue1.pop();
    queue1.pop();
}
