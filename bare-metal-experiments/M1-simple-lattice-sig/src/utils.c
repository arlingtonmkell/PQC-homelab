#include "utils.h"

// Simulate hash by summing message values and mapping to small range
int simulate_hash(const int *message, size_t length) {
    int sum = 0;
    for (size_t i = 0; i < length; i++) {
        sum += message[i];
    }
    return sum % 5 + 1;  // Avoid zero
}
