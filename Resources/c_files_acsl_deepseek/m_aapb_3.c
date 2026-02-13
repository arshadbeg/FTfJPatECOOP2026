/*@ requires \valid(s);
    assigns \nothing;
    ensures \result == 0 || \result == 1;
    behavior accepts_aapb:
      ensures \result == 1 ==> \exists integer i,j; 0 <= i < j && s[i] == 'A' && s[i+1] == 'A' && s[j] == 'B' && s[j+1] == '\0';
    behavior rejects:
      ensures \result == 0 ==> !(\exists integer i,j; 0 <= i < j && s[i] == 'A' && s[i+1] == 'A' && s[j] == 'B' && s[j+1] == '\0');
*/
int m_aapb(char* s) {
  char* cur = s;
  int id = 0;
  int m = 1;
  
  /*@ loop invariant \valid(s) && \valid(cur);
      loop invariant s <= cur;
      loop invariant id == 0 || id == 1 || id == 2;
      loop invariant m == 0 || m == 1;
      loop invariant id == 0 ==> \forall integer k; s <= k < cur ==> \at(s[k], Pre) != 'A';
      loop invariant id == 1 ==> (\exists integer k; s <= k < cur && \at(s[k], Pre) == 'A') && 
                                (\forall integer k; s <= k < cur-1 ==> \at(s[k], Pre) == 'A');
      loop invariant id == 2 ==> (\exists integer i,j; 0 <= i < j && s[i] == 'A' && s[i+1] == 'A' && s[j] == 'B');
      loop assigns cur, id, m;
      loop variant \max(0, INT_MAX - (cur - s));
  */
  while (cur[0]!='\0' && m) {
    m = 0;
    if (id == 0) {
      if (cur[0] == 'A') {
        id = 1;
        m = 1;
      } else {
      }
    } else if (id == 1) {
      if (cur[0] == 'A') {
        id = 1;
        m = 1;
      } else if (cur[0] == 'B') {
        id = 2;
        m = 1;
      } else {
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
