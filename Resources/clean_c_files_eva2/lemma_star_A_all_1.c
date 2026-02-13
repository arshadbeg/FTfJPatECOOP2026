void lemma_star_A_all(char* s, int i, int j) {
  int x = i;
  
  while (x < j) {
    x++;
  }
}

int main(void)
{
    char s_var = 'A';
    lemma_star_A_all(&s_var, 0, 0);
    return 0;
}
