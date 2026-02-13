/*@ 
  requires p != \null;
  requires 0 <= n;
  assigns \nothing;
  ensures 0 <= \result && \result <= p[n-1]; // informal: returns an element from array
*/
int pick_element(int* p, int n) {
    int i = pick_index(n); // assumed to return 0 <= i < n
    return p[i];
}

