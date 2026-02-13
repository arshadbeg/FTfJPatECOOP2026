
int max2(int *r, int* i, int* j) {
if (!r) return -1;
*r = (*i < *j) ? *j : *i;

int main(void)
{
    int r_var = 0;
    int i_var = 0;
    int j_var = 0;
    max2(&r_var, &i_var, &j_var);
    return 0;
}
