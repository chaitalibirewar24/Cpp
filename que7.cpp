//que 7:Reversing a sentence using stack

#include<iostream>
#include<string>
#include<sstream>
using namespace std;

class Stack{
    public:
    int top;
    string *stack;
    int size;
    Stack(int size)
    {
        this->top=-1;
        this->size=size;
        stack=new string[size];
    }
    bool isempty()
    {
        return top==-1;
    }
    bool isfull()
    {
        return top==size-1;
    }
    void push(string work)
    {
        if(isfull())
        {cout<<"stack is full"<<endl;
        return;}
        else{
        stack[++top]=work;
        }
    }
    string pop()
    {
        if(isempty())
        {cout<<"stack is empty"<<endl;}
        else{
           return stack[top--];   
        }
    }
    void display()
    {
        
        if(top>0)
        {
            
            cout<<"original sentence(revese stack printing): ";
            for(int i=0;i<=top;i++)
            {
                cout<<stack[i]<<" ";
            }
            cout<<endl;
            cout<<"reverse sentence: ";
           while(!isempty())
           {
            cout<<pop()<<" ";
           }cout<<endl;
        }
        else{
            cout<<"empty";
        }
     cout<<endl;
    }
};

int main()
{
    string sentence;
    int n;
    cout<<"enter numbewr of words in your sentence"<<endl;
    cin>>n;
    cin.ignore();//to ignore newline charachter
    Stack s(n);
    cout<<"enter a sentence:";
    getline(cin,sentence);
    string word;
    stringstream ss(sentence);//break the sentence in words
    while(ss>>word)
    {
        s.push(word);
    }
    s.display();
    return 0;
}
