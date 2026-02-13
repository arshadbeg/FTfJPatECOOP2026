/*@ predicate inv_vec_Int(int  * x0, int  x1) = ((x1==0) || ((x1>0) &&
\valid(x0+(0..x1-1))));*/
/*@ predicate eq_vec_Int(int  * x16, int  x17, int  * x18, int  x19) = ((x17==x19) &&
(\forall int x23; (0<=x23<x17) ==> (x16[x23]==x18[x23])));*/
/*@
requires (inv_vec_Int(x16,x17) &&
inv_vec_Int(x18,x19));
assigns \nothing;
ensures (inv_vec_Int(x16,x17) &&
inv_vec_Int(x18,x19));
ensures \result <==> eq_vec_Int(x16, x17, x18, x19);
*/