/* unit_0883ABE0: 0x0883ABE0-0x0883AE3C (ULES01213)
 *
 * Bounds (hypothesis): 1 function, between unrelated code.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

extern char *D_089CC438;
extern s32 D_09A4F0C4;
extern s32 D_09A0B544;
extern s32 D_08A62D8C;
extern s32 D_08A62C50;
extern u16 D_089ACA8C;
extern char *D_089CBBEC;

extern char *func_088DCEBC(s32, u8);
typedef struct { u16 a; s16 b; } E;
extern E *func_0889D7E8(s32, char *);
extern void func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s16 func_0885AF28(s32, u16);
extern char *func_0885151C(char *, u16);
extern void func_088307BC(char *, char *);
extern u8 func_08830728(char *, s8, s16, s16);
extern void func_0889D8A8(s32, char *, s32, s32);
extern void func_09AAEE70(char *, s32, s32, s32);

void func_0883ABE0(char *p, char *q) {
    E *e;
    char *w;
    s16 r;

    if (*(u8 *)(func_088DCEBC(D_09A4F0C4, *(u8 *)(D_089CC438 + 0x28)) + 0x62C) > 0) {
        return;
    }
    e = func_0889D7E8(D_09A0B544, q);
    if (e == 0 || *(u8 *)(q + 0xBF) == 5) {
        func_08883988(D_08A62D8C, 0, 0x15, 0, 0, 0, 0, 0, 0);
        return;
    }
    r = func_0885AF28(D_08A62C50, e->a);
    if (r <= 0) {
        func_088307BC(D_089CBBEC, func_0885151C(D_089CC438, D_089ACA8C));
        func_08883988(D_08A62D8C, 0, 0x15, 0, 0, 0, 0, 0, 0);
        w = func_088DCEBC(D_09A4F0C4, *(u8 *)(D_089CC438 + 0x28));
        *(u8 *)(w + 0x62C) = 0x5A;
        return;
    }
    r = func_0885AF28(D_08A62C50, e->a);
    if (r < e->b) {
        func_08830728(D_089CBBEC, 1, 0xF, e->a);
        func_08883988(D_08A62D8C, 0, 0x15, 0, 0, 0, 0, 0, 0);
        w = func_088DCEBC(D_09A4F0C4, *(u8 *)(D_089CC438 + 0x28));
        *(u8 *)(w + 0x62C) = 0x5A;
        return;
    }
    func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
    *(u8 *)(p + 0x580) = 0x96;
    w = func_088DCEBC(D_09A4F0C4, *(u8 *)(D_089CC438 + 0x28));
    *(u16 *)(w + 0x5CA) = e->a;
    *(s16 *)(w + 0x5CC) = e->b;
    func_0889D8A8(D_09A0B544, q, 7, 0);
    func_09AAEE70(w, 0, 6, 0);
    *(u8 *)(p + 0x57E) = 1;
}
