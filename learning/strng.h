#include <stdio.h>

int main(void)
{
  char *c_ptr[] = {"Global", "Edge", "Software",     "Limited"};
  char **cp[] = { c_ptr + 3,  c_ptr + 2, c_ptr  + 1, c_ptr};
  char ***cpp = cp;

  printf("%s\n", **++cpp);
  printf("%s\n", *--*++cpp + 3);
  printf("%s\n", *cpp[-2] + 3);
  printf("%s\n", cpp[-1][-1] + 1);
	return 0;
}
