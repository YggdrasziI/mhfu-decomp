/* unit_0883B190: 0x0883B190-0x0883B3D4 (ULES01213)
 *
 * State handler keyed by the byte at 0x57E; returns the input flags with
 * bit 0x2000 cleared (hypothesis on meaning).
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

extern s32 D_09A4F0C4;
extern char *D_089CC438;
extern s32 D_09A0B544;
extern char *D_08A62D8C;
extern s32 D_09B22D70;
extern u16 D_09B04DFE;
extern char *D_089CBBEC;

extern s32 func_0881C2E4(char *, u8 *, u16, u8);
extern char *func_088DCEBC(s32, s32);
extern s32 func_0883B3D4(char *, s32);
extern s32 func_0889D7E8(s32, s32);
extern void func_0883ABE0(char *, s32);
extern void func_0883AE3C(char *, s32);
extern s32 func_08883988(char *, s32, s32, s32, s32, s32, s32, s32, s32);
extern char *func_09A7B790(s32, u16);
extern void func_088307BC(char *, char *);
extern void func_0883448C(char *);

u16 func_0883B190(char *p, u16 b) {
    char *e;
    u8 v;

    switch (*(u8 *)(p + 0x57E)) {
    case 0:
        if (func_0881C2E4(p, (u8 *)(p + 0x57F), b, 3) == 0) {
            if (b & 0x4000) {
                if (*(u8 *)(func_088DCEBC(D_09A4F0C4, *(u8 *)(D_089CC438 + 0x28)) + 0x62C) <= 0) {
                    if (func_0889D7E8(D_09A0B544, func_0883B3D4(p, *(u8 *)(p + 0x57F))) != 0) {
                        func_0883ABE0(p, func_0883B3D4(p, *(u8 *)(p + 0x57F)));
                    } else {
                        func_0883AE3C(p, func_0883B3D4(p, *(u8 *)(p + 0x57F)));
                    }
                } else {
                    func_08883988(D_08A62D8C, 0, 0x15, 0, 0, 0, 0, 0, 0);
                }
            } else if (b & 0x2000) {
                return b;
            }
        }
        break;
    case 1:
        e = func_088DCEBC(D_09A4F0C4, 0);
        v = *(u8 *)(e + 0x5C8);
        if (v == 1) {
            *(u8 *)(p + 0x57E) = 3;
        } else if (v == 2) {
            *(u8 *)(p + 0x57E) = 3;
        } else {
            *(u8 *)(p + 0x580) -= 1;
            if (*(u8 *)(p + 0x580) <= 0) {
                *(u8 *)(p + 0x57E) = 2;
            }
        }
        break;
    case 2:
        func_088307BC(D_089CBBEC, func_09A7B790(D_09B22D70, D_09B04DFE));
        *(u8 *)(p + 0x57E) = 3;
        func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
        func_0883448C(p);
        break;
    case 3:
        func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
        func_0883448C(p);
        break;
    }
    return b & ~0x2000;
}
