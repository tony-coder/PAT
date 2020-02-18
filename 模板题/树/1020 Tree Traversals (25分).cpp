#include <bits/stdc++.h>
using namespace std;

struct node
{
	int value;
	node* left;
	node* right;
};

int post[50];
int in[50];

//后序和先序遍历提供根节点位置，然后再中序序列中区分出左子树和右子树，递归建树
//从0开始
node* createTree(int postLeft, int postRight, int intLeft, int inRight)
{
	if (postLeft > postRight)
		return NULL;
	int k;
	for (k = intLeft; k <= inRight; ++k)
	{
		if (in[k] == post[postRight])
			break;
	}
	int numLeft = k - intLeft;
	node* root = new node;
	root->value = post[postRight];
	root->left = createTree(postLeft, postLeft + numLeft - 1, intLeft, k - 1);
	root->right = createTree(postLeft + numLeft, postRight - 1, k + 1, inRight);
	return root;
}

int num, N;
void BFS(node* root)
{
	queue<node*> q;
	q.push(root);
	while (!q.empty())
	{
		node* curr = q.front();
		cout << curr->value;
		num++;
		if (num < N)
			cout << " ";
		q.pop();
		if (curr->left != NULL)
			q.push(curr->left);
		if (curr->right != NULL)
			q.push(curr->right);
	}
}

int main(int argc, char const *argv[])
{
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> post[i];
	for (int i = 0; i < N; ++i)
		cin >> in[i];
	node* root = createTree(0, N - 1, 0, N - 1);
	BFS(root);

	return 0;
}