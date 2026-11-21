/* unit_088FC7A8: 0x088FC7A8-0x088FC810 (ULES01213)
 *
 * Bounds (hypothesis): 1 function.
 * Counts, over three 0x1C-byte records at +0x2C, those whose first halfword
 * is 2 (into +0x80) and, among them, those whose next halfword is not zero
 * (into +0x84). Returns whether both counts are equal.
 */

typedef unsigned short u16;
typedef int s32;

s32 func_088FC7A8(char *arg0) {
    u16 *p;
    s32 i;

    *(s32 *)(arg0 + 0x80) = 0;
    *(s32 *)(arg0 + 0x84) = 0;
    for (p = (u16 *)(arg0 + 0x2C), i = 0; i < 3; i++, p = (u16 *)((char *)p + 0x1C)) {
        if (p[0] == 2) {
            (*(s32 *)(arg0 + 0x80))++;
            if (p[1] != 0) {
                (*(s32 *)(arg0 + 0x84))++;
            }
        }
    }
    return *(s32 *)(arg0 + 0x80) == *(s32 *)(arg0 + 0x84);
}
