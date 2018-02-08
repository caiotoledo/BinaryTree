//============================================================================
// Name        : BinaryTree.cpp
// Author      : Caio Toledo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <climits>
#include <cstdlib>
#include <vector>

#include "BinaryTree.h"

#define SIZE_TREE   1000000

int main() {
	std::cout << "Hello World" << std::endl << std::endl; // prints Hello World

	BinaryTree tree;

  for (int i = 0; i < SIZE_TREE; ++i) {
    tree.Insert(rand() % SIZE_TREE);
  }

  tree.SaveBinaryTree();
	tree.LoadBinaryTree();

  std::cout << "Min Value " << tree.MinValue() << std::endl;
  std::cout << "Max Value " << tree.MaxValue() << std::endl;
  std::cout << "Height " << tree.Height() << std::endl;

  int start_s=clock();

	std::cout << tree.Search(18) << std::endl;

  int stop_s=clock();
  std::cout << "Search Time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << " ms" << std::endl;

  tree.SaveBinaryTree();

  std::cout << std::endl << "Bye Bye World" << std::endl;
	return 0;
}
