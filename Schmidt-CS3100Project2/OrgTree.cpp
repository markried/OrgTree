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
	//Best and worst case asymptotic runtime of Theta(1) for a tree of size n.
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
		//Recursively go through 


	}

	//void 

	//Method to return the TreeNode with the given title.
	//If the title is not found, returns null pointer
	//Best case asymptotic run time of Theta(1) for tree of size n. (node is root)
	//Worst case: Theta (n) (All nodes are children of parent or tree is linear, so must traverse through all other nodes to find)
	TREENODEPTR OrgTree::find(string title) {
		//Call preOrderFind and pass through the root and the title being searched for
		return preOrderFind(root, title);
	}

	//Method to traverse the tree and find a string (doing a preorder traversal recursively)
	//Best case asymptotic run time of Theta(1) for tree of size n. (node is root)
	//Worst case: Theta (n) (All nodes are children of parent or tree is linear, so must traverse through all other nodes to find)
	TREENODEPTR OrgTree::preOrderFind(TREENODEPTR findNode, string title) {
		//If the current node has the matching title, return the node.
		if (findNode->title == title) {
			return findNode;
		}
		//If the node has a left child, recursively check it and return result.
		if (findNode->leftmostChild != TREENULLPTR) {
			findNode = findNode->leftmostChild;
			return OrgTree::preOrderFind(findNode, title);
		}
		//If the node has a right sibling, recursively check it and return result.
		if (findNode->rightSibling != TREENULLPTR && findNode->title != title) {
			findNode = findNode->rightSibling;
			return OrgTree::preOrderFind(findNode, title);
		}
		//If title not found, return null pointer
		return TREENULLPTR;
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
	//Best case asymptotic run time of Theta(1) for tree of size n. (fire node is first child of parent and is a leaf)
	//Worst case: Theta(n) (n to find, and n to switch all children to parent (if fireNode is child of root and all other nodes are children of fireNode)
	bool OrgTree::fire(string formerTitle) {
		//Declare variables
		TREENODEPTR fireNode = new TreeNode;
		TREENODEPTR childNode = new TreeNode;
		TREENODEPTR parentNode = new TreeNode;

		//If formerTitle matches root node, return false.
		if (root->title == formerTitle) {
			return false;
		}
		//Find the node with the title formerTitle using the find function
		fireNode = find(formerTitle);
		//If the search returns the null pointer (aka no title found), return false
		if (fireNode == TREENULLPTR) {
			return false;
		}
		//Before deleting node, make parent pointer of all child nodes of fireNode point to fireNode's parent
		//Check if fireNode has children
		if (fireNode->leftmostChild != TREENULLPTR) {
			//Set childNode to fireNode's left child
			childNode = fireNode->leftmostChild;
			parentNode = fireNode->parent;

			//Set fireNode's parent's left child to be fireNode's left child
			parentNode->leftmostChild = childNode;

			//Loop until no more right siblings: set child's parent to fireNode's parent and move to next right sibling
			while (childNode->rightSibling != TREENULLPTR) {
				childNode->parent = fireNode->parent;
				childNode = childNode->rightSibling;
			}
			//Set last child's parent to fireNode's parent
			childNode->parent = fireNode->parent;
		}

		//Once all children have parent pointers to fireNode's pointer, delete fireNode
		fireNode->leftmostChild = TREENULLPTR;
		fireNode->name.clear();
		fireNode->parent = TREENULLPTR;
		fireNode->rightSibling = TREENULLPTR;
		fireNode->title.clear();
		delete fireNode;

		//Return true if firing complete
		return true;
	}