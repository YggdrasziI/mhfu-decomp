/* unit_0884FFE0: 0x0884FFE0-0x08850010 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned short u16;
typedef int s32;
typedef struct { char b[2]; } E2;

void func_0884FFE0(char *arg0, s32 arg1, u16 arg2) {
    s32 temp_v1_i;

    temp_v1_i = (arg1 & 0xFFFF);
    if ((s32) *(u16 *) &((E2 *) (arg0 + 0x4580))[temp_v1_i] < (arg2 & 0xFFFF)) {
        *(u16 *) &((E2 *) (arg0 + 0x4580))[temp_v1_i] = arg2;
    }
}
