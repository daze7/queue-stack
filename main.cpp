#include <iostream>
#include "s.h"
#include "q.h"

using namespace std;

int main()
{
    Stack s;
    s.Push(1);
    s.Push(2);
    s.Push(3);
    cout << s << endl;
    s.Pop();
    s.Push(4);
    s.Push(5);
    s.Pop();
    s.Push(6);
    cout << s << endl;
    Queue que;
    que.Push(1);
    que.Push(2);
    que.Push(3);
    cout << que << endl;

}
