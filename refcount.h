#ifndef _REFCOUNTER
#define _REFCOUNTER

// A tiny library for managing memory by reference counting

// Copyright 2022 Alan Tseng
// The MIT License

/* First, set aside a (int*) pointer for your counter
   then initialize it. Must be called first.
   Automatically sets the count to 1. */
void ref_init(int **count);

/* Increase and decrease reference count.
   When the count reaches 0, freer() will be called on the data.
   The counter itself will be freed too. All handled by the library. */
void ref_up(int **count);
void ref_down(void *data, int **count, void (*freer)(void *));

#endif