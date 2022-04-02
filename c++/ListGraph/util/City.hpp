#ifndef CITY_H
#define CITY_H

#include <string>

class City{
  private:
    std::string _name;
    int _population;

  public:
    City();
    City(std::string name, int pop);

    void setName(std::string name);
    void setPopulation(int pop);

    std::string getName();
    int getPopulation();
    std::string toString();

    bool operator==(const City& c);
};

#endif // CITY_H
