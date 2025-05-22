//que 23: invoice billing system:linkedlist


#include<iostream>
using namespace std;

class invoice{
    public:
    int size;
    float grandtotal;
    class Node{
        public:
        string product;
        float price;
        float quant;
        Node *next;
        public:
        Node(string product,float price,float quant)
        {
            this->product=product;
            this->price=price;
            this->quant=quant;
            this->next=NULL;
        }
        };
        Node *head;
        public:
        invoice()
        {
            this->size=0;
            this->grandtotal=0;
            this->head=NULL;
        }
        void addItem(string product,float price,float quant)
        {
            Node *newnode=new Node(product,price,quant);
            if(head==NULL)
            {
                head=newnode;
                head->next=NULL;
                
            }
            else
            {
                Node *current=head;
                while(current->next!=NULL)
                {
                    current=current->next;
                }
                current->next=newnode;
                newnode->next=NULL;
            }
            size++;
        }
        void display()
        {
            Node *current=head;
            cout << "\n======= INVOICE BILLING SYSTEM =======" << endl;
            cout << "Product\t\tPrice\tQty\tTotal" << endl;
            cout<<"-----------------------------------------"<<endl;
           // cout << "----------------------------------------" << endl;
            while(current!=NULL)
            {
                cout<<current->product<<"\t\t "<<current->price<<"\t "<<current->quant<<endl;
                current=current->next;
            }
        }
        void remove(string product)
        {
                Node *current=head;
                Node *prev=NULL;
                while(current!=NULL && current->product!=product)
                {
                    prev=current;
                    current=current->next;
                }
                if(current==NULL)
            {
                cout<<"product not found"<<endl;
            }
                if(prev==NULL)
                {
                    head=current->next;
                }
                else{
                    prev->next=current->next;
                }
                delete current;
                size--;
        }
        void update(string product,float newprice,float newquant)
        {
            Node *current=head;
            while(current!=NULL && current->product!=product)
            {
                current=current->next;
            }
            if(current == NULL) 
            {
                cout << "Product \"" << product << "\" not found!" << endl;
                return;
            }
            current->price=newprice;
            current->quant=newquant;
            cout<<"updated quantity:"<<current->product<<","<<current->price<<","<<current->quant<<endl;
        }
        float total()
        {
            grandtotal=0;
            Node *current=head;
            while(current!=NULL)
            {
                grandtotal=grandtotal+(current->quant*current->price);
                current=current->next;
            }
            return grandtotal;
        }
};
int main()
{
    invoice inv;
    inv.addItem("Pen", 10, 5.5);
    inv.addItem("Notebook", 2, 45);
    inv.addItem("Eraser", 5, 3);
    inv.display();
    inv.remove("Notebook");
    cout<<"after removal:"<<endl;
    inv.display();
    inv.addItem("Notebook",10,35);
    inv.update("Notebook",10,35);
    cout<<"new invoice:"<<endl;
    inv.display();
    cout<<"total bill of a customer:"<<inv.total()<<endl;
    return 0;
}