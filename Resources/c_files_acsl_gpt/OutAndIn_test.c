/*@
  assigns \nothing;
*/
void OutAndIn_test(void)
{
  int a = 5;
  int b = 0;

  OutAndIn(&a, &b);

  /*@ assert b == 5; */
}

