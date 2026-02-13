/*@
  requires s != \null;
  requires i <= j;
  assigns \nothing;
  ensures \true; // function does not change memory, only calls ghost lemmas
*/
void lemma_star_A_dec(char* s, int i, int j) {
  //@ghost lemma_star_A_all(s, i, j);
  //@ghost lemma_all_star_A(s, i, j-1);
}

