#ifndef Q_H_INCLUDED
#define Q_H_INCLUDED

#include <stdio.h>
#include <iostream>

class Queue
{
private:
    struct Node
    {
        int data;
        Node *next;
    };
    Node *front;
    Node *end;
public:
    // „{„€„~„ƒ„„„‚„…„{„„„€„‚ „„€ „…„}„€„|„‰„p„~„y„
    Queue(): front(NULL), end(NULL) {}

    // „{„€„~„ƒ„„„‚„…„{„„„€„‚ „{„€„„y„‚„€„r„p„~„y„‘
    Queue(const Queue &q)
    {
        Node *q_curr = q.front;
        front = new Node(*q_curr);
        Node *this_curr = front;
        while ((q_curr = q_curr->next))
        {
            this_curr->next = new Node (*q_curr);
            this_curr = this_curr->next;
        }
        this_curr->next = NULL;
        end = this_curr;
    }

    // „{„€„~„ƒ„„„‚„…„{„„„€„‚ „„u„‚„u„}„u„‹„u„~„y„‘
    Queue(Queue &&q): front(q.front), end(q.end)
    {
        q.front = NULL;
        q.end = NULL;
    }

    // „t„u„ƒ„„„‚„…„{„„„€„‚
    ~Queue()
    {
        while (front)
        {
            Node *temp = front;
            front = front->next;
            delete temp;
        }
    }

    // „€„„u„‚„p„ˆ„y„‘ „„‚„y„ƒ„r„p„y„r„p„~„y„‘
    Queue operator = (const Queue &q)
    {
        Node *q_curr = q.front;
        front = new Node(*q_curr);
        Node *this_curr = front;
        while ((q_curr = q_curr->next))
        {
            this_curr->next = new Node (*q_curr);
            this_curr = this_curr->next;
        }
        this_curr->next = NULL;
        end = this_curr;
        return *this;
    }

    // „€„„u„‚„p„ˆ„y„‘ „„‚„y„ƒ„r„p„y„r„p„~„y„‘ „„€ „„u„‚„u„}„u„‹„u„~„y„
    Queue operator = (Queue &&q)
    {
        std::swap(front, q.front);
        return *this;
    }

    // „„€„}„u„‹„u„~„y„u „„|„u„}„u„~„„„p
    void Push(const int e)
    {
        Node *n = new Node;
        n->data = e;
        if (IsEmpty())
        {
            front = n;
            end = n;
        }
        else
        {
            end->next = n;
            end = end->next;
        }
    }

    // „y„x„Œ„‘„„„y„u „„|„u„}„u„~„„„p
    int Pop()
    {
        try
        {
            if (IsEmpty()) throw std::runtime_error("„R„„„u„{ „„…„ƒ„„");
            Node *temp = front;
            int e = front->data;
            front = front->next;
            delete temp;
            return e;
        }
        catch (std::exception ex)
        {
            std::cerr << ex.what() << std::endl;;
            return 1;
        }
    }

    // „„‚„€„r„u„‚„{„p „~„p „„…„ƒ„„„€„„„…
    bool IsEmpty() {
        return front == NULL;
    }

    // „„€„|„…„‰„u„~„y„u „ƒ„ƒ„„|„{„y „~„p „s„€„|„€„r„~„€„z „„|„u„}„u„~„„
    Node GetFront() {
        return *front;
    }

    // „r„„r„€„t „„|„u„}„u„~„„„€„r „ƒ„„y„ƒ„{„p
    friend std::ostream& operator << (std::ostream &stream, const Queue &q)
    {
        Node *curr = q.front;
        do {
            std::cout << curr->data << " ";
        } while ((curr = curr->next));
        return stream;
    }

    // „r„r„€„t „„|„u„}„u„~„„„€„r „ƒ„„y„ƒ„{„p
    friend std::istream& operator >> (std::istream &stream, Queue &q) {
        int e;
        stream >> e;

        q.Push(e);

        return stream;
    }
};

#endif // Q_H_INCLUDED
