//que 21 :n-array tree:directory

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Tree{
    public:
    int size;
    class Node{
        public:
        string file;
        vector<Node*>child;
        public:
        Node(string file)
        {
            this->file=file;
        }
    };
        Node *root;
        public:
        Tree()
        {
            this->size=0;
            this->root=NULL;
        }
        
        //create root node
        
        void addroot(string file)
        {
            if(root==NULL)
            {
                root=new Node(file);
                size++;
            }
            else{
                cout<<"root already exit"<<endl;
            }
        }
        //finding a particular node using dfs
        Node*findnode(Node *current,string parent)
        {
            if(current==NULL)
            {return NULL;}
            if(current->file==parent)
            {return current;}
            for(int i=0;i<current->child.size();i++)
            {
                Node *result=findnode(current->child[i],parent);
                if(result!=NULL)
                {return result;}
            }
            return NULL;
        }
        //add child nodes
        void addfile(string parent,string file)
        {
            Node *parentnode=findnode(root,parent);
            if(parentnode)
            {
                parentnode->child.push_back(new Node(file));
            }
            else{
                cout<<"parent folder"<<parent<<" does not exit"<<endl;
            }
        }


        // dfs :recursion:depth approach
        void display(Node *current,int depth=0)
        {
            if(current==NULL)
            {
                return;
            }
            for (int i=0;i<depth;i++)
            {
                cout<<"  ";
            }
            cout<<current->file<<endl;
            for(int i=0;i<current->child.size();i++)
            {
                display(current->child[i],depth+1);
                
            }
        }
        void display() {
            display(root);
        }
        Node * deletenode(Node *root ,string file,string promote)
        {
            Node *searchnode=findnode(root,file);
            if (searchnode == NULL) {
                cout << "File not found!" << endl;
                return root;
            }
           
            //if only one leaf
            if(searchnode->child.empty()){
                cout << "Deleted leaf node: " << file << endl;
                delete searchnode;
                return NULL;
            }
            //if one child
            else if(searchnode->child.size()==1)
            {
                Node*child=searchnode->child[0];
                searchnode->file=child->file;
                searchnode->child=child->child;
                delete child;
                cout << "Promoted child node: " << file << endl;
                 return root;

            }
                else if (searchnode->child.size() > 1 && !promote.empty()) {
                    Node* promoteChild = NULL;
                    int promoteIndex = -1;
            
                    for (int i = 0; i < searchnode->child.size(); i++) {
                        if (searchnode->child[i]->file == promote) {
                            promoteChild = searchnode->child[i];
                            promoteIndex = i;
                            break;
                        }
                    }

                    if (promoteChild != NULL) {
                        searchnode->file = promoteChild->file;
                        searchnode->child.erase(searchnode->child.begin() + promoteIndex);
            
                        // Add promote child's children to current node
                        for (Node* child : promoteChild->child) {
                            searchnode->child.push_back(child);
                        }
            
                        delete promoteChild;
                        cout << "Promoted specific child: " << promote << endl;
                    }
                    else {
                        cout << "Promotion child not found: " << promote << endl;
                    }
               return root;
                }
                // If multiple children and no specific promotion: promote all
                else if (searchnode->child.size() > 1 && promote.empty()) {
                    cout << "Promoted all children of: " << file << endl;
                }
                return root;
            
            }
            void deletenode(string parent,string child)
            {
                root=deletenode(root,parent,child);
            }
        };


int main()
{
    Tree t;
    t.addroot("root");
    t.addfile("root","chaitali");
    t.addfile("root","kashish");
    t.addfile("kashish","dsa");
    t.addfile("kashish","python");
    t.addfile("kashish","prob");
    t.display();
    t.deletenode("kashish","dsa");
    t.display();
    return 0;
}
