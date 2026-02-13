/*
  @ requires -\infty < i;
  @ ensures 
      ((0 <= i && i <= 9) ==> \result == i + '0') 
      && 
      ((i < 0 || i > 9) ==> \result == ' ');
*/
char e(int i) {
  return (0 <= i && i <= 9) ? i + '0' : ' ';
}
