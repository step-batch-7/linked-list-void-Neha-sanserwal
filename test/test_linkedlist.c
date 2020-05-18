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

    expected->first = create_node(&values[0]);
    expected->last = expected->first;
    expected->length = expected->length + 1;
  }
  for (int i = 1; i < length; i++)
  {
    Node_ptr node = create_node(&values[i]);
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
    status = (*(int *)num1 == *(int *)num2);
    break;
  case FLOAT:
    status = (*(float *)num1 == *(float *)num2);
    break;
  case CHAR:
    status = (*(char *)num1 == *(char *)num2);
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
  Element *void_values = malloc(sizeof(Element) * 2);
  create_array_int(values1, 1, void_values);
  List_ptr expected = set_expectation(void_values, 1);
  int element = 1;
  Element e = &element;
  add_to_list(list, e);
  assert_display_msg("adding the first node to list", list, expected, INT);
  clear_list(expected);
  int values2[] = {1, 2};
  create_array_int(values2, 2, void_values);
  expected = set_expectation(void_values, 2);
  int element2 = 2;
  e = &element2;
  add_to_list(list, e);
  assert_display_msg("adding number at last of existing list with numbers ", list, expected, INT);
  clear_list(expected);
  clear_list(list);
}

void test_add_to_start()
{
  List_ptr list = create_list();
  int values1[] = {1};
  Element *void_values = malloc(sizeof(Element) * 2);
  create_array_int(values1, 1, void_values);
  List_ptr expected = set_expectation(void_values, 1);
  int element = 1;
  Element e = &element;
  add_to_start(list, e);
  assert_display_msg("adding the first node to list", list, expected, INT);
  clear_list(expected);
  int values2[] = {2, 1};
  create_array_int(values2, 2, void_values);
  expected = set_expectation(void_values, 2);
  int element2 = 2;
  e = &element2;
  add_to_start(list, e);
  assert_display_msg("adding number at start of existing list with numbers ", list, expected, INT);
  clear_list(expected);
}

void test_insert_at()
{
  List_ptr list = create_list();
  int values1[] = {1};
  Element e;
  int element = 1;
  e = &element;
  Element *void_values = malloc(sizeof(Element) * 3);
  create_array_int(values1, 1, void_values);
  List_ptr expected = set_expectation(void_values, 1);
  insert_at(list, e, 0);
  assert_display_msg("insert at 0th position of empty list", list, expected, INT);
  clear_list(expected);
  int values2[] = {1, 2};
  int element2 = 2;
  e = &element2;
  void_values = malloc(sizeof(Element) * 3);
  create_array_int(values2, 2, void_values);
  expected = set_expectation(void_values, 2);
  insert_at(list, e, 1);
  assert_display_msg("insert at last position of list", list, expected, INT);
  clear_list(expected);
  int values3[] = {1, 3, 2};
  int element3 = 3;
  e = &element3;
  create_array_int(values3, 3, void_values);
  expected = set_expectation(void_values, 3);
  insert_at(list, e, 1);
  assert_display_msg("insert in middle position of list", list, expected, INT);
  clear_list(expected);
}

void test_remove_at()
{
  List_ptr list = create_list();
  int values1[] = {};
  int element1 = 1;
  Element e = &element1;
  Element *void_values = malloc(sizeof(Element) * 5);
  create_array_int(values1, 0, void_values);
  List_ptr expected = set_expectation(void_values, 0);
  remove_at(list, -1);
  assert_display_msg("should not remove from invalid position of empty list", list, expected, INT);
  add_to_list(list, e);
  remove_at(list, 0);
  assert_display_msg("remove at 0th position of empty list", list, expected, INT);
  clear_list(expected);
  int values2[] = {1};
  create_array_int(values2, 1, void_values);
  expected = set_expectation(void_values, 1);
  add_to_list(list, e);
  int element2 = 2;
  e = &element2;
  add_to_list(list, e);
  remove_at(list, 1);
  assert_display_msg("remove at last position of list", list, expected, INT);
  clear_list(expected);

  int values3[] = {1, 2, 4, 5};
  create_array_int(values3, 4, void_values);
  expected = set_expectation(void_values, 4);
  element2 = 2;
  e = &element2;
  add_to_list(list, e);
  int element3 = 3;
  e = &element3;
  add_to_list(list, e);
  int element4 = 4;
  e = &element4;
  add_to_list(list, e);
  int element5 = 5;
  e = &element5;
  add_to_list(list, e);
  remove_at(list, 2);
  assert_display_msg("remove from middle position of list", list, expected, INT);
  clear_list(expected);
}

void test_remove_from_end()
{
  List_ptr list = create_list();
  int values1[] = {};
  int element1 = 1;
  Element e = &element1;
  add_to_list(list, e);
  Element *void_values = malloc(sizeof(Element) * 5);
  create_array_int(values1, 0, void_values);
  List_ptr expected = set_expectation(void_values, 0);
  remove_from_end(list);
  assert_display_msg("remove single element list", list, expected, INT);
  clear_list(expected);
  int values2[] = {1};
  create_array_int(values2, 1, void_values);
  expected = set_expectation(void_values, 1);
  element1 = 1;
  e = &element1;
  add_to_list(list, e);
  int element2 = 2;
  e = &element2;
  add_to_list(list, e);
  remove_from_end(list);
  assert_display_msg("remove from last position of list more than one element", list, expected, INT);
  clear_list(expected);
  int values3[] = {1, 2, 3, 4};
  create_array_int(values3, 4, void_values);
  expected = set_expectation(void_values, 4);
  element2 = 2;
  e = &element2;
  add_to_list(list, e);
  int element3 = 3;
  e = &element3;
  add_to_list(list, e);
  int element4 = 4;
  e = &element4;
  add_to_list(list, e);
  int element5 = 5;
  e = &element5;
  add_to_list(list, e);
  remove_from_end(list);
  assert_display_msg("remove from last position of long list", list, expected, INT);
  clear_list(expected);
}

void test_remove_from_start()
{
  List_ptr list = create_list();
  int values1[] = {};
  int element1 = 1;
  Element e = &element1;
  add_to_list(list, e);
  Element *void_values = malloc(sizeof(Element) * 5);
  create_array_int(values1, 0, void_values);
  List_ptr expected = set_expectation(void_values, 0);
  remove_from_start(list);
  assert_display_msg("remove from start single element list", list, expected, INT);
  clear_list(expected);
  int values2[] = {1};
  create_array_int(values2, 1, void_values);
  expected = set_expectation(void_values, 1);
  element1 = 2;
  e = &element1;
  add_to_list(list, e);
  int element2 = 1;
  e = &element2;
  add_to_list(list, e);
  remove_from_start(list);
  assert_display_msg("remove from first position of list more than one element", list, expected, INT);
  clear_list(expected);
  int values3[] = {2, 3, 4, 5};
  create_array_int(values3, 4, void_values);
  expected = set_expectation(void_values, 4);
  element2 = 2;
  e = &element2;
  add_to_list(list, e);
  int element3 = 3;
  e = &element3;
  add_to_list(list, e);
  int element4 = 4;
  e = &element4;
  add_to_list(list, e);
  int element5 = 5;
  e = &element5;
  add_to_list(list, e);
  remove_from_start(list);
  assert_display_msg("remove from start position of long list", list, expected, INT);
  clear_list(expected);
}

void test_remove_first_occurrence()
{
  List_ptr list = create_list();
  int values1[] = {1};
  Element *void_values = malloc(sizeof(Element) * 2);
  create_array_int(values1, 1, void_values);
  List_ptr expected = set_expectation(void_values, 1);
  int element = 1;
  Element e = &element;
  add_to_list(list, e);
  int element_to_remove = 2;
  Element element_ptr = &element_to_remove;
  remove_first_occurrence(list, element_ptr, matcher_int);
  assert_display_msg("should not remove the single element list if doesn't match matches", list, expected, INT);
  int values2[] = {};
  *void_values = malloc(sizeof(Element) * 2);
  create_array_int(values2, 0, void_values);
  expected = set_expectation(void_values, 0);
  element_to_remove = 1;
  remove_first_occurrence(list, element_ptr, matcher_int);
  assert_display_msg("remove the  single element list if matches", list, expected, INT);
  remove_first_occurrence(list, element_ptr, matcher_int);
  assert_display_msg("should not execute operation of removing from Empty list", list, expected, INT);
  clear_list(expected);
}

void test_remove_all_occurrences()
{
  List_ptr list = create_list();
  int values1[] = {};
  Element *void_values = malloc(sizeof(Element) * 2);
  create_array_int(values1, 0, void_values);
  List_ptr expected = set_expectation(void_values, 0);
  int element = 1;
  Element e = &element;
  add_to_list(list, e);
  int element_to_remove = 2;
  Element element_ptr = &element_to_remove;
  List_ptr n_list = remove_all_occurrences(list, element_ptr, matcher_int);
  assert_display_msg("should not remove the single element list if doesn't match matches", n_list, expected, INT);
  int values2[] = {1};
  *void_values = malloc(sizeof(Element) * 2);
  create_array_int(values2, 1, void_values);
  expected = set_expectation(void_values, 1);
  element_to_remove = 1;
  n_list = remove_all_occurrences(list, element_ptr, matcher_int);
  assert_display_msg("remove the  single element list if matches", n_list, expected, INT);
  n_list = remove_all_occurrences(list, element_ptr, matcher_int);
  clear_list(expected);
  int values3[] = {2, 2, 2};
  *void_values = malloc(sizeof(Element) * 2);
  create_array_int(values3, 3, void_values);
  expected = set_expectation(void_values, 3);
  int element2 = 2;
  e = &element2;
  add_to_list(list, e);
  int element3 = 2;
  e = &element3;
  add_to_list(list, e);
  int element4 = 4;
  e = &element4;
  add_to_list(list, e);
  int element5 = 2;
  e = &element5;
  add_to_list(list, e);
  element_to_remove = 2;
  n_list = remove_all_occurrences(list, element_ptr, matcher_int);
  assert_display_msg("should remove multiple elements if matches", n_list, expected, INT);
}

void test_add_unique()
{
  List_ptr list = create_list();
  int values1[] = {1};
  Element *void_values = malloc(sizeof(Element) * 2);
  create_array_int(values1, 1, void_values);
  List_ptr expected = set_expectation(void_values, 1);
  int element = 1;
  Element e = &element;
  add_to_list(list, e);
  int element_to_add = 1;
  Element element_ptr = &element_to_add;
  add_unique(list, element_ptr, matcher_int);
  assert_display_msg("should not add element in the list if element already exist", list, expected, INT);
  int values2[] = {1, 2};
  *void_values = malloc(sizeof(Element) * 2);
  create_array_int(values2, 2, void_values);
  expected = set_expectation(void_values, 2);
  element_to_add = 2;
  add_unique(list, element_ptr, matcher_int);
  assert_display_msg("remove the  single element list if matches", list, expected, INT);
  clear_list(expected);
}

void test_reverse()
{
  List_ptr list = create_list();
  int values1[] = {};
  Element *void_values = malloc(sizeof(Element) * 2);
  create_array_int(values1, 0, void_values);
  List_ptr expected = set_expectation(void_values, 0);
  int element = 1;
  Element e = &element;
  reverse(list);
  assert_display_msg("should reverse empty list", list, expected, INT);
  add_to_list(list, e);
  int values2[] = {2, 1};
  *void_values = malloc(sizeof(Element) * 2);
  create_array_int(values2, 2, void_values);
  expected = set_expectation(void_values, 2);
  int element2 = 2;
  e = &element2;
  add_to_list(list, e);
  reverse(list);
  assert_display_msg("should reverse list of more than one element", list, expected, INT);
  clear_list(expected);
}

void test_map()
{
  List_ptr list = create_list();
  int values1[] = {1};
  Element *void_values = malloc(sizeof(Element) * 1);
  create_array_int(values1, 1, void_values);
  List_ptr expected = set_expectation(void_values, 1);
  int element = 0;
  Element e = &element;
  add_to_list(list, e);
  list = map(list, add_one);
  assert_display_msg("should add one to the list containing one element", list, expected, INT);
  clear_list(expected);
   clear_list(list);
  int values2[] = {1,2,3,4};
  *void_values = malloc(sizeof(Element) * 4);
  create_array_int(values2, 4, void_values);
  expected = set_expectation(void_values, 4);
  int element1 = 0;
  e = &element1;
  add_to_list(list, e);
  int element2 = 1;
  e = &element2;
  add_to_list(list, e);
  int element3 = 2;
  e = &element3;
  add_to_list(list, e);
  int element4 = 3;
  e = &element4;
  add_to_list(list, e);
  list = map(list, add_one);
  assert_display_msg("should add one to each element of the list containing more than one element", list, expected, INT);
}

void test_filter()
{
  List_ptr list = create_list();
  int values1[] = {};
  Element *void_values = malloc(sizeof(Element) * 0);
  create_array_int(values1, 0, void_values);
  List_ptr expected = set_expectation(void_values, 0);
  List_ptr n_list = filter(list,is_even);
  assert_display_msg("should predicate for the list containing no element", n_list, expected, INT);
  int element = 1;
  Element e = &element;
  add_to_list(list, e);
  n_list = filter(list,is_even);
  assert_display_msg("should filter the even number from  the list containing one element", n_list, expected, INT);
  clear_list(expected);
  clear_list(list);
  int values2[] = {2,4};
  *void_values = malloc(sizeof(Element) * 2);
  create_array_int(values2, 2, void_values);
  expected = set_expectation(void_values, 2);
  int element1 = 1;
  e = &element1;
  add_to_list(list, e);
  int element2 = 2;
  e = &element2;
  add_to_list(list, e);
  int element3 = 3;
  e = &element3;
  add_to_list(list, e);
  int element4 = 4;
  e = &element4;
  add_to_list(list, e);
  n_list = filter(list, is_even);
  assert_display_msg("should filter the even number from the list containing more than one element", n_list, expected, INT);
}