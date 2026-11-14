/* unit_08872D74: 0x08872D74-0x08872DC4 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;
typedef struct { char b[8]; } E8;

s32 func_08872D74(s32 arg0, s32 arg1) {
    s32 temp_a0;

    temp_a0 = *(s32 *)((E8 *)((char *)arg0 + 0x738))[arg1].b;
    if (temp_a0 & 1) {
        return 2;
    }
    if (temp_a0 & 2) {
        return 1;
    }
    if ((temp_a0 & 0x18004) == 0x18004) {
        return 3;
    }
    return 0;
}
