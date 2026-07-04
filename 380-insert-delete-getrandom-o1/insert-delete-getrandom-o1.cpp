#include <vector>
#include <unordered_map>
#include <random>

class RandomizedSet {
private:
    std::vector<int> nums;                  // Stores the actual values for O(1) random access
    std::unordered_map<int, int> valToIndex; // Maps value -> index in the 'nums' vector
    
    // Put random engines as member variables so they aren't recreated every function call
    std::mt19937 gen;

public:
    RandomizedSet() : gen(std::random_device{}()) {}
    
    bool insert(int val) {
        // If the value already exists, return false
        if (valToIndex.count(val)) {
            return false;
        }
        
        // Add value to the end of the vector
        nums.push_back(val);
        // Record its index in the map
        valToIndex[val] = nums.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        // If the value doesn't exist, return false
        if (!valToIndex.count(val)) {
            return false;
        }
        
        // Get the index of the element to delete, and the value of the last element
        int indexToRemove = valToIndex[val];
        int lastElement = nums.back();
        
        // Swap Trick: Move the last element into the spot of the element we want to delete
        nums[indexToRemove] = lastElement;
        valToIndex[lastElement] = indexToRemove; // Update its index in the map
        
        // Safely erase the last element from both structures in O(1) time
        nums.pop_back();
        valToIndex.erase(val);
        return true;
    }
    
    int getRandom() {
        // Pick a completely random index in O(1) time
        std::uniform_int_distribution<int> distr(0, nums.size() - 1);
        return nums[distr(gen)];
    }
};
