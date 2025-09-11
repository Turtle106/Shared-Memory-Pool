#include <cstddef>
#include <vector>
#include <memory>
#include <span> // C++20
#include <iostream>
#include <format> // C++20 (python style formatting of strings) optional to use,→]
#include "NPCPool.h"


// get memory address for an index
// (nodiscard means throw if the output of this member is being ignored),→
[[nodiscard]] void* Pool::get_slot(std::size_t index) {
    // TODO: Return address of slot at given index
}

// Get a safe view of the memory
// this is optional, but recommended
[[nodiscard]] std::span<std::byte> Pool::get_memory_span() {
// TODO: Return a span covering the entire memory block
}

Pool::Pool(std::size_t count, bool trace = true);

Pool::~Pool();

[[nodiscard]] void* Pool::allocate();

void Pool::deallocate(void* ptr);

void Pool::profile() const;