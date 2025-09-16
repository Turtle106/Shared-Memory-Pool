#include "NPC.h"
#include <iostream>

//Private constructor to enforce use of the pool
NPC::NPC(const std::string& name, const std::string& type, int x, int y, int health) : _name(name), _type(type), _x(x), _y(y), _health(health) {}

//Uses static pool object which manages a slice of the heap
void* NPC::operator new(std::size_t size) {
    return pool.allocate();
}

//Uses static pool object to deallocate from the pool
void NPC::operator delete(void* ptr) noexcept {
    pool.deallocate(ptr);
}

//Uses the pools profile method
void NPC::profile() { pool.profile(); }

//NPCFactory method for creating NPC pointers
NPC* NPCFactory::spawn(const std::string& name, const std::string& type, int x, int y, int health) {
    return new NPC(name, type, x, y, health);
}