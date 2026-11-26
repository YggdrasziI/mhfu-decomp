/* unit_0883185C: 0x0883185C-0x08831CB0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* unit_0883185C: 0x0883185C-0x08831CB0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * func_0883185C: builds GE texture-setup commands for a sprite, from either
 * func_08859848 (flag 0x8000 set) or func_088125A4, then ends the list.
 * The 12-bit index at arg1+8 is read through a bit-field (u.b.idx), the
 * 0x8000 test and the u8 argument through the whole u16: with one u16 for
 * all three the load is kept across the call instead of being redone.
 * Owns two 6-entry jump tables (jtbl_08930B7C, jtbl_08930B94, 0x18 bytes each).
 */

typedef int s32;
typedef unsigned int u32;
typedef short s16;
typedef unsigned short u16;
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
    u32 unk0;
    u16 unk4;
    u16 unk6;
    u32 unk8;
    u16 unkC;
    u16 unkE;
    u32 unk10;
    u16 unk14;
    u16 unk16;
} Surface;

typedef struct {
    s16 x;
    s16 y;
    s16 w;
    s16 h;
    union {
        u16 flags;
        struct {
            u16 idx : 12;
            u16 pad : 3;
            u16 tex : 1;
        } b;
    } u;
    u16 id;
} Sprite;

extern s32 D_08A62C40;
extern s32 D_09A0B540;
extern s32 D_089CBBE0;
extern u32 *func_088597FC(s32);
extern s32 func_08898898(s32, s32);
extern int func_08859848(s32, s32, s32, s32, s32, Tex *);
extern s32 func_0885981C(s32, u32);
extern void func_088125A4(s32, u8, Surface *);
extern int func_088596C8(s32, u32 *, s32, u8);
extern int func_0885980C(s32, u32 *);

void func_0883185C(char *arg0, Sprite *arg1) {
    Tex tex;
    Surface surf;
    s32 n;
    u32 *p;
    u32 unit;
    u32 per;
    u32 off;
    u32 hi;
    u32 sz;
    u32 row;

    n = 0;
    p = func_088597FC(D_08A62C40);
    if (arg1->u.flags & 0x8000) {
        func_08859848(D_08A62C40, func_08898898(D_09A0B540, arg1->id),
                      arg1->u.b.idx, 0, 0, &tex);
        p[0] = 0xC2000001;
        p[1] = tex.unk4 | 0xC3000000;
        switch (tex.unk4) {
        case 0:
        case 1:
        case 2:
        case 3:
            unit = 8;
            break;
        case 5:
            unit = 16;
            break;
        case 4:
            unit = 32;
            break;
        default:
            unit = 4;
            break;
        }
        per = 0x80 / unit;
        row = (arg1->y / 8) * per;
        off = tex.unk8 * row;
        off += unit * (per * (arg1->x / unit));
        p[2] = ((tex.unk0 + off) & 0xFFFFFF) | 0xA0000000;
        p[3] = tex.unk8 | ((((tex.unk0 + off) & 0xFF000000) >> 8) | 0xA8000000);
        hi = (func_0885981C(D_08A62C40, arg1->h) << 8) | 0xB8000000;
        p[4] = hi | func_0885981C(D_08A62C40, arg1->w);
        p[5] = tex.unk10 | 0xC500FF00;
        p[6] = (tex.unkC & 0xFFFFFF) | 0xB0000000;
        p[7] = ((tex.unkC & 0xFF000000) >> 8) | 0xB1000000;
        sz = 0x100;
        if (tex.unk4 == 4) {
            sz = 0x10;
        }
        p[8] = ((sz + 7) >> 3) | 0xC4000000;
        p[9] = 0xCB000000;
        n += 10;
    } else {
        func_088125A4(D_089CBBE0, arg1->u.flags, &surf);
        p[0] = 0xC2000001;
        p[1] = surf.unkC | 0xC3000000;
        switch (surf.unkC) {
        case 0:
        case 1:
        case 2:
        case 3:
            unit = 8;
            break;
        case 5:
            unit = 16;
            break;
        case 4:
            unit = 32;
            break;
        default:
            unit = 4;
            break;
        }
        per = 0x80 / unit;
        row = (arg1->y / 8) * per;
        off = surf.unk4 * row;
        off += unit * (per * (arg1->x / unit));
        p[2] = ((surf.unk8 + off) & 0xFFFFFF) | 0xA0000000;
        p[3] = surf.unk4 | ((((surf.unk8 + off) & 0xFF000000) >> 8) | 0xA8000000);
        hi = (func_0885981C(D_08A62C40, arg1->h) << 8) | 0xB8000000;
        p[4] = hi | func_0885981C(D_08A62C40, arg1->w);
        p[5] = surf.unk14 | 0xC500FF00;
        p[6] = (surf.unk10 & 0xFFFFFF) | 0xB0000000;
        p[7] = ((surf.unk10 & 0xFF000000) >> 8) | 0xB1000000;
        sz = 0x100;
        if (surf.unkC == 4) {
            sz = 0x10;
        }
        p[8] = ((sz + 7) >> 3) | 0xC4000000;
        p[9] = 0xCB000000;
        n += 10;
    }
    p[n++] = 0x10000000;
    p[n++] = 0x08000000;
    func_088596C8(D_08A62C40, p, n, *(u8 *)(arg0 + 0x534));
    func_0885980C(D_08A62C40, p + n);
}
