assigns \nothing;
*/
void dfa_spec_aab1(char* r, char* s) {}

int main(void)
{
    char r_var = 'x';
    char s_var = 'x';
    dfa_spec_aab1(&r_var, &s_var);
    return 0;
}
