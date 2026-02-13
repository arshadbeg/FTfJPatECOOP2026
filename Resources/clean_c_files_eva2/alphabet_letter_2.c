int alphabet_letter(char c){
	if( ('a'<= c && c <='z') || ('A' <= c && c <='Z') ) return 1;
	else return 0;
}

int main(void)
{
    
    alphabet_letter('A');
    return 0;
}
