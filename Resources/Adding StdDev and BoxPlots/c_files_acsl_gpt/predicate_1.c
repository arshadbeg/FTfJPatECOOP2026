/*@ 
  assigns \nothing;
  ensures \result == (v % 2 == 0);
*/
int predicate(int v) {
    return v % 2 == 0;
}

