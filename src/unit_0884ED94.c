/* unit_0884ED94: 0x0884ED94-0x0884EDC8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;
typedef struct { char b[4]; } E4;

s32 func_0884ED94(char *arg0, s32 arg1) {
    s32 temp_v1;
    s32 temp_v0_i;

    temp_v1 = arg1 & 0xFFFF;
    if (temp_v1 == 0xFFFF) {
        return 0;
    }
    temp_v0_i = temp_v1;
    return (*(s32 *) &((E4 *) (arg0 + 0x2AC4))[temp_v0_i] - *(s32 *) &((E4 *) (arg0 + 0x2AC0))[temp_v0_i]) << 0xB;
}
