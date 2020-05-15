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
  add_to_list(list, element);
  *(int *)&element = 3;
  add_to_list(list, element);
  list = map(list, add_one);
  // List_ptr a = filter(list, is_even);
  // *(int *)&element = -1;
  List_ptr k = remove_all_occurrences(list, element, matcher_int);
  display_int(k);
  clear_list(list);
  return 0;
}
