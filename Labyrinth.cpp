#include "Labyrinth.h"

bool isPathToFreedom(MazeCell* start, const std::string& moves) {
    (void) start;
    (void) moves;
    int GotSpellbook=0;
    int GotPotion=0;
    int GotWand=0;

    if (checkPath(start, GotSpellbook, GotPotion, GotWand)) {
        for (int i=0; i<moves.size()-1; i++) {
            if (moves[i] == 'N');
            checkPath(start->north,GotSpellbook,GotPotion,GotWand);
            if (moves[i] == 'S');
            checkPath(start->south,GotSpellbook,GotPotion,GotWand);
            if (moves[i] == 'E');
            checkPath(start->east,GotSpellbook,GotPotion,GotWand);
            if (moves[i] == 'W');
            checkPath(start->west,GotSpellbook,GotPotion,GotWand);
        }
    }
}

bool checkPath(MazeCell* v,int GotSpellbook, int GotPotion, int GotWand ) {

    if(v==nullptr) {
        return false;
    }
    if (v->whatsHere == Item::SPELLBOOK) {
        GotSpellbook=1;
    }
    if(v->whatsHere == Item::POTION) {
        GotPotion=1;
    }
    if(v->whatsHere == Item::WAND) {
        GotWand=1;
    }
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