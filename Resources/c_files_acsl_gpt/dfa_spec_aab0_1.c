/*@
  requires \valid_read(r);
  requires \valid_read(s);
  requires \exists integer n; r[n] == '\0';
  requires \exists integer m; s[m] == '\0';
  assigns \nothing;
*/
void dfa_spec_aab0(char* r, char* s) {}

