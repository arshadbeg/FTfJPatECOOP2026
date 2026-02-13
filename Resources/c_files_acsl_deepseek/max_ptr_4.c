/*@ requires \valid(a) && \valid(b);
    assigns \nothing;
    ensures \result >= *a && \result >= *b;
    ensures \result == *a || \result == *b;
    ensures (*a > *b) ==> \result == *a;
    ensures (*a <= *b) ==> \result == *b;
*/
int max_ptr(int* a,int* b){
    return(*a > *b) ? *a: *b ;
}
