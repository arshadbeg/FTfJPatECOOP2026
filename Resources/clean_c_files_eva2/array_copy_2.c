void array_copy(int *src, int *dst, int n) {
    if (src < dst) {
        // recopier de droite à gauche
        
        for (int i = n-1; -1 < i; i--) {
            dst[i] = src[i];
        }
    } else {
        // recopier de gauche à droite
        
        for (int i = 0; i < n; i++) {
            dst[i] = src[i];
        }
    }
}

int main(void)
{
    int src_var = 0;
    int dst_var = 0;
    array_copy(&src_var, &dst_var, 0);
    return 0;
}
