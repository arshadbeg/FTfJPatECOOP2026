/*@ assigns \nothing;
    ensures \result >= 0;
    ensures \result == (a < b ? b - a : a - b);
    ensures \result == (a >= b ? a - b : b - b);
*/
int distance(int a,int b){
    if(a < b)
        return b - a ;
    else
        return a - b ;
}
