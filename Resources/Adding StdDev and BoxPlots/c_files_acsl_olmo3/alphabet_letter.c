/*
  @ requires i != NULL;
  @ requires o != NULL;
  @ ensures *o == *i;
*/
void OutAndIn(int *i, int *o) {
  *o = *i;
}

int main(){
	int ch ;
	// No meaningful ACSL contract for main unless you want to specify behavior
	ch = alphabet_letter('x'); // @ assert ch == 1;
	ch = alphabet_letter('H'); // @ assert ch == 1;
	ch = alphabet_letter(' '); // @ assert ch == 0;
	
	return 0;
}
