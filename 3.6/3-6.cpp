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

stack<int> SortStack(stack<int> &stk)
{
    stack<int> buf;
    while(!stk.empty())
    {
        int t = stk.top();
        stk.pop();
        while(!buf.empty() && buf.top() > t)
        {
            stk.push(buf.top());
            buf.pop();
        }
        buf.push(t);
    }
    return buf;
}

int main()
{
    stack<int> stk;
    stk.push(5);
    stk.push(3);
    stk.push(4);
    stk.push(1);
    stk.push(2);
    stack<int> ans = SortStack(stk);
    while(!ans.empty())
    {
        cout << ans.top() << endl;
        ans.pop();
    }
    
    return 0;
}