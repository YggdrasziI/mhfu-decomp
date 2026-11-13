/* unit_08850010: 0x08850010-0x08850044 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned short u16;
typedef int s32;
typedef struct { char b[2]; } E2;

void func_08850010(char *arg0, s32 arg1, u16 arg2) {
    u16 temp_a0;
    s32 temp_v1_i;

    temp_v1_i = (arg1 & 0xFFFF);
    temp_a0 = *(u16 *) &((E2 *) (arg0 + 0x4634))[temp_v1_i];
    if ((temp_a0 == 0) || ((arg2 & 0xFFFF) < (s32) temp_a0)) {
        *(u16 *) &((E2 *) (arg0 + 0x4634))[temp_v1_i] = arg2;
    }
}
