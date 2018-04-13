/*
 * Name: Nicholas Allaire
 * Date: 4/7/16
 * Assignment: Programming Assignment 1
 * Overview: A basic binary search tree(BST) class that implements the insert(),
 * find(), inorder(), deleteAll() and many other basic methods that allow you
 * to use the BST.
 */
#ifndef BST_HPP
#define BST_HPP
#include "BSTNode.hpp"
#include "BSTIterator.hpp"
#include <iostream>

template<typename Data>
class BST {

protected:

  /** Pointer to the root of this BST, or 0 if the BST is empty */
  BSTNode<Data>* root;

  /** Number of Data items stored in this BST. */
  unsigned int isize;

  /** Height of this BST. */
  unsigned int iheight;
  
public:

  //BSTNode<Data>* root;
  /** define iterator as an aliased typename for BSTIterator<Data>. */
  typedef BSTIterator<Data> iterator;

  /** Default constructor.
      Initialize an empty BST.
   */
  BST() : root(nullptr), isize(0), iheight(0) {  }


  /** Default destructor.
      Delete every node in this BST.
   */ // TODO
  virtual ~BST() {
    deleteAll(root);  
  }

  /** Given a reference to a Data item, insert a copy of it in this BST.
   *  Return  true if the item was added to this BST
   *  as a result of this call to insert,
   *  false if an item equal to this one was already in this BST.
   *  Note: This function should use only the '<' operator when comparing
   *  Data items. (should not use ==, >, <=, >=)  For the reasoning
   *  behind this, see the assignment writeup.
   */ // TODO
  virtual bool insert(const Data& item) {
    if (root == nullptr) {    // If tree is empty, make it root
      root = new BSTNode<Data>(item);
      isize = 1;
      iheight = 0;
      return true;
    } else {  // tree is not empty
        BSTNode<Data>* tempNode;
        BSTNode<Data>* insertingNode = new BSTNode<Data>(item);
        tempNode = root;
        bool found = false;
        int tempHeight = 0;
          
        while (!found) {
          if (insertingNode->data < tempNode->data) {
            if (tempNode->left == nullptr) {  // insert to left child
              tempNode->left = insertingNode;
              insertingNode->parent = tempNode;
              isize++;
              found = true;
            } else {  // left child is assigned
                tempNode = tempNode->left;
            }
          } else if (tempNode->data < insertingNode->data) {
              if (tempNode->right == nullptr) { // insert to right child
                tempNode->right = insertingNode;
                insertingNode->parent = tempNode;
                isize++;
                found = true;
              } else {  // right child is assigned
                  tempNode = tempNode->right;
              }
          } else { // already in tree
              found = true;
              return false;
          }
          tempHeight++;
        }
        if (tempHeight > iheight)
        iheight = tempHeight;
          
    }
    return true;
  }


  /** Find a Data item in the BST.
   *  Return an iterator pointing to the item, or pointing past
   *  the last node in the BST if not found.
   *  Note: This function should use only the '<' operator when comparing
   *  Data items. (should not use ==, >, <=, >=).  For the reasoning
   *  behind this, see the assignment writeup.
   */ // TODO
  iterator find(const Data& item) const {
    BSTNode<Data>* tempNode;
    tempNode = root;
    bool found = false;
    while (!found) {
      if (item < tempNode->data) { // go to left child
        if (tempNode->left != nullptr) {
          tempNode = tempNode->left;
        } else { // no more nodes to check
            break;
        }
      } else if (tempNode->data < item) { // go to right child
          if (tempNode->right != nullptr) {
            tempNode = tempNode->right;
          } else { // no more nodes to check
              break;
          }
      } else { // found item
          auto searchIterator = BSTIterator<Data>(tempNode);
          return searchIterator;
      }
    }
    auto searchIterator = BSTIterator<Data>(0); // item not found, assign to null
    return searchIterator;
  }

  
  /** Return the number of items currently in the BST.
   */ // TODO
  unsigned int size() const {
    return isize;
  }
  
  /** Return the height of the BST.
   */ // TODO
  unsigned int height() const {
    return iheight;
  }


  /** Return true if the BST is empty, else false.
   */ // TODO
  bool empty() const {
    if (isize == 0)
      return true;
    
    return false;
  }

  /** Return an iterator pointing to the first item in the BST (not the root).
   */ // TODO
  iterator begin() const {
    BSTNode<Data>* tempNode;
    tempNode = first(root);
    auto firstIterator = BSTIterator<Data>(tempNode);
    return firstIterator;
  }

  /** Return an iterator pointing past the last item in the BST.
   */
  iterator end() const {
    return typename BST<Data>::iterator(0);
  }

  /** Perform an inorder traversal of this BST.
   */
  void inorder() const {
    inorder(root);
  }


private:

  /** Recursive inorder traversal 'helper' function */

  /** Inorder traverse BST, print out the data of each node in ascending order.
      Implementing inorder and deleteAll base on the pseudo code is an easy way to get started.
   */ // TODO
  void inorder(BSTNode<Data>* n) const {
    if (n == nullptr)
      return;
    inorder(n->left);
    std::cout << n->data << "\n";
    inorder(n->right);
  }

  /** Find the first element of the BST
   */ 
  static BSTNode<Data>* first(BSTNode<Data>* root) {
    if(root == 0) return 0;
    while(root->left != 0) root = root->left;
    return root;
  }

  /** do a postorder traversal, deleting nodes
   */ // TODO
  static void deleteAll(BSTNode<Data>* n) {
    if (n == nullptr)
      return;
    deleteAll(n->left);
    deleteAll(n->right);
    delete n;
  }


 };


#endif //BST_HPP
