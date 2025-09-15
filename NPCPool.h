/*This module includes the Pool template. This template works for any class, and manages a chunk of heap memory.*/

#pragma once
#include <cstddef>
#include <vector>
#include <memory>
#include <span> // C++20
#include <iostream>
#include <format> // C++20 (python style formatting of strings) optional to use,→
#include <stdexcept>


template<typename T> 
class Pool {
    private:

    //Initialize values
    std::byte* _memory_block; //pointer;
    std::size_t _block_size; //chunk size;
    std::size_t _count; //Number of chunks in pool;
    std::vector<std::size_t> free_indices; //Dynamic vector for tracking available indices
    std::size_t live_npcs = 0;
    bool trace_enabled;

    [[nodiscard]] void* get_slot(std::size_t index) {
        return _memory_block + (index * _block_size);
    }

    [[nodiscard]] std::span<std::byte> get_memory_span() {
        return std::span(_memory_block, _count * _block_size);   
    }

public:
    Pool(std::size_t count, bool trace = true) {    
        _block_size = sizeof(T);
        _count = count;
        for (size_t i = 0; i < count; i++) {
            free_indices.push_back(i);
        }
        trace_enabled = trace;

        _memory_block = new std::byte[count * sizeof(T)];
    }

    ~Pool() {
        delete [] _memory_block;
    }
    [[nodiscard]] void* allocate() {
        if (free_indices.size() <= 0)
            throw std::bad_alloc();

        std::size_t index = free_indices.back();
        free_indices.pop_back();
        live_npcs++;
        void* ret = (sizeof(T) * index) + _memory_block;

        if (trace_enabled) {
            std::cout << "Allocated " << typeid(T).name() << " at slot " << index << " (address: " << ret << ")" << std::endl;
        }

        return ret;
    }

    void deallocate(void* ptr) {
        std::size_t index = (static_cast<std::byte*>(ptr) - _memory_block) / sizeof(T);
        free_indices.push_back(index);
        live_npcs--;
        if (trace_enabled) {
            std::cout << "Deallocated " << typeid(T).name() << " at slot " << index << " (address: " << ptr << ")" << std::endl;
        }
    }
    void profile() const {
        std::cout << "Live " << typeid(T).name() << "s: " << live_npcs << std::endl;
        std::cout << "Available slots: " << free_indices.size() << std::endl;

        for (std::size_t item : free_indices) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
};