#include "NPCPool.h"

class Squirrel {
    int _cuteness_level, _x, _y;

public:
    Squirrel(int cuteness, int x, int y);

    inline static Pool<Squirrel> SquirrelSwimmingPool {1000, true};
    
    static void* operator new(std::size_t size);
    static void operator delete(void* ptr) noexcept;
};