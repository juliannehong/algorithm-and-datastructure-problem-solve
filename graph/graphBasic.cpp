#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <queue>
using namespace std;

struct Node {
  int val;
  list<Node*> connections;
  Node(int val):val(val){}
};


Node* n0 = new Node(0);
Node* n1 = new Node(1);
Node* n2 = new Node(2);
Node* n3 = new Node(3);
Node* n4 = new Node(4);
Node* n5 = new Node(5);
Node* n6 = new Node(6);
Node* n7 = new Node(7);
Node* n8 = new Node(8);
Node* n9 = new Node(9);
Node* n10 = new Node(10);
Node* n11 = new Node(11);
Node* n12 = new Node(12);
Node* n13 = new Node(13);
Node* n14 = new Node(14);
Node* n15 = new Node(15);
array<bool, 16> visited = {false};

void resetVisited(){
  for (auto n : visited)
    n = false;
}

void visit(Node* n){
  cout << n->val << " ";
  visited[n->val] = true;
}

static void createGraph(){
  n1->connections = {n6, n2, n3};
  n2->connections = {n1, n3, n4, n11};
  n3->connections = {n1, n2, n4, n6};
  n4->connections = {n3, n5, n2};
  n5->connections = {n6, n8, n4};
  n6->connections = {n1, n7};
  n7->connections = {n6};
  n8->connections = {n5, n10, n9};
  n9->connections = {n8, n10};
  n10->connections = {n8, n9};
  n11->connections = {n2};
  n12->connections = {n13};
  n13->connections = {n12, n14, n15};
  n14->connections = {n13};
  n15->connections = {n13};
}

void recursiveDFS(Node* node){
  visit(node);
  for (auto connection : node->connections){
    if(!visited[connection->val])
      recursiveDFS(connection);
  }
}

void BFS(Node* n){
  queue<Node*> q;
  q.push(n);
  while (!q.empty()){
    Node* curr = q.front();
    q.pop();
    cout << curr->val << " ";
    //visit(curr);
    for (auto connection : curr->connections){
      if (!visited[connection->val]) {
        q.push(connection);
        visited[connection->val] = true;
      }
    }
  }
}

int main(){
  createGraph();
  BFS(n3);
  cout << endl;
  return 0;
}

