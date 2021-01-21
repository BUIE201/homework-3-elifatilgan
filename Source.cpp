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
void printResults(vector<int> x, int sum)
{
	cout << "Branch with the largest sum is: ";
	for (int i = 0; i < x.size();i++) 
	{
		cout << x[i] << " ";
	}
	cout << " -> SUM= " << sum;
	
}
int calculateSum(vector<int> arr)
{
	int sum = 0;
	for (int i = 0; i <arr.size(); i++)
	{
		sum += arr[i];
	}
	return sum;
}
void printPathsRecur(Node* node, vector<int> path, map<vector<int>, int>& results);

void printPaths(Node* node)
{
	map<vector<int>, int> Results;
	vector<int> path; 
	printPathsRecur(node, path,Results);
	
		int a = 0;
		auto max_branch = Results.begin()->first;
		for (auto itr = Results.begin(); itr != Results.end(); ++itr)
		{
			if (itr->second > a)
			{
				a = itr->second;
				max_branch = itr->first;
			}
		}
		
		printResults(max_branch,a);
	
}

void printPathsRecur(Node* node, vector<int> path, map<vector<int>, int>& Results)
{
	
	
	/* add this node to the path array */
	path.push_back(node->i);

	/* if it's a leaf,get the path that led to there */
	if (node->pLeft == NULL && node->pRight == NULL)
	{
		Results.emplace(pair<vector<int>,int>(path, calculateSum(path)));
		
	}
	else
	{
		/* otherwise try subtrees */
		if(node->pLeft != NULL) printPathsRecur(node->pLeft, path,Results);
		if(node->pRight!= NULL) printPathsRecur(node->pRight, path, Results);
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