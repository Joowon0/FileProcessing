#include "b+Tree.h"
#include <iostream>

BPlusTree::BPlusTree() : rootNode(new TerminalNode())  {}
Node::Node() : allocatedBlockNumber(blockNumCounter++) {}
int Node::blockNumCounter = 1000000000;
//InternalNode::InternalNode() : branchSize(6), scoreSize(5), storedRecordNumber(0) {}
//TerminalNode::TerminalNode() : size(5), storedRecordNumber(0), nextTerminalNode(NULL) {}

InternalNode::InternalNode() : branchSize(512), scoreSize(511), storedRecordNumber(0) {}
TerminalNode::TerminalNode() : size(511), storedRecordNumber(0), nextTerminalNode(NULL) {}

bool BPlusTree::deleteTree() {
  rootNode->deleteTree();
  delete[] rootNode;
  //  rootNode = new TerminalNode();
  return true;
}

bool InternalNode::deleteTree() {
  for (int i = 0; i < storedRecordNumber; i++) {
    branchs[i]->deleteTree();
    delete[] branchs[i];
  }
  return true;
}

bool TerminalNode::deleteTree() {
  return true;
}
