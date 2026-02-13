/*@ 
  assigns \nothing;
  ensures \result == (a < b ? a : b);
*/
int min(int a, int b){
    if(a < b)
        return a;
    else
        return b;
}

