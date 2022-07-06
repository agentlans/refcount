#include <stdlib.h>

#include "refcount.h"

// Reference-counted string
struct foo {
    char* str;
    int* count; // Use this int* field as counter
};

int main() {
    // Get a heap-allocated pointer that must be freed
    struct foo s;
    s.str = malloc(100);
    // Important: always remember to initialize counter
    ref_init(&s.count); // count = 1
    // increase and decrease the counter
    ref_up(&s.count); // count = 2
    ref_down(s.str, &s.count, free); // count = 1
    ref_down(s.str, &s.count, free); // count = 0
}
