/*@ 
  requires p != \null && q != \null;
  assigns *p, *q;
  ensures *p <= *q;
  ensures *p == \old(*p) || *p == \old(*q);
  ensures *q == \old(*p) || *q == \old(*q);
*/
void max_ptr(int* p, int* q) { 
    if (*p > *q) { 
        int tmp = *p; 
        *p = *q; 
        *q = tmp; 
    } 
}

