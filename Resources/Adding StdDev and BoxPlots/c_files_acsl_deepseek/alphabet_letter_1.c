/*@ ensures (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')) ==> \result == 1;
    ensures !(('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')) ==> \result == 0;
    assigns \nothing;
*/
int alphabet_letter(char c){
    if( ('a'<= c && c <='z') || ('A' <= c && c <='Z') ) return 1;
    else return 0;
}
