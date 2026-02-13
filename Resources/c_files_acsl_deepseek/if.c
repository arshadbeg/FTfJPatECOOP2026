/*@ requires \valid(s + (0..nextSpace)); // assuming s is a valid array
    requires 0 <= lastChange < nextSpace;
    requires 0 <= lastSpace < nextSpace;
    requires 0 <= nextNewLine < nextSpace;
    requires length > 0;
    assigns s[lastSpace], s[nextSpace], lastChange, lastSpace;
    behavior first_branch:
      assumes 0 <= nextNewLine && nextNewLine < nextSpace;
      ensures (nextNewLine - lastChange > length && lastSpace >= 0) ==> s[lastSpace] == '\n';
      ensures lastChange == nextNewLine;
      ensures lastSpace == nextNewLine;
    behavior second_branch:
      assumes !(0 <= nextNewLine && nextNewLine < nextSpace);
      ensures (nextSpace - lastChange > length) ==> 
              (lastChange == lastSpace ==> s[nextSpace] == '\n' && lastChange == nextSpace && lastSpace == nextSpace) &&
              (lastChange != lastSpace ==> s[lastSpace] == '\n' && lastChange == lastSpace);
      ensures !(nextSpace - lastChange > length) ==> lastSpace == nextSpace;
*/
// Note: This appears to be a code fragment from a line-wrapping or text formatting function
if(0 <= nextNewLine && nextNewLine < nextSpace) {
    /*@ assert 0 <= nextNewLine && nextNewLine < nextSpace; */
    if(nextNewLine - lastChange > length && lastSpace >= 0) {
        /*@ assert nextNewLine - lastChange > length && lastSpace >= 0; */
        s[lastSpace] = '\n';
    }
    lastChange = lastSpace = nextNewLine;
} else {
    /*@ assert !(0 <= nextNewLine && nextNewLine < nextSpace); */
    if(nextSpace - lastChange > length) {
        /*@ assert nextSpace - lastChange > length; */
        if(lastChange == lastSpace) {
            /*@ assert lastChange == lastSpace; */
            s[nextSpace] = '\n';
            lastChange = lastSpace = nextSpace;
        } else {
            /*@ assert lastChange != lastSpace; */
            s[lastSpace] = '\n';
            lastChange = lastSpace;
        }
    } else {
        /*@ assert !(nextSpace - lastChange > length); */
        lastSpace = nextSpace;
    }
}
return;
