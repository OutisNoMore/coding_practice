#include "City.hpp"

City::City(){
  _name = "Empty";
  _population = 0;
}

City::City(std::string name, int pop){
  _name = name;
  _population = pop;
}

void City::setName(std::string name){
  _name = name;
}

void City::setPopulation(int pop){
  _population = pop;
}

std::string City::getName(){
  return _name;
}

int City::getPopulation(){
  return _population;
}

std::string City::toString(){
  return "(" + _name + ", " + std::to_string(_population) + ")";
}

bool City::operator==(const City& c){
  return c._name == this->_name && c._population == this->_population;
}
