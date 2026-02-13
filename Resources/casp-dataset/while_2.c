/*@ loop invariant
      @     0 <= max <  i <= size &&
      @     (\forall integer a;
      @         0 <= a < i ==> u[a] <= u[max]);
      @ loop assigns i, max;
      @ loop variant size-i;
      @*/
    while (i < size) {
        if (u[i] > u[max]) { max = i; }
        i++;
    }
    return max;
}