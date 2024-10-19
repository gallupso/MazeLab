#include <iostream>
#include <string>
#include "Labyrinth.h"

bool isPathToFreedom(MazeCell* start, const std::string& moves) {
    (void) start;
    (void) moves;
    int GotSpellbook=0;
    int GotPotion=0;
    int GotWand=0;
    
    for (std::size_t myI = 0; myI < moves.size(); myI++) {
        if (start == nullptr) 
          std::cout << "Something is wrong." << std::endl;
            //return gotAllItems(GotSpellbook, GotPotion, GotWand);
      
        switch (moves[myI]) {
            case 'N':
                start = start->north;
                break;
            case 'S':
                start = start->south;
                break;
            case 'E':
                start = start->east;
                break;
            case 'W':
                start = start->west;
                break;
            default:
                std::cout << "null cell: " << moves[myI] << std::endl;
                continue; 
        }

        checkPath(start, GotSpellbook, GotPotion, GotWand);
    }

    return gotAllItems(GotSpellbook, GotPotion, GotWand);
}


//checks the cell we have moved into for items. if there's an item, it adds 1 to our counters.
//this function should not have to do anything if theres nothing in the cell 
void checkPath(MazeCell* v,int& GotSpellbook, int& GotPotion, int& GotWand ) {

    //if(v==nullptr) {
     //   return false;
 //   }
    switch(v->whatsHere){
        case (Item::SPELLBOOK):
           GotSpellbook=1;    
           break;
        case(Item::POTION):
          GotPotion=1;
          break;
        case(Item::WAND):
            GotWand=1;
          break;
        case(Item::NOTHING):
          break;
    }
 
}

bool gotAllItems(int GotSpellbook, int GotPotion, int GotWand) {
    return (GotSpellbook+GotPotion+GotWand==3);
  
}
