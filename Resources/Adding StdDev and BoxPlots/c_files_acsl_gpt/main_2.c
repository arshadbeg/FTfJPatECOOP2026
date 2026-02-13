/*@ 
  assigns a, b; 
  ensures a == \old(b) && b == \old(a);
*/
int main()
{
   int a=13,b=14;
   swap(&a,&b);
}
