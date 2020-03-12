#include <bits/stdc++.h>
using namespace std;

struct node {
	int value;
	node* left;
	node* right;
	int height;
};

int Height(node* p) {
	if (p == nullptr)
		return -1;
	else
		return p->height;
}

/*右旋*/
node* SingleRotateWithLeft(node* K2) {
	node* K1 = K2->left;
	K2->left = K1->right;
	K1->right = K2;
	K2->height = max(Height(K2->left), Height(K2->right)) + 1;
	K1->height = max(Height(K1->left), K2->height) + 1;

	return K1;
}

/*左旋*/
node* SingleRotateWithRight(node* K2) {
	node* K1 = K2->right;
	K2->right = K1->left;
	K1->left = K2;
	K2->height = max(Height(K2->left), Height(K2->right)) + 1;
	K1->height = max(Height(K1->right), K2->height) + 1;

	return K1;
}

/*左-右双旋转*/
node* DoubleRotateWithLeft(node* K3) {
	K3->left = SingleRotateWithRight(K3->left);
	return SingleRotateWithLeft(K3);
}

/*右-左双旋转*/
node* DoubleRotateWithRight(node* K3) {
	K3->right = SingleRotateWithLeft(K3->right);
	return SingleRotateWithRight(K3);
}

node* insert(int v, node* root) {
	if (root == nullptr) {
		root = new node();
		root->value = v;
		root->height = 0;
		root->left = nullptr;
		root->right = nullptr;
		return root;
	}
	if (v < root->value) {
		root->left = insert(v, root->left);
		if (Height(root->left) - Height(root->right) == 2) {
			if (v < root->left->value) //左—左
				root = SingleRotateWithLeft(root); //单旋右旋
			else  //左—右
				root = DoubleRotateWithLeft(root); //左-右双旋转
		}
	} else if (v > root->value) {
		root->right = insert(v, root->right);
		if (Height(root->right) - Height(root->left) == 2) {
			if (v > root->right->value)
				root = SingleRotateWithRight(root);
			else
				root = DoubleRotateWithRight(root);
		}
	}
	root->height = max(Height(root->left), Height(root->right)) + 1;
	return root;
}

int main(int argc, char const *argv[])
{
	int N, t;
	cin >> N;
	node* root = nullptr;
	for (int i = 0; i < N; ++i) {
		cin >> t;
		root = insert(t, root);
	}
	cout << root->value << endl;

	return 0;
}