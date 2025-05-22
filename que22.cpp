//que 22: Book Library Organizer using Binary Search Tree


#include<iostream>
using namespace std;

class Library{
    public:
    int size;
    int total;
    class Node{
        public:
        int isbn;
        string title;
        string author;
        Node *left;
        Node *right;
        public:
        Node(int isbn,string title,string author)
        {
            this->isbn=isbn;
            this->title=title;
            this->author=author;
            this->left=NULL;
            this->right=NULL;
        }
    };

    Node* root;
    public:
    Library()
    {
        this->size=0;
        this->root=NULL;
    }
    Node *insert(Node *current ,int isbn,string title,string author)
    {
        Node *newnode=new Node(isbn,title,author);
        if(current==NULL)
        {
            current=newnode;
            size++;
        }
        else
        {
            if(current->title<title)
            {
                current->right=insert(current->right,isbn,title,author);
            }
            if(current->title>title)
            {
                current->left=insert(current->left,isbn,title,author);
            }
        }
        return current;
    }
    void insert(int isbn,string title,string author)
    {
       root= insert(root,isbn,title,author);
    }
    //inorder traversal:left root right
    void display(Node *current)
    {
        if(current==NULL)
        {
            return;
        }
        display(current->left);
        cout << "ISBN: " << current->isbn << " | Title: " << current->title << " | Author: " << current->author << endl;
        display(current->right);
    }
    void display()
    {
        display(root);
    }
    //search by isbn number of a book
    void search(Node *current,int isbn)
    {
        if(current==NULL)
        {
            cout<<"book not found"<<endl;
            return;
        }
        if(current->isbn==isbn)
        {
            cout<<current->title<<" book found"<<endl;
        }
        else
        {
            if(current->isbn>isbn)
            {
                search(current->left,isbn);
            }
            else{
                search(current->right,isbn);
            }
        }
    }
    void search(int isbn)
    {
        search(root,isbn);
    }
    int getsize()
    {
        return size;
    }
};

int main()
{
    Library b;
    b.insert(1,"real analysis","rudin");
    b.insert(2,"group theory","gallian");
    b.insert(3,"linear algebra","shakiban");
    cout << "Library Books:" << endl;
    b.display();

    cout << "\nSearching for ISBN 2:" << endl;
    b.search(2);

    cout << "\nSearching for ISBN 4 (book not present):" << endl;
    b.search(4);

    cout<<"Total number of books in the Library:"<<b.getsize()<<endl;
    return 0;
}