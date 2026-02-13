/*@
predicate matchhere(char* r, char* s) =
 (r[0]=='\0') ||
 (r[0]!='\0' && r[1]=='*' &&
   (\exists int i; 0 <= i <= strlen(s) && matchhere(r+2, s+i) &&
   (r[0]=='.' || (\forall int j; 0 <= j < i ==> r[0]==s[j])))) ||
 (r[0]=='$' && r[1]=='\0' && s[0]=='\0') ||
 ((s[0]!='\0' && (r[0]=='.' || r[0]==s[0])) &&
  matchhere(r+1, s+1));
*/