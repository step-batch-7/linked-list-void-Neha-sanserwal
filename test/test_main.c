#include <stdio.h>
#include "test_linkedlist.h"

int main()
{
  printf("add_to_list : \n");
  test_add_to_list();
  printf("add_to_first : \n");
  test_add_to_start();
  printf("insert_at : \n");
  test_insert_at();
  printf("remove_at : \n");
  test_remove_at();
  printf("remove_from_end : \n");
  test_remove_from_end();
  printf("remove_from_start : \n");
  test_remove_from_start();
  printf("remove_first_occurrence : \n");
  test_remove_first_occurrence();
  printf("add_unique : \n");
  test_add_unique();
  printf("reverse : \n");
  test_reverse();
  printf("map : \n");
  test_map();
  printf("filter : \n");
  test_filter();
  return 0;
}
