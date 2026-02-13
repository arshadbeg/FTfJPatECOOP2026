assigns \nothing;
*/
int m_aapb(char* s) {
  char* cur = s;
  int id = 0;
  int m = 1;
  //@ghost int i = 0;
  /*@
    loop invariant strlen(s)>=0 && \valid(s+(0..strlen(s)));
    loop invariant strlen(cur)>=0 && \valid(cur+(0..strlen(cur)));
    loop invariant 0<=i<=strlen(s);
    loop invariant (id == 0) && m ==> bwd0(s, 0, i);
    loop invariant (id == 1) && m ==> bwd1(s, 0, i);
    loop invariant (id == 2) && m ==> bwd2(s, 0, i);
    loop invariant (m == 0) ==> !bwd0(s, 0, i) && !bwd1(s, 0, i) && !bwd2(s, 0, i);
    loop invariant (id == 0) && !m ==> s[0]!='A';
    loop invariant (id == 1) && !m ==> s[i-1]!='A' && s[i-1]!='B';
    loop invariant (id == 2) && !m ==> s[i-2]=='B';
    loop invariant (id == 0) && !m ==> bwd0(s, 0, i-1);
    loop invariant (id == 1) && !m ==> bwd1(s, 0, i-1);
    loop invariant (id == 2) && !m ==> bwd2(s, 0, i-1);
    loop invariant (id == 2) && cur[0]=='\0' && m ==> match_aapb(s, 0, i);
    loop invariant (id != 2) || cur[0]!='\0' || !m ==> !match_aapb(s, 0, i);
    loop invariant (id == 0) || (id == 1) || (id == 2);
    loop invariant cur==s+i;
    loop invariant cur[0]==s[i];
    loop assigns cur, id, i, m;
    loop variant strlen(cur);
   */
  while (cur[0]!='\0' && m) {
    m = 0;
    if (id == 0) {
      //@assert (id == 0) ==> bwd0(s, 0, i);
      //@assert bwd0(s, 0, i);
      //@assert i==0;
      if (cur[0] == 'A') {
        id = 1;
        //@ghost lemma01(s, 0, i);
        //@assert bwd1(s, 0, i+1);
        m = 1;
      } else {
        //@assert !bwd0(s, 0, i+1) && !bwd1(s, 0, i+1) && !bwd2(s, 0, i+1);
      }
    } else if (id == 1) {
      //@assert (id == 1) ==> bwd1(s, 0, i);
      //@assert bwd1(s, 0, i);
      if (cur[0] == 'A') {
        //@ghost lemma11(s, 0, i);
        id = 1;
        //@assert bwd1(s, 0, i+1);
        m = 1;
      } else if (cur[0] == 'B') {
        //@ghost lemma12(s, 0, i);
        id = 2;
        //@assert bwd2(s, 0, i+1);
        //@ghost lemma2f(s, 0, i+1);
        m = 1;
      } else {
        //@assert !bwd0(s, 0, i+1);
        //@assert s[i]!='A';
        //@ghost lemma_star_A_not(s, 1, i, i+1);
        //@assert !bwd1(s, 0, i+1);
        //@assert !bwd2(s, 0, i+1);
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
    //@ghost i++;
  }
  int res = id==2 && cur[0]=='\0' && m;
  /*@ghost
  if (!res) {
    if (!m) {
      //@assert i>=1;
      //@assert !match_aapb(s, 0, i);
      //@assert !bwd2(s, 0, i);
      int x = i;
      int j = strlen(s);
      if (id==0) {
        //@assert s[0]!='A';
        //@assert !bwd2(s, 0, j);
      } else if (id==1) {
        //@assert s[i-1]!='A' && s[i-1]!='B';
        //@assert s[i-1]!='A';
        if (i-1<j-1) {
          //@ghost lemma_star_A_not(s, 1, i-1, j-1);
        } else {
          //@assert i==j;
        }
        //@assert !bwd2(s, 0, j);
      } else if (id==2) {
        //@assert s[i-2]=='B';
        //@assert s[i-2]!='A';
        //@ghost lemma_star_A_not(s, 1, i-2, j-1);
        //@assert !bwd2(s, 0, j);
      }
      //@assert !bwd2(s, 0, strlen(s));
      //@assert !match_aapb(s, 0, strlen(s));
    }
  }
  */
  return res;
}