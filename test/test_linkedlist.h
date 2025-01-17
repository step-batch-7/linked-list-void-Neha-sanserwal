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
void test_add_to_start();
void test_insert_at();
void test_remove_at();
void test_remove_from_end();
void test_remove_from_start();
void test_remove_first_occurrence();
void test_remove_all_occurrences();
void test_add_unique();
void test_map();
void test_reverse();
void test_filter();
Status assert_values(Element num1, Element num2, Types type);
Status assert_lists(List_ptr actual, List_ptr expected, Types type);
