#include <iostream>
#include "Labyrinth.h"

bool isPathToFreedom(MazeCell* start, const std::string& moves) {
    (void) start;
    (void) moves;
    int GotSpellbook=0;
    int GotPotion=0;
    int GotWand=0;

    //if (checkPath(start, GotSpellbook, GotPotion, GotWand)) {
        for (int i=0; i<moves.size()-1; i++) {
            if (moves[i] == 'N')
            start = start->north;
           // checkPath(start->north,GotSpellbook,GotPotion,GotWand);
            if (moves[i] == 'S')
            start = start->south;
            //checkPath(start->south,GotSpellbook,GotPotion,GotWand);
            if (moves[i] == 'E')
            start = start->east;
            //checkPath(start->east,GotSpellbook,GotPotion,GotWand);
            if (moves[i] == 'W'){
              //  std::cout<<"west";
            start = start->west;}
            checkPath(start,GotSpellbook,GotPotion,GotWand);
        }
        return gotAllItems(GotSpellbook,GotPotion,GotWand);
    }
//}

bool checkPath(MazeCell* v,int GotSpellbook, int GotPotion, int GotWand ) {

    if(v==nullptr) {
        return false;
    }
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
    }
 /*   if (v->whatsHere == Item::SPELLBOOK) {
        
    }
    if(v->whatsHere == Item::POTION) {
        
    }
    if(v->whatsHere == Item::WAND) {
       
    }*/
}

bool gotAllItems(int GotSpellbook, int GotPotion, int GotWand) {
    if(GotSpellbook + GotPotion +GotWand!=3) {
        return false;
        //if return false we have not collected all items
    }
    if (GotSpellbook + GotPotion + GotWand==3) {
        return true;
    }
}
