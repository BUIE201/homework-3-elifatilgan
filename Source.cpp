#include <iostream>
#include <vector>
using namespace std;
struct Node
{
	int i;
	Node* pLeft;
	Node* pRight;

	Node(int iIn) : i(iIn), pLeft(nullptr), pRight(nullptr) {}
};
void PrintTree(Node* pRoot, int Level)
{
	if (!pRoot)
		return;

	PrintTree(pRoot->pRight, Level + 1);

	for (int i = 0; i < Level; i++)
		cout << "  ";
	cout << pRoot->i << endl;

	PrintTree(pRoot->pLeft, Level + 1);
}
void Insert(Node*& pRoot, Node* pNewNode)
{
	if (!pRoot)
		pRoot = pNewNode;
	else
	{
		if (pNewNode->i < pRoot->i)
			Insert(pRoot->pLeft, pNewNode);
		else
			Insert(pRoot->pRight, pNewNode);
	}
}
void printResults(int* arr, int len)
{
	int sum = 0;
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
		sum += arr[i];
	}
	cout << "->SUM = " << sum << endl;
}

void printPathsRecur(Node* node, int path[], int pathLen);

void printPaths(Node* node)
{
	int path[1000]; //1000 is enough capacity.
	printPathsRecur(node, path, 0);
}

void printPathsRecur(Node* node, int path[], int pathLen)
{
	if (node == NULL)
		return;

	/* append this node to the path array */
	path[pathLen] = node->i;
	pathLen++;

	/* if it's a leaf,print the path that led to there */
	if (node->pLeft == NULL && node->pRight == NULL)
	{
		printResults(path, pathLen);
	}
	else
	{
		/* otherwise try both subtrees */
		printPathsRecur(node->pLeft, path, pathLen);
		printPathsRecur(node->pRight, path, pathLen);
	}
}



void main()
{
	int i;

	Node* pRoot = nullptr;
	while (true)
	{
		cin >> i;
		if (i == 99)
			break;

		Node* p = new Node(i);
		Insert(pRoot, p);
	}
	PrintTree(pRoot, 1);
	printPaths(pRoot);
}