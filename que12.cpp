// que 12: car wash simulation

#include<iostream>
using namespace std;

class queue{
    public:
    int size;
    int washed;
    int rear;
    int front;
    string *car;
    public:
    queue(int size)
    {
        this->size=size;
        this->rear=-1;
        this->front=-1;
        this->washed=0;  
        car=new string[size];
    }
    bool isempty()
    {
        return rear!=size-1;
    }
    bool isfull()
    {
        return rear==size-1 || front>rear;
    }
    void enqueue(string licence)
    {
        if(isfull())
        {
            cout<<"today day is busy..no more cars"<<endl;
            return;
        }
        else{
            if(front==-1)
            {
                front=0;
            }
            car[++rear]= licence;
            cout<<"car no:"<<licence<<" is added in the queue"<<endl;
        }
    }
    void dequeue()
    {
        if(isempty())
        {
            cout<<"all car are washed"<<endl;
        }
        else{
            cout<<"car no:"<<car[front]<<" is washed"<<endl;
            front++;
            washed++;
        }
    }
    void display()
    {
        cout<<"total car washed:"<<washed<<endl;
        cout<<"current queue of cars:";
        if(isempty())
        {
            cout<<"all car are washed"<<endl;
        }
        else {
                for (int i = front; i <= rear; i++) {
                    cout << car[i] << " ";
                }
                cout << endl;
            }
    }
    ~queue() {
        delete[] car;
    }

};

int main()
{
    queue q(5);
    q.enqueue("mh34we2234");
    q.enqueue("mh07we0934");
    q.enqueue("mh12ae2004");
    q.enqueue("mh32wb43434");
    q.enqueue("mh00we6534");
    q.display();
    cout << "\n--- Washing Cars ---\n";
    q.dequeue();
    q.dequeue();
    q.display();
    return 0;
}