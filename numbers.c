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
int main()
{
  int int_value = 1;
  Element element;
  float float_value;
  char char_value;
  List_ptr list = create_list();
  *(int *)&element = 1;
  add_to_list(list, element);
  *(int *)&element = 2;
  add_to_start(list, element);
  *(int *)&element = 3;
  insert_at(list, element, 1);
  display_int(list);

  return 0;
}
