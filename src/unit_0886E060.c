/* unit_0886E060: 0x0886E060-0x0886E08C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef short s16;
typedef int s32;
typedef struct { char b[8]; } E8;

s16 func_0886E060(char *arg0, s32 arg1) {
    s32 temp_a0_i;

    temp_a0_i = (arg1 & 0xFFFF);
    if ((*(s32 *) &((E8 *) (arg0 + 0x728))[temp_a0_i] & 0x11) == 0x11) {
        return *(s16 *) &((E8 *) (arg0 + 0x72E))[temp_a0_i];
    }
    return -1;
}
