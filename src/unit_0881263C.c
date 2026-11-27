/* unit_0881263C: 0x0881263C-0x08812938 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef unsigned int u32;
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

extern s32 D_08A62C40;
extern u8 func_08859848(s32, s32, s32, s32, s32, Tex *);
extern u8 func_08811E18(s32, s32, u16, u16, u16, u16, s32);
extern u8 func_088125A4(s32, u8, Surface *);
extern int func_08812264(s32, u8);
extern s32 func_08859480(s32, u32 *, s32, s32);

u8 func_0881263C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    Tex tex;
    Surface surf;
    u32 buf[32];
    u32 v;
    u32 *p;
    u32 w;
    u32 h;
    u8 r;

    if (func_08859848(D_08A62C40, arg2, arg3, arg4, arg5, &tex) == 0) {
        return 0xFF;
    }
    r = func_08811E18(arg0, arg1, tex.unk8, tex.unkA, tex.unk4, tex.unk10, -1);
    if (r == 0xFF) {
        return 0xFF;
    }
    if (func_088125A4(arg0, r, &surf) == 0) {
        func_08812264(arg0, r);
        return 0xFF;
    }
    switch (surf.unkC) {
    case 1:
        v = (u32)tex.unk8 >> 1;
        h = tex.unkA;
        break;
    case 3:
        v = tex.unk8;
        h = tex.unkA;
        break;
    case 4:
        v = (u32)tex.unk8 >> 3;
        h = tex.unkA;
        break;
    case 5:
        v = (u32)tex.unk8 >> 2;
        h = tex.unkA;
        break;
    default:
        func_08812264(arg0, r);
        return 0xFF;
    }
    p = buf;
    p[0] = (tex.unk0 & 0xFFFFFF) | 0xB2000000;
    p[1] = (((tex.unk0 & 0xFF000000) >> 8) | 0xB3000000) | v;
    p[2] = (surf.unk8 & 0xFFFFFF) | 0xB4000000;
    p[3] = (((surf.unk8 & 0xFF000000) >> 8) | 0xB5000000) | v;
    p[4] = 0xEB000000;
    p[5] = 0xEC000000;
    p[6] = (((h - 1) << 10) | 0xEE000000) | (v - 1);
    p[7] = 0xEA000001;
    p += 8;
    if (tex.unkC != 0) {
        switch (surf.unk14) {
        case 1:
            w = tex.unk14 >> 1;
            break;
        case 3:
            w = tex.unk14;
            break;
        default:
            func_08812264(arg0, r);
            return 0xFF;
        }
        p[0] = (tex.unkC & 0xFFFFFF) | 0xB2000000;
        p[1] = (((tex.unkC & 0xFF000000) >> 8) | 0xB3000000) | w;
        p[2] = (surf.unk10 & 0xFFFFFF) | 0xB4000000;
        p[3] = (((surf.unk10 & 0xFF000000) >> 8) | 0xB5000000) | w;
        p[4] = 0xEB000000;
        p[5] = 0xEC000000;
        p[6] = (w - 1) | 0xEE000000;
        p[7] = 0xEA000001;
        p += 8;
    }
    p[0] = 0xCC000000;
    p[1] = 0x10000000;
    p[2] = 0x08000000;
    p += 3;
    func_08859480(D_08A62C40, buf, p - buf, 1);
    return r;
}
