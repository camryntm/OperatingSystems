#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
  printf("Testing Linked List Implementation\n");
    
    // Create a new list
  list_t *mylist = list_alloc();

    // Test adding elements to the front
  list_add_to_front(mylist, 10);
  list_add_to_front(mylist, 20);
  list_print(mylist); // Expected output: 20 -> 10 -> NULL

    // Test adding elements to the back
  list_add_to_back(mylist, 30);
  list_add_to_back(mylist, 40);
  list_print(mylist); // Expected output: 20 -> 10 -> 30 -> 40 -> NULL

    // Test adding element at index
  list_add_at_index(mylist, 25, 2);
  list_print(mylist); // Expected output: 20 -> 10 -> 25 -> 30 -> 40 -> NULL

    // Test removing elements from the front, back, and at index
  list_remove_from_front(mylist);
  list_print(mylist); // Expected output: 10 -> 25 -> 30 -> 40 -> NULL

  list_remove_from_back(mylist);
  list_print(mylist); // Expected output: 10 -> 25 -> 30 -> NULL

  list_remove_at_index(mylist, 1);
  list_print(mylist); // Expected output: 10 -> 30 -> NULL

    // Test list length
  printf("List length: %d\n", list_length(mylist)); // Expected output: 2

    // Test if value is in list
  printf("Is 10 in the list?: %d\n", list_is_in(mylist, 10)); // Expected output: 1 (true)
  printf("Is 25 in the list?: %d\n", list_is_in(mylist, 25)); // Expected output: 0 (false)

    // Test get element at index
  printf("Element at index 1: %d\n", list_get_elem_at(mylist, 1)); // Expected output: 30

    // Test get index of element
  printf("Index of 30: %d\n", list_get_index_of(mylist, 30)); // Expected output: 1

    // Free the list at the end
  list_free(mylist);

  return 0;
}
