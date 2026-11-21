/* unit_088FC088: 0x088FC088-0x088FC4F4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function.
 * Draws one 8-byte entry of the table at arg3 + 0x150 (index arg4) at
 * (x, y): a name, two two-digit values (a / 10, a % 10 and b), a count and
 * two marks chosen from 2-bit fields. An unused empty entry draws
 * placeholders.
 *
 * Optimized for speed (divisions by 10 as multiplications). The entry is
 * re-indexed as base->ents[idx] at each access.
 */
#pragma optimize_for_size off

typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    u8 used : 1;
    u8 k1 : 2;
    u8 k2 : 2;
    u8 pad1;
    u16 count : 14;
    u16 a;
    u16 b;
} Ent;

typedef struct {
    char pad[0x150];
    Ent ents[1];
} Base;

extern char *D_089CC438;
extern char *D_08A631A8;
extern char *D_089CBBEC;
extern u16 D_089B835C[];
extern u16 D_089AC65C[];
extern u16 D_089AC8E4;
extern char D_089B86E8[];
extern char D_089B86F0[];
extern char D_089B86F4[];
extern char D_089B8670[];
extern char *func_0885151C(char *, u16);
extern void func_08891474(char *, s16, s16, char *, ...);
extern int func_0880E8F0(char *, char *, ...);
extern void func_0887D02C(s32, s32, char *, s32);
extern void func_08891700(char *, s16, s16, char *);
extern s32 func_0882A9DC(char *, u16, u16, s32);

void func_088FC088(char *buf, s32 x, s32 y, Base *base, s32 idx) {
    char *s;
    s32 id;

    if (base->ents[idx].used || base->ents[idx].count > 0) {
        if (base->ents[idx].used) {
            func_08891474(D_08A631A8, x, y, func_0885151C(D_089CC438, D_089AC65C[D_089B835C[idx]]));
        } else {
            func_08891474(D_08A631A8, x, y, func_0885151C(D_089CC438, D_089AC8E4));
        }
        if (base->ents[idx].count > 0) {
            func_0880E8F0(buf + 0x88, D_089B86E8, base->ents[idx].a / 10, base->ents[idx].a % 10);
            func_0887D02C(x + 0x12A, y, buf + 0x88, 0xE);
            func_0880E8F0(buf + 0x88, D_089B86E8, base->ents[idx].b / 10, base->ents[idx].b % 10);
            func_0887D02C(x + 0xC4, y, buf + 0x88, 0xE);
            func_08891700(D_08A631A8, 0xF6, y, D_089B86F0);
        } else {
            s = func_0885151C(D_089CC438, D_089AC8E4);
            func_0887D02C(x + 0x12A, y, s, 0xE);
            func_0887D02C(x + 0xC4, y, s, 0xE);
            func_08891700(D_08A631A8, 0xF6, y, D_089B86F0);
        }
        func_0880E8F0(buf + 0x88, D_089B8670, base->ents[idx].count);
        func_0887D02C(x + 0x178, y, buf + 0x88, 0xE);
        if (base->ents[idx].count > 0) {
            if (base->ents[idx].k1 >= 2) {
                id = (base->ents[idx].k1 != 2) ? 0x1A4 : 0x1A5;
                func_0882A9DC(D_089CBBEC, x + 0xE8, y, 0x20);
                func_0882A9DC(D_089CBBEC, x + 0xED, y + 4, id);
            } else if (base->ents[idx].k1 == 1) {
                func_0882A9DC(D_089CBBEC, x + 0xE8, y, 0x1F);
                func_0882A9DC(D_089CBBEC, x + 0xED, y + 4, 0x1A5);
            }
            if (base->ents[idx].k2 >= 2) {
                id = (base->ents[idx].k2 != 2) ? 0x1A4 : 0x1A5;
                func_0882A9DC(D_089CBBEC, x + 0x88, y, 0x20);
                func_0882A9DC(D_089CBBEC, x + 0x8D, y + 4, id);
            } else if (base->ents[idx].k2 == 1) {
                func_0882A9DC(D_089CBBEC, x + 0x88, y, 0x1F);
                func_0882A9DC(D_089CBBEC, x + 0x8D, y + 4, 0x1A5);
            }
        }
    } else {
        s = func_0885151C(D_089CC438, D_089AC8E4);
        func_08891474(D_08A631A8, x, y, s);
        func_0887D02C(x + 0x12A, y, s, 0xE);
        func_0887D02C(x + 0xC4, y, s, 0xE);
        func_08891700(D_08A631A8, 0xF6, y, D_089B86F0);
        func_0887D02C(x + 0x178, y, D_089B86F4, 0xE);
    }
}
