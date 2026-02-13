/*@
  ensures (('a'<= c && c <='z') ==> \result==1;
  ensures !(('a'<= c && c <='z') ==> \result==0;
*/
int alphabet_letter(char c){
	if( ('a'<= c && c <='z') || ('A' <= c && c <='Z') ) return 1;
	else return 0;
}