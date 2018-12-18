/*
 Julius Garma
 Hank Stalic
 HW 2
 Queue
 */

#ifndef HW2_Queue_MyQueue_h
#define HW2_Queue_MyQueue_h

#include<iostream>

class myQueue
{
    private:
    int* list;
    int front;
    int back;
    int max;
    
    public:
    myQueue(int m);
    ~myQueue();
    int enqueue(int a);
    int dequeue();
    int first(int &a);
};

/**********************
 CLASS MEMBER FUNCTIONS
 **********************/

myQueue::myQueue(int m)
{
    max = m;
    list = new int[max];
    front = 0;
    back = 0;
}

myQueue::~myQueue()
{
    delete [] list;
}

// O(1) operation
int myQueue::enqueue(int a)
{
    if(front == ((back + 1) % max))
    {
           return -1;
    }
   else
    {
        list[back] = a;
        back = ((back + 1) % max);
        return 0;
    }
       
}

// O(1) operation
int myQueue::dequeue()
{
    if(front == back) // queue is empty
    {
        return -1;
    }
    else
    {
        front = ((front + 1) % max);
        return 0;
    }
}

int myQueue::first(int &a)
{
    if(front == back) // queue is empty
    {
        return -1;
    }
    else
    {
        return list[a];
    }
}

#endif
