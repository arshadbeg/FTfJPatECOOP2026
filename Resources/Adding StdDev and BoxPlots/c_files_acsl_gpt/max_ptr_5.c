/*@ 
  requires a != \null && b != \null;
  assigns \nothing;
  ensures \result == (*a > *b ? *a : *b);
*/
int max_ptr(int* a,int* b){
    return (*a > *b) ? *a : *b;
}

