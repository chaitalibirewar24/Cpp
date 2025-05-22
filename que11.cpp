//que 11:print queue management:queue using linkedlist(FIFO)

#include<iostream>
using namespace std;

class Queue{
    public:
    int size;
    class job{
        public:
        int jobid;
        int pages;
        job*next;
        public:
        job(int jobid,int pages)
        {
            this->jobid=jobid;
            this->pages=pages;
            this->next=NULL;
        }
    };
   job *head;
   Queue()
   {
         this->size=0;
        this->head=NULL;
   }
    void enqueue(int jobid,int pages)
    {
        job *newnode=new job(jobid,pages);
        if(head==NULL)
        {
            head=newnode;
            head->next=NULL;
            size++;
            return;
        }
        else{
            job *current=head;
                while(current->next!=NULL)
                {
                    current=current->next;
                }
                current->next=newnode;
                newnode->next=NULL;
                size++;
        }
    }

    void dequeue()
    {
        if(head==NULL)
        {
            cout<<"all jobs are done"<<endl;
            return;
        }
        else{
            job *current=head;
            head=head->next;
            cout<<"jobid: "<<current->jobid<<" is completed"<<endl;
            delete current;
            size--;
        }
    }
    void display()
    {
        if(head==NULL)
        {
            cout<<"0 jobs are remaing"<<endl;
            return;
        }
        if(size!=0)
        {
        cout<<"current status:"<<size <<" jobs are remaining "<<endl;
        }
        job *temp=head;
        while(temp!=NULL)
        {
            cout<<"job id:"<<temp->jobid<<" with no of pages: "<<temp->pages<<endl;
            temp=temp->next;
        }
    }

};
int main() {
    Queue pq;

    pq.enqueue(101, 5);
    pq.enqueue(102, 10);
    pq.enqueue(103, 3);

    cout << endl;
    pq.display();
    cout << "\nProcessing Jobs...\n";
    pq.dequeue();
    pq.display();

    pq.dequeue();
    pq.display();

    pq.dequeue();
    pq.display();

    //recheck if any job is remaining
    pq.dequeue(); 
    return 0;
}