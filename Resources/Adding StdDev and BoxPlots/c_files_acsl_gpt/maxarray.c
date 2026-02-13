/*@ 
  requires u != \null;
  requires size > 0;
  assigns max;
  ensures 0 <= max < size;
  ensures (\forall int k; 0 <= k < size ==> u[max] >= u[k]);
*/
int maxarray(int u[], int size) {
    int i = 1;
    max = 0;
    for (; i < size; i++)
        if (u[i] > u[max])
            max = i;
    return max;
}

