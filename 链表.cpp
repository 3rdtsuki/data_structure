#include<iostream>
using namespace std;
typedef struct lnode{
    int data;
    struct lnode *next;
    void print_list(link_list l){
        l=l->next;
        cout<<"list elements:\n";
        while(l){
            cout<<l->data<<' ';
            l=l->next;
        }
        cout<<endl;
    }

    //insert elements in the begin
    link_list head_insert(link_list &l){
        lnode *s;
        int x;
        cout<<"please input elements:\n";
        cin>>x;
        while(x){
            s=new lnode;
            s->data=x;
            s->next=l->next;
            l->next=s;
            cin>>x;
        }
        return l;
    }

    //insert elements in the end (notice that this function cannot be called when elements have existed)
    link_list tail_insert(link_list &l){
        lnode *tail=l;
        lnode *s;
        int x;
        cout<<"please input elements:\n";
        cin>>x;
        while(x){
            s=new lnode;
            s->data=x;
            tail=tail->next=s;
            cin>>x;
        }
        tail->next=NULL;
        return l;
    }

    //add element x after position i
    void add_lnode(link_list &l,int i,int x){
        lnode *s=new lnode,*p=l;
        s->data=x;
        while(i--){
            p=p->next;
        }
        s->next=p->next;
        p->next=s;
    }
}node,*link_list;


int main(){
    lnode *head=new lnode;
    //head_insert(head);
    head->tail_insert(head);
    head->add_lnode(head,3,8);
    head->print_list(head);
}