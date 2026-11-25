/* unit_08848E04: 0x08848E04-0x088490C8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08848E04 (ULES01213)
 *
 * C++: the (bool) flag test keeps sltu + bnel against 1.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

extern "C" {

extern char *D_089CC438;
extern char *D_08A631A0;
extern char *D_08A62D8C;
extern s32 D_09A1DAEC;

extern void func_0881BF80(char *, u8 *, s32, s32);
extern s32 func_08883988(char *, s32, s32, s32, s32, s32, s32, s32, u8);
extern void func_088490C8(char *arg0);
extern void func_088AB514(s32, s32, s32);
extern s32 func_08849120(char *arg0, u8 arg1);
extern u16 func_08849214(char *arg0, u8 arg1, s32 arg2);
extern void func_08848D30(char *arg0);

void func_08848E04(char *arg0, s32 arg1) {
    u16 r;
    s16 *p;

    switch (*(u8 *)(arg0 + 0x57C)) {
    case 0:
        func_0881BF80(arg0, (u8 *)(arg0 + 0x57D), arg1, 0xC);
        *(s16 *)(arg0 + 0x5FC) = *(u8 *)(arg0 + 0x57D);
        arg1 = (u16)arg1;
        if (arg1 & 0x8000) {
            *(u8 *)(arg0 + 0x576) ^= 1;
            func_08883988(D_08A62D8C, 0, 9, 0, 0, 0, 0, 0, 0);
            func_088490C8(arg0);
            break;
        }
        if ((bool) (*(s32 *)(D_08A631A0 + 0xF7A57C) & 1) == 1) {
            if (arg1 & 0x1000) {
                p = (s16 *)((char *)(*(u8 *)(D_089CC438 + 0x28) * 2) + (s32)arg0 + 0x56C);
                if (*p < 0) {
                    *p = 0;
                    func_088AB514(D_09A1DAEC, 9, 0);
                    func_088490C8(arg0);
                    break;
                }
                func_08883988(D_08A62D8C, 0, 0x15, 0, 0, 0, 0, 0, 0);
            }
        }
        if (arg1 & 0x4000) {
            if (func_08849120(arg0, *(u8 *)(arg0 + 0x57D)) == 0) {
                *(u8 *)(arg0 + 0x57C) += 1;
                *(u8 *)(arg0 + 0x585) = 0;
                func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
            } else {
                func_08883988(D_08A62D8C, 0, 0x15, 0, 0, 0, 0, 0, 0);
            }
        } else if (arg1 & 0x2008) {
            func_088490C8(arg0);
            func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
        }
        break;
    case 1:
        r = func_08849214(arg0, *(u8 *)(arg0 + 0x57D), arg1);
        if (r & 8) {
            func_088490C8(arg0);
            func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
        } else if (r & 0x2000) {
            func_08848D30(arg0);
            func_08883988(D_08A62D8C, 0, 0x14, 0, 0, 0, 0, 0, 0);
        }
        break;
    }
}

}
