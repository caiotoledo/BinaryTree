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
#include <ctime>
#include <vector>

#include "BinaryTree.h"

static const uint32_t SIZE_TREE = 1000000;

class Clock
{
protected:
	clock_t start_s;

public:
	Clock()
	{
		start_s = clock();
	}

	void StartClock()
	{
		start_s = clock();
	}

	double DiffClock_ms()
	{
		return (double)((clock() - start_s) / double(CLOCKS_PER_SEC)) * 1000;
	}
};

void printSearch(BinaryTree *t, mydata d){

	Clock clk;

  std::cout << "Number " << d;
  if ( !t->Search(d) ) {
    std::cout << " NOT";
  }
  std::cout << " found!" << std::endl;

	std::cout << "Search Time: " << clk.DiffClock_ms() << " ms" << std::endl;
}

int main() {
	std::cout << "Hello World" << std::endl << std::endl; // prints Hello World

	BinaryTree tree;

	Clock clk;

  for (int i = 0; i < SIZE_TREE; ++i) {
    tree.Insert(rand() % SIZE_TREE);
  }

	std::cout << SIZE_TREE << " Data Insertions in " << clk.DiffClock_ms() << " ms." << std::endl;

  std::cout << std::endl;
  printSearch(&tree, rand() % SIZE_TREE);

  std::cout << std::endl << "Binary Tree Infos:" << std::endl;
  std::cout << "Min Value " << tree.MinValue() << std::endl;
  std::cout << "Max Value " << tree.MaxValue() << std::endl;
  std::cout << "Height " << tree.Height() << std::endl;

  tree.SaveBinaryTree();

  std::cout << std::endl << "Bye Bye World" << std::endl;
	return 0;
}
