
int max_ptr(int* a,int* b){
	return(*a > *b) ? *a: *b ;
}
extern int h ;

int main(void)
{
    int a_var = 42;
    int b_var = 42;
    max_ptr(&a_var, &b_var);
    return 0;
}
