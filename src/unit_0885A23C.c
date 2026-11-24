/* unit_0885A23C: 0x0885A23C-0x0885A8E0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0885A23C */

typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef float f32;

typedef struct {
    u16 a;
    u16 b;
    u16 c;
    u16 d;
    u8 e;
    u8 f;
    u8 g;
    u8 h;
    u16 x;
    u16 y;
    u32 k;
} Box;

typedef struct {
    u8 pad0;
    u8 type;
    u8 count;
    u8 state;
    f32 speed;
    u16 arg8;
    s16 index;
    s16 xC;
    s16 xE;
    f32 pos;
    s16 x14;
    s16 x16;
    s16 timer;
    u8 pad1A[6];
    s32 x20;
} Banner;

extern u16 D_0899D144;
extern u16 D_0899D146;
extern u16 D_0899D148;
extern u16 D_0899D14A;
extern u8 D_0899D14C;
extern u8 D_0899D14D;
extern u8 D_0899D14E;
extern u8 D_0899D14F;
extern u16 D_0899D150;
extern u16 D_0899D152;
extern u32 D_0899D154;
extern char *D_089CBBEC;
extern char *D_089CC438;
extern char *D_08A631A8;
extern char D_0899D114[];
extern char D_0899D118[];
extern char D_0899D120[];
extern char D_0899D138[];
extern char D_0899D158[];
extern u16 D_089ACA0C[];
extern u16 D_089ACA40[];
extern u16 D_089ACA68[];
extern u16 D_089ACA7C[];
extern u16 D_089ACA84;
extern u16 D_089ACA86;
extern u16 D_089ACA88;
extern u16 D_089ACA8A;
extern u16 D_089AD058[];
extern char *D_09A0B544;

extern void func_0882FC50(char *, Box *, s32, s32);
extern void func_08890E38(char *, s8);
extern void func_08890DE8(char *, s8, u8);
extern char *func_0885151C(char *, u16);
extern char *func_08851528(char *, s32);
extern char *func_08851598(char *, s32);
extern s32 func_08890E48(char *, char *);
extern void func_08891474(char *, s16, s16, char *, ...);
extern void func_088920A8(char *, s16, s16, char *, ...);
extern void func_088912BC(char *, s16, s16, char *);

void func_0885A23C(Banner *p) {
    Box box;
    char *s0;
    char *s2;
    s32 w;
    s16 t;

    box.b = D_0899D146;
    box.c = D_0899D148;
    box.d = D_0899D14A;
    box.e = D_0899D14C;
    box.f = D_0899D14D;
    box.g = D_0899D14E;
    box.h = D_0899D14F;
    box.x = D_0899D150;
    box.y = D_0899D152;
    box.k = D_0899D154;
    box.a = D_0899D144;
    box.a = p->xC;
    box.c = p->xE;
    box.d = p->x14;
    box.x = p->x16;
    box.b = p->pos;
    box.y = box.b + 9;
    func_0882FC50(D_089CBBEC, &box, 0, 0xFF);

    switch (p->type) {
    case 0:
        func_08890E38(D_08A631A8, 0);
        func_08891474(D_08A631A8, (s16)box.x, (s16)box.y, D_0899D114,
                      func_0885151C(D_089CC438, D_089ACA0C[p->index]));
        break;
    case 1:
        func_08890E38(D_08A631A8, 0);
        s0 = func_0885151C(D_089CC438, D_089ACA40[p->index]);
        s2 = func_08851528(D_089CC438, p->arg8);
        func_088920A8(D_08A631A8, (s16)box.x, (s16)box.y, s0, s2);
        break;
    case 2:
        func_08890E38(D_08A631A8, 0);
        func_08891474(D_08A631A8, (s16)box.x, (s16)box.y, D_0899D114,
                      func_0885151C(D_089CC438, D_089ACA68[p->index]));
        w = func_08890E48(D_08A631A8, func_0885151C(D_089CC438, D_089ACA68[p->index]));
        func_08890E38(D_08A631A8, 2);
        func_08891474(D_08A631A8, (s16)(box.x + w * 7), box.y, D_0899D114,
                      func_08851528(D_089CC438, p->arg8));
        break;
    case 3:
        func_08890E38(D_08A631A8, 2);
        func_08890DE8(D_08A631A8, 0x10, 0xE);
        func_088912BC(D_08A631A8, (s16)box.x, (s16)box.y, D_09A0B544 + (u8)p->arg8 * 200 + 0xBC8);
        func_08890DE8(D_08A631A8, 0xE, 0xE);
        func_08890E38(D_08A631A8, 0);
        func_08891474(D_08A631A8, (s16)box.x, (s16)box.y, D_0899D118, D_0899D120,
                      func_0885151C(D_089CC438, D_089ACA7C[p->index]));
        break;
    case 4:
    case 6:
        func_08890E38(D_08A631A8, 0);
        func_088920A8(D_08A631A8, (s16)box.x, (s16)box.y, D_0899D114, p->x20);
        break;
    case 5:
        s0 = func_08851528(D_089CC438, (u16)p->index);
        s2 = func_0885151C(D_089CC438, D_089ACA84);
        func_088920A8(D_08A631A8, (s16)box.x, (s16)box.y, D_0899D158, s0, s2, (s16)p->arg8,
                      func_0885151C(D_089CC438, D_089ACA86));
        break;
    case 7:
        func_08890E38(D_08A631A8, 0);
        s0 = func_0885151C(D_089CC438, D_089ACA88);
        s2 = func_0885151C(D_089CC438, D_089AD058[p->index]);
        func_08891474(D_08A631A8, (s16)box.x, (s16)box.y, D_0899D138, s0, s2,
                      func_0885151C(D_089CC438, D_089ACA8A));
        break;
    case 8:
        func_08890E38(D_08A631A8, 0);
        s0 = func_0885151C(D_089CC438, D_089ACA40[p->index]);
        s2 = func_08851598(D_089CC438, p->arg8);
        func_088920A8(D_08A631A8, (s16)box.x, (s16)box.y, s0, s2);
        break;
    }

    switch (p->state) {
    case 0:
        p->pos += p->speed;
        if (p->pos >= (f32)(0x88 - (p->x14 >> 1))) {
            p->state++;
            p->pos = (f32)(0x88 - (p->x14 >> 1));
        }
        break;
    case 1:
        t = --p->timer;
        if (t <= 0 || (t < 0x1F && *(s8 *)(D_089CBBEC + 0x10F8) > 0)) {
            p->speed *= -1.0f;
            *(u8 *)(D_089CC438 + 0x381) = 0xFF;
            p->state++;
        }
        break;
    case 2:
        p->pos += p->speed;
        if (p->pos <= 0.0f) {
            p->count++;
        }
        break;
    }
}
