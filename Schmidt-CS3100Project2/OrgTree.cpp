#include "stdafx.h"
#include "OrgTree.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

	//Declare variables
	TREENODEPTR root;
	int nodeCount;

	//Default OrgTree constructor
	OrgTree::OrgTree() {
		//Set node count to 0
		nodeCount = 0;
	}


	//Function to add root.
	//If there is no root, it adds one.
	//If there is already a root, the entire tree becomes a subtree of the new root.
	//Best and worst case asymptotic run time of Theta(1) for a tree of size n.
	void OrgTree::addRoot(string title, string name) {
		//Increase node count by 1
		nodeCount++;
		//If no root exists
		if (root == TREENULLPTR) {
			//Create new TreeNode and point root to it
			root = new TreeNode;
			//Set name and title
			root->name = name;
			root->title = title;
			//Set parent, left child, and sibling to null
			root->parent = TREENULLPTR;
			root->leftmostChild = TREENULLPTR;
			root->rightSibling = TREENULLPTR;
		}
		else {
			//Create new TreeNode
			TREENODEPTR newRoot = new TreeNode;
			//Set new node's name and title
			newRoot->name = name;
			newRoot->title = title;
			//Set original root's parent to be new node
			root->parent = newRoot;
			//Set new node's left child to be the old root
			newRoot->leftmostChild = root;
			//Set new node's parent and right sibling to null
			newRoot->parent = TREENULLPTR;
			newRoot->rightSibling = TREENULLPTR;
			//Point "root" pointer to the new node
			root = newRoot;

		}
	}

	//Method to find the number of employees in the tree.
	unsigned int OrgTree::getSize() {
		return nodeCount;
	}

	//Method to return a pointer to the root node.
	//Best and worst case asymptotic run time of Theta(1) for a tree of size n.
	TREENODEPTR OrgTree::getRoot() {
		return root;
	}

	//Method to return a pointer to the leftmost child of the paramater node.
	//If the node has no children, returns null pointer.
	//Best and worst case asymptotic run time of Theta(1) for a tree of size n.
	TREENODEPTR OrgTree::leftmostChild(TREENODEPTR node) {
		if (node->leftmostChild == TREENULLPTR) {
			return TREENULLPTR;
		}
		TREENODEPTR leftChild = node->leftmostChild;
		return leftChild;
	}

	//Method to return a pointer to the right sibling of the parameter node
	//If the node has no right sibling, returns null pointer
	//Best and worst case asymptotic run time of Theta(1) for a tree of size n.
	TREENODEPTR OrgTree::rightSibling(TREENODEPTR node) {
		if (node->rightSibling == TREENULLPTR) {
			return TREENULLPTR;
		}
		TREENODEPTR rightSibling = node->rightSibling;
		return rightSibling;
	}

	//Method to print out the subtree starting at node.
	void OrgTree::printSubTree(TREENODEPTR subTreeRoot) {

	}

	//Method to return the TreeNode with the given title.
	//If the title is not found, returns null pointer
	TREENODEPTR OrgTree::find(string title) {
		return false;
	}

	//Method to create an org tree from a file with the given filename
	//If file is found and tree is created successfully, returns true
	//Else returns false
	bool OrgTree::read(string filename) {

		return false;
	}

	//Writes the org tree to a file with the given filename, using the same format as read
	void OrgTree::write(string filename) {

	}

	//Method to "hire an employee", aka add a node as the last child of the node given by parent
	//with the title given by newTitle and the name given by newName.
	//Best case asymptotic run time of Theta(1) for tree of size n. (new node is first child of parent)
	//Worst case: Theta (n) (All nodes are children of parent, so must traverse through all right siblings to add as last child)
	void OrgTree::hire(TREENODEPTR parent, string newTitle, string newName) {
		//Create new node
		TREENODEPTR newNode = new TreeNode;
		//Increase node count by 1
		nodeCount++;
		//Give new node title, name, and parent corresponding to parameters.
		newNode->title = newTitle;
		newNode->name = newName;
		newNode->parent = parent;
		//Set leftmost child and right sibling to null
		newNode->leftmostChild = TREENULLPTR;
		newNode->rightSibling = TREENULLPTR;
		if (parent->leftmostChild == TREENULLPTR) {
			parent->leftmostChild = newNode;
		}
		else {
			TREENODEPTR child = parent->leftmostChild;
			while (child->rightSibling != TREENULLPTR) {
				child = child->rightSibling;
			}
			child->rightSibling = newNode;
		}
	}

	//Fire the employee whose title matches formerTitle and make all their employee's work directly for the fired employee's boss
	//If no title match is found, return false.  If formerTitle matches root node, return false.
	bool OrgTree::fire(string formerTitle) {
		return false;
	}