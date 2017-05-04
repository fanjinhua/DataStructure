/** /
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 256 + 5;
bool failed;
char s[maxn];

struct Node
{
	bool have_value;
	int v;
	Node *left, *right;
	Node() : have_value(false), left(nullptr), right(nullptr) {}
};

Node* root;
Node* newnode() { return new Node(); }

void addnode(int v, char* s)
{
	int n = strlen(s);
	Node* u = root;
	for (int i = 0; i < n; ++i)
	{
		if (s[i] == 'L')
		{
			if (!u->left) u->left = newnode();
			u = u->left;
		}
		else if (s[i] == 'R')
		{
			if (!u->right) u->right = newnode();
			u = u->right;
		}
	}
	if (u->have_value) failed = true;
	u->v = v;
	u->have_value = true;
}

void remove_tree(Node* n)
{
	if (n == nullptr)
		return;
	remove_tree(n->left);
	remove_tree(n->right);
	delete n;
}

bool read_input()
{
	failed = false;
	remove_tree(root);
	root = newnode();
	for (;;)
	{
		if (scanf("%s", s) != 1) return false;
		if (!strcmp(s, "()")) break;
		int value;
		sscanf(&s[1], "%d", &value);
		addnode(value, strchr(s, ',') + 1);
	}
	return true;
}

bool bfs(vector<int>& ans)
{
	queue<Node*> q;
	ans.clear();
	q.push(root);
	while (!q.empty())
	{
		Node* n = q.front(); q.pop();
		if (!n->have_value) return false;
		ans.push_back(n->v);
		if (n->left) q.push(n->left);
		if (n->right) q.push(n->right);

	}
	return true;
}

int main() 
{
	vector<int> ans;
	while (read_input()) 
	{
		ans.clear();
		if (!bfs(ans)) failed = 1;
		if (failed) printf("not complete\n");
		else 
		{
			for (int i = 0; i < ans.size(); i++) 
			{
				if (i != 0) printf(" ");
				printf("%d", ans[i]);
			}
			printf("\n");
		}
	}
	return 0;
}

/**/