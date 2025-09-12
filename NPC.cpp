#include "NPC.h"
#include <iostream>

NPC::NPC(const std::string& name, const std::string& type, int x, int y, int health) : _name(name), _type(type), _x(x), _y(y), _health(health) {}

void* NPC::operator new(std::size_t size) {
    return pool.allocate();
}

void NPC::operator delete(void* ptr) noexcept {
    pool.deallocate(ptr);
}

void NPC::profile() { pool.profile(); }