#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node(int node)
    {
        data = node;
        next = NULL;
    }
};
class Queue {
    public:
    Node *front, *rear;
    Queue() { front = rear = NULL; }
    void enQueue(int x);
    void deQueue();
    bool isEmpty();
    void sizeOf();
    int topOf();
    int sizeCounter=0;
};
    void Queue::enQueue(int x){
        Node* tmp = new Node(x);
        if (isEmpty()) {
            front = rear = tmp;
            cout<<x<<" enqueued into the queue"<<endl;
            sizeCounter++;
            return;
        }
        rear->next = tmp;
        rear = tmp;
        cout<<x<<" enqueued into the queue"<<endl;
        sizeCounter++;
    }

    void Queue::deQueue(){
        if (isEmpty())
            return;

        Node* tmp = front;
        front = front->next;

        if (isEmpty())
            rear = NULL;

        delete (tmp);
        sizeCounter--;
    }

    bool Queue::isEmpty(){
        if(front==NULL){
            return true;
        }
        else{
            return false;
        }
    }
    void Queue::sizeOf(){
    cout<<"The size of the queue is: "<<sizeCounter<<endl;
    }

    int Queue::topOf(){
        if(!isEmpty()){
            return front->data;
        }
        else{
            exit(1);
        }
    }

int main(){

    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    cout<<q.topOf()<<" dequeued from the queue"<<endl;
    q.deQueue();
    cout<<q.topOf()<<" dequeued from the queue"<<endl;
    q.deQueue();
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);
    cout<<q.topOf()<<" dequeued from the queue"<<endl;
    q.deQueue();
    q.enQueue(6);
    q.sizeOf();

    cout<<"\nCurrent queue is: ";
   while(!q.isEmpty()){
    cout<<q.topOf()<<" ";
    q.deQueue();
   }
}


