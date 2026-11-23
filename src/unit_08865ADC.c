/* unit_08865ADC: 0x08865ADC-0x08865BAC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

extern void func_08865A9C(char *, s32);
extern void func_08865A64(char *, s32);

void func_08865ADC(char *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 flags = (u16)arg1;

    switch ((u8)arg1) {
    case 1:
        *(u8 *)(arg0 + 0x280) = 1;
        break;
    case 2:
        *(u8 *)(arg0 + 0x280) = 2;
        break;
    default:
        *(u8 *)(arg0 + 0x280) = 0;
        break;
    }
    if (flags & 0x8000) {
        func_08865A9C(arg0, 8);
    } else {
        func_08865A64(arg0, 8);
    }
    if (arg2 == 0) {
        func_08865A9C(arg0, 1);
    } else {
        func_08865A64(arg0, 1);
    }
    if (arg3 == 0) {
        func_08865A9C(arg0, 2);
    } else {
        func_08865A64(arg0, 2);
    }
}
