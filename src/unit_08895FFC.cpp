/* unit_08895FFC: 0x08895FFC-0x0889615C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

extern "C" {
extern char *D_089CC438;
extern s32 D_08A62D8C;

extern void func_0885683C(void *);
extern void func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);
s32 func_08895FFC(char *arg0, s32 arg1);
}

s32 func_08895FFC(char *arg0, s32 arg1) {
    u16 buttons;

    if ((bool) (*(s32 *) (D_089CC438 + 0x70000 - 0x50EC) & 0x100) == 0) {
        return 0;
    }
    switch (*(u8 *) (arg0 + 0x1117)) {
    case 0:
        break;
    case 1:
        buttons = arg1;
        if (buttons & 0x2000) {
            *(u8 *) (arg0 + 0x1117) = 0;
            func_0885683C(D_089CC438);
            func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
        } else if (buttons & 0x80) {
            if (*(u8 *) (arg0 + 0x110E) != 0) {
                *(u8 *) (arg0 + 0x110E) -= 1;
                func_08883988(D_08A62D8C, 0, 0x17, 0, 0, 0, 0, 0, 0);
            }
        } else if (buttons & 0x20) {
            if (*(u8 *) (arg0 + 0x110E) < *(u8 *) (arg0 + 0x1110) - 1) {
                *(u8 *) (arg0 + 0x110E) += 1;
                func_08883988(D_08A62D8C, 0, 0x17, 0, 0, 0, 0, 0, 0);
            }
        }
        break;
    }
    return *(u8 *) (arg0 + 0x1117);
}
