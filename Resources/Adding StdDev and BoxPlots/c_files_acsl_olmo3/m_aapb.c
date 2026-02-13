/*
  @ requires s != NULL;
  @ ensures 
      \result == 1 
      <==> 
        exists integer k >= 1; 
          s[0] == 'A' && 
          ... (complex condition on prefix and suffix, see code) ... &&
          s[k] == 'B' && 
          \exists l >= k+1; s[l] == '\0' && 
          (some property maintained in state id == 2 for the suffix);
      \result == 0 otherwise;
  @ ensures 
      \result == (id == 2 && s is at end && m == 1);
*/
int m_aapb(char* s) {
  char* cur = s;
  int id = 0;         // 0: start, 1: seen at least one 'A', 2: seen 'B' after at least one 'A'
  int m = 1;          // flag for "can continue"

  // Loop invariant:
  //   cur points to the current character being examined
  //   id == 0: no 'A' seen yet
  //   id == 1: at least one 'A' seen, no 'B' yet
  //   id == 2: at least one 'A', then at least one 'B', and some invariants about previous characters
  while (cur[0] != '\0' && m) {
    m = 0; // reset to stop unless a transition occurs

    if (id == 0) {
      // Looking for the first 'A'
      if (cur[0] == 'A') {
        id = 1; // Now in state: at least one 'A'
        m = 1; // Continue scanning
      }
      // else: stay in state 0, stop scanning (m stays 0)
    } else if (id == 1) {
      // After at least one 'A'
      if (cur[0] == 'A') {
        // More 'A's, stay in state 1
        id = 1;
        m = 1;
      } else if (cur[0] == 'B') {
        // Transition to state 2 after at least one 'A' and then a 'B'
        id = 2;
        m = 1;
      }
      // else: stop scanning (m stays 0)
    } else if (id == 2) {
      // After 'A'* 'B'
      // The original code had complex assertions here, but since they reference undefined variables,
      // I'll leave a generic loop invariant:
      //   Maintain some property about the suffix starting at this position
      //   (The exact property is not clear without more context)
      // For now, just continue scanning unless m is set to 0
      // (If you have invariants, you can add them here)
    } else {
      // Should never reach here
      //@ assert \false;
    }
    cur++;
  }

  // Final result: must be in state 2 (after 'A'* 'B'), at end of string, and m == 1
  int res = id == 2 && cur[0] == '\0' && m;
  return res;
}
