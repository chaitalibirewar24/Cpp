//que 8:Multiplayer game map(graph navigation)

#include<iostream>
using namespace std;
const int max_size=100;
class Queue{
    public:
    int rear;
    int front;
    int q[max_size];
    Queue()
    {
        this->rear=-1;
        this->front=-1;
    }
    bool isfull()
    {
      return rear==max_size-1;
    }
    bool isempty()
    {
        return front>rear || front==-1;
    }
    void enqueue(int value)
    {
        if(isfull())
        {
            cout<<"full"<<endl;
            return;
        }
        else{
            if(front==-1)
            {
                front=0;
            }
            q[++rear]=value;
        }
    }
    int dequeue()
    {
        if(isempty())
        {
            cout<<"already empty"<<endl;
            return -1;
        }
        else{
           return q[front++];
        }
    }
};

class Game{
    public:
    int level;
    int v;
    class Node{
        public:
        int zone;
        int w;
        Node *next;
        Node(int zone,int w)
        {
            this->zone=zone;
            this->w=w;
            this->next=NULL;
        }
    };
    Node*list[max_size];
    public:
    Game(int v)
    {
        this->v=v;
        this->level=0;
        for(int i=0;i<v;i++)
        {
        this->list[i]=NULL;
        }
    }
    //addegde
    void add(int s,int zone,int w)
    {
        Node *newnode=new Node(zone,w);
        newnode->next=list[s];
        list[s]=newnode;
    }

    void print()
    {
        cout << "\nGame Map:\n";
        for(int i=0;i<v;i++)
        {
            cout<<"level "<<i<<":";
            Node *temp=list[i];
            while(temp)
            {
                cout << "(Zone " << temp->zone << ", Weight " << temp->w << ") -> ";
                temp=temp->next;
            }
            cout << "NULL" << endl;
        }
        
    }
    void BFS(int s)
    {
        Queue q;
        bool visited[v]={false};
        q.enqueue(s);
        cout << "\nBFS Traversal (Player Movement): ";
        while(!q.isempty())
        {
            int current=q.dequeue();
            if(!visited[current])
            {
                cout<<current<<" ";
                visited[current]=true;
                //adding neighbours
                Node *temp=list[current];
                while(temp!=NULL)
                {
                        q.enqueue(temp->zone);
                        temp=temp->next;
                }

            }
        }
        cout<<endl;
    }
  //  through bfs
    bool connectivity(int s)
    {
        Queue q;
        int connect=0;
        bool visited[v]={false};
        q.enqueue(s);
        while(!q.isempty())
        {
            int current=q.dequeue();
            if(!visited[current])
            {
                visited[current]=true;
                connect++;
                Node *temp=list[current];
                while(temp!=NULL)
                {
                    q.enqueue(temp->zone);
                    temp=temp->next;
                }
            }
        }
        return (connect==v);
        
    }
};
int main()
{
    Game g(5);

    g.add(0, 1, 1);
    g.add(1, 2, 0); // teleport
    g.add(1, 3, 2);
    g.add(2, 4, 1);
    g.add(3, 4, 0); // teleport
    g.print();
    g.BFS(0);
    if(g.connectivity(0))
    {
        cout<<"all zone are reachable from starting zone!"<<endl;
    }
    else{
        cout<<"all zone are not reachable from starting zone!"<<endl;
    }
 return 0;
}