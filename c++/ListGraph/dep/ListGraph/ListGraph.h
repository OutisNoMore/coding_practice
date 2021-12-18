#ifndef LISTGRAPH_H 
#define LISTGRAPH_H

#include <string>

#include "LinkedList/LinkedList.h"

template <typename E>
struct pair{
  E source;
  E destination;
  double weight;

  pair(){
  }

  pair(E source, E destination, double weight){
    this->source = source;
    this->destination = destination;
    this->weight = weight;
  }

  std::string toString(){
    return "(" + destination.toString() + ", " + std::to_string(weight) + ")";
  }
};

template <typename E>
class ListGraph{
  private:
    LinkedList<LinkedList<pair<E>>> _graph;
    LinkedList<E> _nodes;

  public:
    ListGraph();
    void addNode(E node);
    void addEdge(E source, E destination, double weight);
    void removeEdge(E source, E destination);
    void removeNode(E node);

    std::string toString();
};

template <typename E>
ListGraph<E>::ListGraph(){

}

template <typename E>
void ListGraph<E>::addNode(E node){
  _nodes.add(node);
  LinkedList<pair<E>> edges;
  _graph.add(edges);
}

template <typename E>
void ListGraph<E>::addEdge(E source, E destination, double weight){
  int index = _nodes.indexOf(source);
  if(index == -1){
    return;
  }

  pair<E> edge(source, destination, weight);  
  _graph.get(index).add(edge);
}

template <typename E>
std::string ListGraph<E>::toString(){
  std::string output = "";

  for(int i = 0; i < _nodes.size(); i++){
    output += _nodes.get(i).toString();
    output += " -> ";
    for(int j = 0; j < _graph.get(i).size(); j++){
      output += _graph.get(i).get(j).toString() + "; ";
    }
    output += "\n";
  }

  return output;
}

#endif // LISTGRAPH_H
