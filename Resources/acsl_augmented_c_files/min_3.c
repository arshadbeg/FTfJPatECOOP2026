
/*@
  ensures (a<b) ==> \result==a;
  ensures !(a<b) ==> \result==b;
*/
int min(int a, int b){
	if(a<b)
		return a;
	else
		return b;
}