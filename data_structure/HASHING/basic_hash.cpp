#include <iostream>
#include <cstring>
#include "hashtable.h"

using namespace std;

int main()
{
    HashTable<int> price_menu;
    

    price_menu.insert("Chomin",40);
    price_menu["Maggie"]=20;
    price_menu.insert("Manchurian",60);
    price_menu["Egg Roll"]=45;
    price_menu.print();
    price_menu.erase("Chomin");
    // price_menu["Dosa"]=120;
    price_menu.print();
        
}