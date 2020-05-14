#include "linkedlist.h"
int main()
{
  int int_value;
  float float_value;
  char char_value;
  List_ptr list = create_list();
  Element element = &int_value;
  add_to_list(list, element);
  int_value = 0;
  add_to_start(list, element);
  return 0;
}
