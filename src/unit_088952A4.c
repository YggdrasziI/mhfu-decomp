/* unit_088952A4: 0x088952A4-0x088952E4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;

u8 func_088952A4(char *arg0, s32 arg1, s32 arg2, u8 arg3) {
    u8 ret;

    if (*(u8 *)(arg0 + 0x130) == 0) {
        if (arg2 == 0) {
            ret = arg3;
        } else {
            ret = (u32)arg3 >> 1;
        }
    } else {
        if (arg2 == 0) {
            ret = arg3;
        } else {
            ret = (u32)arg3 >> 1;
        }
    }
    return ret;
}
