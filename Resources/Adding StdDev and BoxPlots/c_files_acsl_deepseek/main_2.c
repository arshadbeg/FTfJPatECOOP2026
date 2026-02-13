/*@ requires \valid_function(swap);
    ensures \result == 0;
*/
int main()
 {
   int a=13,b=14;
   swap(&a,&b);
 }
