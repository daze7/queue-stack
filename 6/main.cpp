#include <iostream>

#include "s.h"
#include "q.h"

using namespace std;

int main()
{
    Stack<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    cout << s1 << endl;         // 3->2->1
    cout << s1.getSize() << endl;
    Stack<int> s2 (s1), s3;
    s1.pop();
    s1.push(4);
    s1.push(5);
    s2.pop();
    s2.push(6);
    cout << s1 << endl;         // 5->4->2->1
    cout << s1.getSize() << endl;
    cout << s2 << endl;         // 6->2->1
    cout << s2.getSize() << endl;
    s3 = s1;
    s1.pop();
    s1.push(7);
    s1.push(8);
    s3.pop();
    s3.push(9);
    cout << s1 << endl;         // 8->7->4->2->1
    cout << s1.getSize() << endl;
    cout << s2 << endl;         // 6->2->1
    cout << s2.getSize() << endl;
    cout << s3 << endl;         // 9->4->2->1
    cout << s3.getSize() << endl;
    Queue<int> q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    cout << q1 << endl;          // 1->2->3
    cout << q1.getSize() << endl;
    Queue<int> q2 (q1), q3;
    q1.pop();
    q1.push(4);
    q1.push(5);
    q2.pop();
    q2.push(6);
    cout << q1 << endl;         // 2->3->4->5
    cout << q1.getSize() << endl;
    cout << q2 << endl;         // 2->3->6
    cout << q2.getSize() << endl;
    q3 = q1;
    q1.pop();
    q1.push(7);
    q1.push(8);
    q3.pop();
    q3.push(9);
    cout << q1 << endl;         // 3->4->5->7->8
    cout << q1.getSize() << endl;
    cout << q2 << endl;         // 2->3->6
    cout << q2.getSize() << endl;
    cout << q3 << endl;
    cout << q3.getSize() << endl;  // 3->4->5->9
    return 0;
}
