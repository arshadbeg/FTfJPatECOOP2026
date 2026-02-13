
int max_ptr(int* a,int* b){
	return(*a > *b) ? *a: *b ;
}
extern int h ;
int main(){
	h =42;
	int a =24,b =42;
	int x= max_ptr(&a,&b);
	//@ assert x ;

}