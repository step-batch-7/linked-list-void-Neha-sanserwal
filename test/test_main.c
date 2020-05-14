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
  return 0;
}
