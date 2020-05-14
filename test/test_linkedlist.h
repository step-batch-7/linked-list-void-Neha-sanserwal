#include "../linkedlist.h"
#
typedef enum
{
  INT,
  FLOAT,
  CHAR
} Types;
void assert_display_msg(char *msg, List_ptr actual, List_ptr expected, Types type);
void test_add_to_list();

Status assert_values(Element num1, Element num2, Types type);
Status assert_lists(List_ptr actual, List_ptr expected, Types type);
