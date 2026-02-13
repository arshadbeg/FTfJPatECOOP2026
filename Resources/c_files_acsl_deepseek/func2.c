/*@ requires a > 0 && b > 0 && c > 0;
    requires a + b > c && b + c > a && c + a > b; // triangle inequality
    requires a >= b && a >= c; // a is the largest side (hypotenuse)
    assigns \nothing;
    ensures \result == right <==> (a*a == b*b + c*c);
    ensures \result == acute <==> (a*a < b*b + c*c);
    ensures \result == obtuse <==> (a*a > b*b + c*c);
*/
enum type2 func2(int a,int b,int c){
    //since a is assumed as hypotenuse
    if(a*a==b*b+c*c) return right;
    else if (a*a<b*b+c*c) return acute;
    else return obtuse;
}
