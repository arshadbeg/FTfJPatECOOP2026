[kernel] Warning: no input file.
[kernel] Parsing func2.c (with preprocessing)
[kernel] func2.c:1: User Error: 
  forward declaration of enum only allowed for GCC machdeps; see option -machdep or run 'frama-c -machdep help' for the list of available machdeps
[kernel] func2.c:3: User Error: 
  Cannot resolve variable right
  1     enum type2 func2(int a,int b,int c){
  2     	//since a is assumed as hypotenuse
  3     	if(a*a==b*b+c*c) return right;
                                 ^^^^^
  4     	else if (a*a<b*b+c*c) return acute;
  5     	else return obtuse;
[kernel] Frama-C aborted: invalid user input.
