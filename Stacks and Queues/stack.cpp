#include <iostream>

using namespace std;


class stack{
public:
    int *arr;
    int top;
    int size;
    
//ab behaviour set karna hai
    stack(int size){
        this->size = size;
        arr = new int(size);
        top = -1;
    }
    
    void push(int element){
        if(size-top){
            top++;
            arr[top]=element;
        }
        else{
            cout<<"stack overflow "<<endl;
        }
    }
    
    void pop(){
        if(top>=0) top--;
        else cout<<"underflow condition"<<endl;
    }
    
    int peek(){
        if(top == -1){
            cout<<"underflow condition"<<endl;
            return -1;
        }
        
        return arr[top];
    }
    
    bool isEmpty(){
        if(top == -1) return true;
        else return false;
    }
};

int main(){
    
//    s.push(2);
//    s.push(3);
//    
//    cout<<s.top()<<endl;
//    
//    s.pop();
//    if(s.empty()) cout<<"stack is empty "<<endl;
//    else cout<<"stack is not empty" <<endl;
    
    char a[8] = "aryaman";
    
    stack st(8);
    
    for(int i = 0 ; i < 8 ; i++){
        st.push(a[i]);
    }
    
    for(int i = 0 ; i < 8 ; i++){
        a[i]=st.peek();
        st.pop();
    }
    
    for(int i = 0 ; i < 8 ; i++){
        cout<<a[i];
    }
    
}
