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
	test.hire(Boss,"Test Employee 1","TestOne");
	test.hire(Boss, "Test Employee 2", "TestTwo");
	test.hire(Boss, "Test Employee 3", "TestThree");
	//New root
	test.addRoot("BetterBoi", "Boiest");
	//Get children all over
	TreeNode* newBoss = test.getRoot();
	TreeNode* oldBoss = test.leftmostChild(newBoss);
	TreeNode* TestEmp1 = test.leftmostChild(oldBoss);
	TreeNode* TestEmp2 = test.rightSibling(TestEmp1);
	TreeNode* TestEmp3 = test.rightSibling(TestEmp2);
	//Next one should go null
	TreeNode* nullboiintheory = test.rightSibling(TestEmp3);
	//get size
	int count = test.getSize();
	//Try to find existing node
	TreeNode* TestReturn2 = test.find("Test Employee 2");
	//Try to find nonexistent node
	TreeNode* TestReturnNull = test.find("Nothing");
	//Fire existing non-root node
	bool fired = test.fire("TopBoi");
	//Fire root node (should return false)
	fired = test.fire("BetterBoi");
	//Fire nonexistent node
	fired = test.fire("YabbaDabbaDoo");
	return 0;
}

