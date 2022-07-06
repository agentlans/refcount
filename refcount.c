#include <stdlib.h>

#include "refcount.h"

// Initializes a reference counter (int* pointer)
void ref_init(int** count) {
    *count = malloc(sizeof(int));
    **count = 1;
}

// Increases the reference count by 1
void ref_up(int** count) {
    if (!count || !(*count)) return; // already freed
    ++**count;
}

// Decreases the reference count by 1 and 
// calls freer() on the data when the count reaches 0
void ref_down(void* data, int** count, void (*freer)(void*)) {
    if (!count || !(*count)) return; // already freed
    --**count;
    // Destroy object when count reaches 0
    if (**count == 0) {
        freer(data);
        // Make the counter point to NULL
        free(*count);
        *count = NULL;
    }
}
