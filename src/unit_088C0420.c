/* unit_088C0420: 0x088C0420-0x088C0468 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088C022C (NonMatching)
 * and unit_088C0468 (NonMatching).
 *
 * Checks the sum of the 0x1C3FC words at +0x950 against the word after them.
 */

typedef int s32;
typedef unsigned int u32;

s32 func_088C0420(char *arg0) {
    u32 *p;
    u32 sum;
    u32 *q;
    u32 i;

    p = *(u32 **) (arg0 + 0x950);
    sum = 0;
    i = 0;
    q = p;
    do {
        sum += *q;
        i++;
        q++;
    } while (i < 0x1C3FC);
    return sum == p[0x1C3FD];
}
