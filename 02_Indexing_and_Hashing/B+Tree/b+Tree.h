#include "../Index_Hashing/HashTable.h"

#ifndef BPLUSTREE_H
#define BPLUSTREE_H

class BPlusTree;
class Node;
class InternalNode;
class TerminalNode;

class BPlusTree{
protected:
  Node* rootNode;
  
public:
  BPlusTree();

  bool storeTree();
  bool loadTree();
  
  bool insert(float score, int blckN);
  TerminalNode* findKthTerminal(int k);
  // return first match terminal node
  Node* searchFirstMatch(float scoreLowerBound);
  void print();
  void printWithBlockNum(int*hashTable);
};

class Node {
 public:
  Node();
  int   allocatedBlockNumber;
  static  int   blockNumCounter;
  virtual bool  ifTerminal() = 0;
  virtual Node* searchFirstMatch(float scoreLowerBound) = 0;
  virtual Node* insert(float score, int blckN) = 0;
  virtual int   minVal() = 0;
  virtual int   maxVal() = 0;
  virtual void  print(int)  = 0;
  virtual void  printWithBlockNum(int indent, int* hashTable) = 0;
};


class InternalNode: public Node {
  friend class BPlusTree;
  
private:
  const int branchSize; //512
  const int scoreSize;  //511

  // contents of the block
  int   storedRecordNumber;
  Node* branchs[512];
  float scoreDeli[511];

protected:
  //const int allocatedBlockNumber;
  
  InternalNode();
  bool  ifTerminal() {return false;}
  int   minVal() {return scoreDeli[0];}
  int   maxVal() {return scoreDeli[storedRecordNumber-2];}

  // functions to help internalNode::insert()
  bool insertABranch(int insertIndex, Node* newVal);
  InternalNode* overflowSplit(bool ifNewAtThis);
  
  // return first match terminal node
  Node* searchFirstMatch(float scoreLowerBound);
  Node* insert(float score, int blckN);
  
public:
  void print(int indent);
  void printWithBlockNum(int indent, int* hashTable);
};


class TerminalNode: public Node {
  friend class BPlusTree;
  friend class InternalNode;
  
private:
  const int size;
  

  // contents of the block
  int storedRecordNumber;
  TerminalNode* nextTerminalNode;
  float scores[511];
  int   blockNum[511]; // this should be changed into studentNumber

  // functions to help Terminal::search()
  int  cntTillUpper(float scoreUpperBound);
  bool cpyMatchRecords(int* blockNums, int startIndex, int cpyLeft);
  
protected:
  //const int allocatedBlockNumber;
  
  TerminalNode();
  bool  ifTerminal() {return true;}
  int   minVal() {return scores[0];}
  int   maxVal() {return scores[storedRecordNumber-1];}

  Node* searchFirstMatch(float scoreLowerBound);
  int*  search(float scoreLowerBound, float scoreUpperBound);
  Node* insert(float score, int blckN);

public:
  void print(int indent);
  void printWithBlockNum(int indent, int* hashTable);
};

#endif
