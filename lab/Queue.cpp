#include<iostream>
using namespace std;

struct Node{
        int val;
        Node* next;
        Node():next(NULL){}
        Node(int data):val(data),next(NULL){}
};

class Queue{
        Node *head,*tail;
public:
        Queue():head(NULL),tail(NULL){}
        void push(int data){
                Node *temp=new Node(data);
		if(head==NULL || tail==NULL) head=tail=temp;
		else {
			tail->next=temp;
			tail=temp;
		}
                return;
        }
        int pop(){
                Node* temp=head;
                if(temp!=NULL)
                        head=temp->next;
                else{
                        cout<<"Queue is empty"<<endl;
                        return -1;
                }

                int data=temp->val;
                delete temp;
                return data;
        }
        int top(){
                if(head!=NULL)
                        return head->val;
                cout<<"Queue is empty"<<endl;
                return -1;
        }
};
int main(){
        Queue Q;
        cout<<"1.Push\n2.Pop\n3.top\n4.exit"<<endl;
        int opt;
        while(1){
                cout<<"Enter the opt: ";cin>>opt;
                if(opt==1){
                        int data;cin>>data;
                        Q.push(data);
                }
                else if(opt==2){
                        cout<<Q.pop()<<endl;
                }
                else if(opt==3){
                        cout<<Q.top()<<endl;
                }
                else break;
        }
        return 0;
}
