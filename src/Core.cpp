#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include "Checker.hpp"

// Global thread synchronization
std::mutex mtx;

void StartChecking(const std::string& moduleName) {
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << "[SYSTEM] Thread started for module: " << moduleName << std::endl;
}

int main() {
    std::cout << "--- Simple Checker Professional Edition ---" << std::endl;
    std::cout << "[INFO] Loading modules from /configs..." << std::endl;
    
    // Simulate engine startup
    std::vector<std::string> modules = {"Steam_v4.2", "EpicGames_v2.1", "Netflix_API"};
    
    for(const auto& mod : modules) {
        std::thread t(StartChecking, mod);
        t.detach();
    }

    std::cin.get();
    return 0;
}