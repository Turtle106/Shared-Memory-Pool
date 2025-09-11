#include "npc.h"
#include <iostream>

/*std::string _name; // e.g., "Goblin_247"
std::string _type; // e.g., "merchant", "enemy","quest_giver",→
int _x, _y; // Grid location on the map
int _health; // Health points*/

NPC::NPC(const std::string& name, const std::string& type, int x, int y, int health) {
    ...
}

static void* NPC::operator new(std::size_t size) {
    ...
}

static void NPC::operator delete(void* ptr) noexcept {
    ...
}