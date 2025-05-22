//que 20:Binary calender:binary search tree

#include<iostream>
using namespace std;

class Calender{
    public:
    int size;
    class Node{
        public:
        int date;
        string time;
        string data;
        Node *left;
        Node *right;
        public:
        Node(int date,string time,string data)
        {
            this->date=date;
            this->time=time;
            this->data=data;
            this->left=NULL;
            this->right=NULL;
        }
    };
    Node *root;
    public:
    Calender()
    {
        this->size=0;
        this->root=NULL;
    }

    //add appointments
    Node *add(Node *current,int date,string time,string data)
    {
        Node *newnode=new Node(date,time,data);
        if(current==NULL)
        {
            current=newnode;
            size++;
        }
        else{
            if(current->date<date)
            {
                current->right=add(current->right,date,time,data);
            }
            else{
                current->left=add(current->left,date,time,data);
            }
        }
        return current;
    }
    void add(int date,string time,string data)
    {
       root = add(root,date,time,data);
    }
    void search(Node *current,int date)
    {
        if(current==NULL)
        {
            cout<<"not found"<<endl;
            return;
        }
        if(current->date==date)
        {
            cout<<"appointment scedule at "<<current->date<< "is of "<<current->data<<"at "<<current->time<<endl;
            return;
        }
        else{
            if(current->date>date)
            {
                search(current->left,date);
            }
            else{
                search(current->right,date);
            }
        }
    }
    void search(int date)
    {
        search(root,date);
    }
    void inorder(Node *current)
    {
        if(current==NULL)
        {return;}
        inorder(current->left);
        cout<<current->data<<" at "<<current->time<<" on "<<current->date<<endl;
        inorder(current->right);
    }
    void display()
    {
        inorder(root)   ;
    }
    Node *findmin(Node *node,int date)
    {
        while(node &&node->left!=NULL)
        {
            node=node->left;
        }
        return node;
    }

    Node *deletedate(Node *current,int date)
    {
        if(current==NULL)
        {
            cout<<"date not found"<<endl;
        }
        if(date>current->date)
        {
            current->right=deletedate(current->right,date);
        }
        if(date<current->date)
        {
            current->left=deletedate(current->left,date);
        }
         else {
             // Found the node to delete
            cout << "Deleted appointment at " << current->date << endl;
            size--;
            // no left child
            if(current->left==NULL)
            {
                Node *temp=current->right;
                delete current;
                size--;
                return temp;
            }
            //No right child
            else if(current->right==NULL){
               Node *temp=current->left;
               delete current;
               size--;
               return temp; 
            }
            //two child
            else{
            Node *temp=findmin(current->right,date);
            current->date=temp->date;
            current->time = temp->time;
            current->data = temp->data;
            current->right=deletedate(current->right,temp->date);
            delete current;
            }
        }
    }
    void deletedate(int val)
        {
            root = deletedate(root, val);
        }
};
int main()
{
    Calender c;
    c.add(2,"3pm","gynac for sonography");
    c.add(5,"5pm","neuro for mri");
    c.add(1,"8pm","ortho for xray");
    c.display();
    c.search(5);
    c.deletedate(2);
    c.display();
    return 0;
}