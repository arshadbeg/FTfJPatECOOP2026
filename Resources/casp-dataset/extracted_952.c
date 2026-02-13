/*@
predicate star_A(char* s, integer i, integer j) = 
  i==j || (j>i && (s[i]=='A' && star_A(s, i+1, j)));
predicate match_aapb(char* s, integer i, integer j) =
 s[i]=='A' && \exists integer m; i<m<j && star_A(s,i+1,m) && s[m]=='B' && s[m+1]=='\0' && m+1==j;
predicate bwd0(char* s, integer i, integer j) = i>=j;
predicate bwd1(char* s, integer i, integer j) =  s[i]=='A' && \exists integer m; i<m<=j && star_A(s,i+1,m) && m>=j;
predicate bwd2(char* s, integer i, integer j) =
 s[i]=='A' && \exists integer m; i<m<j && star_A(s,i+1,m) && s[m]=='B' && m+1>=j;
*/