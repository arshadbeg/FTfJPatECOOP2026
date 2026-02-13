/*@ ensures \true;
*/
void OutAndIn_test()
{
    int a = 5;
    int b = 0;
    //@ assert a == 5 && b == 0;
    OutAndIn(&a, &b);
    //@ assert a == 5 && b == 5;
}
