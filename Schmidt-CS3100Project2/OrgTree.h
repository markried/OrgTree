//IMPLEMENTATION: BINARYIZED TREE
//For a tree of n employees, the space requirement is 3n pointers.

#pragma once
#define TREENODEPTR TreeNode*
#define TREENULLPTR NULL

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//TreeNode struct
struct TreeNode {
	//Each node contains a title and name, as well as pointers to parent, left child, and right sibling
	string title;
	string name;
	TREENODEPTR parent;
	TREENODEPTR leftmostChild;
	TREENODEPTR rightSibling;
};

//For a tree of n employees, the space requirement is 3n pointers.
class OrgTree {

private:

	//Declare variables
	TREENODEPTR root;
	int nodeCount;

	//Recursive method to traverse the tree and find a string (doing a preorder traversal recursively)
	//Best case asymptotic run time of Theta(1) for tree of size n. (node is root)
	//Worst case: Theta (n) (All nodes are children of parent or tree is linear, so must traverse through all other nodes to find)
	TREENODEPTR preOrderFind(TREENODEPTR, string);

	//Recursive method to print subtree and keep a count of how deep in the subtree the method is (to insert appropriate number of tabs)
	//Best case runtime: Theta(1) (currentNode is a leaf)
	//Worst case runtime: Theta(n) (currentNode is the root of a tree of n nodes)
	void recursivePrintSubTree(TREENODEPTR, int);

	//Function to recursively write each line to output file
	//Best and worst case runtime: Theta(n) (must traverse every node to write it)
	void recursiveWrite(TREENODEPTR, ofstream&);

	//Recursive method to delete everything in the tree
	//Best and worst case runtime: Theta(n) (must traverse every node to delete it)
	void recursiveDelete(TREENODEPTR);

public:
	
	//Default OrgTree constructor
	OrgTree();

	//Orgtree Destructor
	//Best and worst case runtime: Theta(n) (must traverse every node to delete it)
	~OrgTree();

	//Function to add root.
	//Best and worst case asymptotic run time of Theta(1) for a tree of size n.
	void addRoot(string, string);

	//Method to find the number of employees in the tree.
	//Best and worst case asymptotic runtime of Theta(1) for a tree of size n.
	unsigned int getSize();

	//Method to return a pointer to the root node.
	//Best and worst case asymptotic runtime of Theta(1) for a tree of size n.
	TREENODEPTR getRoot();

	//Method to return a pointer to the leftmost child of the paramater node.
	//Best and worst case asymptotic runtime of Theta(1) for a tree of size n.
	TREENODEPTR leftmostChild(TREENODEPTR);

	//Method to return a pointer to the right sibling of the parameter node
	//Best and worst case asymptotic runtime of Theta(1) for a tree of size n.
	TREENODEPTR rightSibling(TREENODEPTR);

	//Method to print out the subtree starting at node.
	//Best case runtime: Theta(1) (currentNode is a leaf)
	//Worst case runtime: Theta(n) (currentNode is the root of a tree of n nodes)
	void printSubTree(TREENODEPTR);

	//Method to return the TreeNode with the given title.
	//Best case asymptotic run time of Theta(1) for tree of size n. (node is root)
	//Worst case: Theta (n) (All nodes are children of parent or tree is linear, so must traverse through all other nodes to find)
	TREENODEPTR find(string);

	//Method to create an org tree from a file with the given filename
	//Best case: Theta(n) (n entries in file to process, but if it's a linear tree, only need to go down and back up)
	//Worst case: Theta(n^2) (n entries in file to process, and if it's a flat tree, n steps to add rightmost child of root)
	bool read(string);

	//Writes the org tree to a file with the given filename, using the same format as read
	//Best and worst case scenario: Theta(n) (must traverse every node to write it)
	void write(string);

	//Method to "hire an employee", aka add a node as the last child of the node given by parent
	//with the title given by newTitle and the name given by newName.
	//Best case asymptotic run time of Theta(1) for tree of size n. (new node is first child of parent)
	//Worst case: Theta (n) (All nodes are children of parent, so must traverse through all right siblings to add as last child)
	void hire(TREENODEPTR, string, string);


	//Method to "hire an employee", aka add a node as the last child of the node given by parent
	//with the title given by newTitle and the name given by newName. Same as hire but returns TREENODEPTR to newly created node;
	//Best case asymptotic run time of Theta(1) for tree of size n. (new node is first child of parent)
	//Worst case: Theta (n) (For a flat tree, must traverse through all children of parent to add as last child)
	TREENODEPTR returnHire(TREENODEPTR, string, string);

	//Fire the employee whose title matches formerTitle and make all their employee's work directly for the fired employee's boss
	//If no title match is found, return false.  If formerTitle matches root node, return false.
	//Best case asymptotic run time of Theta(1) for tree of size n. (fire node is first child of parent and is a leaf)
	//Worst case: Theta(n) (n to find, and n to switch all children to parent (if fireNode is child of root and all other nodes are children of fireNode)
	bool fire(string);
};