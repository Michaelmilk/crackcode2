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
#include <list>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Animal
{
public:
    int order;
    string name;

public:
    Animal()
    {}
    Animal(string n)
    {
        name = n;
    }

    void setOrder(int o)
    {
        order = o;
    }

    int getOrder()
    {
        return order;
    }

    bool isCat()
    {
        return name == "cat";
    }

    bool isDog()
    {
        return name == "dog";
    }

    bool isOlder(Animal &a)
    {
        return order > a.order;
    }
};

class AnimalQueue
{
public:
    list<Animal> dogs;
    list<Animal> cats;
    int cur_order;

public:
    AnimalQueue() : cur_order(0)
    {}

    void enqueue(Animal a)
    {
        a.setOrder(cur_order++);
        if(a.isDog())
            dogs.push_back(a);
        else if(a.isCat())
            cats.push_back(a);
    }

    Animal dequeueDogs()
    {
        Animal a = dogs.back();
        dogs.pop_back();
        return a;
    }

    Animal dequeueCats()
    {
        Animal a = cats.back();
        cout << "ds" << endl; 
        cats.pop_back();
        cout << "ds" << endl; 
        return a;
    }

    Animal dequeueAny()
    {
        Animal a;
        if(!dogs.empty() && dogs.back().isOlder(cats.back()))
        {
            a = dequeueDogs();
        }
        else if(!cats.empty() && cats.back().isOlder(dogs.back()))
        {
            a = dequeueCats();
        }
        return a;
    }


};

int main()
{
    AnimalQueue que;
    Animal d1("dog");
    que.enqueue(d1);
    Animal d2("dog");
    que.enqueue(d2);
    Animal d3("dog");
    que.enqueue(d3);
    Animal c1("cat");
    que.enqueue(c1);
    Animal c2("cat");
    que.enqueue(c2);
    Animal c3("cat");
    que.enqueue(c3);
    Animal c4("cat");
    que.enqueue(c4);
    Animal d4("dog");
    que.enqueue(d4);

    Animal a = que.dequeueCats();
    cout << a.name << " " << a.order << endl;
    Animal a2 = que.dequeueDogs();
    cout << a2.name << " " << a2.order << endl;
    cout << que.dogs.size() << " " << que.cats.size() << endl;
    Animal a3 = que.dequeueAny();
    cout << a3.name << " " << a3.order << endl;
    return 0;
}