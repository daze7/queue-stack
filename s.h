#ifndef S_H_INCLUDED
#define S_H_INCLUDED

#include <stdio.h>
#include <iostream>

class Stack
{
private:
    struct Node
    {
        int data;
        Node *next;
    };
    Node *front;
public:
    // „{„€„~„ƒ„„„‚„…„{„„„€„‚ „„€ „…„}„€„|„‰„p„~„y„
    Stack() {front = NULL;}
    // „{„€„~„ƒ„„„‚„…„{„„„€„‚ „{„€„„y„‚„€„r„p„~„y„‘
    Stack(const Stack &s)
    {
        Node *s_curr = s.front;
        front = new Node(*s_curr);
        Node *this_curr = front;
        while ((s_curr = s_curr->next))
        {
            this_curr->next = new Node(*s_curr);
            this_curr = this_curr->next;
        }
        this_curr->next = NULL;
    }
    // „{„€„~„ƒ„„„‚„…„{„„„€„‚ „„u„‚„u„}„u„‹„u„~„y„‘
    Stack(Stack &&s): front(s.front) {s.front = NULL;}
    // „t„u„ƒ„„„‚„…„{„„„€„‚
    ~Stack()
    {
        while(front)
        {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
    // „€„„u„‚„p„ˆ„y„‘ „„‚„y„ƒ„r„p„y„r„p„~„y„‘
    Stack operator = (const Stack &s)
    {
        Node *s_curr = s.front;
        front = new Node(*s_curr);
        Node *this_curr = front;
        while ((s_curr = s_curr->next))
        {
            this_curr->next = new Node (*s_curr);
            this_curr = this_curr->next;
        }
        this_curr->next = NULL;
        return *this;
    }

    // „€„„u„‚„p„ˆ„y„‘ „„‚„y„ƒ„r„p„y„r„p„~„y„‘ „„€ „„u„‚„u„}„u„‹„u„~„y„
    Stack operator = (Stack &&s)
    {
        std::swap(front, s.front);
        return *this;
    }
    // „„€„}„u„‹„u„~„y„u „„|„u„}„u„~„„„p
    void Push(const int e)
    {
        Node *new_front = new Node;
        new_front->data = e;
        new_front->next = front;
        front = new_front;
    }
    // „y„x„Œ„‘„„„y„u „„|„u„}„u„~„„„p
    int Pop()
    {
        try
        {
            if (IsEmpty()) throw std::runtime_error("Stack is empty");
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
    bool IsEmpty() const
    {
        return front == NULL;
    }
    // „„€„|„…„‰„u„~„y„u „ƒ„ƒ„„|„{„y „~„p „s„€„|„€„r„~„€„z „„|„u„}„u„~„„
    Node GetFront()
    {
        return *front;
    }
    // „r„„r„€„t „„|„u„}„u„~„„„€„r „ƒ„„y„ƒ„{„p
    friend std::ostream& operator << (std::ostream &stream, const Stack &s)
    {
        Node *curr = s.front;
        do
        {
            std::cout << curr->data << " ";
        } while ((curr = curr->next));
        return stream;
    }
    // „r„r„€„t „„|„u„}„u„~„„„€„r „ƒ„„y„ƒ„{„p
    friend std::istream& operator >> (std::istream &stream, Stack &s)
    {
        int e;
        stream >> e;
        s.Push(e);
        return stream;
    }
};

#endif // S_H_INCLUDED
