/*
 * Name: Nicholas Allaire
 * Date: 4/7/16
 * Assignment: Programming Assignment 1
 * Overview: The nodes for the binary search tree. Each node stores the
 * parent, left child, right child, and data value associated with it.
 */
#ifndef BSTNODE_HPP
#define BSTNODE_HPP
#include <iostream>
#include <iomanip>

template<typename Data>
class BSTNode {

public:

  /** Constructor.  Initialize a BSTNode with the given Data item,
   *  no parent, and no children.
   */
  BSTNode(const Data & d) : data(d) {
    left = right = parent = 0;
  }

  BSTNode<Data>* left;
  BSTNode<Data>* right;
  BSTNode<Data>* parent;
  Data const data;   // the const Data in this node.

  /** Return the successor of this BSTNode in a BST, or 0 if none.
   ** PRECONDITION: this BSTNode is a node in a BST.
   ** POSTCONDITION:  the BST is unchanged.
   ** RETURNS: the BSTNode that is the successor of this BSTNode,
   ** or 0 if there is none.
   */ // TODO
  BSTNode<Data>* successor() {
    BSTNode<Data>* tempNode;
    tempNode = this;
    if (tempNode->right != nullptr) { // has right child
      tempNode = tempNode->right;
      while (tempNode->left != nullptr) {
        tempNode = tempNode->left;
      }
      return tempNode;
      // has no right child but has a left child
    } else if (tempNode->right == nullptr && tempNode->left != nullptr) { 
        while (tempNode->parent->data < tempNode->data) {
          tempNode = tempNode->parent;
          if (tempNode->parent == nullptr) {
            return 0;
          }
      }
      return tempNode->parent;
    } else if (tempNode->left == nullptr && tempNode->right == nullptr 
               && tempNode->data < tempNode->parent->data) { //node is left leaf
        return tempNode->parent;
    } else if (tempNode->left == nullptr && tempNode->right == nullptr 
               && tempNode->parent->data < tempNode->data) { //node is right leaf
        while (tempNode->parent->data < tempNode->data) {
          tempNode = tempNode->parent;
          if (tempNode->parent == nullptr)
            return 0;
        }
        return tempNode->parent;
    }
    return 0;
  }

}; 

/** Overload operator<< to print a BSTNode's fields to an ostream. */
template <typename Data>
std::ostream & operator<<(std::ostream& stm, const BSTNode<Data> & n) {
  stm << '[';
  stm << std::setw(10) << &n;                 // address of the BSTNode
  stm << "; p:" << std::setw(10) << n.parent; // address of its parent
  stm << "; l:" << std::setw(10) << n.left;   // address of its left child
  stm << "; r:" << std::setw(10) << n.right;  // address of its right child
  stm << "; d:" << n.data;                    // its data field
  stm << ']';
  return stm;
}

#endif // BSTNODE_HPP
