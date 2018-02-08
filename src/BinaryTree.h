/*
 * BinaryTree.h
 *
 *  Created on: 7 de fev de 2018
 *      Author: caio
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_

#include <cstddef>
#include <iostream>
#include <fstream>

typedef int mydata;

class Node {
private:
  Node *left;
  mydata data;
  Node *right;
public:
  Node(int data){
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  }

  virtual ~Node(){
//    std::cout << "Bye Bye " << this->data << std::endl;
    if (this->left != NULL) {
      delete this->left;
    }
    if (this->right != NULL) {
      delete this->right;
    }
  }

  void AddLeftNode(Node *pNode)
  {
    this->left = pNode;
  }

  void AddRightNode(Node *pNode)
  {
    this->right = pNode;
  }

  void SetData(mydata d){
    this->data = d;
  }

  mydata getData()
  {
    return data;
  }

  Node* getLeft()
  {
    return left;
  }

  Node* getRight()
  {
    return right;
  }
};

class BinaryTree {

private:
  Node *root;
  std::string sFile;

  int Height(Node *pNode);
  mydata MaxValue(Node *pNode);
  mydata MinValue(Node *pNode);
  void Delete(mydata d, Node *pNode);
  bool Search(mydata d, Node *pNode);
  void Insert(mydata d, Node *pNode);

  void SaveBinaryTree(Node *pNode, std::ofstream *file);
  void LoadBinaryTree(Node *pNode, std::ifstream *file);
  void PrintTree(Node *pNode);
public:
  BinaryTree();
  virtual ~BinaryTree();

  int Height(void);
  mydata MaxValue(void);
  mydata MinValue(void);
  void Delete(mydata d);
  bool Search(mydata d);
  void Insert(mydata d);

  void SaveBinaryTree(void);
  void LoadBinaryTree(void);
  void PrintTree();
};

#endif /* BINARYTREE_H_ */
