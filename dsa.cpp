#include <bits/stdc++.h>
using namespace std;
#define ll long long 
// admin ids:111111,222222
// password:123456
class linked_list{
    struct node{
    ll id;
    string Asset_Type;
    string Date_Issued;
    bool state;
    node *nxt;
    };
    node*head;
   public:
   linked_list(){
    head=nullptr;
   }
   //sizeof_id=5
   void add_NewOne(ll idd,string Asset,string Date){
    int size=log10(idd)+1;
while(size!=5){
    cout<<"INVALID,enter id again,must be 5 digits\n";
    cin>>idd;
    size=log10(idd)+1;
}
    node* new_node=new node;
new_node->id=idd;
new_node->Asset_Type=Asset;
new_node->Date_Issued=Date;
new_node->state=false;
if(head==nullptr){
head=new_node;
new_node->nxt=nullptr;
}else{
    node *temp=head;
    while (temp->nxt!=nullptr)
    {
        temp=temp->nxt;
    }
temp->nxt=new_node;
new_node->nxt=nullptr;
}
   }
   void change_state(ll id,string assert){
if(head==nullptr){
    cout<<"NO Users to change\n";
    return;
}
node *temp=head;
while (temp->id!=id&&temp->Asset_Type!=assert)
{
    temp=temp->nxt;
}
if(temp==nullptr){
    cout<<"this employee didnot take any thing\n";
    return;
}
temp->state=true;
   }
   void print_false(){
    if(head==nullptr){
        cout<<"NO Users to print\n";
        return;
    }
    node *temp=head;
while (temp!=nullptr)
{
    if(temp->state==0){
        cout<<temp->id<<" "<<temp->Asset_Type<<"\n";
    }
    temp=temp->nxt;
}
}
void print_true(){
    if(head==nullptr){
        cout<<"NO Users to print\n";
        return;
    }
    node *temp=head;
while (temp!=nullptr)
{
    if(temp->state==1){
        cout<<temp->id<<" "<<temp->Asset_Type<<"\n";
    }
    temp=temp->nxt;
}
   }
   void Delete(int idd,string assert){
    if(head==nullptr){
        cout<<"No element to delete\n";
        return;
    };
    if(head->id==idd&&head->Asset_Type==assert){
        node *prev=head;
        head=head->nxt;//nullptr
        delete prev;
        return;
    }
    node *prev=nullptr,*curr=head;
    while(curr->id!=idd&&curr->Asset_Type!=assert&&curr!=nullptr){
        prev=curr;
        curr=curr->nxt;
    }
    if(curr==nullptr){
          cout<<"this employee NOt found \n";
    }else{
    prev->nxt=curr->nxt;
    delete curr;
   }
}
};
int main(){
linked_list ob1;
ll id;cin>>id;string s1,s2;cin>>s1>>s2;
ob1.add_NewOne(id,s1,s2);
ob1.print_false();
    ob1.change_state(77777,"laptop");

    ob1.print_false();
}