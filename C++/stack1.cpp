#include <iostream>
#include <string>
#include <stack>
using namespace std;
template <typename T>
class Stack {
    public:
        stack<T> a;
        void push(){
            cout<<"Enter element to be pushed:";
            T b;
            cin>>b;
            a.push(b);
        }
        void pop(){
            if(a.empty())
                cout<<"Stack Underflow"<<endl;
            else{
                a.pop();
                cout<<"Element popped";
            }
        }
        void top(){
            if(a.empty())
                cout<<"Stack Underflow"<<endl;
            else
                cout<<a.top();
        }
};
int main(){
    Stack<string> st;
    st.push();
    st.top();
    st.push();
    st.push();
    st.top();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    return 0;
}