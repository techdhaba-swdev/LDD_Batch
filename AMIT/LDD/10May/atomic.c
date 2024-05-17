#include <linux/atomic.h>

// Define an atomic variable to hold the click count
atomic_t click_count = ATOMIC_INIT(0);

// Function to increment the click count atomically
void button_clicked() {
    atomic_inc(&click_count);
}
