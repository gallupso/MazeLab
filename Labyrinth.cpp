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

    
    //if (checkPath(start, GotSpellbook, GotPotion, GotWand)) {
        
        /*for (std::size_t myI = 0; myI<moves.size()-1; myI++) {

            if (moves[myI] == 'N')
            MazeCell* start = start->north;
           // checkPath(start->north,GotSpellbook,GotPotion,GotWand);
            if (moves[myI] == 'S')
            MazeCell* start = start->south;
            //checkPath(start->south,GotSpellbook,GotPotion,GotWand);
            if (moves[myI] == 'E')
            MazeCell* start = start->east;
            //checkPath(start->east,GotSpellbook,GotPotion,GotWand);
            if (moves[myI] == 'W'){
              //  std::cout<<"west";
            MazeCell* start = start->west;}
            
        }
       } 
        //checkPath(start,GotSpellbook,GotPotion,GotWand);
        return gotAllItems(GotSpellbook,GotPotion,GotWand);

    }*/
//}

//checks the cell we have moved into for items. if there's an item, it adds 1 to our counters.
//this function should not have to do anything if theres nothing in the cell 
void checkPath(MazeCell* v,int& GotSpellbook, int& GotPotion, int& GotWand ) {

    //if(v==nullptr) {
     //   return false;
 //   }
    switch(v->whatsHere){
        case (Item::SPELLBOOK):
           GotSpellbook=1;
           std::cout<<"spell";
           break;
        case(Item::POTION):
          GotPotion=1;
          std::cout<<"potion";
          break;
        case(Item::WAND):
            GotWand=1;
          std::cout<<"wand";
          break;
        case(Item::NOTHING):
          break;
    }
 
}

bool gotAllItems(int GotSpellbook, int GotPotion, int GotWand) {
    return (GotSpellbook+GotPotion+GotWand==3);
    /*if(GotSpellbook + GotPotion +GotWand!=3) {
        return false;
        //if return false we have not collected all items
    }
    if (GotSpellbook + GotPotion + GotWand==3) {
        //std::cout<<"yes";
        return true;
    }*/
}
