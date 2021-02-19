//implement queue and stack with array
#include<iostream>
using namespace std;
const short maxsize=128;
typedef struct stack{
    int data[maxsize];
    int top;
    stack(){top=-1;}
    bool empty(){
        return top==-1?true:false;
    }
    void push(int x){
        data[++top]=x;
    }
    void pop(){
        top--;
    }
    int get_top(){
        return data[top];
    }
    void print(){
        while(!empty()){
            cout<<get_top()<<' ';
            pop();
        }
        cout<<endl;
    }
}stack;

typedef struct queue{
    int data[maxsize];
    int front;
    int tail;//tail永远指向一个空位置
    queue(){front=tail=0;}
    bool empty(){
        return front==tail?true:false;
    }
    void push(int x){
        data[tail++]=x;
    }
    void pop(){
        front++;//the base address of queue increases
    }
    int get_front(){
        return data[front];
    }
    void print(){
        while(!empty()){
            cout<<get_front()<<' ';
            pop();
        }
        cout<<endl;
    }
}queue;

//循环队列
typedef struct circle_queue{
    int data[maxsize];
    int front;
    int tail;
    circle_queue(){front=tail=0;}
    bool empty(){
        return front==tail?true:false;
    }
    void push(int x){
        if((tail+1)%maxsize==front){//为了区分空和满，必须浪费一个格
            cout<<"the queue is full!\n";
            return;
        }
        data[tail]=x;
        tail=(tail+1)%maxsize;
        cout<<"push "<<x<<" ok!\n";
    }
    void pop(){
        if(empty()){
            cout<<"the queue is empty!\n";
            return;
        }
        front=(front+1)%maxsize;//the base address of queue increases
        cout<<"pop ok!\n";
    }
    int get_front(){
        return data[front];
    }
    void print(){
        while(!empty()){
            cout<<get_front()<<' ';
            pop();
        }
        cout<<endl;
    }
}circle_queue;


int main(){
    stack s;
    for(int i=0;i<5;++i){
        s.push(2*i+1);
    }
    s.pop();
    s.print();
    
    queue q;
    //circle_queue q;
    q.push(0);
    q.push(1);
    q.push(2);
    q.pop();
    q.pop();
    q.push(3);
    q.push(4);
    q.print();
}
