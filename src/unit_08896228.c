/* unit_08896228: 0x08896228-0x0889645C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

extern s32 D_089CC438;
extern s32 D_08A62D8C;

extern void func_0885683C(s32);
extern void func_0881C68C(char *, char *, s32, s32);
extern s32 func_08896C2C(char *, u8, u8);
extern s32 func_08896CF8(char *, u8, u8);
extern void func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);

s32 func_08896228(char *arg0, s32 arg1) {
    u16 btn;

    switch (*(u8 *) (arg0 + 0x10FC)) {
    case 0:
        btn = arg1;
        if (btn & 0x2008) {
            func_0885683C(D_089CC438);
            return arg1;
        }
        if (*(u8 *) (arg0 + 0x1109) != 0) {
            func_0881C68C(arg0, arg0 + 0x1100, arg1, 0);
            if (btn & 0x4000) {
                if ((u8) func_08896C2C(arg0, *(u8 *) (arg0 + 0x1111), *(u8 *) (arg0 + 0x1104)) == 1) {
                    *(u8 *) (arg0 + 0x110E) = 0;
                    *(u8 *) (arg0 + 0x1112) = *(u16 *) (arg0 + 0x1104);
                    *(u8 *) (arg0 + 0x1110) = func_08896CF8(arg0, *(u8 *) (arg0 + 0x1111), *(u8 *) (arg0 + 0x1112));
                    *(u8 *) (arg0 + 0x10FC) += 1;
                    func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
                } else {
                    func_08883988(D_08A62D8C, 0, 0x15, 0, 0, 0, 0, 0, 0);
                }
            }
        }
        break;
    case 1:
        btn = arg1;
        if (btn & 0x2000) {
            *(u8 *) (arg0 + 0x10FC) = 0;
            func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
        } else if (btn & 0x80) {
            if (*(u8 *) (arg0 + 0x110E) != 0) {
                *(u8 *) (arg0 + 0x110E) -= 1;
                func_08883988(D_08A62D8C, 0, 0x17, 0, 0, 0, 0, 0, 0);
            }
        } else if (btn & 0x20) {
            if (*(u8 *) (arg0 + 0x110E) < *(u8 *) (arg0 + 0x1110) - 1) {
                *(u8 *) (arg0 + 0x110E) += 1;
                func_08883988(D_08A62D8C, 0, 0x17, 0, 0, 0, 0, 0, 0);
            }
        }
        break;
    }
    return 0;
}
