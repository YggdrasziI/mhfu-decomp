/* unit_0885048C: 0x0885048C-0x08850520 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Speed setting (`#pragma optimize_for_size off`): needed to match.
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned short u16;
typedef unsigned char u8;

extern u8 *D_0899BF40[];
extern u16 func_0884FF38(s32, s32);

u16 func_0885048C(s32 arg0, u8 arg1) {
    u16 sum;
    u8 *p;

    sum = 0;
    p = D_0899BF40[arg1];
    while (*p != 0xFF) {
        sum += func_0884FF38(arg0, *p);
        p++;
    }
    if (sum > 9999) {
        sum = 9999;
    }
    return sum;
}
