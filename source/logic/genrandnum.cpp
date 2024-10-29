#include <random>

namespace logic { 
    int generateRandomNumber(int min, int max) {
        // Seed
        std::random_device rd;
        std::mt19937 gen(rd());
        
        // Set range
        std::uniform_int_distribution<int> distr(min, max);
        
        // Gen
        return distr(gen);
    }
}