#include "BSNode.h"
/*
* function set all the first info.
*/
BSNode::BSNode(std::string data)
{
	this->_count = 1;
	this->_left = NULL;
	this->_right = NULL;
	this->_data = data;
}
/*
* Function copy one tree to other
*/
BSNode::BSNode(const BSNode& other)
{
	this->_count = other._count;
	this->_data = other._data;
	if (other._right == NULL)
	{
		this->_right = NULL;
	}
	else
	{
		this->_right = new BSNode(*(other._right));
	}
	if (other._left == NULL)
	{
		this->_left = NULL;
	}
	else
	{
		this->_left = new BSNode(*(other._left));
	}
}
/*
* free memory
*/
BSNode::~BSNode()
{
	if (this->_right != NULL)
	{
		delete this->_right;
	}
	if (this->_left != NULL)
	{
		delete this->_left;
	}
}
/*
* function insert value into the tree
*/
void BSNode::insert(std::string value)
{
	if (this->_data == value)
	{
		this->_count++;
		return;
	}
	if (this->_data < value)
	{
		if (this->_right == NULL)
		{
			this->_right = new BSNode(value);
		}
		else
		{
			this->_right->insert(value);
		}
	}
	else
	{
		if (this->_left == NULL)
		{
			this->_left = new BSNode(value);
		}
		else
		{
			this->_left->insert(value);
		}
	}
}
/*
* Operator "=" for class BSNode
*/
BSNode& BSNode::operator=(const BSNode& other)
{
	if (&other == this) //If the trees are the same
		return *this;
	if (other._right)
		this->_right = new BSNode(*(other._right));
	if (other._left)
		this->_left = new BSNode(*(other._left));
	return *this;
}
/*
* Return true if leaf, false if not leaf
*/
bool BSNode::isLeaf()
{
	if (this->_left == NULL && this->_right == NULL)
		return true;
	return false;
}
/*
* Return the data
*/
std::string BSNode::getData() const
{
	return this->_data;
}
/*
* Return thr left
*/
BSNode* BSNode::getLeft() const
{
	return this->_left;
}
/*
* return the right
*/
BSNode* BSNode::getRight() const
{
	return this->_right;
}
/*
* The function return true if the val is in the tree, false if not
*/
bool BSNode::search(std::string val)
{
	if (this->_data == val)
		return true;
	return ((this->_right == NULL ? false : this->_right->search(val)) || (this->_left == NULL ? false : this->_left->search(val)));
}
/*
* The function return the Hight of the tree
*/
int BSNode::getHeight()
{
	int hl = 0; // hight of the left side
	int hr = 0; // hight of the right side
	if (this->_left != NULL)
		hl = 1 + this->_left->getHeight();
	if (this->_right != NULL)
		hl = 1 + this->_right->getHeight();
	if (hl > hr)
		return hl;
	else
		return hr;
}
/*
* The function return the depth
*/
int BSNode::getDepth(BSNode& root)
{
	if (this == nullptr || !root.search(this->getData()))
	{
		return -1;
	}
	return this->getCurrNodeDistFromInputNode(&root);
}
/*
* The function print the nodes- alphbet order.
*/
void BSNode::printNodes()
{
	if (this != NULL)
	{
		if (this->_left != NULL)
		{
			this->_left->printNodes();
		}
		std::cout << this->_data << " " << this->_count << std::endl;
		if (this->_right != NULL)
		{
			this->_right->printNodes();
		}
	}
}
/*
* Function return the distence.
*/
int BSNode::getCurrNodeDistFromInputNode(BSNode* node)
{
	if (node == nullptr)
	{
		return -1;
	}
	if (node->search(this->_data) == false)
	{
		return -1;
	}
	if (this->_data != node->_data && node->_left != nullptr && this->_data < node->_data)
	{
		return getCurrNodeDistFromInputNode(node->_left) + 1;
	}
	if (this->_data != node->_data && node->_right != nullptr && this->_data > node->_data)
	{
		return getCurrNodeDistFromInputNode(node->_right) + 1;
	}
	return 0;
}