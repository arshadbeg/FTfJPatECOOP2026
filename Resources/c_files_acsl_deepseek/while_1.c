/*@
  loop invariant 0 <= i <= size;
  loop invariant 0 <= max < size || (i == 0 && max == 0);
  loop invariant \forall integer j; 0 <= j < i ==> u[j] <= u[max];
  loop assigns i, max;
  loop variant size - i;
*/
while (i < size) {
        if (u[i] > u[max]) { max = i; }
        i++;
    }
    return max;
}
