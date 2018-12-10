#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <queue>
#include <unordered_set>
using namespace std;

struct Vertex {
  enum Status { None, Processed, Finished }; // dfs; with this enum, bfs unordered_set visited not needed
  Status status = None;
  int val;
  list<Vertex*> neighbors;
  Vertex* parent = nullptr; // bfs path tracking
  
  Vertex(int val) : val(val){}
  bool operator=(const Vertex* rhs) const {return val == rhs->val;}
};

Vertex* V0 = new Vertex(0);
Vertex* v1 = new Vertex(1);
Vertex* v2 = new Vertex(2);
Vertex* v3 = new Vertex(3);
Vertex* v4 = new Vertex(4);
Vertex* v5 = new Vertex(5);
Vertex* v6 = new Vertex(6);
Vertex* v7 = new Vertex(7);
Vertex* v8 = new Vertex(8);
Vertex* v9 = new Vertex(9);
Vertex* v10 = new Vertex(10);
Vertex* v11 = new Vertex(11);
Vertex* v12 = new Vertex(12);
Vertex* v13 = new Vertex(13);
Vertex* v14 = new Vertex(14);
Vertex* v15 = new Vertex(15);


static void createUndirectedGraph(){
  v1->neighbors = {v6, v2, v3};
  v2->neighbors = {v1, v3, v4, v11};
  v3->neighbors = {v1, v2, v4, v6};
  v4->neighbors = {v3, v5, v2};
  v5->neighbors = {v6, v8, v4};
  v6->neighbors = {v1, v7};
  v7->neighbors = {v6};
  v8->neighbors = {v5, v10, v9};
  v9->neighbors = {v8, v10};
  v10->neighbors = {v8, v9};
  v11->neighbors = {v2};
  v12->neighbors = {v13};
  v13->neighbors = {v12, v14, v15};
  v14->neighbors = {v13};
  v15->neighbors = {v13};
}

static void createDirectedGraphWithCycle() {
  v1->neighbors = {v2, v4};
  v2->neighbors = {v5};
  v3->neighbors = {v6};
  v4->neighbors = {v2};
  v5->neighbors = {v4, v3};
  v6->neighbors = {v6};
}

static void createDirectedAcyclicGraph(){
  v1->neighbors = {v2};
  v3->neighbors = {v2, v4};
  v4->neighbors = {v5};
  v5->neighbors = {v6};
  v7->neighbors = {v4, v8};
  v8->neighbors = {v6};
}

void visitVertexBFS(Vertex* from, Vertex* to, unordered_set<Vertex*>& visited, queue<Vertex*>& q) {
  to->parent = from;
  visited.insert(to);
  q.push(to);
  cout << to->val << " ";
}

void BFS(Vertex* src) {
  unordered_set<Vertex*> visited;
  queue<Vertex*> q;
  visitVertexBFS(nullptr, src, visited, q);
  while(!q.empty()) {
    Vertex* from = q.front();
    q.pop();
    for (auto neighbor : from->neighbors){
      if (visited.find(neighbor) == visited.end())
        visitVertexBFS(from, neighbor, visited, q);
    }
  }
}

list<Vertex*> createPathFrom(Vertex* dst) {
  list<Vertex*> thePath;
  Vertex* dummy = dst;
  while(dummy != nullptr) {
    thePath.push_front(dummy);
    dummy = dummy->parent;
  }
  return thePath;
}

list<Vertex*> findShortestPathBFS(Vertex* src, Vertex* dst) {
  unordered_set<Vertex*> visited;
  queue<Vertex*> q;
  visitVertexBFS(nullptr, src, visited, q);
  while(!q.empty()) {
    Vertex* from = q.front();
    q.pop();
    for (auto neighbor : from->neighbors) {
      if (visited.find(neighbor) == visited.end()){
        if (neighbor == dst) {
          neighbor->parent = from;
          return createPathFrom(neighbor);
        } else {
          visitVertexBFS(from, neighbor, visited, q);
        }
      }
    }
  }
  return {};
}

void visitVertexDFS(Vertex* v) {
  v->status = Vertex::Processed;
  cout << v->val << " ";
}
void DFSVisit(Vertex* src) {
  visitVertexDFS(src);
  for (auto neighbor : src->neighbors){
    if (neighbor->status == Vertex::None)
      DFSVisit(neighbor);
  }
  src->status = Vertex::Finished;
}

void DFS() {
  list<Vertex*> temp = {v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15};
  for (auto v : temp) {
    if (v->status == Vertex::None)
      DFSVisit(v);
  }
}

bool cycleDetection(Vertex* src){
  src->status = Vertex::Processed;
  for (auto neighbor : src->neighbors){
    if (neighbor->status == Vertex::Processed)
      return true;
    else
      if (cycleDetection(neighbor))
        return true;
  }
  src->status = Vertex::Finished;
  return false;
}

int main(){
  //createUndirectedGraph();
  //createDirectedGraphWithCycle();
  createDirectedAcyclicGraph();
  //BFS(v5);
//  auto thePath = findShortestPathBFS(v10, v11);
//  for (auto e : thePath)
//    cout << e->val << " ";
//  cout << endl;
  //DFS();
  cout << cycleDetection(v1) << endl;
  return 0;
}
