#pragma once
#include <cstddef>
#include <vector>
#include <memory>
#include <span> // C++20
#include <iostream>
#include <format> // C++20 (python style formatting of strings) optional to use,→

class Pool {
    private:
    // Memory storage

    std::byte* _memory_block; //pointer to array of bytes ('new'size of array),→
    std::size_t _block_size; //how we divide up the pool (sizeof NPC in this case),→

    // Free slot tracking using vector
    std::vector<std::size_t> free_indices; // Indices of freeslots,→

    // Statistics
    std::size_t live_npcs = 0; //how many npcs exist in the pool
    bool trace_enabled; //if true, dump lots of extra info tostdout

    // get memory address for an index
    // (nodiscard means throw if the output of this member is being ignored),→
    [[nodiscard]] void* get_slot(std::size_t index) {
    // TODO: Return address of slot at given index
    }

    // Get a safe view of the memory
    // this is optional, but recommended
    [[nodiscard]] std::span<std::byte> get_memory_span() {
    // TODO: Return a span covering the entire memory block
    }
public:
    Pool(std::size_t count, bool trace = true);
    ~Pool();
    [[nodiscard]] void* allocate();
    void deallocate(void* ptr);
    void profile() const;
};