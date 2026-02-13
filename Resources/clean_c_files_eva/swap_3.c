
 void swap(int* a, int* b){
 int tmp = *a;
 *a = *b;
 *b = tmp;
 }

int main(void)
{
    int a_var = 42;
    int b_var = 42;
    swap(&a_var, &b_var);
    return 0;
}
