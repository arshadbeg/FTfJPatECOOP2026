
int is_sorted(int a[],int n){
    
    for (int i=1;i<n;i++){
        if (a[i-1]>a[i]){
            return 0;
        }
    }
        return 1;
}

int main(void)
{
    int a_var[4] = {1, 2, 3, 4};
    is_sorted(a_var, 42);
    return 0;
}
