/*@ 
  requires u != \null;
  requires size > 0;
  assigns \nothing; // if just returning max
  ensures 0 <= \result < size;
  ensures \forall integer i; 0 <= i < size ==> u[\result] >= u[i];
*/
int find_max_index(int* u, int size) {
    int i = 1, max = 0;
    while (i < size) {
        if (u[i] > u[max]) { max = i; }
        i++;
    }
    return max;
}

