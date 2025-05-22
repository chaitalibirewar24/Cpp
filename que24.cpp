//que24 : coin change breakdown by linkedlist
//greedy algorithm

#include<iostream>
using namespace std;

class currency{
    public:
    int size;
    int money;
    int tensize;
    int fivesize;
    int twosize;
    int onesize;
    //int coincount;
    class Node{
        public:
        int coin;
        Node *next;
        public:
        Node(int coin)
        {
            this->coin=coin;
            this->next=NULL;
        }
    };
    Node *head;
    public:
    currency(int money)
    {
        this->money=money;
        this->size=0;
        this->head=NULL;
        this->tensize=0;
        this->fivesize=0;
        this->twosize=0;
        this->onesize=0;

    }
    void insert(int coin)
    {
        Node *newnode=new Node(coin);
        newnode->next=head;
        head=newnode;
        size++;
    }
    void breakdown()
    {
        int amt=money;
        int ten=amt/10;
        for(int i=0;i<ten;i++)
        {
            insert(10);
            tensize++;
        }
        amt=amt-(ten*10);
        int five=amt/5;
        for(int i=0;i<five;i++)
        {
            insert(5);
            fivesize++;
        }
        amt=amt-(five*5);
        int two=amt/2;
        for(int i=0;i<two;i++)
        {
            insert(2);
            twosize++;
        }
        amt=amt-(two*2);
        int one=amt/1;
        for(int i=0;i<one;i++)
        {
            insert(1);
            onesize++;
        }
    }
    void display()
    {
        Node *current=head;
        cout<<"currency breakdown of rupees "<<money<<":";
        while(current!=NULL)
        {
            cout<<"coin "<<current->coin<<"->";
            current=current->next;
        }
        cout<<endl;
        cout<<"minimun count of coins:"<<endl;
        if(tensize>0)cout<<"10 *"<<tensize<<" coins"<<endl;
        if(fivesize>0)cout<<"5 *"<<fivesize<<" coins"<<endl;
        if(twosize>0) cout<<"2 *"<<twosize<<" coins"<<endl;
        if(onesize>0)cout<<"1 *"<<onesize<<" coins"<<endl;

    }
    int getsize()
    {
        return size;
    }
};

int main()
{
    currency c(103);
    c.breakdown();
    c.display();
    cout<<"minimun number of coins:"<<c.getsize()<<endl;
    return 0;
}