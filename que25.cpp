//que 25:to do list

#include<iostream>
using namespace std;

class List{
    public:
    int size;
    class Node{
        public:
        string task;
        int prior;
        Node *next;
        public:
        Node(string task,int prior)
        {
            this->task=task;
            this->prior=prior;
            this->next=NULL;
        }
    };
    Node *head[2];
   
    public:
    List()
    {
        this->size=0;
        this->head[0]=NULL;
        this->head[1]=NULL;
    }
    void add(string task,int p)
    {
        Node *newnode=new Node(task,p);
        if(head[0]==NULL||p>head[0]->prior)
        {
            newnode->next=head[0];
            head[0]=newnode;
            return;
        }
        else{
       Node *current=head[0];
       while(current->next && current->next->prior>p)
       {
        current=current->next;
       }
       
       newnode->next=current->next;
       current->next=newnode;
        }
        size++;
    }

    void mark(string task,int p)
    {
        Node*completed=new Node(task,p);
        completed->next=NULL;
        if(head[1]==NULL)
        {
            head[1]=completed;
        }
        else{
            Node*current=head[1];
           
            while(current->next!=NULL)
            {
               
                current=current->next;
            }
            current->next=completed;
    
        }
    }
    void deletetask(string task)
    {
        Node*current=head[0];
        Node *prev=NULL;
        while(current->task!=task)
        {
            prev=current;
            current=current->next;
        }
        if(current==NULL)
        {
            cout<<"task not fount";
            return;
        }
       // cout<<"completed task:"<<current->task<<"( priority:"<<current->prior<<")"<<endl;
        mark(current->task,current->prior);
        if(prev==NULL)
        {
            head[0]=current->next;
        }
        else{
            prev->next=current->next;
        }
        delete current;
        size--;
    }
    void display(Node *current)
    {
        cout<<"task:";
        while(current!=NULL)
        {
            
            cout<<current->task<<"( priority:"<<current->prior<<")"<<"->";
            current=current->next;
        }
        cout<<"NULL\n";
    }
    void display()
    {
        cout<<"to do list: ";
        display(head[0]);
        cout<<endl;
        cout<<"list of completed task:";
        display(head[1]);
    }
    
};
int main()
{
    List l;
    l.add("dsa",5);
    l.add("gt",3);
    l.add("dip",4);
    l.add("prob",1);
    l.add("graph",0);
    l.add("python",2);
    l.deletetask("prob");
    l.deletetask("python");
    l.display();
    return 0;
}