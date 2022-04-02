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

    void dijkstraHelper(int node, E destination, E output[]);

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
    E* dijkstra(E source, E destination);
    void floydWarshall(E source, E destination);
    void prim();
    void kruskal();
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
void ListGraph<E>::dijkstraHelper(int node, E destination, E output[]){
  if(node == -1){
    throw "Node does not exist";
  }
  if(_graph[node] == destination){
    return;
  }
  _visited[node] = true;
  PriorityQueue<pair<E>, CompareMax<pair<E>>> dijkstraEdges;
  for(int i = 0; i < _graph[node].edges.size(); i++){
    dijkstraEdges.push(_graph[node].edges[i]);
  }
  while(dijkstraEdges.size() != 0){
    pair<E> next = dijkstraEdges.pop();
    int index = _graph.indexOf(next.destination);
    if(!_visited[index] && _state[node] + next.weight < _state[index]){
      _state[index] = _state[node] + next.weight;
      output[index] = _graph[node].node;
      dijkstraHelper(index, destination, output);
    }
  }
}

template <typename E>
E* ListGraph<E>::dijkstra(E source, E destination){
  int index1 = _graph.indexOf(source);
  int index2 = _graph.indexOf(destination);
  if(index1 == -1){
    throw "Source does not exist";
  }
  if(index2 == -1){
    throw "Destination does not exist";
  }
  E* output = new E[_graph.size()];
  for(int i = 0; i < _graph.size(); i++){
    _state[i] = 1000000;
    _visited[i] = false;
  }
  _state[index1] = 0;
  dijkstraHelper(index1, destination, output);
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
