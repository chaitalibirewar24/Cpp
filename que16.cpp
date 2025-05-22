//que 16: circular linked list for round robin

#include<iostream>
#include<string>
using namespace std;

class RR{
    public:
    int tprocess;
    int qt;
    class Process{
        public:
        int pno;
        int at;
        int bt;
        int rem_bt;
        int ct;
        int tat;
        int wt;
        Process *next;
        public:
        Process( int pno,int at,int bt)
        {
            this->pno=pno;
            this->at=at;
            this->bt=bt;
            this->rem_bt=bt;
            this->ct=0;
            this->tat=0;
            this->wt=0;
            this->next=NULL;
        }
    };
    Process *head;
    public:
    RR(int qt)
    {
        this->qt=qt;
        this->tprocess=0;
        this->head=NULL;
    }
    void add(int pno,int at,int bt)
    {
        Process *newnode=new Process(pno,at,bt);
    
        if(head==NULL)
        {
            head=newnode;
            head->next=head;
            tprocess++;
            
        }
        else
        {
            Process *temp=head;
            while(temp->next!=head)
            {
                temp=temp->next;
            }
            temp->next=newnode;
            newnode->next=head;
            tprocess++;

        }
    }
    void displayProcesses() {
        if(head == NULL) {
            cout << "No processes to display.\n";
            return;
        }
        Process* temp = head;
        
        do {
            cout << "Process ID: " << temp->pno << ", Arrival Time: " << temp->at << ", Burst Time: " << temp->bt << endl;
            temp = temp->next;
        } while(temp != head);
    }

    void roundrobin()
    {
        Process *current=head;
        int time=0;
        int completed=0;
        while(completed<tprocess)
        {
            bool didprocess=false;
            if(current->rem_bt>0)
            {
                didprocess=true;
                if(current->rem_bt>qt)
                {
                    cout<<"Process id"<<current->pno<<" executed for "<<qt<<" units "<<endl;
                    time+=qt;
                    current->rem_bt-=qt;
                }
                else
                {
                    cout<<"Process id"<<current->pno<<" executed for "<<qt<<" units (completed) "<<endl; 
                    time+=current->rem_bt;
                    current->rem_bt-=0;
                    current->ct=time;
                    completed++;
                }
            }
            current=current->next;
            if(!didprocess && current==head)
            {
                time++;
            }
        }

        cout<<"\tProcess details\n";
        cout<<"pno\tat\tbt\tct\ttat\twt\n";
        Process *temp = head;
        do{
            temp->tat=temp->ct-temp->at;
            temp->wt=temp->tat-temp->bt;
            cout << temp->pno << "\t" << temp->at << "\t" << temp->bt << "\t" << temp->ct << "\t" << temp->tat << "\t" << temp->wt << endl;
            temp=temp->next;
        }while(temp!=head);
    }   
};


int main()
{
    int timeQuantum;
    cout << "Enter Time Quantum: ";
    cin >> timeQuantum;
    
    RR scheduler(timeQuantum);
    
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    
    for(int i = 1; i <= n; i++) {
        int at, bt;
        cout << "Enter Arrival Time for Process " << i << ": ";
        cin >> at;
        cout << "Enter Burst Time for Process " << i << ": ";
        cin >> bt;
        scheduler.add(i, at, bt);
    }

    cout << "\nInitial Processes:\n";
    scheduler.displayProcesses();

    scheduler.roundrobin();

    return 0;
}