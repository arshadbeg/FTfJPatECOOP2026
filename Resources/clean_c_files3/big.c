// OutAndIn.c
@ ensures *o == *i;
*/
void OutAndIn(int *i, int *o) {
  *o = *i;
}

// OutAndIn_1.c
void OutAndIn(int *i, int *o) {
  *o = *i;
}

// OutAndIn_2.c
void OutAndIn(int *i, int *o) {
  *o = *i;
}

// OutAndIn_test.c
void OutAndIn_test()
{
	int a = 5;
	int b = 0;
	OutAndIn(&a, &b);
	
}

// alphabet_letter.c

int alphabet_letter(char c){
	if( ('a'<= c && c <='z') || ('A' <= c && c <='Z') ) return 1;
	else return 0;
}
int main(){
	int ch ;
	ch = alphabet_letter('x') ;
	
	ch = alphabet_letter('H') ;
	
	ch = alphabet_letter(' ') ;
	
}

// alphabet_letter_1.c
int alphabet_letter(char c){
	if( ('a'<= c && c <='z') || ('A' <= c && c <='Z') ) return 1;
	else return 0;
}

// alphabet_letter_2.c
int alphabet_letter(char c){
	if( ('a'<= c && c <='z') || ('A' <= c && c <='Z') ) return 1;
	else return 0;
}

// array_copy.c

void array_copy(int *src, int *dst, int n) {
    if (src < dst) {
        // recopier de droite à gauche
        
        for (int i = n-1; -1 < i; i--) {
            dst[i] = src[i];
        }
    } else {
        // recopier de gauche à droite
        
        for (int i = 0; i < n; i++) {
            dst[i] = src[i];
        }
    }
}

// array_copy_1.c
void array_copy(int *src, int *dst, int n) {
    if (src < dst) {
        // recopier de droite à gauche
        
        for (int i = n-1; -1 < i; i--) {
            dst[i] = src[i];
        }
    } else {
        // recopier de gauche à droite
        
        for (int i = 0; i < n; i++) {
            dst[i] = src[i];
        }
    }
}

// array_copy_2.c
void array_copy(int *src, int *dst, int n) {
    if (src < dst) {
        // recopier de droite à gauche
        
        for (int i = n-1; -1 < i; i--) {
            dst[i] = src[i];
        }
    } else {
        // recopier de gauche à droite
        
        for (int i = 0; i < n; i++) {
            dst[i] = src[i];
        }
    }
}

// big.c


// bubbleinnerloop.c

void bubbleinnerloop(int a[], int n)
{
	
	for (int j = 0; j < n - 1; j++)
	{
		if (a[j] > a[j + 1])
		{
			int temp = a[j];
			a[j] = a[j + 1];
			a[j + 1] = temp;
		}
	}
}

// bubbleinnerloop_1.c
void bubbleinnerloop(int a[], int n)
{
	
	for (int j = 0; j < n - 1; j++)
	{
		if (a[j] > a[j + 1])
		{
			int temp = a[j];
			a[j] = a[j + 1];
			a[j + 1] = temp;
		}
	}
}

// bubbleinnerloop_2.c
void bubbleinnerloop(int a[], int n)
{
	
	for (int j = 0; j < n - 1; j++)
	{
		if (a[j] > a[j + 1])
		{
			int temp = a[j];
			a[j] = a[j + 1];
			a[j + 1] = temp;
		}
	}
}

// clamp.c

int clamp(int v, int min, int max)
{
	int low = v > min ? v : min;
	return low < max ? low : max;
}

// clamp_1.c
int clamp(int v, int min, int max)
{
	int low = v > min ? v : min;
	return low < max ? low : max;
}

// clamp_2.c
int clamp(int v, int min, int max)
{
	int low = v > min ? v : min;
	return low < max ? low : max;
}

// countSameConsecutive.c

int countSameConsecutive(int N, int x[]) {
	int best = 0, i = 0;
	// we try to maintain an essence of current best in order to reach total (best)
	// for that we replace N <- i+1 (to look until i array positions)
	
	while (i < N) {
		int j = i+1;
		// while we are inside the second loop everything allequ for j-i 
		// (starting from i) matrix positions is maintained
		
		while (j < N && x[j] == x[i]) ++j;
		if (j-i > best) best = j-i;
		i = j;
	}
	return best;
}

// countSameConsecutive_1.c
int countSameConsecutive(int N, int x[]) {
	int best = 0, i = 0;
	// we try to maintain an essence of current best in order to reach total (best)
	// for that we replace N <- i+1 (to look until i array positions)
	
	while (i < N) {
		int j = i+1;
		// while we are inside the second loop everything allequ for j-i 
		// (starting from i) matrix positions is maintained
		
		while (j < N && x[j] == x[i]) ++j;
		if (j-i > best) best = j-i;
		i = j;
	}
	return best;
}

// countSameConsecutive_2.c
int countSameConsecutive(int N, int x[]) {
	int best = 0, i = 0;
	// we try to maintain an essence of current best in order to reach total (best)
	// for that we replace N <- i+1 (to look until i array positions)
	
	while (i < N) {
		int j = i+1;
		// while we are inside the second loop everything allequ for j-i 
		// (starting from i) matrix positions is maintained
		
		while (j < N && x[j] == x[i]) ++j;
		if (j-i > best) best = j-i;
		i = j;
	}
	return best;
}

// d.c

int d(char c) {
  return ('0' <= c && c <= '9') ? c - '0' : -1;
}

// d_1.c
int d(char c) {
  return ('0' <= c && c <= '9') ? c - '0' : -1;
}

// d_2.c
int d(char c) {
  return ('0' <= c && c <= '9') ? c - '0' : -1;
}

// d_3.c

int d(char c) {
  return ('0' <= c && c <= '9') ? c - '0' : -1;
}

// d_4.c

int d(char c) {
  return ('0' <= c && c <= '9') ? c - '0' : -1;
}

// d_5.c

int d(char c) {
  return ('0' <= c && c <= '9') ? c - '0' : -1;
}

// de.c

int de(int i) {
  return d(e(i));
}

// de_1.c

int de(int i) {
  return d(e(i));
}

// ded.c

int ded(char c) {
  return d(e(d(c)));
}

// ded_1.c

int ded(char c) {
  return d(e(d(c)));
}

// dfa.c
#include <limits.h>
#include <string.h>

int dfa(char  * x0) {
  int x2 = 1/*true*/;
  int x3 = 0;
  
  char  *x5 = x0;
  
  for (;;) {
    char  *x7 = x5;
    char x8 = x7[0];
    int x9 = x8 == '\0';
    int x13;
    if (x9) {
      x13 = 0/*false*/;
    } else {
      int x11 = x2;
      x13 = x11;
    }
    if (!x13) break;
    char  *x37 = x5;
    char  *x38 = x37+1;
    x5 = x38;
    
  }
  char  *x84 = x5;
  char x85 = x84[0];
  int x86 = x85 == '\0';
  int x89;
  if (x86) {
    int x87 = x2;
    x89 = x87;
  } else {
    x89 = 0/*false*/;
  }
  int x93;
  if (x89) {
    int x90 = x3;
    int x91 = x90 == 2;
    x93 = x91;
  } else {
    x93 = 0/*false*/;
  }
  
  return x93;
}

// dfa_1.c
int dfa(char  * x0) {
  int x2 = 1/*true*/;
  int x3 = 0;
  
  char  *x5 = x0;
  
  for (;;) {
    char  *x7 = x5;
    char x8 = x7[0];
    int x9 = x8 == '\0';
    int x13;
    if (x9) {
      x13 = 0/*false*/;
    } else {
      int x11 = x2;
      x13 = x11;
    }
    if (!x13) break;
    char  *x37 = x5;
    char  *x38 = x37+1;
    x5 = x38;
    
  }
  char  *x84 = x5;
  char x85 = x84[0];
  int x86 = x85 == '\0';
  int x89;
  if (x86) {
    int x87 = x2;
    x89 = x87;
  } else {
    x89 = 0/*false*/;
  }
  int x93;
  if (x89) {
    int x90 = x3;
    int x91 = x90 == 2;
    x93 = x91;
  } else {
    x93 = 0/*false*/;
  }
  
  return x93;
}

// dfa_2.c
int dfa(char  * x0) {
  int x2 = 1/*true*/;
  int x3 = 0;
  
  char  *x5 = x0;
  
  for (;;) {
    char  *x7 = x5;
    char x8 = x7[0];
    int x9 = x8 == '\0';
    int x13;
    if (x9) {
      x13 = 0/*false*/;
    } else {
      int x11 = x2;
      x13 = x11;
    }
    if (!x13) break;
    char  *x37 = x5;
    char  *x38 = x37+1;
    x5 = x38;
    
  }
  char  *x84 = x5;
  char x85 = x84[0];
  int x86 = x85 == '\0';
  int x89;
  if (x86) {
    int x87 = x2;
    x89 = x87;
  } else {
    x89 = 0/*false*/;
  }
  int x93;
  if (x89) {
    int x90 = x3;
    int x91 = x90 == 2;
    x93 = x91;
  } else {
    x93 = 0/*false*/;
  }
  
  return x93;
}

// dfa_3.c
#include <limits.h>
#include <string.h>

int dfa(char  * x0) {
  int x2 = 1/*true*/;
  int x3 = 0;
  
  char  *x5 = x0;
  
  for (;;) {
    char  *x7 = x5;
    char x8 = x7[0];
    int x9 = x8 == '\0';
    int x13;
    if (x9) {
      x13 = 0/*false*/;
    } else {
      int x11 = x2;
      x13 = x11;
    }
    if (!x13) break;
    char  *x39 = x5;
    char  *x40 = x39+1;
    x5 = x40;
    
  }
  char  *x86 = x5;
  char x87 = x86[0];
  int x88 = x87 == '\0';
  int x91;
  if (x88) {
    int x89 = x2;
    x91 = x89;
  } else {
    x91 = 0/*false*/;
  }
  int x95;
  if (x91) {
    int x92 = x3;
    int x93 = x92 == 3;
    x95 = x93;
  } else {
    x95 = 0/*false*/;
  }
  
  return x95;
}

// dfa_4.c
int dfa(char  * x0) {
  int x2 = 1/*true*/;
  int x3 = 0;
  
  char  *x5 = x0;
  
  for (;;) {
    char  *x7 = x5;
    char x8 = x7[0];
    int x9 = x8 == '\0';
    int x13;
    if (x9) {
      x13 = 0/*false*/;
    } else {
      int x11 = x2;
      x13 = x11;
    }
    if (!x13) break;
    char  *x39 = x5;
    char  *x40 = x39+1;
    x5 = x40;
    
  }
  char  *x86 = x5;
  char x87 = x86[0];
  int x88 = x87 == '\0';
  int x91;
  if (x88) {
    int x89 = x2;
    x91 = x89;
  } else {
    x91 = 0/*false*/;
  }
  int x95;
  if (x91) {
    int x92 = x3;
    int x93 = x92 == 3;
    x95 = x93;
  } else {
    x95 = 0/*false*/;
  }
  
  return x95;
}

// dfa_5.c
int dfa(char  * x0) {
  int x2 = 1/*true*/;
  int x3 = 0;
  
  char  *x5 = x0;
  
  for (;;) {
    char  *x7 = x5;
    char x8 = x7[0];
    int x9 = x8 == '\0';
    int x13;
    if (x9) {
      x13 = 0/*false*/;
    } else {
      int x11 = x2;
      x13 = x11;
    }
    if (!x13) break;
    char  *x39 = x5;
    char  *x40 = x39+1;
    x5 = x40;
    
  }
  char  *x86 = x5;
  char x87 = x86[0];
  int x88 = x87 == '\0';
  int x91;
  if (x88) {
    int x89 = x2;
    x91 = x89;
  } else {
    x91 = 0/*false*/;
  }
  int x95;
  if (x91) {
    int x92 = x3;
    int x93 = x92 == 3;
    x95 = x93;
  } else {
    x95 = 0/*false*/;
  }
  
  return x95;
}

// dfa_spec_aab0.c
assigns \nothing;
*/
void dfa_spec_aab0(char* r, char* s) {}

// dfa_spec_aab0_1.c
assigns \nothing;
*/
void dfa_spec_aab0(char* r, char* s) {}

// dfa_spec_aab0_2.c
assigns \nothing;
*/
void dfa_spec_aab0(char* r, char* s) {}

// dfa_spec_aab0_3.c
void dfa_spec_aab0(char* r, char* s) {}

// dfa_spec_aab0_4.c
void dfa_spec_aab0(char* r, char* s) {}

// dfa_spec_aab1.c
assigns \nothing;
*/
void dfa_spec_aab1(char* r, char* s) {}

// dfa_spec_aab1_1.c
assigns \nothing;
*/
void dfa_spec_aab1_1(char* r, char* s) {}

// dfa_spec_aab1_1_1.c
assigns \nothing;
*/
void dfa_spec_aab1_1(char* r, char* s) {}

// dfa_spec_aab1_1_2.c
void dfa_spec_aab1_1(char* r, char* s) {}

// dfa_spec_aab1_1_3.c
void dfa_spec_aab1_1(char* r, char* s) {}

// dfa_spec_aab1_1_4.c
assigns \nothing;
*/
void dfa_spec_aab1_1(char* r, char* s) {}

// dfa_spec_aab1_1_5.c
assigns \nothing;
*/
void dfa_spec_aab1_1(char* r, char* s) {}

// dfa_spec_aab1_1_6.c
assigns \nothing;
*/
void dfa_spec_aab1_1(char* r, char* s) {}

// dfa_spec_aab1_2.c
void dfa_spec_aab1(char* r, char* s) {}

// dfa_spec_aab1_3.c
void dfa_spec_aab1(char* r, char* s) {}

// dfa_spec_aab1_4.c
assigns \nothing;
*/
void dfa_spec_aab1(char* r, char* s) {}

// dfa_spec_aab1_5.c
assigns \nothing;
*/
void dfa_spec_aab1(char* r, char* s) {}

// dfa_spec_aab1_6.c
assigns \nothing;
*/
void dfa_spec_aab1(char* r, char* s) {}

// dfa_spec_aab1_7.c
assigns \nothing;
*/
void dfa_spec_aab1(char* r, char* s) {}

// dfa_spec_aab1_8.c
assigns \nothing;
*/
void dfa_spec_aab1(char* r, char* s) {}

// dfa_spec_aab1_9.c
assigns \nothing;
*/
void dfa_spec_aab1(char* r, char* s) {}

// distance.c

int distance(int a,int b){
	if(a < b)
		return b - a ;
	else
		return a - b ;
}

// distance_1.c
int distance(int a,int b){
	if(a < b)
		return b - a ;
	else
		return a - b ;
}

// distance_2.c
int distance(int a,int b){
	if(a < b)
		return b - a ;
	else
		return a - b ;
}

// e.c

char e(int i) {
  return (0 <= i && i <= 9) ? i + '0' : ' ';
}

// e_1.c

char e(int i) {
  return (0 <= i && i <= 9) ? i + '0' : ' ';
}

// e_2.c
char e(int i) {
  return (0 <= i && i <= 9) ? i + '0' : ' ';
}

// e_3.c
char e(int i) {
  return (0 <= i && i <= 9) ? i + '0' : ' ';
}

// ed.c

char ed(char c) {
  return e(d(c));
}

// ed_1.c

char ed(char c) {
  return e(d(c));
}

// ede.c

char ede(int i) {
  return e(d(e(i)));
}

// ede_1.c

char ede(int i) {
  return e(d(e(i)));
}

// eq_VC.c

// Contract and implementation for Vector[Char] equality

int eq_VC(char *a1, char *a2, int n1, int n2) {
  if (n1 != n2) return 0;
    
    for (int i = 0; i < n1; i++) {
      if (a1[i] != a2[i]) return 0;
    }
    return 1;
}
// Contract and implementation for Vector[Vector[Char]] equality

int eq_VVC(char **a1, char **a2, int *an1, int *an2, int n1, int n2) {
  if (n1 != n2) return 0;
    
    for (int i = 0; i < n1; i++) {
      if (eq_VC(a1[i],a2[i],an1[i],an2[i]) != 1) return 0;
    }
    return 1;
}

// eq_VC_1.c
int eq_VC(char *a1, char *a2, int n1, int n2) {
  if (n1 != n2) return 0;
    
    for (int i = 0; i < n1; i++) {
      if (a1[i] != a2[i]) return 0;
    }
    return 1;
}

// eq_VC_2.c
int eq_VC(char *a1, char *a2, int n1, int n2) {
  if (n1 != n2) return 0;
    
    for (int i = 0; i < n1; i++) {
      if (a1[i] != a2[i]) return 0;
    }
    return 1;
}

// eq_vec_Int.c
#include <limits.h>



int eq_vec_Int(int  * x16, int  x17, int  * x18, int  x19) {
  int x21 = x17 == x19;
  int x33;
  if (x21) {
    int x32 = 1;
    
    for (int x24 = 0; x24 < x17; x24++) {
      int x29 = x16[x24];
      int x30 = x18[x24];
      int x31 = x29 == x30;
      if (!x31) { x32 = 0; break; }
    }
    x33 = x32;
  } else {
    x33 = 0/*false*/;
  }
  return x33;
}



int eq_vec_vec_Int(int  * * x61, int  * x62, int  x63, int  * * x64, int  * x65, int  x66) {
  int x68 = x63 == x66;
  int x84;
  if (x68) {
    int x83 = 1;
    
    for (int x71 = 0; x71 < x63; x71++) {
      int  *x78 = x61[x71];
      int x79 = x62[x71];
      int  *x80 = x64[x71];
      int x81 = x65[x71];
      int x82 = eq_vec_Int(x78,x79,x80,x81);
      if (!x82) { x83 = 0; break; }
    }
    x84 = x83;
  } else {
    x84 = 0/*false*/;
  }
  return x84;
}

// eq_vec_Int_1.c
int eq_vec_Int(int  * x16, int  x17, int  * x18, int  x19) {
  int x21 = x17 == x19;
  int x33;
  if (x21) {
    int x32 = 1;
    
    for (int x24 = 0; x24 < x17; x24++) {
      int x29 = x16[x24];
      int x30 = x18[x24];
      int x31 = x29 == x30;
      if (!x31) { x32 = 0; break; }
    }
    x33 = x32;
  } else {
    x33 = 0/*false*/;
  }
  return x33;
}

// eq_vec_Int_2.c
int eq_vec_Int(int  * x16, int  x17, int  * x18, int  x19) {
  int x21 = x17 == x19;
  int x33;
  if (x21) {
    int x32 = 1;
    
    for (int x24 = 0; x24 < x17; x24++) {
      int x29 = x16[x24];
      int x30 = x18[x24];
      int x31 = x29 == x30;
      if (!x31) { x32 = 0; break; }
    }
    x33 = x32;
  } else {
    x33 = 0/*false*/;
  }
  return x33;
}

// func1.c
#include<stdio.h>
enum type1 {scalene,isoscele,equilateral};
enum type2 {right,acute,obtuse};

enum type1 func1(int a,int b,int c){
	if(a==b && b==c) return equilateral;
	else if(a==b || b==c || c==a) return isoscele;
	else return scalene;
}

enum type2 func2(int a,int b,int c){
	//since a is assumed as hypotenuse
	if(a*a==b*b+c*c) return right;
	else if (a*a<b*b+c*c) return acute;
	else return obtuse;
}

// func1_1.c
enum type1 func1(int a,int b,int c){
	if(a==b && b==c) return equilateral;
	else if(a==b || b==c || c==a) return isoscele;
	else return scalene;
}

// func1_2.c
enum type1 func1(int a,int b,int c){
	if(a==b && b==c) return equilateral;
	else if(a==b || b==c || c==a) return isoscele;
	else return scalene;
}

// func1_3.c
#include<stdio.h>
enum type1 {scalene,isoscele,equilateral};
enum type2 {right,acute,obtuse};

enum type1 func1(int a,int b,int c){
	if(a==b && b==c) return equilateral;
	else if(a==b || b==c || c==a) return isoscele;
	else return scalene;
}

enum type2 func2(int a,int b,int c){
	//since a is assumed as hypotenuse
	if(a*a==b*b+c*c) return right;
	else if (a*a<b*b+c*c) return acute;
	else return obtuse;
}

// func1_4.c

enum type1 func1(int a,int b,int c){
	if(a==b && b==c) return equilateral;
	else if(a==b || b==c || c==a) return isoscele;
	else return scalene;
}


// func1_5.c

enum type1 func1(int a,int b,int c){
	if(a==b && b==c) return equilateral;
	else if(a==b || b==c || c==a) return isoscele;
	else return scalene;
}


// func2.c
enum type2 func2(int a,int b,int c){
	//since a is assumed as hypotenuse
	if(a*a==b*b+c*c) return right;
	else if (a*a<b*b+c*c) return acute;
	else return obtuse;
}

// func2_1.c
enum type2 func2(int a,int b,int c){
	//since a is assumed as hypotenuse
	if(a*a==b*b+c*c) return right;
	else if (a*a<b*b+c*c) return acute;
	else return obtuse;
}

// gimmeOne.c

int gimmeOne() {
  return 1;
}

// gimmeOne_1.c
int gimmeOne() {
  return 1;
}

// gimmeOne_2.c
int gimmeOne() {
  return 1;
}

// if.c
if(0 <= nextNewLine && nextNewLine < nextSpace) {
      if(nextNewLine - lastChange > length && lastSpace >= 0) {
	s[lastSpace] = '\n';
      }
      lastChange = lastSpace = nextNewLine;
    } else {
      if(nextSpace - lastChange > length) {
	if(lastChange == lastSpace) {
	  s[nextSpace] = '\n';
	  lastChange = lastSpace = nextSpace;
	} else {
	  s[lastSpace] = '\n';
	  lastChange = lastSpace;
	}
      } else {
	lastSpace = nextSpace;
      }
    }
  }
  return;
}

// if_1.c

  for(j=p; j<r; j++) 
    if (A[j] <= x) { 
      i++; 
      tmp = A[i];
      A[i] = A[j];
      A[j] = tmp;
    } 
  tmp = A[i+1];
  A[i+1] = A[r];
  A[r] = tmp;
  return i+1; 
}

// if_2.c

  for(j=p; j<r; j++) 
    if (A[j] <= x) { 
      i++; 
      tmp = A[i];
      A[i] = A[j];
      A[j] = tmp;
    } 
  tmp = A[i+1];
  A[i+1] = A[r];
  A[r] = tmp;
  return i+1; 
}

// if_3.c

  for(j=p; j<r; j++) 
    if (A[j] <= x) { 
      i++; 
      tmp = A[i];
      A[i] = A[j];
      A[j] = tmp;
    } 
  tmp = A[i+1];
  A[i+1] = A[r];
  A[r] = tmp;
  return i+1; 
}

// index.c
#include <limits.h>

int index(int  x0, int  x1, int  x2, int  x3) {
  int x5 = x2 * x1;
  int x6 = x5 + x3;
  return x6;
}


void add(int  * x63, int  x64, int  x65, int  * x66, int  x67, int  x68, int  * x69, int  x70, int  x71) {
  
  for(int x76=0; x76 < x70; x76++) {
    
    for(int x78=0; x78 < x71; x78++) {
      int x79 = index(x64,x65,x76,x78);
      int x80 = x63[x79];
      int x81 = index(x67,x68,x76,x78);
      int x82 = x66[x81];
      int x83 = x80 || x82;
      int x84 = index(x70,x71,x76,x78);
      x69[x84] = x83;
    }
  }
}

void scalar_mult(int  x110, int  * x111, int  x112, int  x113, int  * x114, int  x115, int  x116) {
  
  for(int x121=0; x121 < x115; x121++) {
    
    for(int x123=0; x123 < x116; x123++) {
      int x126;
      if (x110) {
        int x124 = index(x112,x113,x121,x123);
        int x125 = x111[x124];
        x126 = x125;
      } else {
        x126 = 0/*false*/;
      }
      int x127 = index(x115,x116,x121,x123);
      x114[x127] = x126;
    }
  }
}

// indexOf.c

static int indexOf(char* s, char c, int from, int to) {
  
  for(int k = from; k < to; k++) {
    if(s[k] == c) {
      return k;
    }
  }
  return -1;
}

// indexOf_1.c
static int indexOf(char* s, char c, int from, int to) {
  
  for(int k = from; k < to; k++) {
    if(s[k] == c) {
      return k;
    }
  }
  return -1;
}

// indexOf_2.c
static int indexOf(char* s, char c, int from, int to) {
  
  for(int k = from; k < to; k++) {
    if(s[k] == c) {
      return k;
    }
  }
  return -1;
}

// index_1.c
int index(int  x0, int  x1, int  x2, int  x3) {
  int x5 = x2 * x1;
  int x6 = x5 + x3;
  return x6;
}

// index_2.c
int index(int  x0, int  x1, int  x2, int  x3) {
  int x5 = x2 * x1;
  int x6 = x5 + x3;
  return x6;
}

// index_where.c

int index_where(int* v, int n, int* o) {
  int r = 0;
  
  for (int i = 0; i < n; i++) {
    if (predicate(v[i])) {
      o[r++] = i;
    }
  }
  return r;
}

// inswap.c
#include <limits.h>

void inswap(int  * x0, int  x1, int  x2) {
  int x4 = x0[x1];
  int x5 = x0[x2];
  x0[x1] = x5;
  x0[x2] = x4;
}

void insort(int  * x25, int  x26) {
  int x29 = x26;
  
  for (;;) {
    int x30 = x29;
    int x31 = x30 > 1;
    if (!x31) break;
    int x33 = 0;
    int x34 = x29;
    
    for(int x36=0; x36 < x34; x36++) {
      int x37 = x25[x36];
      int x38 = x33;
      int x39 = x25[x38];
      int x40 = x37 >= x39;
      if (x40) {
        x33 = x36;
      } else {
      }
    }
    int x96 = x33;
    int x95 = x34 - 1;
    inswap(x25,x95,x96);
    
    
    
    x29 = x95;
  }
}

// inswap_1.c
void inswap(int  * x0, int  x1, int  x2) {
  int x4 = x0[x1];
  int x5 = x0[x2];
  x0[x1] = x5;
  x0[x2] = x4;
}

// inswap_2.c
void inswap(int  * x0, int  x1, int  x2) {
  int x4 = x0[x1];
  int x5 = x0[x2];
  x0[x1] = x5;
  x0[x2] = x4;
}

// is_nat.c
int is_nat(int  x3) {
  int x5 = x3 >= 0;
  return x5;
}

// is_nat_1.c
int is_nat(int  x3) {
  int x5 = x3 >= 0;
  return x5;
}

// is_pos.c
#include <limits.h>


int is_pos(int  x0) {
  int x2 = x0 > 0;
  return x2;
}


int is_nat(int  x3) {
  int x5 = x3 >= 0;
  return x5;
}

int minus1(int  x6) {
  int x8 = x6 - 1;
  return x8;
}

// is_pos_1.c
int is_pos(int  x0) {
  int x2 = x0 > 0;
  return x2;
}

// is_pos_2.c
int is_pos(int  x0) {
  int x2 = x0 > 0;
  return x2;
}

// is_pos_3.c
#include <limits.h>


int is_pos(int  x0) {
  int x2 = x0 > 0;
  return x2;
}


int is_nat(int  x3) {
  int x5 = x3 >= 0;
  return x5;
}

int minus1(int  x6) {
  int x8 = x6 - 1;
  return x8;
}

// is_pos_4.c


int is_pos(int  x0) {
  int x2 = x0 > 0;
  return x2;
}



// is_pos_5.c


int is_pos(int  x0) {
  int x2 = x0 > 0;
  return x2;
}



// is_pos_6.c
#include <limits.h>


int is_pos(int  x0) {
  int x2 = x0 > 0;
  return x2;
}


int is_nat(int  x3) {
  int x5 = x3 >= 0;
  return x5;
}

int minus1(int  x6) {
  int x8 = x6 - 1;
  return x8;
}

// is_pos_7.c


int is_pos(int  x0) {
  int x2 = x0 > 0;
  return x2;
}


int is_nat(int  x3) {
  int x5 = x3 >= 0;
  return x5;
}


// is_pos_8.c


int is_pos(int  x0) {
  int x2 = x0 > 0;
  return x2;
}


int is_nat(int  x3) {
  int x5 = x3 >= 0;
  return x5;
}


// is_sorted.c

int is_sorted(int a[],int n){
    
    for (int i=1;i<n;i++){
        if (a[i-1]>a[i]){
            return 0;
        }
    }
        return 1;
}

// is_sorted_1.c
int is_sorted(int a[],int n){
    
    for (int i=1;i<n;i++){
        if (a[i-1]>a[i]){
            return 0;
        }
    }
        return 1;
}

// is_sorted_2.c
int is_sorted(int a[],int n){
    
    for (int i=1;i<n;i++){
        if (a[i-1]>a[i]){
            return 0;
        }
    }
        return 1;
}

// lemma01.c
assigns \nothing;
*/
void lemma01(char* s, int i, int j) {
  //@assert j==0;
  //@assert star_A(s, j+1, j+1);
}

// lemma01_1.c
assigns \nothing;
*/
void lemma01(char* s, int i, int j) {
  //@assert j==0;
  //@assert star_A(s, j+1, j+1);
}

// lemma01_2.c
assigns \nothing;
*/
void lemma01(char* s, int i, int j) {
  //@assert j==0;
  //@assert star_A(s, j+1, j+1);
}

// lemma01_3.c
assigns \nothing;
*/
void lemma01(char* s, int i, int j) {
  //@assert j==0;
  //@assert star_A(s, j+1, j+1);
}

// lemma01_4.c
void lemma01(char* s, int i, int j) {
  //@assert j==0;
  //@assert star_A(s, j+1, j+1);
}

// lemma01_5.c
void lemma01(char* s, int i, int j) {
  //@assert j==0;
  //@assert star_A(s, j+1, j+1);
}

// lemma01_6.c
assigns \nothing;
*/
void lemma01(char* s, int i, int j) {
  //@assert j==0;
  //@assert star_A(s, j+1, j+1);
}

// lemma01_7.c
assigns \nothing;
*/
void lemma01(char* s, int i, int j) {
  //@assert j==0;
  //@assert star_A(s, j+1, j+1);
}

// lemma01_8.c
assigns \nothing;
*/
void lemma01(char* s, int i, int j) {
  //@assert j==0;
  //@assert star_A(s, j+1, j+1);
}

// lemma11.c
assigns \nothing;
*/
void lemma11(char* s, int i, int j) {
  //@assert s[0]=='A';
  //@assert star_A(s, 1, j);
  //@assert s[j]=='A';
  //@assert star_A(s, j+1, j+1);
  //@ghost lemma_star_A(s, 1, j, j+1);
  //@assert star_A(s, 1, j+1);
}

// lemma11_1.c
assigns \nothing;
*/
void lemma11(char* s, int i, int j) {
  //@assert s[0]=='A';
  //@assert star_A(s, 1, j);
  //@assert s[j]=='A';
  //@assert star_A(s, j+1, j+1);
  //@ghost lemma_star_A(s, 1, j, j+1);
  //@assert star_A(s, 1, j+1);
}

// lemma11_2.c
assigns \nothing;
*/
void lemma11(char* s, int i, int j) {
  //@assert s[0]=='A';
  //@assert star_A(s, 1, j);
  //@assert s[j]=='A';
  //@assert star_A(s, j+1, j+1);
  //@ghost lemma_star_A(s, 1, j, j+1);
  //@assert star_A(s, 1, j+1);
}

// lemma11_3.c
assigns \nothing;
*/
void lemma11(char* s, int i, int j) {
  //@assert s[0]=='A';
  //@assert star_A(s, 1, j);
  //@assert s[j]=='A';
  //@assert star_A(s, j+1, j+1);
  //@ghost lemma_star_A(s, 1, j, j+1);
  //@assert star_A(s, 1, j+1);
}

// lemma11_4.c
assigns \nothing;
*/
void lemma11(char* s, int i, int j) {
  //@assert s[0]=='A';
  //@assert star_A(s, 1, j);
  //@assert s[j]=='A';
  //@assert star_A(s, j+1, j+1);
  //@ghost lemma_star_A(s, 1, j, j+1);
  //@assert star_A(s, 1, j+1);
}

// lemma11_5.c
assigns \nothing;
*/
void lemma11(char* s, int i, int j) {
  //@assert s[0]=='A';
  //@assert star_A(s, 1, j);
  //@assert s[j]=='A';
  //@assert star_A(s, j+1, j+1);
  //@ghost lemma_star_A(s, 1, j, j+1);
  //@assert star_A(s, 1, j+1);
}

// lemma11_6.c
assigns \nothing;
*/
void lemma11(char* s, int i, int j) {
  //@assert s[0]=='A';
  //@assert star_A(s, 1, j);
  //@assert s[j]=='A';
  //@assert star_A(s, j+1, j+1);
  //@ghost lemma_star_A(s, 1, j, j+1);
  //@assert star_A(s, 1, j+1);
}

// lemma12.c
assigns \nothing;
*/
void lemma12(char* s, int i, int j) {
  //@assert bwd1(s, i, j);
  //@assert s[i]=='A';
  //@assert star_A(s, i+1, j);
  //@assert s[j]=='B';
  //@assert bwd2(s, i, j+1);
}

// lemma12_1.c
assigns \nothing;
*/
void lemma12(char* s, int i, int j) {
  //@assert bwd1(s, i, j);
  //@assert s[i]=='A';
  //@assert star_A(s, i+1, j);
  //@assert s[j]=='B';
  //@assert bwd2(s, i, j+1);
}

// lemma12_2.c
assigns \nothing;
*/
void lemma12(char* s, int i, int j) {
  //@assert bwd1(s, i, j);
  //@assert s[i]=='A';
  //@assert star_A(s, i+1, j);
  //@assert s[j]=='B';
  //@assert bwd2(s, i, j+1);
}

// lemma12_3.c
assigns \nothing;
*/
void lemma12(char* s, int i, int j) {
  //@assert bwd1(s, i, j);
  //@assert s[i]=='A';
  //@assert star_A(s, i+1, j);
  //@assert s[j]=='B';
  //@assert bwd2(s, i, j+1);
}

// lemma12_4.c
assigns \nothing;
*/
void lemma12(char* s, int i, int j) {
  //@assert bwd1(s, i, j);
  //@assert s[i]=='A';
  //@assert star_A(s, i+1, j);
  //@assert s[j]=='B';
  //@assert bwd2(s, i, j+1);
}

// lemma12_5.c
void lemma12(char* s, int i, int j) {
  //@assert bwd1(s, i, j);
  //@assert s[i]=='A';
  //@assert star_A(s, i+1, j);
  //@assert s[j]=='B';
  //@assert bwd2(s, i, j+1);
}

// lemma12_6.c
void lemma12(char* s, int i, int j) {
  //@assert bwd1(s, i, j);
  //@assert s[i]=='A';
  //@assert star_A(s, i+1, j);
  //@assert s[j]=='B';
  //@assert bwd2(s, i, j+1);
}

// lemma2f.c
assigns \nothing;
*/
void lemma2f(char* s, int i, int j) {
  //@assert bwd2(s, i, j);
  //@assert s[i]=='A';
  //@assert star_A(s, i+1, j-1);
  //@assert s[j-1]=='B';
  //@assert s[j]=='\0' ==> match_aapb(s, i, j);
}

// lemma2f_1.c
assigns \nothing;
*/
void lemma2f(char* s, int i, int j) {
  //@assert bwd2(s, i, j);
  //@assert s[i]=='A';
  //@assert star_A(s, i+1, j-1);
  //@assert s[j-1]=='B';
  //@assert s[j]=='\0' ==> match_aapb(s, i, j);
}

// lemma2f_2.c
assigns \nothing;
*/
void lemma2f(char* s, int i, int j) {
  //@assert bwd2(s, i, j);
  //@assert s[i]=='A';
  //@assert star_A(s, i+1, j-1);
  //@assert s[j-1]=='B';
  //@assert s[j]=='\0' ==> match_aapb(s, i, j);
}

// lemma2f_3.c
assigns \nothing;
*/
void lemma2f(char* s, int i, int j) {
  //@assert bwd2(s, i, j);
  //@assert s[i]=='A';
  //@assert star_A(s, i+1, j-1);
  //@assert s[j-1]=='B';
  //@assert s[j]=='\0' ==> match_aapb(s, i, j);
}

// lemma2f_4.c
assigns \nothing;
*/
void lemma2f(char* s, int i, int j) {
  //@assert bwd2(s, i, j);
  //@assert s[i]=='A';
  //@assert star_A(s, i+1, j-1);
  //@assert s[j-1]=='B';
  //@assert s[j]=='\0' ==> match_aapb(s, i, j);
}

// lemma_all_star_A.c
assigns \nothing;
*/
void lemma_all_star_A(char* s, int i, int j) {
  int x = j;
  
  while (i < x) {
    x--;
  }
}

// lemma_all_star_A_1.c
assigns \nothing;
*/
void lemma_all_star_A(char* s, int i, int j) {
  int x = j;
  
  while (i < x) {
    x--;
  }
}

// lemma_all_star_A_10.c
assigns \nothing;
*/
void lemma_all_star_A(char* s, int i, int j) {
  int x = j;
  
  while (i < x) {
    x--;
  }
}

// lemma_all_star_A_11.c
assigns \nothing;
*/
void lemma_all_star_A(char* s, int i, int j) {
  int x = j;
  
  while (i < x) {
    x--;
  }
}

// lemma_all_star_A_12.c
assigns \nothing;
*/
void lemma_all_star_A(char* s, int i, int j) {
  int x = j;
  
  while (i < x) {
    x--;
  }
}

// lemma_all_star_A_2.c
void lemma_all_star_A(char* s, int i, int j) {
  int x = j;
  
  while (i < x) {
    x--;
  }
}

// lemma_all_star_A_3.c
void lemma_all_star_A(char* s, int i, int j) {
  int x = j;
  
  while (i < x) {
    x--;
  }
}

// lemma_all_star_A_4.c
assigns \nothing;
*/
void lemma_all_star_A(char* s, int i, int j) {
  int x = j;
  
  while (i < x) {
    x--;
  }
}

// lemma_all_star_A_5.c
assigns \nothing;
*/
void lemma_all_star_A(char* s, int i, int j) {
  int x = j;
  
  while (i < x) {
    x--;
  }
}

// lemma_all_star_A_6.c
assigns \nothing;
*/
void lemma_all_star_A(char* s, int i, int j) {
  int x = j;
  
  while (i < x) {
    x--;
  }
}

// lemma_all_star_A_7.c
assigns \nothing;
*/
void lemma_all_star_A(char* s, int i, int j) {
  int x = j;
  
  while (i < x) {
    x--;
  }
}

// lemma_all_star_A_8.c
assigns \nothing;
*/
void lemma_all_star_A(char* s, int i, int j) {
  int x = j;
  
  while (i < x) {
    x--;
  }
}

// lemma_all_star_A_9.c
assigns \nothing;
*/
void lemma_all_star_A(char* s, int i, int j) {
  int x = j;
  
  while (i < x) {
    x--;
  }
}

// lemma_star_A.c
assigns \nothing;
*/
void lemma_star_A(char* s, int i, int j, int n) {
  int x = j;
  
  while (i < x) {
    
    
    
    
    
    
    x--;
  }
}

// lemma_star_A_1.c
assigns \nothing;
*/
void lemma_star_A(char* s, int i, int j, int n) {
  int x = j;
  
  while (i < x) {
    
    
    
    
    
    
    x--;
  }
}

// lemma_star_A_2.c
assigns \nothing;
*/
void lemma_star_A(char* s, int i, int j, int n) {
  int x = j;
  
  while (i < x) {
    
    
    
    
    
    
    x--;
  }
}

// lemma_star_A_3.c
assigns \nothing;
*/
void lemma_star_A(char* s, int i, int j, int n) {
  int x = j;
  
  while (i < x) {
    
    
    
    
    
    
    x--;
  }
}

// lemma_star_A_4.c
assigns \nothing;
*/
void lemma_star_A(char* s, int i, int j, int n) {
  int x = j;
  
  while (i < x) {
    
    
    
    
    
    
    x--;
  }
}

// lemma_star_A_5.c
assigns \nothing;
*/
void lemma_star_A(char* s, int i, int j, int n) {
  int x = j;
  
  while (i < x) {
    
    
    
    
    
    
    x--;
  }
}

// lemma_star_A_6.c
assigns \nothing;
*/
void lemma_star_A(char* s, int i, int j, int n) {
  int x = j;
  
  while (i < x) {
    
    
    
    
    
    
    x--;
  }
}

// lemma_star_A_7.c
assigns \nothing;
*/
void lemma_star_A(char* s, int i, int j, int n) {
  int x = j;
  
  while (i < x) {
    
    
    
    
    
    
    x--;
  }
}

// lemma_star_A_8.c
assigns \nothing;
*/
void lemma_star_A(char* s, int i, int j, int n) {
  int x = j;
  
  while (i < x) {
    
    
    
    
    
    
    x--;
  }
}

// lemma_star_A_all.c
assigns \nothing;
*/
void lemma_star_A_all(char* s, int i, int j) {
  int x = i;
  
  while (x < j) {
    x++;
  }
}

// lemma_star_A_all_1.c
void lemma_star_A_all(char* s, int i, int j) {
  int x = i;
  
  while (x < j) {
    x++;
  }
}

// lemma_star_A_all_10.c
assigns \nothing;
*/
void lemma_star_A_all(char* s, int i, int j) {
  int x = i;
  
  while (x < j) {
    x++;
  }
}

// lemma_star_A_all_11.c
assigns \nothing;
*/
void lemma_star_A_all(char* s, int i, int j) {
  int x = i;
  
  while (x < j) {
    x++;
  }
}

// lemma_star_A_all_12.c
assigns \nothing;
*/
void lemma_star_A_all(char* s, int i, int j) {
  int x = i;
  
  while (x < j) {
    x++;
  }
}

// lemma_star_A_all_13.c
assigns \nothing;
*/
void lemma_star_A_all(char* s, int i, int j) {
  int x = i;
  
  while (x < j) {
    x++;
  }
}

// lemma_star_A_all_14.c
assigns \nothing;
*/
void lemma_star_A_all(char* s, int i, int j) {
  int x = i;
  
  while (x < j) {
    x++;
  }
}

// lemma_star_A_all_2.c
void lemma_star_A_all(char* s, int i, int j) {
  int x = i;
  
  while (x < j) {
    x++;
  }
}

// lemma_star_A_all_3.c
assigns \nothing;
*/
void lemma_star_A_all(char* s, int i, int j) {
  int x = i;
  
  while (x < j) {
    x++;
  }
}

// lemma_star_A_all_4.c
assigns \nothing;
*/
void lemma_star_A_all(char* s, int i, int j) {
  int x = i;
  
  while (x < j) {
    x++;
  }
}

// lemma_star_A_all_5.c
assigns \nothing;
*/
void lemma_star_A_all(char* s, int i, int j) {
  int x = i;
  
  while (x < j) {
    x++;
  }
}

// lemma_star_A_all_6.c
assigns \nothing;
*/
void lemma_star_A_all(char* s, int i, int j) {
  int x = i;
  
  while (x < j) {
    x++;
  }
}

// lemma_star_A_all_7.c
assigns \nothing;
*/
void lemma_star_A_all(char* s, int i, int j) {
  int x = i;
  
  while (x < j) {
    x++;
  }
}

// lemma_star_A_all_8.c
assigns \nothing;
*/
void lemma_star_A_all(char* s, int i, int j) {
  int x = i;
  
  while (x < j) {
    x++;
  }
}

// lemma_star_A_all_9.c
assigns \nothing;
*/
void lemma_star_A_all(char* s, int i, int j) {
  int x = i;
  
  while (x < j) {
    x++;
  }
}

// lemma_star_A_dec.c
assigns \nothing;
*/
void lemma_star_A_dec(char* s, int i, int j) {
  //@ghost lemma_star_A_all(s, i, j);
  //@ghost lemma_all_star_A(s, i, j-1);
}

// lemma_star_A_dec_1.c
assigns \nothing;
*/
void lemma_star_A_dec(char* s, int i, int j) {
  //@ghost lemma_star_A_all(s, i, j);
  //@ghost lemma_all_star_A(s, i, j-1);
}

// lemma_star_A_dec_2.c
assigns \nothing;
*/
void lemma_star_A_dec(char* s, int i, int j) {
  //@ghost lemma_star_A_all(s, i, j);
  //@ghost lemma_all_star_A(s, i, j-1);
}

// lemma_star_A_dec_3.c
assigns \nothing;
*/
void lemma_star_A_dec(char* s, int i, int j) {
  //@ghost lemma_star_A_all(s, i, j);
  //@ghost lemma_all_star_A(s, i, j-1);
}

// lemma_star_A_dec_4.c
assigns \nothing;
*/
void lemma_star_A_dec(char* s, int i, int j) {
  //@ghost lemma_star_A_all(s, i, j);
  //@ghost lemma_all_star_A(s, i, j-1);
}

// lemma_star_A_dec_5.c
assigns \nothing;
*/
void lemma_star_A_dec(char* s, int i, int j) {
  //@ghost lemma_star_A_all(s, i, j);
  //@ghost lemma_all_star_A(s, i, j-1);
}

// lemma_star_A_dec_6.c
assigns \nothing;
*/
void lemma_star_A_dec(char* s, int i, int j) {
  //@ghost lemma_star_A_all(s, i, j);
  //@ghost lemma_all_star_A(s, i, j-1);
}

// lemma_star_A_dec_7.c
assigns \nothing;
*/
void lemma_star_A_dec(char* s, int i, int j) {
  //@ghost lemma_star_A_all(s, i, j);
  //@ghost lemma_all_star_A(s, i, j-1);
}

// lemma_star_A_dec_8.c
assigns \nothing;
*/
void lemma_star_A_dec(char* s, int i, int j) {
  //@ghost lemma_star_A_all(s, i, j);
  //@ghost lemma_all_star_A(s, i, j-1);
}

// lemma_star_A_not.c
assigns \nothing;
*/
void lemma_star_A_not(char* s, int i, int m, int j) {
  int x = m;
  
  while (i < x) {
    x--;
  }
}

// lemma_star_A_not_1.c
assigns \nothing;
*/
void lemma_star_A_not(char* s, int i, int m, int j) {
  int x = m;
  
  while (i < x) {
    x--;
  }
}

// lemma_star_A_not_10.c
assigns \nothing;
*/
void lemma_star_A_not(char* s, int i, int m, int j) {
  int x = m;
  
  while (i < x) {
    x--;
  }
}

// lemma_star_A_not_2.c
assigns \nothing;
*/
void lemma_star_A_not(char* s, int i, int m, int j) {
  int x = m;
  
  while (i < x) {
    x--;
  }
}

// lemma_star_A_not_3.c
void lemma_star_A_not(char* s, int i, int m, int j) {
  int x = m;
  
  while (i < x) {
    x--;
  }
}

// lemma_star_A_not_4.c
void lemma_star_A_not(char* s, int i, int m, int j) {
  int x = m;
  
  while (i < x) {
    x--;
  }
}

// lemma_star_A_not_5.c
assigns \nothing;
*/
void lemma_star_A_not(char* s, int i, int m, int j) {
  int x = m;
  
  while (i < x) {
    x--;
  }
}

// lemma_star_A_not_6.c
assigns \nothing;
*/
void lemma_star_A_not(char* s, int i, int m, int j) {
  int x = m;
  
  while (i < x) {
    x--;
  }
}

// lemma_star_A_not_7.c
assigns \nothing;
*/
void lemma_star_A_not(char* s, int i, int m, int j) {
  int x = m;
  
  while (i < x) {
    x--;
  }
}

// lemma_star_A_not_8.c
assigns \nothing;
*/
void lemma_star_A_not(char* s, int i, int m, int j) {
  int x = m;
  
  while (i < x) {
    x--;
  }
}

// lemma_star_A_not_9.c
assigns \nothing;
*/
void lemma_star_A_not(char* s, int i, int m, int j) {
  int x = m;
  
  while (i < x) {
    x--;
  }
}

// m_aapb.c
assigns \nothing;
*/
int m_aapb(char* s) {
  char* cur = s;
  int id = 0;
  int m = 1;
  
  
  while (cur[0]!='\0' && m) {
    m = 0;
    if (id == 0) {
      
      
      
      if (cur[0] == 'A') {
        id = 1;
        
        
        m = 1;
      } else {
        
      }
    } else if (id == 1) {
      
      
      if (cur[0] == 'A') {
        
        id = 1;
        
        m = 1;
      } else if (cur[0] == 'B') {
        
        id = 2;
        
        
        m = 1;
      } else {
        
        
        
        
        
      }
    } else if (id == 2) {
      //@assert (id == 2) ==> bwd2(s, 0, i);
      //@assert bwd2(s, 0, i);
      //@assert !bwd0(s, 0, i+1);
      //@assert s[i-1]!='A';
      //@ghost lemma_star_A_not(s, 1, i-1, i+1);
      //@assert !star_A(s, 1, i+1);
      //@assert !bwd1(s, 0, i+1);
      //@ghost lemma_star_A_not(s, 1, i-1, i);
      //@assert !star_A(s, 1, i);
      //@assert !bwd2(s, 0, i+1);
    } else {
      //@assert \false;
    }
    cur++;
    
  }
  int res = id==2 && cur[0]=='\0' && m;
  
  return res;
}

// m_aapb_1.c
assigns \nothing;
*/
int m_aapb(char* s) {
  char* cur = s;
  int id = 0;
  int m = 1;
  
  
  while (cur[0]!='\0' && m) {
    m = 0;
    if (id == 0) {
      
      
      
      if (cur[0] == 'A') {
        id = 1;
        
        
        m = 1;
      } else {
        
      }
    } else if (id == 1) {
      
      
      if (cur[0] == 'A') {
        
        id = 1;
        
        m = 1;
      } else if (cur[0] == 'B') {
        
        id = 2;
        
        
        m = 1;
      } else {
        
        
        
        
        
      }
    } else if (id == 2) {
      //@assert (id == 2) ==> bwd2(s, 0, i);
      //@assert bwd2(s, 0, i);
      //@assert !bwd0(s, 0, i+1);
      //@assert s[i-1]!='A';
      //@ghost lemma_star_A_not(s, 1, i-1, i+1);
      //@assert !star_A(s, 1, i+1);
      //@assert !bwd1(s, 0, i+1);
      //@ghost lemma_star_A_not(s, 1, i-1, i);
      //@assert !star_A(s, 1, i);
      //@assert !bwd2(s, 0, i+1);
    } else {
      //@assert \false;
    }
    cur++;
    
  }
  int res = id==2 && cur[0]=='\0' && m;
  
  return res;
}

// m_aapb_2.c
assigns \nothing;
*/
int m_aapb(char* s) {
  char* cur = s;
  int id = 0;
  int m = 1;
  
  
  while (cur[0]!='\0' && m) {
    m = 0;
    if (id == 0) {
      
      
      
      if (cur[0] == 'A') {
        id = 1;
        
        
        m = 1;
      } else {
        
      }
    } else if (id == 1) {
      
      
      if (cur[0] == 'A') {
        
        id = 1;
        
        m = 1;
      } else if (cur[0] == 'B') {
        
        id = 2;
        
        
        m = 1;
      } else {
        
        
        
        
        
      }
    } else if (id == 2) {
      //@assert (id == 2) ==> bwd2(s, 0, i);
      //@assert bwd2(s, 0, i);
      //@assert !bwd0(s, 0, i+1);
      //@assert s[i-1]!='A';
      //@ghost lemma_star_A_not(s, 1, i-1, i+1);
      //@assert !star_A(s, 1, i+1);
      //@assert !bwd1(s, 0, i+1);
      //@ghost lemma_star_A_not(s, 1, i-1, i);
      //@assert !star_A(s, 1, i);
      //@assert !bwd2(s, 0, i+1);
    } else {
      //@assert \false;
    }
    cur++;
    
  }
  int res = id==2 && cur[0]=='\0' && m;
  
  return res;
}

// m_aapb_3.c
assigns \nothing;
*/
int m_aapb(char* s) {
  char* cur = s;
  int id = 0;
  int m = 1;
  
  
  while (cur[0]!='\0' && m) {
    m = 0;
    if (id == 0) {
      
      
      
      if (cur[0] == 'A') {
        id = 1;
        
        
        m = 1;
      } else {
        
      }
    } else if (id == 1) {
      
      
      if (cur[0] == 'A') {
        
        id = 1;
        
        m = 1;
      } else if (cur[0] == 'B') {
        
        id = 2;
        
        
        m = 1;
      } else {
        
        
        
        
        
      }
    } else if (id == 2) {
      //@assert (id == 2) ==> bwd2(s, 0, i);
      //@assert bwd2(s, 0, i);
      //@assert !bwd0(s, 0, i+1);
      //@assert s[i-1]!='A';
      //@ghost lemma_star_A_not(s, 1, i-1, i+1);
      //@assert !star_A(s, 1, i+1);
      //@assert !bwd1(s, 0, i+1);
      //@ghost lemma_star_A_not(s, 1, i-1, i);
      //@assert !star_A(s, 1, i);
      //@assert !bwd2(s, 0, i+1);
    } else {
      //@assert \false;
    }
    cur++;
    
  }
  int res = id==2 && cur[0]=='\0' && m;
  
  return res;
}

// m_aapb_4.c
assigns \nothing;
*/
int m_aapb(char* s) {
  char* cur = s;
  int id = 0;
  int m = 1;
  
  
  while (cur[0]!='\0' && m) {
    m = 0;
    if (id == 0) {
      
      
      
      if (cur[0] == 'A') {
        id = 1;
        
        
        m = 1;
      } else {
        
      }
    } else if (id == 1) {
      
      
      if (cur[0] == 'A') {
        
        id = 1;
        
        m = 1;
      } else if (cur[0] == 'B') {
        
        id = 2;
        
        
        m = 1;
      } else {
        
        
        
        
        
      }
    } else if (id == 2) {
      //@assert (id == 2) ==> bwd2(s, 0, i);
      //@assert bwd2(s, 0, i);
      //@assert !bwd0(s, 0, i+1);
      //@assert s[i-1]!='A';
      //@ghost lemma_star_A_not(s, 1, i-1, i+1);
      //@assert !star_A(s, 1, i+1);
      //@assert !bwd1(s, 0, i+1);
      //@ghost lemma_star_A_not(s, 1, i-1, i);
      //@assert !star_A(s, 1, i);
      //@assert !bwd2(s, 0, i+1);
    } else {
      //@assert \false;
    }
    cur++;
    
  }
  int res = id==2 && cur[0]=='\0' && m;
  
  return res;
}

// main.c
void main() {
    max = maxarray(vec, LENGTH);

// main_1.c
int main(){

// main_2.c
int main()
 {
   int a=13,b=14;
   swap(&a,&b);
 }

// main_3.c
int main() {
  int x = gimmeOne();

// main_4.c
int main(){
 int a = 42;
 int b = 37;

// matcher.c
#include <limits.h>
#include <string.h>

int matcher(char  * x0) {
  int x2 = strlen(x0);
  int x3 = 0 < x2;
  int x6;
  if (x3) {
    char x4 = x0[0];
    int x5 = 'a' == x4;
    x6 = x5;
  } else {
    x6 = 0/*false*/;
  }
  int x7;
  if (x6) {
    x7 = 1/*true*/;
  } else {
    x7 = 0/*false*/;
  }
  return x7;
}

// matcher_1.c
int matcher(char  * x0) {
  int x2 = strlen(x0);
  int x3 = 0 < x2;
  int x6;
  if (x3) {
    char x4 = x0[0];
    int x5 = 'a' == x4;
    x6 = x5;
  } else {
    x6 = 0/*false*/;
  }
  int x7;
  if (x6) {
    x7 = 1/*true*/;
  } else {
    x7 = 0/*false*/;
  }
  return x7;
}

// matcher_2.c
int matcher(char  * x0) {
  int x2 = strlen(x0);
  int x3 = 0 < x2;
  int x6;
  if (x3) {
    char x4 = x0[0];
    int x5 = 'a' == x4;
    x6 = x5;
  } else {
    x6 = 0/*false*/;
  }
  int x7;
  if (x6) {
    x7 = 1/*true*/;
  } else {
    x7 = 0/*false*/;
  }
  return x7;
}

// matcher_a_or_b.c
#include <limits.h>
#include <string.h>


int matcher_a_or_b(char  * x0) {
  char x2 = x0[0];
  int x3 = x2 == '\0';
  int x9;
  if (x3) {
    x9 = 0/*false*/;
  } else {
    int x4 = x2 == 'a';
    int x8;
    if (x4) {
      char  *x5 = x0+1;
      char x6 = x5[0];
      int x7 = x6 == '\0';
      x8 = x7;
    } else {
      x8 = 0/*false*/;
    }
    x9 = x8;
  }
  int x12;
  if (x3) {
    x12 = 0/*false*/;
  } else {
    int x10 = x2 == 'b';
    int x11;
    if (x10) {
      char  *x5 = x0+1;
      char x6 = x5[0];
      int x7 = x6 == '\0';
      x11 = x7;
    } else {
      x11 = 0/*false*/;
    }
    x12 = x11;
  }
  int x13 = x9 || x12;
  return x13;
}

// matcher_a_or_b_1.c
int matcher_a_or_b(char  * x0) {
  char x2 = x0[0];
  int x3 = x2 == '\0';
  int x9;
  if (x3) {
    x9 = 0/*false*/;
  } else {
    int x4 = x2 == 'a';
    int x8;
    if (x4) {
      char  *x5 = x0+1;
      char x6 = x5[0];
      int x7 = x6 == '\0';
      x8 = x7;
    } else {
      x8 = 0/*false*/;
    }
    x9 = x8;
  }
  int x12;
  if (x3) {
    x12 = 0/*false*/;
  } else {
    int x10 = x2 == 'b';
    int x11;
    if (x10) {
      char  *x5 = x0+1;
      char x6 = x5[0];
      int x7 = x6 == '\0';
      x11 = x7;
    } else {
      x11 = 0/*false*/;
    }
    x12 = x11;
  }
  int x13 = x9 || x12;
  return x13;
}

// matcher_a_or_b_2.c
int matcher_a_or_b(char  * x0) {
  char x2 = x0[0];
  int x3 = x2 == '\0';
  int x9;
  if (x3) {
    x9 = 0/*false*/;
  } else {
    int x4 = x2 == 'a';
    int x8;
    if (x4) {
      char  *x5 = x0+1;
      char x6 = x5[0];
      int x7 = x6 == '\0';
      x8 = x7;
    } else {
      x8 = 0/*false*/;
    }
    x9 = x8;
  }
  int x12;
  if (x3) {
    x12 = 0/*false*/;
  } else {
    int x10 = x2 == 'b';
    int x11;
    if (x10) {
      char  *x5 = x0+1;
      char x6 = x5[0];
      int x7 = x6 == '\0';
      x11 = x7;
    } else {
      x11 = 0/*false*/;
    }
    x12 = x11;
  }
  int x13 = x9 || x12;
  return x13;
}

// matcher_ab.c
#include <limits.h>
#include <string.h>


int matcher_ab(char  * x0) {
  char x2 = x0[0];
  int x3 = x2 == '\0';
  int x7;
  if (x3) {
    x7 = 0/*false*/;
  } else {
    int x4 = x2 == 'a';
    int x6;
    if (x4) {
      x6 = 0/*false*/;
    } else {
      x6 = 0/*false*/;
    }
    x7 = x6;
  }
  int x17;
  if (x3) {
    x17 = 0/*false*/;
  } else {
    int x4 = x2 == 'a';
    int x16;
    if (x4) {
      char  *x5 = x0+1;
      char x8 = x5[0];
      int x9 = x8 == '\0';
      int x15;
      if (x9) {
        x15 = 0/*false*/;
      } else {
        int x10 = x8 == 'b';
        int x14;
        if (x10) {
          char  *x11 = x5+1;
          char x12 = x11[0];
          int x13 = x12 == '\0';
          x14 = x13;
        } else {
          x14 = 0/*false*/;
        }
        x15 = x14;
      }
      x16 = x15;
    } else {
      x16 = 0/*false*/;
    }
    x17 = x16;
  }
  int x18 = x7 || x17;
  return x18;
}

// matcher_ab_1.c
int matcher_ab(char  * x0) {
  char x2 = x0[0];
  int x3 = x2 == '\0';
  int x7;
  if (x3) {
    x7 = 0/*false*/;
  } else {
    int x4 = x2 == 'a';
    int x6;
    if (x4) {
      x6 = 0/*false*/;
    } else {
      x6 = 0/*false*/;
    }
    x7 = x6;
  }
  int x17;
  if (x3) {
    x17 = 0/*false*/;
  } else {
    int x4 = x2 == 'a';
    int x16;
    if (x4) {
      char  *x5 = x0+1;
      char x8 = x5[0];
      int x9 = x8 == '\0';
      int x15;
      if (x9) {
        x15 = 0/*false*/;
      } else {
        int x10 = x8 == 'b';
        int x14;
        if (x10) {
          char  *x11 = x5+1;
          char x12 = x11[0];
          int x13 = x12 == '\0';
          x14 = x13;
        } else {
          x14 = 0/*false*/;
        }
        x15 = x14;
      }
      x16 = x15;
    } else {
      x16 = 0/*false*/;
    }
    x17 = x16;
  }
  int x18 = x7 || x17;
  return x18;
}

// matcher_ab_2.c
int matcher_ab(char  * x0) {
  char x2 = x0[0];
  int x3 = x2 == '\0';
  int x7;
  if (x3) {
    x7 = 0/*false*/;
  } else {
    int x4 = x2 == 'a';
    int x6;
    if (x4) {
      x6 = 0/*false*/;
    } else {
      x6 = 0/*false*/;
    }
    x7 = x6;
  }
  int x17;
  if (x3) {
    x17 = 0/*false*/;
  } else {
    int x4 = x2 == 'a';
    int x16;
    if (x4) {
      char  *x5 = x0+1;
      char x8 = x5[0];
      int x9 = x8 == '\0';
      int x15;
      if (x9) {
        x15 = 0/*false*/;
      } else {
        int x10 = x8 == 'b';
        int x14;
        if (x10) {
          char  *x11 = x5+1;
          char x12 = x11[0];
          int x13 = x12 == '\0';
          x14 = x13;
        } else {
          x14 = 0/*false*/;
        }
        x15 = x14;
      }
      x16 = x15;
    } else {
      x16 = 0/*false*/;
    }
    x17 = x16;
  }
  int x18 = x7 || x17;
  return x18;
}

// max2.c

int max2(int *r, int* i, int* j) {
if (!r) return -1;
*r = (*i < *j) ? *j : *i;

// max2_1.c
int max2(int *r, int* i, int* j) {
if (!r) return -1;
*r = (*i < *j) ? *j : *i;

// max2_2.c
int max2(int *r, int* i, int* j) {
if (!r) return -1;
*r = (*i < *j) ? *j : *i;

// max_idx.c

int max_idx(unsigned int *t, int len) {
  int max = 0;
  
  for(int i = 1; i < len; i++)
    if (t[max] < t[i])
      max = i;
  return max;
}

// max_idx_1.c
int max_idx(unsigned int *t, int len) {
  int max = 0;
  
  for(int i = 1; i < len; i++)
    if (t[max] < t[i])
      max = i;
  return max;
}

// max_idx_2.c
int max_idx(unsigned int *t, int len) {
  int max = 0;
  
  for(int i = 1; i < len; i++)
    if (t[max] < t[i])
      max = i;
  return max;
}

// max_ptr.c

void max_ptr(int*p, int*q) { 
  if (*p > *q) { 
    int tmp = *p; 
    *p = *q; 
    *q = tmp; 
  } 
}

// max_ptr_1.c
void max_ptr(int*p, int*q) { 
  if (*p > *q) { 
    int tmp = *p; 
    *p = *q; 
    *q = tmp; 
  } 
}

// max_ptr_2.c
void max_ptr(int*p, int*q) { 
  if (*p > *q) { 
    int tmp = *p; 
    *p = *q; 
    *q = tmp; 
  } 
}

// max_ptr_3.c

int max_ptr(int* a,int* b){
	return(*a > *b) ? *a: *b ;
}
extern int h ;
int main(){
	h =42;
	int a =24,b =42;
	int x= max_ptr(&a,&b);
}

// max_ptr_4.c
int max_ptr(int* a,int* b){
	return(*a > *b) ? *a: *b ;
}

// max_ptr_5.c
int max_ptr(int* a,int* b){
	return(*a > *b) ? *a: *b ;
}

// max_seq.c

int max_seq(unsigned int *t, int len) {
  if (len <= 0) return -1;
  return t[max_idx(t, len)];
}

// max_seq_1.c

int max_seq(unsigned int *t, int len) {
  if (len <= 0) return -1;
  return t[max_idx(t, len)];
}

// max_seq_2.c

int max_seq(unsigned int *t, int len) {
  if (len <= 0) return -1;
  return t[max_idx(t, len)];
}

// maxarray.c

int maxarray(int u[], int size) {
    int i = 1;
    max = 0;

// maxarray_1.c
int maxarray(int u[], int size) {
    int i = 1;
    max = 0;

// maxarray_2.c
int maxarray(int u[], int size) {
    int i = 1;
    max = 0;

// min.c
int min(int * t, int n) {
  int minInd = 0, i =0;

// min_1.c
int min(int * t, int n) {
  int minInd = 0, i =0;

// min_2.c
int min(int * t, int n) {
  int minInd = 0, i =0;

// min_3.c

int min(int a, int b){
	if(a<b)
		return a;
	else
		return b;
}

// min_4.c
int min(int a, int b){
	if(a<b)
		return a;
	else
		return b;
}

// min_5.c
int min(int a, int b){
	if(a<b)
		return a;
	else
		return b;
}

// minus1.c
int minus1(int  x6) {
  int x8 = x6 - 1;
  return x8;
}

// minus1_1.c
int minus1(int  x6) {
  int x8 = x6 - 1;
  return x8;
}

// opa.c

void opa() {
  rr++;
}

// opa_1.c
void opa() {
  rr++;
}

// opa_2.c
void opa() {
  rr++;
}

// opb.c
void opb () {
  status=1;
}

// opc.c
void opc() {
  rr=9000;
}

// partition.c

int partition (int A[], int p, int r) 
{ 
  int x = A[r]; 
  int tmp, j, i = p-1;

// partition_1.c
int partition (int A[], int p, int r) 
{ 
  int x = A[r]; 
  int tmp, j, i = p-1;

// partition_2.c
int partition (int A[], int p, int r) 
{ 
  int x = A[r]; 
  int tmp, j, i = p-1;

// pick_element.c

int pick_element(int* p, int n) {
  int i = pick_index(n);
  
  return p[i];
}

// pick_element_1.c

int pick_element(int* p, int n) {
  int i = pick_index(n);
  
  return p[i];
}

// pick_element_2.c

int pick_element(int* p, int n) {
  int i = pick_index(n);
  
  return p[i];
}

// pick_element_3.c

int pick_element(int* p, int n) {
  int i = pick_index(n);
  
  return p[i];
}

// pick_first.c

int pick_first(int* p) {
  return p[0];
}

// pick_first_1.c

int pick_first(int* p) {
  return p[0];
}

// pick_first_2.c
int pick_first(int* p) {
  return p[0];
}

// pick_first_3.c
int pick_first(int* p) {
  return p[0];
}

// pick_index.c

int pick_index(int n) { return 0; }

// pick_index_1.c
int pick_index(int n) { return 0; }

// pick_index_2.c
int pick_index(int n) { return 0; }

// pick_index_3.c

int pick_index(int n) { return 0; }

// pick_index_4.c

int pick_index(int n) { return 0; }

// pick_index_5.c

int pick_index(int n) { return 0; }

// predicate.c

int predicate(int v) {
  return v % 2 == 0;
}

// predicate_1.c
int predicate(int v) {
  return v % 2 == 0;
}

// predicate_2.c
int predicate(int v) {
  return v % 2 == 0;
}

// q2.c

void q2(int a[],int n,int k)
{

	for (int j=0;j<k;j++)
	{
		if(a[j]>a[j+1])
		{
			int t=a[j];
			a[j]=a[j+1];
			a[j+1]=t;
		}
	}
}

// q2_1.c
void q2(int a[],int n,int k)
{

	for (int j=0;j<k;j++)
	{
		if(a[j]>a[j+1])
		{
			int t=a[j];
			a[j]=a[j+1];
			a[j+1]=t;
		}
	}
}

// q2_2.c
void q2(int a[],int n,int k)
{

	for (int j=0;j<k;j++)
	{
		if(a[j]>a[j+1])
		{
			int t=a[j];
			a[j]=a[j+1];
			a[j+1]=t;
		}
	}
}

// reverse.c

void reverse(int a[], int res[], int size)
{
	int i;
	
	for(i = size - 1; i >= 0; --i) {
		res[i] = a[size - i - 1];
	}
}

// reverse_1.c
void reverse(int a[], int res[], int size)
{
	int i;
	
	for(i = size - 1; i >= 0; --i) {
		res[i] = a[size - i - 1];
	}
}

// reverse_2.c
void reverse(int a[], int res[], int size)
{
	int i;
	
	for(i = size - 1; i >= 0; --i) {
		res[i] = a[size - i - 1];
	}
}

// swap.c
void swap(int* a, int* b){

// swap_1.c
void swap(int* a, int* b){

// swap_2.c
void swap(int* a, int* b){

// swap_3.c

 void swap(int* a, int* b){
 int tmp = *a;
 *a = *b;
 *b = tmp;
 }

// swap_4.c
void swap(int* a, int* b){
 int tmp = *a;
 *a = *b;
 *b = tmp;
 }

// swap_5.c
void swap(int* a, int* b){
 int tmp = *a;
 *a = *b;
 *b = tmp;
 }

// while.c

    while (i < size) {
        if (u[i] > u[max]) { max = i; }
        i++;
    }
    return max;
}

// while_1.c

    while (i < size) {
        if (u[i] > u[max]) { max = i; }
        i++;
    }
    return max;
}

// while_2.c

    while (i < size) {
        if (u[i] > u[max]) { max = i; }
        i++;
    }
    return max;
}

// while_3.c

  while(lastSpace != -1) {
    if(lastSpace - lastBreak > lineLength) {
      s[lastSpace] = '\n';
      lastBreak = lastSpace;
    }
    lastSpace = indexOf(s, ' ', lastSpace+1, n);
  }
  return;
}

// while_4.c

  while(1) {
    int nextSpace = indexOf(s, ' ', lastSpace + 1,n);
    int nextNewLine = indexOf(s, '\n', lastSpace + 1,n);
    if(nextSpace == -1) {
      /*n - lastChange can overflow if the array contain no space and is of size MAX_INT*/
      if(n - lastChange > length &&
	 (nextNewLine - lastChange > length || nextNewLine == -1) &&
	 lastSpace >= 0) {
	s[lastSpace] = '\n';
      }
      return;
    }

// wrapLines.c

void wrapLines(char* s, int length, int n) {

// wrapLines_simpl.c

void wrapLines_simpl(char* s, int lineLength, int n) {

