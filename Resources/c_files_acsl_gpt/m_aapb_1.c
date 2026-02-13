/*@
  requires s != \null;
  assigns \nothing;
  ensures \result == 1 <==> (
      // The string represents the language A*B
      \exists int i; 
        0 <= i && i < \strlen(s) &&
        (\forall int j; 0 <= j < i ==> s[j] == 'A') &&
        s[i] == 'B' &&
        (\forall int k; i+1 <= k < \strlen(s) ==> s[k] != 'A' && s[k] != 'B')
  );
*/
int m_aapb(char* s) {
  char* cur = s;
  int id = 0;
  int m = 1;
  
  while (cur[0]!='\0' && m) {
    m = 0;
    if (id == 0) {
      if (cur[0] == 'A') {
        id = 1;
        m = 1;
      } else {
        // nothing
      }
    } else if (id == 1) {
      if (cur[0] == 'A') {
        id = 1;
        m = 1;
      } else if (cur[0] == 'B') {
        id = 2;
        m = 1;
      } else {
        // nothing
      }
    } else if (id == 2) {
      //@assert (id == 2) ==> bwd2(s, 0, i);
      //@assert bwd2(s, 0, i);
      //@assert !bwd0(s, 0, i+1);
      //@assert s[i-1]!='A';
      //@ghost lemma_star_A_not(s, 1, i-1, i+1);
      //@assert !star_A(s, 1, i+1);
      //@assert !bwd1(s, 0, i+1);
      //@ghost lemma_star_A_not(s, 1, i-1, i);
      //@assert !star_A(s, 1, i);
      //@assert !bwd2(s, 0, i+1);
    } else {
      //@assert \false;
    }
    cur++;
  }
  
  int res = id==2 && cur[0]=='\0' && m;
  return res;
}

