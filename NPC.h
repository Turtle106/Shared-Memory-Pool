#pragma once
//npc.h decl

#include <iostream>
#include "NPCPool.h"

class NPCFactory;

class NPC {
    //Allows NPCFactory to call NPC's private constructor
    friend class NPCFactory;
    
private:
    std::string _name; // e.g., "Goblin_247"
    std::string _type; // e.g., "merchant", "enemy","quest_giver",→
    int _x, _y; // Grid location on the map
    int _health; // Health points

    //Private constructor to enforce usage of the pool
    NPC(const std::string& name, const std::string& type, int x, int y, int health);
public:
    //this is for ease of displaying the contents of an NPC object.
    friend std::ostream& operator<<(std::ostream& os, const NPC& npc) {
        os << "NPC[name='" << npc._name
        << "', type='" << npc._type
        << "', pos=(" << npc._x << "," << npc._y << ")"
        << ", hp=" << npc._health << "]";
        return os;
    }

    //Profile method hint (NPC.cpp)
    static void profile();

    //Static pool for managing NPCs
    inline static Pool<NPC> pool{100, true};

    //New and delete hints for override (NPC.cpp)
    static void* operator new(std::size_t size);
    static void operator delete(void* ptr) noexcept;
};

//Factory with a static method for creating pool-managed NPCs.
class NPCFactory {
    public:
        static NPC* spawn(const std::string& name, const std::string& type, int x, int y, int health = 100);
    private:
        NPCFactory() = default;
        ~NPCFactory() = default;
        NPCFactory(const NPCFactory&) = delete;
        NPCFactory& operator=(const NPCFactory&) = delete;
};