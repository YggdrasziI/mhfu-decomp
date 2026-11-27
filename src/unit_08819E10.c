/* unit_08819E10: 0x08819E10-0x0881A30C (ULES01213)
 *
 * Bounds (hypothesis): 1 function.
 *
 * func_08852F58 is called with one argument here (its definition takes two,
 * the second unused). func_08852FA0 takes an s32 count: a u8 parameter loads
 * the byte before the global.
 */

typedef int s32;
typedef short s16;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Box {
    u16 x0;
    u16 y0;
    u16 w;
    u8 unk6[6];
    u16 x;
    u16 y;
    s16 h;
    u8 unk12[6];
    s32 color;
    u8 unk1C[0xC];
} Box;

typedef struct {
    u8 pad0;
    u8 a;
    u8 b;
    u8 id;
    u8 pad4[8];
    u8 kind;
    u8 padD;
} Entry;

extern char *D_089CC438;
extern char *D_08A631A8;
extern char *D_08A62C7C;
extern Entry D_08930BDC[];
extern u16 D_089AC60A;
extern u16 D_089AC638;
extern u16 D_089AC63A;
extern u16 D_089AC63C;
extern u16 D_089AC63E;
extern u16 D_089AC640;
extern u16 D_089AC642;
extern u16 D_089AC644;
extern u16 D_089AC648[];
extern u16 D_089AC65C[];
extern char D_0893854C;
extern char D_0893B0CC;
extern char D_08938478;

extern char *func_0885151C(char *, u16);
extern int func_0880E8F0(char *, char *, ...);
extern void func_0882FA24(Box *, char *, char *, s32, s32);
extern void func_0882F580(char *, Box *, char *, s32, s32, s32);
extern void func_0882FB38(char *, Box *, u16, u16, s32, s32);
extern s32 func_08852F58(char *);
extern u8 func_08852FA0(char *, s32);
extern void func_088920A8(char *, s16, s16, char *, ...);
extern u16 func_08850520(char *, u8);
extern void func_08890E40(char *, s32);
extern char *func_08851674(char *, s32);
extern void func_08891474(char *, s16, s16, char *, ...);
extern s32 func_0886D644(char *, u16);
extern u16 func_0885028C(char *, u8, u8 *);
extern u16 func_08850338(char *, u8, u8 *);
extern float func_08850238(char *, u8, u16);
extern void func_0881A7A4(char *, Entry *, s16, s16, s16);
extern s32 func_0882AF70(char *, u16, u16, u16, u16, s32);
extern s32 func_0882FE34(char *, u16, u16, u8, u8);
extern int func_088915B0(char *, s16, s16, s32, char *, ...);

void func_08819E10(char *arg0) {
    Box box;
    char text[0x20];
    char buf1[0x10];
    char buf2[0x10];
    u8 b;
    Entry *e;
    u16 n;
    s32 m;
    char *s;
    char *p1;
    char *p2;
    float f1;
    float f2;
    s16 v;

    func_0880E8F0(text, &D_0893854C, func_0885151C(D_089CC438, D_089AC60A));
    func_0882FA24(&box, &D_0893B0CC, text, 0, 0);
    func_0882F580(arg0, &box, text, -1, 0xFF, 0);
    if (*(s8 *)(arg0 + 0x5D9) >= 0) {
        e = &D_08930BDC[*(s8 *)(arg0 + 0x5D9)];
        n = func_08852F58(D_089CC438);
        if (n > 1) {
            func_0882FB38(arg0, &box, func_08852FA0(D_089CC438, *(u8 *)(arg0 + 0x5D9)) - 1, n, 0, 0);
        }
        s = func_0885151C(D_089CC438, D_089AC63A);
        func_088920A8(D_08A631A8, box.x, box.y, s, func_0885151C(D_089CC438, D_089AC65C[e->id]));
        s = func_0885151C(D_089CC438, D_089AC63C);
        func_088920A8(D_08A631A8, box.x, box.y + 0x10, s, func_0885151C(D_089CC438, D_089AC648[e->kind]));
        m = func_08850520(D_089CC438, e->id);
        func_088920A8(D_08A631A8, box.x, box.y + 0x20, func_0885151C(D_089CC438, D_089AC63E), m);
        func_08890E40(D_08A631A8, 0xE);
        func_08891474(D_08A631A8, box.x, box.y + 0x50, &D_08938478, func_08851674(D_089CC438, *(s8 *)(arg0 + 0x5D9)));
        if ((u8)func_0886D644(D_08A62C7C, e->id) == 1) {
            if (m > 0) {
                v = func_0885028C(D_089CC438, e->id, &b);
                f1 = func_08850238(D_089CC438, b, v);
                func_0881A7A4(arg0, e, box.x + 0x4D, box.y + 0x30, v);
                v = func_08850338(D_089CC438, e->id, &b);
                f2 = func_08850238(D_089CC438, b, v);
                func_0881A7A4(arg0, e, box.x + 0x4D, box.y + 0x3E, v);
                func_0880E8F0(buf1, func_0885151C(D_089CC438, D_089AC642), f1);
                func_0880E8F0(buf2, func_0885151C(D_089CC438, D_089AC642), f2);
                p1 = buf1;
                p2 = buf2;
            } else {
                p1 = p2 = func_0885151C(D_089CC438, D_089AC644);
            }
            func_088920A8(D_08A631A8, box.x, box.y + 0x30, func_0885151C(D_089CC438, D_089AC640));
            func_088920A8(D_08A631A8, box.x + 0x62, box.y + 0x30, p1);
            func_088920A8(D_08A631A8, box.x + 0x62, box.y + 0x3E, p2);
        }
        func_0882AF70(arg0, box.x0 + 0x9F, box.y0 + 0x25, 0x58, 0x40, 0xAF);
        func_0882FE34(arg0, box.x0 + 0xB3, box.y0 + 0x2C, e->a, e->b);
    } else {
        s = func_0885151C(D_089CC438, D_089AC638);
        func_088915B0(D_08A631A8, box.x0 + ((box.w - 0x70) >> 1), box.y + 0x50, 0, &D_08938478, s);
    }
}
