#include "lite_vector.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/**
 * A lite vector is a struct that holds a current length, a
 * maximum capacity, and a dynamically allocated chunk of
 * memory. It will hold elements added and will extend the
 * memory if it needs more space.
 *
 * Note: All referenced sources and notes can be found in notes.md
 *
 * @author Evan Johns
 * @date 2/6/2022
 */

/**
 * Create a new lite_vector.
 *
 * @param type_size The number of bytes for a single element of
 *                  the type to be stored in the vector.
 * @return The vector, or NULL if the operation fails.
 */
lite_vector* lv_new_vec(size_t type_size) {

    // allocate memory for vec pointer
    lite_vector* tmp = malloc(sizeof(lite_vector));

    // set vec parameters
    tmp->length = 0;
    tmp->max_capacity = 10;

    // allocate memory for data
    tmp->data = malloc(sizeof(void*) * tmp->max_capacity);

    // return new vector
    return tmp;
}

/**
 * Free all memory used by the vector.  Should be called
 * whenever the vector is no longer needed.
 *
 * @param vec The address of the vector we are finished using.
 */
void lv_cleanup(lite_vector* vec){

    // free memory of vector data
    free(vec->data);

    // free memory of vector
    free(vec);
}

/**
 * Get the current number of elements stored in the vector.
 *
 * @param vec The address of the vector we want to know the length of.
 * @return The vector length, or 0 if the operation fails.
 */
size_t lv_get_length(lite_vector* vec){

    // check if vector is null
    if (!vec) {
        return 0;
    }
    return vec->length;
}

/**
 * Clear the contents of the vector and reset it to a default state.
 *
 * @param vec The address of the vector we wish to clear.
 * @retun Sends true on success, or false otherwise.
 */
bool lv_clear(lite_vector* vec){

    // Check if vec is NULL
    if (!vec) {
        return false;
    }

    // Free vec data memory
    free(vec->data);

    // re-initialize vector
    vec->length = 0;
    vec->max_capacity = 10;
    vec->data = malloc(sizeof(void*) * vec->max_capacity);
    return true;
}

/**
 * Get an element from an index from a vector.
 *
 * @param vec The address of the vector we wish to retrieve from.
 * @param index The index we wish to retrieve from.
 * @return An element from the vector.  NULL if doesn't exist or
 *	   the function cannot complete.
 */
void* lv_get(lite_vector* vec, size_t index){

    // Check if vec is NULL or Index is not in vec
    if (!vec || (index >= vec->length)) {
        return NULL;
    }

    // Return Indexed element
    return vec->data[index];
}

/**
 * lv_resize is essentially private since we marked it static.
 * The job of this function is to attempt to resize the vector.
 * There may be functions you can call to do this for you, or
 * you may write it yourself.  Either way it isn't too hard.
 * With everything though, check to make sure the code worked
 * and return appropriately.  Do NOT destroy the data if the code
 * fails.  If the resize cannot complete, the original vector
 * must remain unaffected.
 * @param lite_vector* vec Vector to be resized
 *
 */
static bool lv_resize(lite_vector* vec){

    // If the vector is NULL, return false
    if (!vec) {
        return false;
    }

    // Create temporary data
    void** data = malloc(sizeof(void*) * vec->max_capacity * 2);

    // Increase vector max capacity
    vec->max_capacity = vec->max_capacity*2;

    // Copy data from vec to data
    memcpy(data, vec->data, sizeof(void*) * vec->max_capacity);

    // If the data isn't the same, return false
    if (*vec->data != *data) {
        return false;
    }

    // Check for memory leaks (valgrind) maybe
    free(vec->data);
    vec->data = data;
    return true;
}

/**
 * Add an element to the vector, and extend the vector if needed.
 *
 * @param vec The address of the vector we wish to add to.
 * @param element The element we wish to add.
 * @return Will return true if successful, false otherwise.
 */
bool lv_append(lite_vector* vec, void* element){

    // Check if vec is NULL
    if (!vec) {
        return false;
    }

    // Check if vec is at max capacity.
    if (vec->length >= vec->max_capacity) {
        // If at max capacity, resize to fit new element
        if (lv_resize(vec)) {
            // Add element
            vec->data[vec->length] = element;
            vec->length += 1;
        } else {
            // If resize fails, return false
            return false;
        }
    } else {
        // If vec isn't at max capacity, add element
        vec->data[vec->length] = element;
        vec->length += 1;
    }
    return true;
}
