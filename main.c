#include <stdio.h>
#include "linkedlist.h"
void display_int(List_ptr list)
{
  Node_ptr p_walk = list->first;
  while (p_walk != NULL)
  {
    printf("%d\n", *(int *)&p_walk->element);
    p_walk = p_walk->next;
  }
}
void display_float(List_ptr list)
{
  Node_ptr p_walk = list->first;
  while (p_walk != NULL)
  {
    printf("%0.2f\n", *(float *)&p_walk->element);
    p_walk = p_walk->next;
  }
}

int main()
{
  Element element;
  List_ptr list = create_list();
  *(int *)&element = 1;
  add_to_list(list, element);
  *(int *)&element = 2;
  add_to_start(list, element);
  *(int *)&element = 3;
  insert_at(list, element, 1);
  element = remove_from_start(list);
  printf("Element removed : %d\n", *(int *)&element);
  element = remove_from_end(list);
  printf("Element removed : %d\n", *(int *)&element);
  element = remove_at(list, 0);
  printf("Element removed : %d\n", *(int *)&element);
  printf("Element removed from: %d\n", *(int *)&element);
  *(int *)&element = 1;
  add_to_list(list, element);
  *(int *)&element = 2;
  add_to_list(list, element);
  *(int *)&element = 3;
  add_to_list(list, element);
  display_int(list);
  element = remove_first_occurrence(list, element, matcher_int);
  clear_list(list);
  // list = create_list();
  // *(float *)&element = 1.1;
  // add_to_list(list, element);
  // *(float *)&element = 2.1;
  // add_to_start(list, element);
  // *(float *)&element = 3.1;
  // insert_at(list, element, 1);
  // display_float(list);
  // element = remove_from_start(list);
  // printf("Element removed : %0.2f\n", *(float *)&element);
  // element = remove_from_end(list);
  // printf("Element removed : %0.2f\n", *(float *)&element);
  // element = remove_at(list, 0);
  // printf("Element removed : %0.2f\n", *(float *)&element);
  return 0;
}
