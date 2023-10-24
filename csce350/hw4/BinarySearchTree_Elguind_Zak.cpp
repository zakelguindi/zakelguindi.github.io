/**
 * 1. store integers as nodes in BST
 * 2, perform insert, search, and delete functions 
 *  insertion- allow user to provide integer values. first value becomes root, user can insert any number of nodes into BST, be able to handle duplicates. 
 *  search: allow user to search for node in BST. if search key is found, return all nodes visited (path traversed) to reach search key. 
 *    if search key isn't found, return path traversed to find search key and indicate search was unsuccessful. 
 *  deletion: allow user to delete nodes from BST. delete node with no children, delete node with 1 child, delete node with 2 children. 
 * 3. display BST node with smallest value
 * 4. display BST node with largest value 
 * 5. at end of each operation display nodes of current BST 
 * 
 * */

#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
using std::stack; 
using std::max; 
using std::cin; 
using std::cout; 
using std::endl; 
using std::string; 

class Node {
  public: 
  // every node has a number, a leftChild, and a rightChild
    int number; 
    Node* leftChild; 
    Node* rightChild; 

    Node(int value) {
      //set the number of the node to its value, and leave the children as null for now
      number = value; 
      leftChild = nullptr; 
      rightChild = nullptr; 
    }

    
};

bool Search(Node* root, int value) {
  // cout << "Searching for " << value << ": "; 
  Node* thisNode = root; 
  while(thisNode != NULL) {
    cout << thisNode->number << " --> ";
    if(thisNode->number == value) {
      // cout << " - FOUND" << endl; 
      return true; 
    } else if(thisNode->number > value) {
      //on left side
      thisNode = thisNode->leftChild; 
    } else if(thisNode->number < value) {
      thisNode = thisNode->rightChild; 
    } else {
    }
  }
  cout << "Number not found" << endl; 
  return false; 
};

bool PrintSearch(Node* root, int value) {
  cout << "Searching for " << value <<": "; 
  return Search(root, value); 
}


Node* insert(Node* root, int key) {
  // remove duplicates 
  //if search(key) == true, don't insert
  bool exists = Search(root, key); 
  if(!exists) {
    if(root == nullptr || root->number < 0) {
      // cout << "here" << endl; 
      root = new Node(key); 
      // cout << "new null root: " << root->number << endl; 
      // return nullptr; 
    }
    if(root->number > key) {
      //there's a free leftchild where it belongs 
      //if leftchild is null, fill it there, otherwise, move to leftchildl
      if(root->leftChild == nullptr) {
        root->leftChild = new Node(key); 
        return root->leftChild; 
      } else {
        insert(root->leftChild, key); 
      }
    } else if(root->number < key) {
      if(root->rightChild == nullptr) {
        root->rightChild = new Node(key); 
        return root->rightChild;
      } else {
        insert(root->rightChild, key); 
      }
    } else {
      //key is the root number 
      return root; 
    }
  } else {
    cout << "Node " << key << " Is a duplicate note. Cannot insert Node " << key << " again." << endl; 
  }
  return nullptr; 
};




void PrintNodes(Node* root) {
  //print everything to the left, print the root, print everything to the right 
  if(root == nullptr) {
    //reached end 
    return; 
  } 

  PrintNodes(root->leftChild);
  cout << root->number << " "; 
  PrintNodes(root->rightChild); 
};

void printNodes(Node* root) {
  cout << "BST Nodes Are: "; 
  PrintNodes(root);
};

void printStack(stack<int> stack) {
  while(!stack.empty()) {
    cout << stack.top() << ", "; 
    stack.pop(); 
  }
  cout << "STACK PRINTED: " << endl; 
};

stack<int> fillStack() {
  stack<int> stack; 
  int rootVal; 
  cout << "Enter the root value" << endl; 
  cin >> rootVal;
  stack.push(rootVal); 

  bool addMore = true; 
  // int i=1;
  int value; 
  while(addMore == true) {
    cout << "Enter the next number you'd like to add. if done, enter any negative number" << endl; 
    cin >> value; 
    if(value <= 0) {
      addMore = false; 
    } else {
    stack.push(value); 
    }

  }
  // printStack(stack); 
  return stack; 
};

Node* findMin(Node* root) {
  // left-most value
  // cout << "ROOT: " << root->number << endl; 
  if(root == nullptr) {
    return nullptr; 
  } else if(root->leftChild == nullptr) {
    //left-most value
    // cout << "left most value" << root->number << endl; 
    // cout << "mem add: " << root << endl; 
    return root; 
  } else {
    findMin(root->leftChild); 
    // return root; 
  }
  return findMin(root->leftChild); 
};

Node* findMax(Node* root) {
  //find right-most value
  if(root == nullptr) {
    return nullptr; 
  } else if(root->rightChild == nullptr) {
    //right-most child is the root
    return root; 
  } else {
    findMax(root->rightChild); 
  }
  return findMax(root->rightChild); 
};


Node* Remove(Node* root, int key) {
  if(root == nullptr) {
    //base case
    return nullptr; 
  } else if(key < root->number) {
    //key is less than root 
    root->leftChild = Remove(root->leftChild, key); 
  } else if(key > root->number) {
    //key is greater than root- it's on right 
    root->rightChild = Remove(root->rightChild, key); 
  } else {
    //it's been found 
    //case 0: no children- just delete root 
    //case 1: one child- find the null child and delete the other
    //case 2: two children, find min, replace root with min, restructure
    if(root->rightChild == nullptr) {
      //right is null, 
      return root->leftChild;
    } else if(root->leftChild == nullptr) {
      //right is populated
      return root->rightChild; 
    }

    //means node has two children 
    Node* n = findMin(root->rightChild); //find min in rightchild
    root->number = n->number; //sets root as min 
    root->rightChild = Remove(root->rightChild, n->number); //removes duplicate
  }
  return root; 
};


void RemoveThis(Node* root, int key) {
  bool exists = Search(root, key); 
  if(exists) {
    root = Remove(root, key);
  } else {
    cout << "Cannot remove a node that doesn't exist" << endl; 
  }
  // root = Remove(root, key); 
};


int main() {

  cout << "TEST 1: Inserting nodes into the BST in the following order: 5, 3, 1, 4, 7, 8" << endl; 
  stack<int> newStack; 
  stack<int> stack; 

  // stack works 
  Node* root = nullptr;
  stack = fillStack(); 

  while(!stack.empty()) {
    //swapping them 
    newStack.push(stack.top()); 
    stack.pop(); 
  }

  //must set base case 
  root = new Node(newStack.top()); 

  while(!newStack.empty()) {
    insert(root, newStack.top()); 
    newStack.pop(); 
      // stack.pop(); 

  }
  printNodes(root); 

  cout << endl << endl; 
  cout << "Delete node 4: " << endl; 
  cout << "Node 4 has been deleted" << endl; 
  RemoveThis(root, 4);
  printNodes(root); 
  cout << endl; 

  cout << endl; 
  cout << "Insert node 2: " << endl; 
  cout << "Node 2 has been inserted " << endl; 
  insert(root, 2); 
  printNodes(root); 
  cout << endl << endl; 

  cout << "Insert node 7" << endl; 
  // cout << "Node 7 has been inserted" << endl; 
  insert(root, 7); 
  printNodes(root); 
  cout << endl << endl; 

  cout << "Inserting node 6 " << endl; 
  insert(root, 6); 
  cout << "Node 6 has been inserted" << endl; 
  printNodes(root); 
  cout << endl << endl; 

  cout << "Deleting node 7" << endl; 
  cout << "Node 7 has been deleted" << endl; 
  RemoveThis(root, 7); 
  printNodes(root); 
  cout << endl << endl; 

  cout << "BST Node with the smallest value" << endl; 
  // Node* min = findMin(root); 
  // int min = findMinNumber(root); 
  cout << "Node: " << findMin(root)->number << endl; 
  printNodes(root); 
  cout << endl << endl ; 

  cout << "Search for Node 9" << endl; 
  PrintSearch(root, 9); 
  printNodes(root); 
  cout << endl << endl; 

  cout << "BST Node with highest value" << endl; 
  cout << "Node: " << findMax(root)->number << endl; 
  printNodes(root); 

  return 0; 

}

