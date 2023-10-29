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
#include<queue>
using std::queue; 
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
      cout << " - NUMBER FOUND" << endl; 
      return true; 
    } else if(thisNode->number > value) {
      //on left side
      thisNode = thisNode->leftChild; 
    } else if(thisNode->number < value) {
      thisNode = thisNode->rightChild; 
    } else {
      // cout << "Here" << endl; 
      return false; 
    }
  }
  // cout << "Number not found" << endl; 
  return false; 
};

bool PrintSearch(Node* root, int value) {
  cout << "Searching for " << value <<": "; 
  if(Search(root, value) == true) {
    return true; 
  } else {
    cout << "Number not found" << endl; 
    return false; 
  }
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

int homeMessage() {
  int number = 0; 
  cout << "Press 1 to insert a node" << endl << "Press 2 to remove a node" << endl << "Press 3 to Search for a node" << endl << "Press 4 to find the minimum value" << endl << "Press 5 to find the maximum value" << endl << "Press 9 to stop" << endl; 
  cin >> number; 
  return number; 
};

int main() {
  
  int rootVal = 0; 
  cout << "Enter the first node of your tree" << endl; 
  cin >> rootVal; 
  Node* root = new Node(rootVal); 

  bool quit = false; 
  while(!quit) {
    int input = homeMessage(); 
    // cout << "NUMBER: " << number; 
    if(input == 1) {
      //make method that will convert number to node 
      int insertedNum = -1; 
      cout << "What number do you want to input " << endl; 
      cin >> insertedNum; 
      insert(root, insertedNum); 
    } else if(input == 2) {
      if(root->number >= 0) {
        int insertedNum = -1; 
        cout << "What number do you want to remove " << endl; 
        cin >> insertedNum; 
        root = Remove(root, insertedNum); 
      }
    } else if(input == 3) {
        int insertedNum = -1; 
        cout << "What number do you want to Search for " << endl; 
        cin >> insertedNum; 
        // root = Remove(root, insertedNum); 
        PrintSearch(root, insertedNum); 
    } else if(input == 4) {
        cout << "Minimum Value is: " << findMin(root)->number << endl; 
      } else if(input == 5) {
        cout << "Maximum Value is: " << findMax(root)->number << endl; 
      } else if(input == 9) {
        cout << "Final Tree: "; 
        printNodes(root); 
        quit = true; 
      } else {
        cout << "Enter a valid value" << endl; 
      }
      printNodes(root);
      cout << endl; 
    }

  return 0; 
};