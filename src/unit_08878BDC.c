/* unit_08878BDC: 0x08878BDC-0x08878EEC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_08878BC0 and unit_08878EEC.
 *
 * Optimized for speed: divisions by a constant are multiplications.
 */

#pragma optimize_for_size off

typedef int s32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

extern char D_089A8870;
extern u16 D_089AD0BC[];
extern u16 D_089B53A0;
extern u16 D_089B53A6;
extern u16 D_089B53AE;
extern u16 D_089B53EC;
extern u16 D_089B53EE;
extern s32 D_089CC438;
extern char *D_089CBBEC;
extern char *D_08A631A8;
extern s32 D_09A44C5C;

extern int func_0880E8F0(char *, char *, ...);
extern void func_08825DA8(char *);
extern s32 func_0882A9DC(s32, s32, s32, s32);
extern void func_0882DCA0(s32, u16, u16, u16, u16, s32);
extern int func_08832548(s32, s32);
extern char *func_0885151C(s32, u16);
extern s32 func_088785CC(char *, s32);
extern void func_0887941C(s32, s32, char *);
extern void func_08890DE8(char *, s8, u8);
extern void func_08890DFC(char *, s16, s16);
extern int func_08890E08(s32, s32);
extern void func_08890E38(char *, s8);
extern void func_08892004(char *, char *, ...);
extern char *func_09A63198(s32, u16);

static inline u16 group(s32 i) {
    if (i <= 9) {
        return 0;
    }
    if (i <= 0xE) {
        return 1;
    }
    if (i <= 0x12) {
        return 2;
    }
    return 3;
}

void func_08878BDC(char *arg0) {
    char text[0x100];
    char *g = D_089CBBEC;
    s32 n;
    s32 y;
    s32 i;

    g[0x534] = 9;
    func_08890E08((s32) D_08A631A8, 0);
    func_08825DA8(g);
    func_08832548((s32) D_089CBBEC, 0);
    func_0882DCA0((s32) D_089CBBEC, 0x18, 0x30, 0x1B0, 0xB0, 0xFF);
    func_08890E38(D_08A631A8, 0);
    func_08890DE8(D_08A631A8, 0x10, 0x10);
    func_0880E8F0(text, &D_089A8870, func_09A63198(D_09A44C5C, D_089B53A0));
    func_0887941C((s32) arg0, 0x40, text);
    func_0887941C((s32) arg0, 0x60, func_09A63198(D_09A44C5C, D_089B53A6));
    n = 0;
    y = 0x70;
    for (i = 0; i < 0x1B; i++) {
        if (func_088785CC(arg0, i) != 0) {
            func_0887941C((s32) arg0, (s16) y, func_0885151C(D_089CC438, D_089AD0BC[group(i)]));
            func_0887941C((s32) arg0, (s16) (y + 0x10), func_0885151C(D_089CC438, D_089AD0BC[i + 4]));
            y += 0x20;
            n++;
        }
        if (n > 1) {
            break;
        }
    }
    if (*(s8 *)(arg0 + 0xC1) == 0 && *(s16 *)(arg0 + 0xAC) < 0x32B) {
        func_0880E8F0(text, func_09A63198(D_09A44C5C, D_089B53AE));
        func_08890DFC(D_08A631A8, 0x190, 0xC0);
        func_08892004(D_08A631A8, &D_089A8870, text);
        func_0882A9DC((s32) D_089CBBEC, 0x17E, 0xBF, 0x33);
    }
    func_08890DFC(D_08A631A8, 0x40, 0xC0);
    func_08892004(D_08A631A8, func_09A63198(D_09A44C5C, D_089B53EC), *(s16 *)(arg0 + 0xAC) / 30);
    func_08890E38(D_08A631A8, 5);
    func_0880E8F0(text, &D_089A8870, func_09A63198(D_09A44C5C, D_089B53EE));
    func_0887941C((s32) arg0, (s16) y, text);
}
