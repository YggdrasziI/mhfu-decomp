/* unit_08865CEC: 0x08865CEC-0x08865D54 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef short s16;
typedef unsigned char u8;

void func_08865CEC(char *arg0, s16 arg1) {
    s16 t = *(s16 *)(arg0 + 0x334);
    s16 a = *(s16 *)(arg0 + 0x32C);

    *(s32 *)(arg0 + 0x3F4) = 0;
    if (t < 0) {
        t = -t;
    }
    *(s32 *)(arg0 + 0x3F4) += a - t;
    if (arg1 != 0) {
        if (t != 0) {
            t--;
        }
        *(u8 *)(arg0 + 0x426) += (u8)(t - a);
    }
}
