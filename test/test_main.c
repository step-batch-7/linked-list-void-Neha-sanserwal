#include <stdio.h>
typedef enum
{
  INT,
  FLOAT,
  CHAR
} Types;

typedef enum Bool
{
  TRUE,
  FALSE
} Bool;

void assert_display_msg(char *msg, void *actual, void *expected, Types type)
{

  if (assert_numbers(actual, expected, type))
  {

    printf("✅ %s\n", msg);
  }
  else
  {
    printf("❌ %s\n", msg);
  }
}

int main()
{

  return 0;
}
