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

/*@ ensures h == 42;
*/
extern int h ;

/*@ ensures \result == 0;
*/
int main(){
    h =42;
    int a =24,b =42;
    int x= max_ptr(&a,&b);
}
