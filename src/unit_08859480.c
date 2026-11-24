/* unit_08859480: 0x08859480-0x088596C8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

/* func_08859480: copies arg2 words from arg1 to the write pointer at
 * arg0+0x80198 (one 0x40000-byte buffer per index at arg0+4), refusing ids
 * outside 0..19 and overflows past 0x10000 words, then calls func_088596C8.
 * Speed setting needed (the copy loop is unrolled by 8).
 */

typedef int s32;
typedef unsigned int u32;

extern int func_088596C8(char *, s32 *, s32, s32);

s32 func_08859480(char *arg0, s32 *arg1, s32 arg2, s32 arg3) {
    s32 i;
    u32 n;
    s32 *start;

    if (arg3 < 0 || arg3 >= 20) {
        return 0;
    }
    start = *(s32 **)(arg0 + 0x80198);
    n = arg2 + (start - (s32 *)(arg0 + (*(s32 *)(arg0 + 4) << 18) + 0x198));
    if (n >= 0x10000) {
        return 0;
    }
    for (i = 0; i < arg2; i++) {
        **(s32 **)(arg0 + 0x80198) = *arg1;
        *(s32 **)(arg0 + 0x80198) += 1;
        arg1++;
    }
    func_088596C8(arg0, start, arg2, arg3);
    return 1;
}
