//que 6:parenthesis checker using stack

#include<iostream>
#include<string>
#include<sstream>
using namespace std;

class Stack{
    public:
    int top;
    char *stack;
    int size;
    public:
    Stack(int size)
    {
        top=-1;
        this->size=size;
        stack=new char[size];
    }
    bool isempty()
    {
        return top==-1;
    }
    bool isfull()
    {
        return top==size-1;
    }
    void push(char c)
    {
        if(isfull())
        {
            cout<<"already full"<<endl;
            return;
        }
        else{
            stack[++top]=c;
        }
    }
    char pop()
    {
        if(isempty())
        {
            cout<<"already empty"<<endl;
            return '\0';
        }
        else{
            return stack[top--];
        }
    }
    void display()
    {
        if(top>0)
        {
            for(int i=top;i>=0;i--)
            {
                cout<<stack[i]<<" ";
            }
        }
        else{
            cout<<"stack empty";
        }
        cout<<endl;
    } 
    bool check(const string &p)
    {
        for(char c:p)
        {
            if((c=='{') || (c=='[') ||(c=='('))
            {
                push(c);
            }
            else{
                if((c=='}') || (c==']') ||(c==')'))
                {
                    if(isempty())
                    {return false;}
                    char topchar=pop();
                    if((c=='}'&& topchar!='{')||(c==']' && topchar!='[')||(c==')' && topchar!='('))
                    {return false;}
                }
            }
        }
        return isempty();
    }
};

int main()
{
    string sentence;
    cout<<"enter the expression:"<<endl;
    getline(cin,sentence);
    int n=sentence.length();
    Stack s(n);
    if(s.check(sentence))
    {
        cout<<"parenthesis is balanced"<<endl;
    }
    else{
        cout<<"parenthesis is unbalanced"<<endl;
    }
    return 0;
}