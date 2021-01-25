#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct Node
{
	int i;
	Node* pLeft;
	Node* pRight;

	Node(int iIn) : i(iIn), pLeft(nullptr), pRight(nullptr) {}
};

void InsertToTree(Node*& pRoot, Node* pNew)
{
	if (!pRoot)
	{
		pRoot = pNew;
		return;
	}

	if (pNew->i <= pRoot->i)
		InsertToTree(pRoot->pLeft, pNew);

	else
		InsertToTree(pRoot->pRight, pNew);
}



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

int LargestSumOfNodes(Node* pRoot, vector<Node*>& branch) {
	if (pRoot == nullptr)
		return 0;

	branch.push_back(pRoot);

	int sum = pRoot->i;

	if (pRoot->pLeft != nullptr && pRoot->pRight != nullptr) {

		int leftSum = LargestSumOfNodes(pRoot->pLeft, branch);
		int rightSum = LargestSumOfNodes(pRoot->pRight, branch);
		
		if(leftSum > rightSum)
			sum += leftSum;
		else
			sum += rightSum;
	}
	else if (pRoot->pLeft != nullptr)
		sum += LargestSumOfNodes(pRoot->pLeft, branch);
	else if (pRoot->pRight != nullptr)
		sum += LargestSumOfNodes(pRoot->pRight, branch);


	return sum;
}

void PrintBranchAndSum(Node* pRoot) {

	vector<Node*> branch;
	
	int largestSum = LargestSumOfNodes(pRoot, branch);

	cout << "Branch with the largest sum is: ";

	for (int j = 0; j < branch.size(); j++)
		cout << branch[j]->i << " ";
	cout << "-> SUM = " << largestSum;

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
		InsertToTree(pRoot, p);
	}

	PrintTree(pRoot, 1);

	PrintBranchAndSum(pRoot);
}