#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

typedef struct Node {
	int val;
	Node* left;
	Node* right;
} Node;

Node* GetNode(int val);
Node* Inset(int arr[],int,int);
int IsBalanced(Node* root, bool& balanced);

class InOrder {
public:
	InOrder(Node* _root) :root(_root) { }
	void init() {
		Node* n=root;
		while(n) {
			st.push(n);
			n=n->left;
		}
	}
	Node* getNext() {
		if(st.empty())
			return NULL;
		Node* nxt =st.top();st.pop();
		updateSt();
		return nxt;
	}
	void updateSt() {
		if(st.empty())
			return;
		Node* nxt = st.top();st.pop();
		if(nxt->right) {
			Node* n = nxt->right;
			while(n) {
				st.push(n);
				n=n->left;
			}
		}
		st.push(nxt);
	}
private:
	stack<Node*> st;
	Node* root;
};

int main() {
//	int arr[] = {1,2,3,4,5,6,7,8,9,10,34};
//	int len=sizeof(arr)/sizeof(int);
//	Node* root = Inset(arr,0,len-1);
	Node* root = GetNode(1);
	root->left = GetNode(2);
	root->right = GetNode(3);
	root->right->right = GetNode(3);
	root->left->left = GetNode(4);
	root->left->left->left = GetNode(5);
	root->left->left->left->left = GetNode(5);
	root->left->right = GetNode(5);
	root->right->left = GetNode(5);
	InOrder in(root);
	in.init();
	Node* n = in.getNext();
	while(n) {
		cout<<n->val<<"->";
		n=in.getNext();
	}
	cout<<endl;
//	bool bal = true;
//	IsBalanced(root, bal);
//	cout<<"Tree is Balanced->"<<bal<<endl;
	return 0;
}

int IsBalanced(Node* root, bool& balanced) {
	if(!root) return 0;
	int left = IsBalanced(root->left, balanced);
	int right = IsBalanced(root->right, balanced);
	cout<<"balance of "<<root->val<<" is "<<left<<","<<right<<endl;
	if(abs(left-right) > 1 ) {
		cout<<"unbalanced\n";
		balanced = false;
	}
	return left+right+1;
}

Node* Inset(int arr[],int s, int e) {
	Node* n = NULL;
	if(s<=e) {
		int m = (s+e)/2;
		n = GetNode(arr[m]);
		n->left = Inset(arr,s,m-1);
		n->right = Inset(arr,m+1,e);
	}
	return n;
}

Node* GetNode(int val) {
	Node* n = new Node;
	n->left = NULL;
	n->right = NULL;
	n->val = val;
	return n;
}
