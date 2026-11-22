/* unit_08892A88: 0x08892A88-0x08892E7C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off
typedef int s32;
typedef unsigned int u32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;

typedef struct {
    u32 unk0;
    u32 unk4;
    u16 unk8;
    u16 unkA;
    u32 unkC;
    u32 unk10;
    u32 unk14;
} Tex;

typedef struct {
    s16 x;
    s16 y;
    s16 size;
    u8 idx;
    s8 color;
} Item;

extern s32 D_09A0B540;
extern s32 D_08A62C40;
extern u8 D_08931BFC[];
extern s32 func_08898898(s32, s32);
extern int func_08859848(s32, s32, s32, s32, s32, Tex *);
extern char *func_088597FC(s32);
extern s32 func_0885981C(s32, u32);
extern int func_088596C8(s32, char *, s32, s32);
extern int func_0885980C(s32, char *);

void func_08892A88(char *arg0, Item *arg1, u8 arg2, s32 arg3) {
    Tex tex;
    char *p;
    u32 hi;
    u8 *t;
    u8 t0, t1, t2, t3;
    u32 col;

    func_08859848(D_08A62C40, func_08898898(D_09A0B540, 0), 1, 0, 0, &tex);
    p = func_088597FC(D_08A62C40);
    *(s32 *)(p + 0x0) = 0x23000000;
    *(s32 *)(p + 0x4) = 0xDE000000;
    *(s32 *)(p + 0x8) = 0x21000001;
    *(s32 *)(p + 0xC) = 0xDF000032;
    *(s32 *)(p + 0x10) = 0x22000001;
    *(s32 *)(p + 0x14) = 0xDBFF0003;
    *(s32 *)(p + 0x18) = 0xC9000100;
    *(s32 *)(p + 0x1C) = 0xC0000000;
    *(s32 *)(p + 0x20) = 0xC7000101;
    *(s32 *)(p + 0x24) = 0xC6000101;
    *(s32 *)(p + 0x28) = 0xC2000001;
    *(s32 *)(p + 0x2C) = tex.unk4 | 0xC3000000;
    *(s32 *)(p + 0x30) = (tex.unk0 & 0xFFFFFF) | 0xA0000000;
    *(s32 *)(p + 0x34) = ((tex.unk0 & 0xFF000000) >> 8) | 0xA8000000 | tex.unk8;
    hi = (func_0885981C(D_08A62C40, tex.unkA) << 8) | 0xB8000000;
    *(s32 *)(p + 0x38) = hi | func_0885981C(D_08A62C40, tex.unk8);
    *(s32 *)(p + 0x3C) = tex.unk10 | 0xC500FF00;
    *(s32 *)(p + 0x40) = (tex.unkC & 0xFFFFFF) | 0xB0000000;
    *(s32 *)(p + 0x44) = ((tex.unkC & 0xFF000000) >> 8) | 0xB1000000;
    *(s32 *)(p + 0x48) = (tex.unk14 >> 3) | 0xC4000000;
    *(s32 *)(p + 0x4C) = 0xCB000000;
    *(s32 *)(p + 0x50) = 0x10000000;
    *(s32 *)(p + 0x54) = 0x08000000;
    func_088596C8(D_08A62C40, p, 0x16, arg3);
    func_0885980C(D_08A62C40, p + 0x58);

    if (arg2 <= 0) {
        return;
    }
    for (; arg2 > 0; arg2--, arg1++) {
        t = &D_08931BFC[arg1->idx * 4];
        t0 = t[0];
        t1 = t[1];
        t2 = t[2];
        t3 = t[3];
        if ((u32)(arg1->idx - 10) < 2) {
            if (arg1->color >= 0x30) {
                arg1->color = 0;
            }
            if (arg1->color < 0) {
                col = *(u32 *)(arg0 + 0x164);
            } else {
                col = *(u32 *)(arg0 + 0x168 + arg1->color * 4);
            }
            col |= 0xFF000000;
        } else {
            col = -1;
        }
        p = func_088597FC(D_08A62C40);
        *(s32 *)(p + 0x0) = (t1 << 16) | t0;
        *(s32 *)(p + 0x4) = col;
        *(s32 *)(p + 0x8) = (arg1->y << 16) | (u16)arg1->x;
        *(s32 *)(p + 0xC) = *(u16 *)(arg0 + 0x12A);
        *(s32 *)(p + 0x10) = ((t1 + t3) << 16) | (t0 + t2);
        *(s32 *)(p + 0x14) = col;
        *(s32 *)(p + 0x18) = ((arg1->y + arg1->size) << 16) | (u16)(arg1->x + arg1->size);
        *(s32 *)(p + 0x1C) = *(u16 *)(arg0 + 0x12A);
        *(s32 *)(p + 0x20) = (((u32)p & 0xFF000000) >> 8) | 0x10000000;
        *(s32 *)(p + 0x24) = ((u32)p & 0xFFFFFF) | 0x01000000;
        *(s32 *)(p + 0x28) = 0x1E000001;
        *(s32 *)(p + 0x2C) = 0x50000001;
        *(s32 *)(p + 0x30) = 0x1280011E;
        *(s32 *)(p + 0x34) = 0x04060002;
        *(s32 *)(p + 0x38) = 0x10000000;
        *(s32 *)(p + 0x3C) = 0x08000000;
        func_088596C8(D_08A62C40, p + 0x20, 8, arg3);
        func_0885980C(D_08A62C40, p + 0x40);
    }
}
