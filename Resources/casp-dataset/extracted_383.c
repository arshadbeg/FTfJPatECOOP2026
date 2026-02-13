/*@ predicate matcher_a_or_b(char  * x0) = ((((x0[0]=='\0')) ? (\false) : (((x0[0]=='a') &&
((x0+1)[0]=='\0')))) || (((x0[0]=='\0')) ? (\false) : (((x0[0]=='b') &&
((x0+1)[0]=='\0')))));*/
/*@
requires ((strlen(x0)>=0) &&
\valid(x0+(0..(strlen(x0)+1)-1)));
assigns \nothing;
ensures \result <==> matcher_a_or_b(x0);
*/