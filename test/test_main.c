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
  return 0;
}
