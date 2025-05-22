//que 17:adding polynomial using linked list

#include<iostream>
#include<string>
using namespace std;

class Poly{
    public:
    int size;
    class Node{
        public:
        int val;
        int expo;
        Node *next;
        Node *prev;
        public:
        Node(int val,int expo)
        {
            this->val=val;
            this->expo=expo;
            this->prev=NULL;
            this->next=NULL;
        }
    };
    Node *head[3];
    public:
    Poly()
    {
        this->size=0;
        this->head[0]=NULL;
        this->head[1]=NULL;
        this->head[2]=NULL;
    }
    //create polynomial:
    Node* add(Node *current,int val,int expo)
    {
        Node *newnode=new Node(val,expo);
            if(current==NULL)
            {
                current=newnode;
                current->next=NULL;
                current->prev=NULL;
                size++;
                
            }
            else
            {
                Node *temp=current;
                while(temp->next!=NULL)
                {
                    temp=temp->next;
                }
                temp->next=newnode;
                newnode->prev=temp;
                newnode->next=NULL;
                size++;
            }     
            return current;  
    }
    void add(int choice,int val,int expo) {
        if(choice==1)
        {
           head[0]= add(head[0],val,expo);
        }
        if(choice==2)
        {
            head[1]=add(head[1],val,expo);
        }    
        if(choice==3)
        {
            head[2]=add(head[2],val,expo);
        }    
    }
    void display(Node *current)
    {
        while(current!=NULL)
        {
            cout << current->val;
            if(current->expo != 0)
            cout << "x^" << current->expo;
            if(current->next != NULL)
            cout << " + ";
        current = current->next;
        }
        cout<<endl;
    }
    void display()
    {
        cout<<"1st polynomial: ";
        display(head[0]);
        cout<<endl;
        cout<<"2st polynomial: ";
        display(head[1]);
        cout<<endl;

    }

    void polysum()
    {
        Node *current[2];
        int newval;
        current[0]=head[0];
        current[1]=head[1];

            while(current[0]!=NULL &&current[1]!=NULL)
            {
                if(current[0]->expo==current[1]->expo)
                {
                    newval=current[0]->val+current[1]->val;
                    head[2]=add(head[2],newval,current[0]->expo);
                    current[0]=current[0]->next;  
                    current[1]=current[1]->next;
                }
                else{
                    if(current[0]->expo>current[1]->expo)
                    {
                    head[2]=add(head[2],current[0]->val,current[0]->expo); 
                    current[0]=current[0]->next;
                }
                    else
                    {
                    head[2]=add(head[2],current[1]->val,current[1]->expo); 
                    current[1]=current[1]->next;
                    }
                }
                 
            }
            while(current[0]!=NULL)
            {
                head[2]=add(head[2],current[0]->val,current[0]->expo);
                current[0]=current[0]->next;
            }  
            while(current[1]!=NULL)
            {
                head[2]=add(head[2],current[1]->val,current[1]->expo);
                current[1]=current[1]->next;
            }   
        cout<<"sum of both poly:";
        display(head[2]);
        cout<<endl;

    }
};
int main()
{
    Poly p;
    p.add(1,2,4);
    p.add(1,4,3);
    p.add(1,6,2);
    p.add(1,1,1);
    p.add(1,2,0);
    p.add(2,2,4);
    p.add(2,4,2);
    p.display();
    p.polysum();
    return 0;
}