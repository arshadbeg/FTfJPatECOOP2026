
/*@
  ensures (a < b) ==> \result==b - a;
  ensures !(a < b) ==> \result==a - b;
*/
int distance(int a,int b){
	if(a < b)
		return b - a ;
	else
		return a - b ;
}