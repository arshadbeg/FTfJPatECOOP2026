/*@ requires min <= max;
    assigns \nothing;
    ensures \result >= min && \result <= max;
    ensures v >= min && v <= max ==> \result == v;
    ensures v < min ==> \result == min;
    ensures v > max ==> \result == max;
*/
int clamp(int v, int min, int max)
{
    int low = v > min ? v : min;
    return low < max ? low : max;
}
