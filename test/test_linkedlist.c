#include "../linkedlist.c"
#include "test_linkedlist.h"
void create_array_int(int *values, int length, Element *numbers)
{
  for (int i = 0; i < length; i++)
  {
    *(int *)&numbers[i] = values[i];
  }
}

List_ptr set_expectation(Element *values, int length)
{
  List_ptr expected = create_list();
  expected->length = 0;
  if (length > 0)
  {

    expected->first = create_node(values[0]);
    expected->last = expected->first;
    expected->length = expected->length + 1;
  }
  for (int i = 1; i < length; i++)
  {
    Node_ptr node = create_node(values[i]);
    expected->last->next = node;
    expected->last = node;
    ++expected->length;
  }
  return expected;
}

void assert_display_msg(char *msg, List_ptr actual, List_ptr expected, Types type)
{
  if (assert_lists(actual, expected, type))
  {

    printf("✅ %s\n", msg);
  }
  else
  {
    printf("❌ %s\n", msg);
  }
}
Status assert_values(Element num1, Element num2, Types type)
{
  Status status;
  switch (type)
  {
  case INT:
    status = (*(int *)&num1 == *(int *)&num2);
    break;
  case FLOAT:
    status = (*(float *)&num1 == *(float *)&num2);
    break;
  case CHAR:
    status = (*(char *)&num1 == *(char *)&num2);
    break;
  default:
    break;
  }
  return status;
}
Status assert_lists(List_ptr actual, List_ptr expected, Types type)
{
  if (!(actual->length == expected->length))
  {
    return Failure;
  }
  if (actual->length == expected->length && expected->length == 0)
  {
    return Success;
  }
  Node_ptr p_walkA = actual->first;
  Node_ptr p_walkB = expected->first;

  while (p_walkB != NULL)
  {
    if (!assert_values(p_walkA->element, p_walkB->element, type))
    {
      return Failure;
    }
    p_walkB = p_walkB->next;
    p_walkA = p_walkA->next;
  }
  return Success;
}

void test_add_to_list()
{

  List_ptr list = create_list();
  int values1[] = {1};
  Element e;
  *(int *)&e = 1;
  Element *void_values = malloc(sizeof(Element) * 3);
  create_array_int(values1, 1, void_values);
  List_ptr expected = set_expectation(void_values, 1);
  add_to_list(list, e);
  assert_display_msg("adding the first node to list", list, expected, INT);
  clear_list(expected);
  int values2[] = {1, 2};
  *(int *)&e = 2;
  add_to_list(list, e);
  create_array_int(values2, 2, void_values);
  expected = set_expectation(void_values, 2);
  assert_display_msg("adding number at last of existing list with numbers ", list, expected, INT);
  clear_list(expected);
}

void test_add_to_start()
{
  List_ptr list = create_list();
  int values1[] = {1};
  Element e;
  *(int *)&e = 1;
  Element *void_values = malloc(sizeof(Element) * 3);
  create_array_int(values1, 1, void_values);
  List_ptr expected = set_expectation(void_values, 1);
  add_to_start(list, e);
  assert_display_msg("adding the first node to list", list, expected, INT);
  clear_list(expected);
  int values2[] = {2, 1};
  *(int *)&e = 2;
  add_to_start(list, e);
  create_array_int(values2, 2, void_values);
  expected = set_expectation(void_values, 2);
  assert_display_msg("adding number at start of existing list with numbers ", list, expected, INT);
  clear_list(expected);
}

void test_insert_at()
{
  List_ptr list = create_list();
  int values1[] = {1};
  Element e;
  *(int *)&e = 1;
  Element *void_values = malloc(sizeof(Element) * 3);
  create_array_int(values1, 1, void_values);
  List_ptr expected = set_expectation(void_values, 1);
  insert_at(list, e, 0);
  assert_display_msg("insert at 0th position of empty list", list, expected, INT);
  clear_list(expected);
  int values2[] = {1, 2};
  create_array_int(values2, 2, void_values);
  expected = set_expectation(void_values, 2);
  *(int *)&e = 2;
  insert_at(list, e, 1);
  assert_display_msg("insert at last position of list", list, expected, INT);
  clear_list(expected);
  int values3[] = {1, 3, 2};
  create_array_int(values3, 3, void_values);
  expected = set_expectation(void_values, 3);
  *(int *)&e = 3;
  insert_at(list, e, 1);
  assert_display_msg("insert in middle position of list", list, expected, INT);
  clear_list(expected);
}
void display_int(List_ptr list)
{
  Node_ptr p_walk = list->first;
  while (p_walk != NULL)
  {
    printf("%d\n", *(int *)&p_walk->element);
    p_walk = p_walk->next;
  }
}
void test_remove_at()
{
  List_ptr list = create_list();
  int values1[] = {};
  Element e;
  *(int *)&e = 1;
  add_to_list(list, e);
  Element *void_values = malloc(sizeof(Element) * 10);
  create_array_int(values1, 0, void_values);
  List_ptr expected = set_expectation(void_values, 0);
  remove_at(list, 0);
  assert_display_msg("remove at 0th position of empty list", list, expected, INT);
  clear_list(expected);
  int values2[] = {1};
  create_array_int(values2, 1, void_values);
  expected = set_expectation(void_values, 1);
  *(int *)&e = 1;
  add_to_list(list, e);
  *(int *)&e = 2;
  add_to_list(list, e);
  remove_at(list, 1);
  clear_list(expected);

  assert_display_msg("remove at last position of list", list, expected, INT);
  clear_list(expected);
  int values3[] = {1, 2, 4, 5};
  create_array_int(values3, 4, void_values);
  expected = set_expectation(void_values, 4);
  *(int *)&e = 2;
  add_to_list(list, e);
  *(int *)&e = 3;
  add_to_list(list, e);
  *(int *)&e = 4;
  add_to_list(list, e);
  *(int *)&e = 5;
  add_to_list(list, e);
  remove_at(list, 2);
  assert_display_msg("remove from middle position of list", list, expected, INT);
  clear_list(expected);
}
