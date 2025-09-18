#include "Squirrel.h"

Squirrel::Squirrel(int cuteness, int x, int y) : _cuteness_level(cuteness), _x(x), _y(y) {}

void* Squirrel::operator new(std::size_t size) {
    return SquirrelSwimmingPool.allocate();
}

void Squirrel::operator delete(void* ptr) noexcept {
    SquirrelSwimmingPool.deallocate(ptr);
}