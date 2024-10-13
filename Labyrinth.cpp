#include "Labyrinth.h"

bool isPathToFreedom(MazeCell* start, const std::string& moves) {
  //string looks like NSWE, and our pointers are named north,south,east,west. I'm trying to link them here so the function knows that if the string is N, it needs to check if a north pointer is null. This might be wrong bc they might already be linked, or bc this is incorrect syntax. 
  N = north;
  S = south;
  E = east;
  W = west;
  //std::string nope = "This path is illegal ;

  if (start == nullptr)
    return "This path is illegal";

  else {
    counter += 1; //counts how many cells we have passed through 
    //since moves is const, not sure if i can break this into a substr here and be able to pass it in 
    std::string part = moves.substr(counter +1);
    //'moves(counter)' represents the cell we are currently in,
    //'part' contains the part of the moves string that we still need to check 
    isPathToFreedom(moves(counter), part);
  }
  
   
}
