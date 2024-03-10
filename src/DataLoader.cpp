#include "DataLoader.h"

#include <fstream>
#include <iostream>
#include <sstream>

std::map<std::pair<int, int>, float> loadDataFromFile(std::string FilePath) {
  std::map<std::pair<int, int>, float> Output;
  std::ifstream DataFile(FilePath);

  std::string NodeCount;
  std::string ColumnHeader;
  std::getline(DataFile, NodeCount);
  std::getline(DataFile, ColumnHeader);

  int NodeCountInt = std::stoi(NodeCount);
  for (int I = 1; I <= NodeCountInt; ++I) {
    Output[std::make_pair(I, I)] = 0;
  }

  for (std::string Line; std::getline(DataFile, Line);) {
    std::string Node1Number;
    std::string Node2Number;
    std::string Distance;
    std::stringstream LineStream(Line);
    std::getline(LineStream, Node1Number, ' ');
    std::getline(LineStream, Node2Number, ' ');
    std::getline(LineStream, Distance, ' ');
    int Node1 = std::stoi(Node1Number);
    int Node2 = std::stoi(Node2Number);
    float DistanceFloat = std::stof(Distance);
    Output[std::make_pair(Node1, Node2)] = DistanceFloat;
    //Output[std::make_pair(Node2, Node1)] = DistanceFloat;
  }
  return Output;
}
