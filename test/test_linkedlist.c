#include "../linkedlist.c"
#include "test_linkedlist.h"
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
  List_ptr expected = create_list();
  int value = 1;
  Element e = &value;
  Node_ptr node = create_node(e);
  expected->first = node;
  expected->last = node;
  expected->length = 1;
  add_to_list(list, e);
  assert_display_msg("adding the first node to list", list, expected, INT);

  value = 2;
  node = create_node(e);
  expected->length = 2;
  add_to_list(list, e);
  assert_display_msg("adding number at last of existing list with numbers ", list, expected, INT);
}

void test_add_to_start()
{
}