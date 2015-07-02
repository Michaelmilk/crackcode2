#include <iostream>
#include <cstdlib>
#include <stack>
using namespace std;


void MoveTop(int origin, int dest)
{
    cout << origin << " ----> " << dest << endl;
}

void MoveDisks(int n, int origin, int buf, int dest)
{
    if(n <= 0)
        return;
    MoveDisks(n - 1, origin, dest, buf);
    MoveTop(origin, dest);
    MoveDisks(n - 1, buf, origin, dest);
}

class Tower
{
private:
    stack<int> disks;
    int index;

public:
    Tower(int i)
    {
        index = i;
    }

    void add(int d)
    {
        if(!disks.empty() && d >= disks.top())
        {
            cout << "error disks" << endl;
            return;
        }

        disks.push(d);
    }

    void moveTop(Tower *dest)
    {
        int d = disks.top();
        disks.pop();
        dest->add(d);
        cout << index << " ----> " << dest->index << endl;
    }

    void moveDisks(int n, Tower *buf, Tower *dest)
    {
        if(n > 0)
        {
            moveDisks(n - 1, dest, buf);
            moveTop(dest);
            buf->moveDisks(n - 1, this, dest);
        }
    }
};

int main()
{
    MoveDisks(3, 0, 1, 2);
    //system("pause");
    cout << "---------------------" << endl;

    Tower *tower[3];
    for(int i = 0; i < 3; i++)
        tower[i] = new Tower(i);

   for(int i = 3; i >= 0; i--)
        tower[0]->add(i);
    cout << "4444" << endl;
    tower[0]->moveDisks(3, tower[1], tower[2]);
    return 0;
}