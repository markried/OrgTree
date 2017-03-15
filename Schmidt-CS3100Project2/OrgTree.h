#pragma once
#define TREENODEPTR TreeNode*
#define TREENULLPTR NULL

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
struct TreeNode {
	string title;
	string name;
	TREENODEPTR parent;
	TREENODEPTR leftmostChild;
	TREENODEPTR rightSibling;
};

class OrgTree {
private:
	//Declare variables
	TREENODEPTR root;
	int nodeCount;
public:
	//Default OrgTree constructor
	OrgTree();

	//Function to add root.
	void addRoot(string, string);

	//Method to find the number of employees in the tree.
	unsigned int getSize();

	//Method to return a pointer to the root node.
	TREENODEPTR getRoot();

	//Method to return a pointer to the leftmost child of the paramater node.
	TREENODEPTR leftmostChild(TREENODEPTR);

	//Method to return a pointer to the right sibling of the parameter node
	TREENODEPTR rightSibling(TREENODEPTR);

	//Method to print out the subtree starting at node.
	void printSubTree(TREENODEPTR);

	//Method to return the TreeNode with the given title.
	TREENODEPTR find(string);

	//Method to create an org tree from a file with the given filename
	bool read(string);

	//Writes the org tree to a file with the given filename, using the same format as read
	void write(string);

	//Method to "hire an employee", aka add a node as the last child of the node given by parent
	//with the title given by newTitle and the name given by newName.
	void hire(TREENODEPTR, string, string);

	//Fire the employee whose title matches formerTitle and make all their employee's work directly for the fired employee's boss
	//If no title match is found, return false.  If formerTitle matches root node, return false.
	bool fire(string);
};