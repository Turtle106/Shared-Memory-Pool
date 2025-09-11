#pragma once
//npc.h decl

#include <iostream>

class NPC {
    
private:

    std::string _name; // e.g., "Goblin_247"
    std::string _type; // e.g., "merchant", "enemy","quest_giver",→
    int _x, _y; // Grid location on the map
    int _health; // Health points

public:

    NPC(const string& name, const string& type, int x, int y, int health = 100);

    //this is for ease of displaying the contents of an NPC object.
    friend std::ostream& operator<<(std::ostream& os, const NPC& npc);
    // Should output: "NPC[name='Goblin_247', type='enemy', pos=(5,10), hp=100]"

    static void* operator new(std::size_t size);
    static void operator delete(void* ptr) noexcept;


};