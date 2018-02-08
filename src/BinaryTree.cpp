/*
 * BinaryTree.cpp
 *
 *  Created on: 7 de fev de 2018
 *      Author: caio
 */

#include <stdlib.h>
#include "BinaryTree.h"

BinaryTree::BinaryTree()
{
  this->root = NULL;
  this->sFile.assign("BinaryTree.txt");
}

BinaryTree::~BinaryTree()
{
  if (this->root != NULL) {
    delete this->root;
  }
}

void BinaryTree::Insert(mydata d, Node *pNode)
{

  if ( d <= pNode->getData() ) {
    if (pNode->getLeft() != NULL) {
      Insert(d, pNode->getLeft());
    } else {
      pNode->AddLeftNode( new Node(d) );
    }
  }
  else if ( d > pNode->getData() )
  {
    if (pNode->getRight() != NULL) {
      Insert(d, pNode->getRight());
    } else {
      pNode->AddRightNode( new Node(d) );
    }
  }

}

void BinaryTree::Insert(mydata d)
{

  if ( this->root != NULL ) {
    Insert(d, this->root);
  }
  else
  {
    this->root = new Node(d);
    this->root->AddLeftNode(NULL);
    this->root->AddRightNode(NULL);
  }

}

bool BinaryTree::Search(mydata d, Node *pNode)
{
  if (pNode != NULL)
  {
    if (d == pNode->getData())
    {
      return true;
    } else if (d < pNode->getData())
    {
      return Search(d, pNode->getLeft());
    } else
    {
      return Search(d, pNode->getRight());
    }
  } else
  {
    return false;
  }
}

bool BinaryTree::Search(mydata d)
{
  return Search(d, this->root);
}

int BinaryTree::Height(Node *pNode){
  if (pNode == NULL) {
    return -1;
  }

  return 1 + std::max( Height(pNode->getRight()), Height(pNode->getLeft()) );
}

int BinaryTree::Height(void){
  return Height(this->root);
}

mydata BinaryTree::MaxValue(Node *pNode)
{
  if (pNode->getRight() != NULL) {
    return this->MaxValue(pNode->getRight());
  }

  return pNode->getData();
}

mydata BinaryTree::MaxValue(void)
{
  return this->MaxValue(root);
}

mydata BinaryTree::MinValue(Node *pNode)
{
  if (pNode->getLeft() != NULL) {
    return this->MinValue(pNode->getLeft());
  }

  return pNode->getData();
}

mydata BinaryTree::MinValue(void)
{
  return this->MinValue(root);
}

void BinaryTree::Delete(mydata d, Node *pNode)
{
  if (pNode == NULL) {
    return;
  }

  if (d < pNode->getData())
  {
    this->Delete(d, pNode->getLeft());
  } else if (d > pNode->getData())
  {
    this->Delete(d, pNode->getRight());
  } else
  {

    /* Left Child do not exist, just bring right to top: */
    if (pNode->getLeft() == NULL)
    {
      /* TODO delete pNode before assign a new pointer (Memory Leak) */
      pNode = pNode->getRight();
    } else if (pNode->getRight() == NULL)
    {
      /* TODO delete pNode before assign a new pointer (Memory Leak) */
      pNode = pNode->getLeft();
    } else
    {
      /* TODO */
//      Node *pTemp = MinValue(pNode);
//
//      pNode->SetData(pTemp->getData());
//
//      this->Delete(pTemp->getData(), pNode->getRight());
    }

  }
}

void BinaryTree::Delete(mydata d)
{
  this->Delete(d, root);
}

void BinaryTree::PrintTree()
{
  PrintTree(this->root);
  std::cout << std::endl;
}

void BinaryTree::PrintTree(Node *pNode)
{
  if (pNode != NULL) {
    PrintTree(pNode->getLeft());
    PrintTree(pNode->getRight());
    std::cout << pNode->getData();
    if (pNode != root) {
      std::cout << ",";
    }
  }
}

void BinaryTree::SaveBinaryTree(Node *pNode, std::ofstream *file)
{
  if (NULL == pNode) {
    *file << "#" << std::endl;
  }
  else
  {
    *file << pNode->getData() << std::endl;
    this->SaveBinaryTree(pNode->getLeft(), file);
    this->SaveBinaryTree(pNode->getRight(), file);
  }
}
void BinaryTree::LoadBinaryTree(Node *pNode, std::ifstream *file)
{
  std::string sNum;

  if (root != NULL) {
    delete root;
  }

  while( std::getline(*file, sNum) )
  {
    if (sNum.compare("#") != 0) {
      this->Insert(atoi(sNum.c_str()));
    }
  }
}

void BinaryTree::SaveBinaryTree(void)
{
  std::ofstream file;
  file.open(this->sFile.c_str());
  this->SaveBinaryTree(root, &file);
  file.close();
}

void BinaryTree::LoadBinaryTree(void)
{
  std::ifstream file;
  file.open(this->sFile.c_str());
  this->LoadBinaryTree(root, &file);
  file.close();
}
