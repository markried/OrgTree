// Schmidt-CS3100Project2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "OrgTree.h"

int main()
{
	//Create org tree
	OrgTree test;
	//Add root
	test.addRoot("TopBoi", "Boi");
	//Get root as node
	TreeNode* Boss = test.getRoot();
	//Hire
	test.hire(Boss,"Test Employee 1","TestBoi");
	test.hire(Boss, "Test Employee 2", "TestMan");
	test.hire(Boss, "Test Employee 3", "TestDude");
	//New root
	test.addRoot("BetterBoi", "Boiest");
	//Get children all over
	TreeNode* newBoss = test.getRoot();
	TreeNode* oldBoss = test.leftmostChild(newBoss);
	TreeNode* oldBossLeftChild = test.leftmostChild(oldBoss);
	TreeNode* LeftChildRightSib = test.rightSibling(oldBossLeftChild);
	TreeNode* Ye = test.rightSibling(LeftChildRightSib);
	TreeNode* nullboiintheory = test.rightSibling(Ye);
	int count = test.getSize();
	return 0;
}

