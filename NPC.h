#pragma once
//npc.h decl

#include <iostream>
#include "NPCPool.h"

class NPCFactory;

class NPC {
    friend class NPCFactory;
    
private:
    std::string _name; // e.g., "Goblin_247"
    std::string _type; // e.g., "merchant", "enemy","quest_giver",→
    int _x, _y; // Grid location on the map
    int _health; // Health points

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

    static void profile();
    inline static Pool<NPC> pool{100, true};

    static void* operator new(std::size_t size);
    static void operator delete(void* ptr) noexcept;
};

class NPCFactory {
    public:
        static NPC* spawn(const std::string& name, const std::string& type, int x, int y, int health = 100);
    private:
        NPCFactory() = default;
        ~NPCFactory() = default;
        NPCFactory(const NPCFactory&) = delete;
        NPCFactory& operator=(const NPCFactory&) = delete;
};