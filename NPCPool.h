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

    std::byte* _memory_block;
    std::size_t _block_size;
    std::size_t _count;
    std::vector<std::size_t> free_indices;
    std::size_t live_npcs = 0;
    bool trace_enabled;

    [[nodiscard]] void* get_slot(std::size_t index) {
    // TODO: Return address of slot at given index
    }

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