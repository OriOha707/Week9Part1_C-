#ifndef BSNode_H
#define BSNode_H
#include <string>
#include <iostream>
class BSNode
{
public:
    BSNode(std::string data);
    BSNode(const BSNode& other);
    ~BSNode();
    void insert(std::string value);
    BSNode& operator=(const BSNode& other);
    bool isLeaf();
    std::string getData()const;
    BSNode* getLeft()const;
    BSNode* getRight()const;
    bool search(std::string val);
    int getHeight();
    int getDepth(BSNode& root);
    void printNodes();
private:
    std::string _data;
    BSNode* _left;
    BSNode* _right;
    int _count; //to count replicates
    int getCurrNodeDistFromInputNode(BSNode* node); //auxiliary function for getDepth
};
#endif