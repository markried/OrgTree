#include "stdafx.h"
#include "OrgTree.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
//For a tree of n employees, the space requirement is 3n pointers.

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
		//Return count of nodes in the tree
		return nodeCount;
	}

	//Method to return a pointer to the root node.
	//Best and worst case asymptotic run time of Theta(1) for a tree of size n.
	TREENODEPTR OrgTree::getRoot() {
		//Return root pointer
		return root;
	}

	//Method to return a pointer to the leftmost child of the paramater node.
	//If the node has no children, returns null pointer.
	//Best and worst case asymptotic run time of Theta(1) for a tree of size n.
	TREENODEPTR OrgTree::leftmostChild(TREENODEPTR node) {
		//If node has no children, return null pointer
		if (node->leftmostChild == TREENULLPTR) {
			return TREENULLPTR;
		}
		//Otherwise, return leftmost child's pointer
		TREENODEPTR leftChild = node->leftmostChild;
		return leftChild;
	}

	//Method to return a pointer to the right sibling of the parameter node
	//If the node has no right sibling, returns null pointer
	//Best and worst case asymptotic run time of Theta(1) for a tree of size n.
	TREENODEPTR OrgTree::rightSibling(TREENODEPTR node) {
		//If node has no right siblings, return null pointer
		if (node->rightSibling == TREENULLPTR) {
			return TREENULLPTR;
		}
		//Otherwise, return right sibling's pointer
		TREENODEPTR rightSibling = node->rightSibling;
		return rightSibling;
	}

	//Method to print out the subtree starting at node.
	//Best case runtime: Theta(1) (currentNode is a leaf)
	//Worst case runtime: Theta(n) (currentNode is the root)
	void OrgTree::printSubTree(TREENODEPTR subTreeRoot) {
		//Call recursivePrintSubTree and pass through subTreeRoot and a starting depth of 0
		recursivePrintSubTree(subTreeRoot, 0);
	}

	//Recursive method to print subtree and keep a count of how deep in the subtree the method is (to insert appropriate number of tabs)
	//Best case runtime: Theta(1) (currentNode is a leaf)
	//Worst case runtime: Theta(n) (currentNode is the root)
	void OrgTree::recursivePrintSubTree(TREENODEPTR currentNode, int depth) {
		//Declare variables
		string tabs, nodeName, nodeTitle;

		//Get appropriate number of tabs to add at beginning of output string
		for (int i = 0; i < depth; i++) {
			tabs.append("\t");
		}
		
		//Get title and name from current node
		nodeTitle = currentNode->title;
		nodeName = currentNode->name;

		//Output current node's title and name
		cout << tabs << nodeTitle << ": " << nodeName << endl;

		//If current node has a leftmost child, then run recursion on child
		if (currentNode->leftmostChild != TREENULLPTR) {
			//When recursing deeper, increase depth
			recursivePrintSubTree(currentNode->leftmostChild, depth + 1);
		}

		//If current node has a right sibling, then run recursion on sibling
		if (depth != 0 && currentNode->rightSibling != TREENULLPTR) {
			//WHen recursing to a sibling, depth does not change
			recursivePrintSubTree(currentNode->rightSibling, depth);
		}

		return;
	}

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
		//Declare variables
		TREENODEPTR child;
		TREENODEPTR sibling;

		//If the current node has the matching title, return the node.
		if (findNode->title == title) {
			return findNode;
		}

		//If the node has a left child, recursively check it and return result.
		if (findNode->leftmostChild != TREENULLPTR) {
			child = preOrderFind(findNode->leftmostChild, title);
			//If the child node has the matching title, return the node.
			if (child != TREENULLPTR && child->title == title) {
				return child;
			}
		}

		//If the node has a right sibling, recursively check it and return result.
		if (findNode->rightSibling != TREENULLPTR && findNode->title != title) {
			sibling = preOrderFind(findNode->rightSibling, title);
			//If the sibling node has the matching title, return the node.
			if (sibling != TREENULLPTR && sibling->title == title) {
				return sibling;
			}
		}

		//If title not found, return null pointer
		return TREENULLPTR;
	}

	//Method to create an org tree from a file with the given filename
	//If file is found and tree is created successfully, returns true
	//Else returns false
	//Best case: Theta(n) (n entries in file to process, but if it's a linear tree, only need to go down and back up)
	//Worst case: Theta(n^2) (n entries in file to process, and if it's a flat tree, n steps to add rightmost child of root)
	//Used given FileIO.cpp to understand how I/O should work, so any similarities are due to that.
	bool OrgTree::read(string filename) {
		//Declare variables
		TREENODEPTR newNode = new TreeNode;
		TREENODEPTR currentNode = new TreeNode;
		TREENODEPTR leftSibling = new TreeNode;
		string inTitle, inName;

		//Create filestream
		ifstream inFile(filename);
		//Check if file cannot be opened
		if (inFile.is_open() == false) {
			//If file cannot be opened, return false.
			return false;
		}

		//While end of file has not been reached
		while (inFile.eof() == false) {
			TREENODEPTR newNode = new TreeNode;
			//If current node is null (improperly formatted text file), then return false.
			if (currentNode == TREENULLPTR) {
				return false;
			}
			//If current line is a close paren
			if (inFile.peek() == ')') {
				//Set currentNode to be currentNode's parent (go up a step in the tree)
				currentNode = currentNode->parent;
				inFile.ignore(256, '\n');
			}
			//If line isn't a close paren
			else {
				//Get title and name
				getline(inFile, inTitle, ',');
				getline(inFile, inName, '\n');

				//Assign title and name to new node
				newNode->title = inTitle;
				newNode->name = inName;
				
				//Set new node's child and sibling pointers to null
				newNode->leftmostChild = TREENULLPTR;
				newNode->rightSibling = TREENULLPTR;
				//Set new node's parent to null (it'll be set later if it's not root)
				newNode->parent = TREENULLPTR;

				//If root does not exist
				if (root == TREENULLPTR) {
					//Set new node to be root
					root = newNode;
					//Set root as parent node
					currentNode = root;
				}
				//If root exists
				else {
					//Set new node's parent to be parent node
					newNode->parent = currentNode;

					//If parent node has no children
					if (currentNode->leftmostChild == TREENULLPTR) {
						currentNode->leftmostChild = newNode;
					}
					//If parent node has children
					else {
						//Set a node to find last child of parent
						leftSibling = currentNode->leftmostChild;
						//While search node's right sibling is not null
						while (leftSibling->rightSibling != TREENULLPTR) {
							//Set search node to be search node's right sibling
							leftSibling = leftSibling->rightSibling;
						}
						//Once last child is found, set its right sibling to be the new node.
						leftSibling->rightSibling = newNode;
					}

					//Set new node to be parent node (keep parent trailing)
					currentNode = newNode;
				}
			}
		}

		return true;
	}

	//Writes the org tree to a file with the given filename, using the same format as read
	//Best and worst case scenario: Theta(n) (must traverse every node to write it)
	void OrgTree::write(string filename) {
		//Create output file stream
		ofstream outFile(filename);
		//Call recursiveWrite with the root node and filename
		
		recursiveWrite(root, outFile);
	}

	//Function to recursively write each line to output file
	//Best and worst case scenario: Theta(n) (must traverse every node to write it)
	void OrgTree::recursiveWrite(TREENODEPTR currentNode, ofstream& outFile) {
		//Output current node
		outFile << currentNode->title << ", " << currentNode->name << endl;

		//If the node has a left child, recursively output it and check for relationships.
		if (currentNode->leftmostChild != TREENULLPTR) {
			//Go to the leftChild of the node
			recursiveWrite(currentNode->leftmostChild, outFile);
		}

		//Output closed paren to signify end of subtree when no more left children
		outFile << ")";
		//If current node is not root, append new line to the file.
		//Doing this because if endline is appended after the root, there's an extra (blank) line in the file, which bugs things.
		if (currentNode != root) {
			outFile << endl;
		}

		//If the node has a right sibling, recursively output it and check for relationships.
		if (currentNode->rightSibling != TREENULLPTR) {
			//Go to the rightSibling of the node
			recursiveWrite(currentNode->rightSibling, outFile);
		}

		return;
	}

	//Method to "hire an employee", aka add a node as the last child of the node given by parent
	//with the title given by newTitle and the name given by newName.
	//Best case asymptotic run time of Theta(1) for tree of size n. (new node is first child of parent)
	//Worst case: Theta (n) (For a flat tree, must traverse through all children of parent to add as last child)
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
		//If parent of new node has no children, make this its leftmost child
		if (parent->leftmostChild == TREENULLPTR) {
			parent->leftmostChild = newNode;
		}
		//If parent of new node has children, make this its last child
		else {
			//Set child node to be parent's left child
			TREENODEPTR child = parent->leftmostChild;
			//Cycle through children of the parent to find the last child 
			while (child->rightSibling != TREENULLPTR) {
				child = child->rightSibling;
			}
			//Add new node as right sibling of parent's last child
			child->rightSibling = newNode;
		}
	}

	//Fire the employee whose title matches formerTitle and make all their employee's work directly for the fired employee's boss
	//If no title match is found, return false.  If formerTitle matches root node, return false.
	//Best case asymptotic run time of Theta(1) for tree of size n. (fire node is only child of parent and is a leaf)
	//Worst case: Theta(n) (Theta(n) to find plus Theta(n) to repoint everything around fireNode)
	bool OrgTree::fire(string formerTitle) {
		//Declare variables
		TREENODEPTR fireNode = new TreeNode;
		TREENODEPTR childNode = new TreeNode;
		TREENODEPTR parentNode = new TreeNode;
		TREENODEPTR firesLeftSibling = new TreeNode;

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

		//Set parentNode = fireNode's parent
		parentNode = fireNode->parent;

		//Before deleting node, make parent pointer of all child nodes of fireNode point to fireNode's parent
		//Check if fireNode has children
		if (fireNode->leftmostChild != TREENULLPTR) {
			//Set childNode to fireNode's left child
			childNode = fireNode->leftmostChild;

			//If parent node's left child is fireNode, set parent node's new left child to be fireNode's left child
			if (parentNode->leftmostChild == fireNode) {
				parentNode->leftmostChild = childNode;
			}
			//If parent node's left child is not fireNode, find fireNode's left sibling and make its right sibling childNode
			else {
				//Set pointer to parent node's left child
				firesLeftSibling = parentNode->leftmostChild;
				//Find firenode's left sibling
				while (firesLeftSibling->rightSibling != fireNode) {
					firesLeftSibling = firesLeftSibling->rightSibling;
				}
				//Make fireNode's left sibling's right sibling the first childNode
				firesLeftSibling->rightSibling = childNode;
			}

			//Loop through all of fireNode's children and make them children of fireNode's parent
			while (childNode->rightSibling != TREENULLPTR) {
				childNode->parent = fireNode->parent;
				childNode = childNode->rightSibling;
			}

			//Set last child's parent to fireNode's parent
			childNode->parent = fireNode->parent;
			//Set last child's right sibling to be fireNode's right sibling
			childNode->rightSibling = fireNode->rightSibling;
		}

		//If fireNode has no children
		else {
			//If fireNode is parent's leftmost child
			if (parentNode->leftmostChild == fireNode) {
				//Make fireNode's right sibling be parentNode's left child
				parentNode->leftmostChild = fireNode->rightSibling;
			}

			//If parent node's left child is not fireNode, find fireNode's left sibling and make its right sibling childNode
			else {
				//Pointer to parent's left child
				firesLeftSibling = parentNode->leftmostChild;
				//Find fireNode's left sibling
				while (firesLeftSibling->rightSibling != fireNode) {
					firesLeftSibling = firesLeftSibling->rightSibling;
				}
				//Make fireNode's left sibling's right sibling equal fireNode's right sibling (skip over fireNode)
				firesLeftSibling->rightSibling = fireNode->rightSibling;
			}
		}
		//Once nothing points to or from fireNode anymore, delete fireNode
		fireNode->leftmostChild = TREENULLPTR;
		fireNode->name.clear();
		fireNode->parent = TREENULLPTR;
		fireNode->rightSibling = TREENULLPTR;
		fireNode->title.clear();
		delete fireNode;

		//Subtract one from nodeCount to keep count accurate
		nodeCount--;
		//Return true if firing complete
		return true;
	}