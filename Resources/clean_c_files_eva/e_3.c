char e(int i) {
  return (0 <= i && i <= 9) ? i + '0' : ' ';
}

int main(void)
{
    
    e(42);
    return 0;
}
