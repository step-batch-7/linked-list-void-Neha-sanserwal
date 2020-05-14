#include "linkedlist.h"
#include <stdlib.h>

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
    list->first = node;
    list->last = node;
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
  if (!list->first)
  {
    return removed_element;
  }
  Node_ptr p_walk = list->first;
  list->first = p_walk->next;
  list->length = list->length - 1;
  removed_element = p_walk->element;
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
  list->length = list->length - 1;
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
  removed_element = temp;
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