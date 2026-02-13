/*@ ensures (0 <= i && i <= 9) ==> ('0' <= \result && \result <= '9');
    ensures !(0 <= i && i <= 9) ==> \result == ' ';
    ensures (0 <= i && i <= 9) ==> \result == i + '0';
    assigns \nothing;
*/
char e(int i) {
    return (0 <= i && i <= 9) ? i + '0' : ' ';
}
