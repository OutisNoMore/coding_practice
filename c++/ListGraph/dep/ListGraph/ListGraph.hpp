#ifndef LISTGRAPH_H 
#define LISTGRAPH_H

#include <string>

#include "LinkedList/LinkedList.hpp"
#include "PriorityQueue/PriorityQueue.hpp"

template <typename E>
struct pair{
  E destination;
  double weight;

  pair(){
  }

  pair(E destination, double weight){
    this->destination = destination;
    this->weight = weight;
  }

  std::string toString(){
    return "(" + destination.toString() + ", " + std::to_string(weight) + ")";
  }

  bool operator>(const pair& p){
    return this->weight > p.weight;
  }

  bool operator<(const pair& p){
    return this->weight < p.weight;
  }

  bool operator==(const pair& p){
    return this->destination == p.destination;
  }

  bool operator==(const E& element){
    return this->destination == element;
  }
};

template <typename T>
struct Edge{
  T node;
  LinkedList<pair<T>> edges;

  Edge(){}
  Edge(T n){ node = n; }

  void add(pair<T> element){ edges.add(element); }
  void remove(pair<T> element){ edges.remove(element); }
  bool operator==(const T& e){ return this->node == e; }
  bool operator==(const Edge& e){ return this->node == e.node; }
  std::string toString(){
    std::string output = node.toString();
    output += " -> ";
    for(int i = 0; i < edges.size(); i++){
      output += edges[i].toString() + "; ";
    }
    output += "\n";
    return output;
  }
};

template <typename T>
class CompareMax{
  public:
    bool operator()(T i1, T i2){
      return i1 > i2;
    }
};

template <typename E>
class ListGraph{
  private:
    LinkedList<Edge<E>> _graph;
    LinkedList<bool> _visited;
    LinkedList<double> _state;

    void dijkstraHelper(int node, E destination, int output[]);

  public:
    /***************
     * CONSTRUCTOR *
     ***************/
    ListGraph();

    /************
     * MUTATORS *
     ************/
    void addNode(E node);
    void addEdge(E source, E destination, double weight);
    void removeEdge(E source, E destination, double weight=-1);
    void removeNode(E node);

    /*************
     * ACCESSORS *
     *************/
    LinkedList<E> dijkstra(E source, E destination);
    std::string toString();
};

template <typename E>
ListGraph<E>::ListGraph(){

}

template <typename E>
void ListGraph<E>::addNode(E node){
  if(_graph.indexOf(node) != -1){
    throw "Node already exists";
  }
  _visited.add(false);
  _state.add(1000000);
  _graph.add(Edge<E>(node));
}

template <typename E>
void ListGraph<E>::addEdge(E source, E destination, double weight){
  int index = _graph.indexOf(source);
  if(index == -1){
    throw "Source node does not exist";
  }
  int index2 = _graph.indexOf(destination);
  if(index2 == -1){
    this->addNode(destination);
  }

  pair<E> edge(destination, weight);  
  _graph[index].add(edge);
}

template <typename E>
void ListGraph<E>::removeEdge(E source, E destination, double weight){
  int index = _graph.indexOf(source);
  if(index == -1){
    return;
  }
  _graph[index].remove(pair<E>(destination, weight));
}

template <typename E>
void ListGraph<E>::removeNode(E node){
  int index = _graph.indexOf(node);
  if(index == -1){
    return;
  }
  _graph.remove(index);
  _visited.remove(index);
  _state.remove(index);
  for(int i = 0; i < _graph.size(); i++){
    _graph[i].remove(pair<E>(node, -1));
  }
}

template <typename E>
void ListGraph<E>::dijkstraHelper(int node, E destination, int output[]){
  // Check that node exists
  if(node == -1){
    throw "Node does not exist";
  }
  // Destination reached, end of function
  if(_graph[node] == destination){
    return;
  }
  // Mark node as visited
  _visited[node] = true;
  // Priority queue of nodes to visit
  PriorityQueue<pair<E>, CompareMax<pair<E>>> dijkstraEdges;
  // Breadth first search
  for(int i = 0; i < _graph[node].edges.size(); i++){
    dijkstraEdges.push(_graph[node].edges[i]);
  }
  // Visit all adjacent nodes
  while(dijkstraEdges.size() != 0){
    pair<E> next = dijkstraEdges.pop();
    int index = _graph.indexOf(next.destination);
    // Only visit node if not visited and distance is shortest
    if(!_visited[index] && _state[node] + next.weight < _state[index]){
      _state[index] = _state[node] + next.weight;
      output[index] = node; // Build path from source to destination
      dijkstraHelper(index, destination, output);
    }
  }
}

template <typename E>
LinkedList<E> ListGraph<E>::dijkstra(E source, E destination){
  int index1 = _graph.indexOf(source);
  int index2 = _graph.indexOf(destination);
  // Check that source and destination exists
  if(index1 == -1){
    throw "Source does not exist";
  }
  if(index2 == -1){
    throw "Destination does not exist";
  }
  // initialize required parameters
  for(int i = 0; i < _graph.size(); i++){
    _state[i] = 1000000;
    _visited[i] = false;
  }
  // set first source node
  _state[index1] = 0;
  // index of path from source to destination
  int path[_graph.size()];
  // Use dijkstras to find shortest path
  dijkstraHelper(index1, destination, path);
  // convert from index to elements
  LinkedList<E> output;
  int index = index2;
  while(index != index1){
    output.append(_graph[index].node);
    index = path[index];
  }
  output.append(_graph[index1].node);
  return output;
}

template <typename E>
std::string ListGraph<E>::toString(){
  std::string output = "";
  for(int i = 0; i < _graph.size(); i++){
    output += _graph[i].toString();
  }
  return output;
}

#endif // LISTGRAPH_H
