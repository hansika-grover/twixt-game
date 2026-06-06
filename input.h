#ifndef INPUT_H
#define INPUT_H

/*
 * Return convention (both functions):
 *     1    success - value(s) stored in the out-params
 *     0    invalid input (non-numeric); the bad line is discarded,
 *          so the caller can simply prompt again
 *     EOF  the input stream is closed; the caller should stop reading
 */
int read_int(int *out);
int read_two_ints(int *a, int *b);

#endif