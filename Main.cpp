#include <iostream>
#include <vector>
#include "npc.h"
int main() {
    // Create several NPCs
    std::vector<NPC*> npcs;
    // Spawn a wave of enemies
    for (int i = 0; i < 10; ++i) {
        npcs.push_back(new NPC(
        "Goblin_" + std::to_string(i),
        "enemy",
        i * 10, i * 10, // Position
        50 + i * 5 // Health
    ));
    }

    // Show one NPC
    std::cout << *npcs[5] << std::endl;
    // Delete some NPCs (simulating death)
    delete npcs[3];
    delete npcs[5];
    npcs[3] = nullptr;
    npcs[5] = nullptr;
    // Profile the pool
}