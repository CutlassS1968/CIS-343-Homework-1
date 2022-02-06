#include "lite_vector.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/*
 * Vector is a dynamic "array", should be able to increase in size, but not decrease
 * vector struct:
 * typedef struct lv {
 *	  size_t length;
 *	  size_t max_capacity;
 *	  size_t type_size;
 *	  void** data;
 *} lite_vector;
 *
 * Notes say that type_size in lite_vector is useless, don't use it
 *
 * ArrayList = Vector
 * A bucket of elements
 *      Ask for chunk of memory
 *      Has specific amount of elements
 *      Starts to fill up
 *      Ask computer for more memory
 *      Copy all elements in Vec1 to new malloc'd Vec2
 *      Free Vec1
 *      Storing pointers inside of arraylist
 *          Data type is void*
 *          lv_data = void** because it points to a void*
 *          Malloc to some size you want to start out with (10, 100)
 *          When you fill it up, ask for more.
 *              How much more? idk pick something, 2x original size or 1.67x
 *              resize does this
 *              use memcpy to do the vec1 to vec2 copy
 *
 *
 *   Two things you can do in the first function
 *      Has to return a lite_vector pointer,
 *          this implies that it has to go on the heap
 *              Mechanism for getting heap memory is malloc
 *              lite_vector HOLD data (void**)
 *                  We have to malloc DATA void** too!!!!!1
 *
 */

/**
 * Create a new lite_vector.
 *
 * @param type_size The number of bytes for a single element of the type
 *                  to be stored in the vector.
 * @return The vector, or NULL if the operation fails.
 */
lite_vector* lv_new_vec(size_t type_size) {
    lite_vector* tmp = malloc(sizeof(lite_vector)); // allocate nbits of memory to the pointer
    tmp->data = malloc(sizeof(void**));
    tmp->length = 0;
    tmp->max_capacity = 0;
}

/**
 * Free all memory used by the vector.  Should be called
 * whenever the vector is no longer needed.
 *
 * @param vec The address of the vector we are finished using.
 */
void lv_cleanup(lite_vector* vec){
    free(vec); //lul no
}

/**
 * Get the current number of elements stored in the vector.
 *
 * @param vec The address of the vector we want to know the length of.
 * @return The vector length, or 0 if the operation fails.
 */
size_t lv_get_length(lite_vector* vec){
    return vec->length;
}

/**
 * Clear the contents of the vector and reset it to a default state.
 *
 * @param vec The address of the vector we wish to clear.
 * @retun Sends true on success, or false otherwise.
 */
bool lv_clear(lite_vector* vec){
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
 */
static bool lv_resize(lite_vector* vec){
}

/**
 * Add an element to the vector, and extend the vector if needed.
 *
 * @param vec The address of the vector we wish to add to.
 * @param element The element we wish to add.
 * @return Will return true if successful, false otherwise.
 */
bool lv_append(lite_vector* vec, void* element){
}
