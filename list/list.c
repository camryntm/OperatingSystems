#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// Allocates a new list
list_t *list_alloc() {
  list_t* mylist = (list_t *) malloc(sizeof(list_t)); 
  if (mylist == NULL) {
      // handle the error, maybe print a message or exit
  }
  mylist->head = NULL;
  return mylist;
}

// Frees the list
void list_free(list_t *l) {
  node_t *current = l->head;
  node_t *next;

  while (current != NULL) {
      next = current->next;
      free(current);
      current = next;
  }

  free(l);
}

// Prints the list
void list_print(list_t *l) {
  node_t *current = l->head;
  while (current != NULL) {
      printf("%d -> ", current->value);
      current = current->next;
  }
  printf("NULL\n");
}

// Adds an element to the back of the list
void list_add_to_back(list_t *l, elem value) {
  node_t *new_node = (node_t *)malloc(sizeof(node_t));
  new_node->value = value;
  new_node->next = NULL;

  if (l->head == NULL) {
      l->head = new_node;
      return;
  }

  node_t *current = l->head;
  while (current->next != NULL) {
      current = current->next;
  }

  current->next = new_node;
}

// Adds an element to the front of the list
void list_add_to_front(list_t *l, elem value) {
  node_t *new_node = (node_t *)malloc(sizeof(node_t));
  new_node->value = value;
  new_node->next = l->head;
  l->head = new_node;
}

// Adds an element at a specific index (0-based)
void list_add_at_index(list_t *l, elem value, int index) {
  if (index == 0) {
      list_add_to_front(l, value);
      return;
  }

  node_t *new_node = (node_t *)malloc(sizeof(node_t));
  new_node->value = value;
  new_node->next = NULL;

  node_t *current = l->head;
  for (int i = 0; i < index - 1; i++) {
      if (current->next == NULL) {
          // Index out of bounds, handle error
          free(new_node);
          return;
      }
      current = current->next;
  }

  new_node->next = current->next;
  current->next = new_node;
}

// Other functions can be implemented in a similar manner

// Removes an element from the front of the list and returns its value
elem list_remove_from_front(list_t *l) {
  if (l->head == NULL) {
        // Handle error for empty list, maybe return a specific error value
    return -1;
  }

  node_t *temp = l->head;
  elem value = temp->value;
  l->head = l->head->next;
  free(temp);
  return value;
}

// Removes an element from the back of the list and returns its value
elem list_remove_from_back(list_t *l) {
  if (l->head == NULL) {
        // Handle error for empty list
    return -1;
  }

  if (l->head->next == NULL) {
        // Only one element
    elem value = l->head->value;
    free(l->head);
    l->head = NULL;
    return value;
  }

  node_t *current = l->head;
  while (current->next->next != NULL) {
    current = current->next;
  }

  elem value = current->next->value;
  free(current->next);
  current->next = NULL;
  return value;
}

// Removes an element at a specific index (0-based) and returns its value
elem list_remove_at_index(list_t *l, int index) {
  if (l->head == NULL || index < 0) {
      // Handle error for empty list or invalid index
    return -1;
  }

  if (index == 0) {
    return list_remove_from_front(l);
  }

  node_t *current = l->head;
  for (int i = 0; i < index - 1; i++) {
    if (current->next == NULL) {
            // Index out of bounds
      return -1;
    }
    current = current->next;
  }

  node_t *temp = current->next;
  if (temp == NULL) {
    return -1;
  }

  elem value = temp->value;
  current->next = temp->next;
  free(temp);
  return value;
}

// Returns the length of the list
int list_length(list_t *l) {
  int count = 0;
  node_t *current = l->head;
  while (current != NULL) {
    count++;
    current = current->next;
  }
  return count;
}

// Checks if a value is in the list
bool list_is_in(list_t *l, elem value) {
  node_t *current = l->head;
  while (current != NULL) {
    if (current->value == value) {
      return true;
    }
    current = current->next;
  }
  return false;
}

// Returns the value of the element at a specific index (0-based)
elem list_get_elem_at(list_t *l, int index) {
  if (index < 0) {
        // Handle invalid index
    return -1;
  }

  node_t *current = l->head;
  for (int i = 0; i < index; i++) {
    if (current == NULL) {
            // Index out of bounds
      return -1;
    }
    current = current->next;
  }

  return current != NULL ? current->value : -1;
}

// Returns the index of the first occurrence of a value (0-based)
int list_get_index_of(list_t *l, elem value) {
  int index = 0;
  node_t *current = l->head;
  while (current != NULL) {
    if (current->value == value) {
      return index;
    }
    current = current->next;
    index++;
  }
  return -1; // Value not found
}
