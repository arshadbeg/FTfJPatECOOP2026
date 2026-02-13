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
    int a_var[1] = {0};
    is_sorted(a_var, 0);
    return 0;
}
