#include "linkedlist.h"
#include <stdlib.h>
Status matcher_int(Element elementA, Element elementB)
{
  return *(int *)elementA == *(int *)elementB;
}

Status matcher_float(Element elementA, Element elementB)
{
  return *(float *)elementA == *(float *)elementB;
}

Element add_one(Element element)
{
  ++*(int *)element;
  return element;
}
void multiply_two(Element element)
{
  *(int *)element = *(int *)element * 2;
}

Status is_even(Element element)
{
  return *(int *)element % 2 == 0;
}

Element greatest_of_two(Element elementA, Element elementB)
{
  return *(int *)elementA > *(int *)elementB ? elementA : elementB;
}

Node_ptr walk_to(Node_ptr p_walk, int from, int position)
{
  for (int i = from; i < position; i++)
  {
    p_walk = p_walk->next;
  }
  return p_walk;
}

List_ptr assign_first_and_last(List_ptr list, Node_ptr ptr)
{
  list->first = ptr;
  list->last = ptr;
  return list;
}

List_ptr create_list()
{
  List_ptr list = malloc(sizeof(LinkedList));
  list->first = NULL;
  list->last = NULL;
  list->length = 0;
  return list;
}

Node_ptr create_node(Element element)
{
  Node_ptr node = malloc(sizeof(Node));
  node->element = element;
  node->next = NULL;
  return node;
}

Status add_to_list(List_ptr list, Element element)
{
  Node_ptr node = create_node(element);
  if (list->first == NULL)
  {
    assign_first_and_last(list, node);
    ++list->length;
    return Success;
  }

  list->last->next = node;
  list->last = node;
  ++list->length;
  return Success;
}
Status add_to_start(List_ptr list, Element element)
{
  Node_ptr node = create_node(element);
  if (list->first == NULL)
  {
    list->first = node;
    list->last = node;
    ++list->length;
    return Success;
  }
  node->next = list->first;
  list->first = node;
  ++list->length;
  return Success;
}

Status insert_at(List_ptr list, Element element, int position)
{
  if (position > list->length || position < 0)
  {
    return Failure;
  }
  if (position == 0)
  {
    return add_to_start(list, element);
  }
  if (position == list->length)
  {
    return add_to_list(list, element);
  }
  Node_ptr p_walk = list->first;
  Node_ptr node = create_node(element);
  p_walk = walk_to(p_walk, 1, position);
  node->next = p_walk->next;
  p_walk->next = node;
  ++list->length;
  return Success;
}

Element remove_from_start(List_ptr list)
{
  Element removed_element = NULL;
  if (list->first == NULL)
  {
    return removed_element;
  }
  Node_ptr p_walk = list->first;
  list->first = p_walk->next;
  list->length = list->length - 1;
  removed_element = p_walk->element;
  if (list->first == NULL)
  {
    list->last = NULL;
  }
  free(p_walk);

  return removed_element;
}
Element remove_from_end(List_ptr list)
{
  Element removed_element = NULL;
  Node_ptr p_walk = list->first;
  if (!p_walk)
  {
    return removed_element;
  }
  if (list->length == 1)
  {
    removed_element = p_walk->element;
    free(p_walk);
    list = assign_first_and_last(list, NULL);
    list->length = list->length - 1;
    return removed_element;
  }
  p_walk = walk_to(p_walk, 2, list->length);
  list->last = p_walk;
  removed_element = p_walk->next->element;
  free(p_walk->next);
  p_walk->next = NULL;
  --list->length;
  return removed_element;
}

Element remove_at(List_ptr list, int position)
{
  Node_ptr p_walk = list->first;
  Element removed_element = NULL;
  if (position > list->length - 1 || position < 0 || !p_walk)
  {
    return removed_element;
  }
  if (position == list->length - 1)
  {
    return remove_from_end(list);
  }
  if (position == 0)
  {
    return remove_from_start(list);
  }
  p_walk = walk_to(p_walk, 1, position);
  Node_ptr temp = p_walk->next;
  p_walk->next = temp->next;
  removed_element = temp->element;
  free(temp);
  --list->length;
  return removed_element;
}

Status clear_list(List_ptr list)
{
  while (list->length)
  {
    Node_ptr p_walk = list->first;
    list->first = p_walk->next;
    free(p_walk);
    list->length = list->length - 1;
  }
  list = assign_first_and_last(list, NULL);
  if (list->length == 0)
  {
    return Success;
  }
  return Failure;
}

Element does_exist(Element value, List_ptr list, Matcher matcher)
{
  Element position = malloc(sizeof(int));
  *(int *)position = -1;
  Node_ptr p_walk = list->first;
  for (int i = 0; i < list->length; i++)
  {
    if (matcher(p_walk->element, value))
    {
      *(int *)position = i;
      return position;
    }
    p_walk = p_walk->next;
  }
  return position;
}

Element remove_first_occurrence(List_ptr list, Element value, Matcher matcher)
{

  Element element_removed = does_exist(value, list, matcher);
  if (*(int *)element_removed == -1)
  {
    return NULL;
  }
  element_removed = remove_at(list, *(int *)element_removed);
  return element_removed;
}

List_ptr remove_all_occurrences(List_ptr list, Element value, Matcher matcher)
{
  Element element = remove_first_occurrence(list, value, matcher);
  List_ptr new_list = create_list();
  while (element != NULL)
  {
    add_to_list(new_list, element);
    element = remove_first_occurrence(list, value, matcher);
  }
  return new_list;
}

Status add_unique(List_ptr list, Element value, Matcher matcher)
{
  Element position = does_exist(value, list, matcher);
  if (*(int *)position != -1)
  {
    return Failure;
  }
  add_to_list(list, value);
  return Success;
}

List_ptr reverse(List_ptr list)
{
  if (!list->first)
  {
    return list;
  }

  Node_ptr temp_prev = NULL;
  list->last = list->first;
  Node_ptr temp_next = list->first->next;

  while (temp_next != NULL)
  {
    list->first->next = temp_prev;
    temp_prev = list->first;
    list->first = temp_next;
    temp_next = temp_next->next;
  }

  list->first->next = temp_prev;
  return list;
}

List_ptr map(List_ptr list, Mapper mapper)
{
  Node_ptr p_walk = list->first;
  while (p_walk != NULL)
  {
    p_walk->element = mapper(p_walk->element);
    p_walk = p_walk->next;
  }
  return list;
}

List_ptr filter(List_ptr list, Predicate Predicate)
{
  Node_ptr p_walk = list->first;
  List_ptr filtered_list = create_list();
  while (p_walk != NULL)
  {
    if (Predicate(p_walk->element))
    {
      add_to_list(filtered_list, p_walk->element);
    }
    p_walk = p_walk->next;
  }

  return filtered_list;
}

Element reduce(List_ptr list, Element initial_value, Reducer reducer)
{
  Node_ptr p_walk = list->first;
  while (p_walk != NULL)
  {
    initial_value = reducer(p_walk->element, initial_value);
    p_walk = p_walk->next;
  }
  return initial_value;
}
void forEach(List_ptr list, ElementProcessor processor)
{
  Node_ptr p_walk = list->first;
  while (p_walk != NULL)
  {
    processor(p_walk->element);
    p_walk = p_walk->next;
  }
}