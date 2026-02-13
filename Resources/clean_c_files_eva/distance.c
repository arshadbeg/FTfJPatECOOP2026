
int distance(int a,int b){
	if(a < b)
		return b - a ;
	else
		return a - b ;
}

int main(void)
{
    
    distance(42, 42);
    return 0;
}
