/* unit_08832548: 0x08832548-0x08832684 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between two functions still in assembly.
 * Its jump tables (0x08930BAC-0x08930BDC) are linked from this unit.
 */

typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;

extern void func_08832B98(char *, s32);
extern s32 func_0882AF70(s32, s32, s32, s32, s32, s32);

void func_08832548(char *arg0, u32 arg1) {
    u32 old;

    func_08832B98(arg0, 1);
    old = *(u8 *)(arg0 + 0x534);
    switch (arg1) {
    case 0:
        *(u8 *)(arg0 + 0x534) = 9;
        break;
    case 1:
        *(u8 *)(arg0 + 0x534) = 10;
        break;
    case 2:
        *(u8 *)(arg0 + 0x534) = 11;
        break;
    case 3:
        *(u8 *)(arg0 + 0x534) = 12;
        break;
    case 4:
        *(u8 *)(arg0 + 0x534) = 13;
        break;
    case 5:
        *(u8 *)(arg0 + 0x534) = 14;
        break;
    }
    func_0882AF70((s32) arg0, 0, 0, 0x1E0, 0x110, 0x108);
    switch (old) {
    case 0:
        *(u8 *)(arg0 + 0x534) = 9;
        break;
    case 1:
        *(u8 *)(arg0 + 0x534) = 10;
        break;
    case 2:
        *(u8 *)(arg0 + 0x534) = 11;
        break;
    case 3:
        *(u8 *)(arg0 + 0x534) = 12;
        break;
    case 4:
        *(u8 *)(arg0 + 0x534) = 13;
        break;
    case 5:
        *(u8 *)(arg0 + 0x534) = 14;
        break;
    }
    func_08832B98(arg0, 0);
}
