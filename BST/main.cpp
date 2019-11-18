#include <assert.h>
#include <stdlib.h>
#include <iostream>
#include "bst.cpp"
#include "bst.h"

int main(int argc, char* argv[]) {
  using namespace pd;

  BSTNode* root = nullptr;

  root = Insert(root, 15);
  root = Insert(root, 10);
  root = Insert(root, 12);
  root = Insert(root, 8);
  root = Insert(root, 9);
  root = Insert(root, 5);
  root = Insert(root, 7);
  root = Insert(root, 23);
  root = Insert(root, 16);
  root = Insert(root, 44);
  root = Insert(root, 2);
  root = Insert(root, 32);

  int min = GetMin(root);
  int max = GetMax(root);
  int height = GetHeight(root);

  std::cout << "Min: " << min << std::endl;
  assert(min == 2);
  std::cout << "Max: " << max << std::endl;
  assert(max == 44);
  std::cout << "Height: " << height << std::endl;
  assert(height == 5);

  std::cout << "Tree items (breadth-first): ";
  PrintBFS(root);
  std::cout << std::endl;

  std::cout << "Tree items (in order): ";
  PrintInOrder(root);
  std::cout << std::endl;

  std::cout << "Is a binary search tree: " << IsBinarySearchTree(root)
            << std::endl;
  assert(IsBinarySearchTree(root));

  return EXIT_SUCCESS;
}