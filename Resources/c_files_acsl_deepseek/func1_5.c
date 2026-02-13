/*@ requires a > 0 && b > 0 && c > 0; // triangle sides must be positive
    requires a + b > c && b + c > a && c + a > b; // triangle inequality
    assigns \nothing;
    ensures \result == equilateral <==> (a == b && b == c);
    ensures \result == isoscele <==> ((a == b && b != c) || (b == c && c != a) || (c == a && a != b));
    ensures \result == scalene <==> (a != b && b != c && c != a);
*/
enum type1 func1(int a,int b,int c){
    if(a==b && b==c) return equilateral;
    else if(a==b || b==c || c==a) return isoscele;
    else return scalene;
}
