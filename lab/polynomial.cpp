#include<iostream>
using namespace std;

class Node{
public:
	int cf,deg;
	Node *next;
	Node():cf(0),deg(0),next(NULL){}
};

Node* input(){
int n;
cout<<"Enter the number of term: ";cin>>n;
Node *head=NULL,*s=NULL;
for(int i=0;i<n;i++){
	Node *temp=new Node;
	cin >> (temp->cf) >> (temp->deg);
	if(head==NULL){
		head=temp;
		s=temp;
	}
	else{
		s->next=temp;
		s=s->next;
	}
}
return head;
}
Node* poly_add(Node *a,Node *b){
Node *head=NULL,*temp,*var;
while(a!=NULL ||  b!=NULL){
	temp=new Node;
	if((a!=NULL &&  b!=NULL) && a->deg==b->deg){
		temp->cf=a->cf+b->cf;
		temp->deg=a->deg;
		a=a->next;
		b=b->next;
	}
	else if(a==NULL && b!=NULL || b->deg > a->deg){
		temp->cf=b->cf;
		temp->deg=b->deg;
		b=b->next;
	}
	else if(b==NULL && a!=NULL || a->deg > b->deg){
		temp->cf=a->cf;
		temp->deg=a->deg;
		a=a->next;
	}
	//insert at last.
	if(head==NULL){
		head=temp;
		var=temp;
	}
	else{
		var->next=temp;
		var=var->next;
	}
}
return head;
}

int main(){
Node *a=NULL,*b=NULL,*c=NULL;
a=input();
b=input();
c=poly_add(a,b);
while(c!=NULL){
	cout<< (c->cf) << " " << (c->deg) << endl;
	c=c->next;
}
return 0;
}
