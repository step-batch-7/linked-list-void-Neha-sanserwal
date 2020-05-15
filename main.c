#include <stdio.h>
#include "linkedlist.h"
void display_int(List_ptr list)
{
  Node_ptr p_walk = list->first;
  while (p_walk != NULL)
  {
    printf("%d\n", *(int *)p_walk->element);
    p_walk = p_walk->next;
  }
}
void display_float(List_ptr list)
{
  Node_ptr p_walk = list->first;
  while (p_walk != NULL)
  {
    printf("%0.2f\n", *(float *)p_walk->element);
    p_walk = p_walk->next;
  }
}

int main()
{
  Element element = malloc(sizeof(int));
  List_ptr list = create_list();
  *(int *)element = 1;
  add_to_list(list, element);
  element = malloc(sizeof(int));
  *(int *)element = 3;
  add_to_list(list, element);
  element = malloc(sizeof(int));
  *(int *)element = 3;
  add_to_list(list, element);
  List_ptr a = remove_all_occurrences(list, element, matcher_int);
  forEach(list, multiply_two);
  display_int(a);
  return 0;
}
