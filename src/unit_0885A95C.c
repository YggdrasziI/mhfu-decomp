/* unit_0885A95C: 0x0885A95C-0x0885A994 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

extern char *D_089CC438;

void func_0885A95C(u8 *arg0, s32 arg1, u8 arg2, s32 arg3) {
    if (arg3 == 0) {
        arg0[1] = 4;
    } else {
        arg0[1] = 6;
    }
    arg0[0] = 1;
    arg0[2] = 0;
    *(s32 *)(arg0 + 0x20) = arg1;
    D_089CC438[0x381] = arg2;
}
