#include <limits.h>
#include <string.h>

/*@
  requires \valid_read(x0);
  requires \exists integer n; x0[n] == '\0';
  assigns \nothing;
  ensures \result == 0;
*/
int dfa(char *x0) {
  int x2 = 1;
  int x3 = 0;
  char *x5 = x0;

  for (;;) {
    char x8 = x5[0];
    if (!(x8 != '\0' && x2)) break;
    x5 = x5 + 1;
  }

  return (x5[0] == '\0' && x2 && x3 == 2);
}

