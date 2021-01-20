#include <iostream>
#include <vector>
#include <map>
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
void printResults(int arr[], int len, int sum)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "sum";
}
int calculateSum(int arr[], int len)
{
	int sum = 0;
	for (int i = 0; i < len; i++)
	{
		sum += arr[i];
	}
	return sum;
}
map<pair<int*, int>, int> printPathsRecur(Node* node, int path[], int pathLen);

void printPaths(Node* node)
{
	map<pair<int*, int>, int> temp;
	int path[1000]; //1000 is enough capacity.
	temp = printPathsRecur(node, path, 0);
	
		int a = 0;
		pair<int*, int> b;
		map<pair<int*, int>, int>::iterator itr;
		for (itr = temp.begin(); itr != temp.end(); itr++)
		{
			if (itr->second > a)
			{
				a = itr->second;
				b = itr->first;
			}
		}
		printResults(b.first, b.second, a);
	
}

map<pair<int*, int>, int> printPathsRecur(Node* node, int path[], int pathLen)
{
	map<pair<int*, int>, int> Results;
	
	/* add this node to the path array */
	path[pathLen] = node->i;
	pathLen++;

	/* if it's a leaf,get the path that led to there */
	if (node->pLeft == NULL && node->pRight == NULL)
	{
		auto x = make_pair(path, pathLen);
		Results.insert(pair<pair<int*, int>, int>(x, calculateSum(path, pathLen)));
		return Results;
	}
	else
	{
		/* otherwise try subtrees */
		if(node->pLeft != NULL) printPathsRecur(node->pLeft, path, pathLen);
		if(node->pRight!= NULL) printPathsRecur(node->pRight, path, pathLen);
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