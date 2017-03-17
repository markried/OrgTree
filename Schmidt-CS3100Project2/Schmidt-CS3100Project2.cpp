// Schmidt-CS3100Project2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "OrgTree.h"

int RaymerTest();

int main()
{
	cout << "TEST\tTEST" << endl;
	//Create org tree
	OrgTree test;
	//Add root
	test.addRoot("OldRoot", "Old");
	//Get root as node
	TreeNode* Boss = test.getRoot();
	//Hire
	test.hire(Boss,"Test Employee 1","TestOne");
	test.hire(Boss, "Test Employee 2", "TestTwo");
	test.hire(Boss, "Test Employee 3", "TestThree");
	//New root
	test.addRoot("Root", "Root");
	//Get children all over
	TreeNode* newBoss = test.getRoot();
	test.hire(newBoss, "BossBro", "NeverWasRoot");
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
	cout << TestReturn2->name<<endl;
	//Try to find nonexistent node
	TreeNode* TestReturnNull = test.find("Nothing");

	//Print full tree
	test.printSubTree(newBoss);
	//Print tree from under root
	test.printSubTree(oldBoss);
	//Print what should only be one node:
	test.printSubTree(TestEmp1);

	//Fire existing non-root node
	bool fired = test.fire("OldRoot");
	//Fire root node (should return false)
	fired = test.fire("Root");
	//Fire nonexistent node
	fired = test.fire("YabbaDabbaDoo");

	//Print full tree
	test.printSubTree(newBoss);

	int x = RaymerTest();

	system("PAUSE");
	return 0;
}

int RaymerTest() {
	OrgTree o1, o2, o3;

	// Adding roots should make a linear tree
	o1.addRoot("R1", "R1");
	o1.addRoot("R2", "R2");
	o1.addRoot("R3", "R3");

	o1.printSubTree(o1.getRoot()); //printSubTree from root


								   //add two children to root
	o1.hire(o1.getRoot(), "R3C1", "R3C1");
	o1.hire(o1.getRoot(), "R3C2", "R3C2");

	o1.printSubTree(o1.getRoot());
//o1.hire(o1.find("R3C1"), "R3C1C1", "R3C1C1");//test find on leaf node and hire to it
//	o1.hire(o1.find("R3C1"), "R3C1C2", "R3C1C2");//test find on leaf node and hire to it

	cout << o1.getSize() << endl;
	o1.printSubTree(o1.getRoot()); //printSubTree from root


	o1.fire("R3C1"); //fire an internal node
	cout << o1.getSize() << endl;
	o1.printSubTree(o1.getRoot());

	//// Write out a tree and read it back in to a new tree, then print
	//o1.write("output.txt");
	//o2.read("output.txt");
	//o2.printSubTree(o2.getRoot()); //printSubTree from root

	o3.read("testIn.txt");
	o3.printSubTree(o3.getRoot());
	//system("PAUSE");
	return 0;
}