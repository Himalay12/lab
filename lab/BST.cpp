#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *left;
	Node *right;
	Node(int info):data(info),left(NULL),right(NULL){}
};

Node *root=NULL;
//create tree
void insert(int info){
	Node *temp=root;
	if(root==NULL) root=new Node(info);
	else{
		while(temp!=NULL){
			if(temp->data > info && temp->left!=NULL) temp=temp->left;
			else if(temp->right!=NULL)temp=temp->right;
			else break;
		}
		if(temp->data > info) temp->left=new Node(info);
		else temp->right=new Node(info);
	}
	return;
}

//Traverse Tree
//inorder traversal

void inorder(Node *temp=root){
	if(temp==NULL) return;

	inorder(temp->left);
	cout<< (temp->data) << " ";
	inorder(temp->right);

	return;
}
//inorder using stack
set<Node*> vis;
void inorder_s(){
	stack<Node*> s;
	s.push(root);

	while(!s.empty()){
		Node *temp=s.top();

		if(vis.find(temp)!=vis.end()){ s.pop();continue;}
		temp=temp->left;
		while(vis.find(temp)==vis.end() && temp){
			s.push(temp);
			temp=temp->left;
		}

		temp=s.top();
		cout << (temp->data) << " ";
		s.pop();
		if(temp->right) s.push(temp->right);

		vis.insert(temp);
	}
	return;
}
//recursive approach
void preorder(Node *temp=root){
	if(temp==NULL) return;
	
	cout<<temp->data<<" ";
	preorder(temp->left);
	preorder(temp->right);
	
	return;
}

void postorder(Node *temp=root){
	if(temp==NULL) return;

	postorder(temp->left);
	postorder(temp->right);
	cout << temp->data << " ";

	return;
}
//iterative approach
void preorder_s(){
	stack<Node*> s;
	s.push(root);

	while(!s.empty()){
		Node* temp=s.top();
		s.pop();
		cout << temp->data << " ";
		
		if(temp->right) s.push(temp->right);
		if(temp->left) s.push(temp->left);
	}
	return;
}

void postorder_s(){}

int main(){
	int a[]={7,4,10,5,24,19};
	for(auto& i:a) insert(i);
	cout<<"inorder : ";inorder_s();cout<<endl;
	cout<<"preorder : ";preorder();cout<<" ";preorder_s(); cout<<endl;
	cout<<"postorder : ";postorder();cout<<endl;
	return 0;
}
