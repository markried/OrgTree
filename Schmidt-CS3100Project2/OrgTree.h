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
	TreeNode* parent;
	TreeNode* leftmostChild;
	TreeNode* rightSibling;
};

class OrgTree {
public: 
	//Declare variables
	TreeNode* root;

	//Default OrgTree constructor
	OrgTree() {
		////Declare variables
		//root = new TreeNode;
		//root->next = NULL;
	}


	//Function to add root.
	//If there is no root, it adds one.
	//If there is already a root, the entire tree becomes a subtree of the new root.
	//Best and worst case asymptotic run time of Theta(1) for a tree of size n.
	void addRoot(string title, string name) {
		//If no root exists
		if (root == NULL) {
			//Create new TreeNode and point root to it
			root = new TreeNode;
			//Set name and title
			root->name = name;
			root->title = title;
			//Set parent, left child, and sibling to null
			root->parent = NULL;
			root->leftmostChild = NULL;
			root->rightSibling = NULL;
		}
		else {
			//Create new TreeNode
			TreeNode* newRoot = new TreeNode;
			//Set new node's name and title
			newRoot->name = name;
			newRoot->title = title;
			//Set original root's parent to be new node
			root->parent = newRoot;
			//Set new node's left child to be the old root
			newRoot->leftmostChild = root;
			//Set new node's parent and right sibling to null
			newRoot->parent = NULL;
			newRoot->rightSibling = NULL;
			//Point "root" pointer to the new node
			root = newRoot;

		}
	}

	//Method to find the number of employees in the tree.
	unsigned int getSize() {

		return 0;
	}

	//Method to return a pointer to the root node.
	//Best and worst case asymptotic run time of Theta(1) for a tree of size n.
	TreeNode* getRoot() {
		return root;
	}

	//Method to return a pointer to the leftmost child of the paramater node.
	//If the node has no children, returns null pointer.
	//Best and worst case asymptotic run time of Theta(1) for a tree of size n.
	TreeNode* leftmostChild(TreeNode* node) {
		if (node->leftmostChild == NULL) {
			return NULL;
		}
		TreeNode* leftChild = node->leftmostChild;
		return leftChild;
	}

	//Method to return a pointer to the right sibling of the parameter node
	//If the node has no right sibling, returns null pointer
	//Best and worst case asymptotic run time of Theta(1) for a tree of size n.
	TreeNode* rightSibling(TreeNode* node) {
		if (node->rightSibling == NULL) {
			return NULL;
		}
		TreeNode* rightSibling = node->rightSibling;
		return rightSibling;
	}

	//Method to print out the subtree starting at node.
	void printSubTree(TreeNode* subTreeRoot) {

	}

	//Method to return the TreeNode with the given title.
	//If the title is not found, returns null pointer
	TreeNode* find(string title) {

	}

	//Method to create an org tree from a file with the given filename
	//If file is found and tree is created successfully, returns true
	//Else returns false
	bool read(string filename) {

	}

	//Writes the org tree to a file with the given filename, using the same format as read
	void write(string filename) {

	}

	//Method to "hire an employee", aka add a node as the last child of the node given by parent
	//with the title given by newTitle and the name given by newName.
	//Best case asymptotic run time of Theta(1) for tree of size n. (new node is first child of parent)
	//Worst case: Theta (n) (All nodes are children of parent, so must traverse through all right siblings to add as last child)
	void hire(TreeNode* parent, string newTitle, string newName) {
		//Create new node
		TreeNode* newNode = new TreeNode;
		//Give new node title, name, and parent corresponding to parameters.
		newNode->title = newTitle;
		newNode->name = newName;
		newNode->parent = parent;
		//Set leftmost child and right sibling to null
		newNode->leftmostChild = NULL;
		newNode->rightSibling = NULL;
		if (parent->leftmostChild == NULL) {
			parent->leftmostChild = newNode;
		}
		else {
			TreeNode* child = parent->leftmostChild;
			while (child->rightSibling != NULL) {
				child = child->rightSibling;
			}
			child->rightSibling = newNode;
		}
	}

	//Fire the employee whose title matches formerTitle and make all their employee's work directly for the fired employee's boss
	//If no title match is found, return false.  If formerTitle matches root node, return false.
	bool fire(string formerTitle) {

	}


};