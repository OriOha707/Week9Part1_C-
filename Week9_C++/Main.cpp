#include "BSNode.h"
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include "printTreeToFile.h"
#pragma comment(lib, "printTreeToFile")
int main()
{
	//BSNode* bs = new BSNode("6");
	//bs->insert("2");
	//bs->insert("8");
	//bs->insert("3");
	//bs->insert("5");
	//bs->insert("9");
	//bs->insert("6");
	BSNode* bs = new BSNode("b");
	bs->insert("aaaaa");
	bs->insert("bbbbb");
	bs->insert("zzzz");
	bs->insert("aaaaa");
	bs->insert("b");
	bs->insert("rar");
	//std::cout << "Tree height: " << bs->getHeight() << std::endl;
	//std::cout << "depth of node with 5 depth: " << bs->getLeft()->getRight()->getRight()->getDepth(*bs) << std::endl;
	//std::cout << "depth of node with 3 depth: " << bs->getLeft()->getRight()->getDepth(*bs) << std::endl;
	bs->printNodes();
	std::string textTree = "BSTData.txt";
	printTreeToFile(bs, textTree);
	system("BinaryTree.exe");
	system("pause");
	remove(textTree.c_str());
	delete bs;
	return 0;
}