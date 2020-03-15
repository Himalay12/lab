#include<iostream>
using namespace std;

int n=0,i=0;

struct Node{
	int val;
	Node* next;
	Node():next(NULL){}
	Node(int data,Node *temp):val(data),next(temp){}
};

class Stack{
	Node *head;
public:
	Stack():head(NULL){}
	void push(int data){
		Node *temp=new Node(data,head);
		head=temp;
		return;
	}
	int pop(){
		Node* temp=head;
		if(temp!=NULL)
			head=temp->next;
	       	else{
			return -1;
		}	
		int data=temp->val;
		delete temp;
		return data;
	}
	int top(){
		if(head!=NULL)
			return head->val;
		return -1;
	}

	bool check_palindrome(){
		int temp=pop();

		if(temp==-1) return true;
		n++;
		//call function
		if(check_palindrome()){
			i+=1;
			if(i<=n/2) {
				push(temp);
		}
		else if(n%2==0){
			if(pop()==temp) return true;
			else false;
		}
		else if(i > (n+1)/2){
			if(pop()==temp) return true;
			return false;
		}
		return true;

		}
		return false;
	}

};
//Note: To make global palindrome function define copy constructor for all element of stack as default copy data of head pointer. 
int main(){
	Stack S;
	cout<<"1.Push\n2.Pop\n3.top\n4.palindrome\n5.exit"<<endl;
	int opt;
	while(1){
		cout<<"Enter the opt: ";cin>>opt;
		if(opt==1){
			int data;cin>>data;
			S.push(data);
		}
		else if(opt==2){
			if(S.top()!=-1)
				cout<<S.pop()<<endl;
			else cout<<"Stack is empty";
		}
		else if(opt==3){
			if(S.top()==-1)
				cout<<S.top()<<endl;
			else cout<<"Stack is empty";
		}
		else if(opt==4){
			n=0;i=0;
			cout<<S.check_palindrome();
		}
		else break;
	}
	return 0;
}
