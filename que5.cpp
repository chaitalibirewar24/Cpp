//que 5:evaluating infix to postfix:using stack


#include<iostream>
#include<string>
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
};
class stackint { // a separate integer stack for evaluation
    public:
        int top;
        int *stack;
        int size;
    
        stackint(int size) {
            top = -1;
            this->size = size;
            stack = new int[size];
        }
    
        bool isempty() {
            return top == -1;
        }
    
        void push(int num) {
            stack[++top] = num;
        }
    
        int pop() {
            if (isempty()) {
                cout << "Stack underflow" << endl;
                return -1;
            }
            return stack[top--];
        }
    };
    //convert infix to postfix
    int precedence(char c)
    {
       
        if(c=='^') return 3;
        if((c=='*') ||(c=='/')) return 2;
        if(c=='+'||(c=='-')) return 1;
        else return 0;

    }
    //evaluate the answer
    int evaluate(const string &p,int m)
    {
        stackint s(m);
        for(int i=0;p[i]<'\0';i++)
        {
            int c=p[i];
            if(c>=0 && c<=9)
            {
                s.push(int(c));
            }
            else{ if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
                int b=s.pop();
               // push(b);
                int a=s.pop();
                //push(a);
                if(c=='*')
                {s.push(a*b);}
                if(c=='/')
                {s.push(a/b);}
                if(c=='+')
                {s.push(a+b);}
                if(c=='-')
                {s.push(a-b);}

            }
            else {
                // It's a variable (any other character)
                int val;
                cout << "Enter the value of " << c << ": ";
                cin >> val;
                s.push(val);
            }
        }
        }
        return s.top;
    }
    string convert(const string &p,int n) 
    {
        Stack s(n);
        string post;
        for(char c:p)
        {
            if((c>='a' && c<='z')||(c>='A' && c<='Z')||(c>='0' && c<='9'))
            {
                post=post+c;
            }
            else{
                if((c=='('))
                {
                    s.push(c);
                }
                else if((c==')'))
                    {
                        while(!s.isempty() && s.top!='(')
                        {
                            post=post+s.pop();
                        }s.pop();
                    }
                else if((c == '+' || c == '-' || c == '*' || c == '/' || c == '^'))
                {
                    while(!s.isempty() && precedence(s.top)>=precedence(c))
                    {
                        post=post+s.pop();
                    }
                    s.push(c);
                }
                
            }
        }
        while(!s.isempty())
        {
            post=post+s.pop();
        }
        cout<<endl;
        cout<<post<<"=";
        return post;
    }


int main()
{
    string sentence;
    cout<<"enter the expression:"<<endl;
    getline(cin,sentence);
    int n=sentence.length();
    string post=convert(sentence,n);
    int m=post.length();
    int result=evaluate(post,m);
    cout<<result;
    return 0;
}