#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <cmath>
#include <map>
#include <algorithm>
#include <climits>
#include <cfloat>
#include <iomanip>
#include <queue>
#include <stack>
#include <deque>
#include <sstream>
#include <set>
#include <fstream>
#include <cstring>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class MyQueue
{
private:
    stack<int> stk1;
    stack<int> stk2;

public:
    MyQueue(){}

    void push(int v)
    {
        stk1.push(v);
    }

    int front()
    {
        if(stk2.empty())
        {
            while(!stk1.empty())
            {
                stk2.push(stk1.top());
                stk1.pop();
            }
        }
        return stk2.top();
    }

    void pop()
    {
        if(stk2.empty())
        {
            while(!stk1.empty())
            {
                stk2.push(stk1.top());
                stk1.pop();
            }
        }
        stk2.pop();
    }

    int size()
    {
        return stk1.size() + stk2.size();
    }
};

int main()
{
    MyQueue que;
    que.push(3);
    que.push(66);
    cout << que.size() << endl;
    que.pop();
    cout << que.size() << endl;
    //cout << que.front() << endl;

    return 0;
}