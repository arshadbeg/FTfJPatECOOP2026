/*@ 
  requires a != \null;
  requires res != \null;
  requires size >= 0;
  assigns res[0..size-1];
  ensures \forall integer i; 0 <= i < size ==> res[i] == a[size - i - 1];
*/
void reverse(int a[], int res[], int size) {
    int i;
    for (i = size - 1; i >= 0; --i) {
        res[i] = a[size - i - 1];
    }
}

