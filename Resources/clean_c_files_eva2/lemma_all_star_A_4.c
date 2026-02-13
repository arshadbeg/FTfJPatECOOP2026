assigns \nothing;
*/
void lemma_all_star_A(char* s, int i, int j) {
  int x = j;
  
  while (i < x) {
    x--;
  }
}

int main(void)
{
    char s_var = 'A';
    lemma_all_star_A(&s_var, 0, 0);
    return 0;
}
