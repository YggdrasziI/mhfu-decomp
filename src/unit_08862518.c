/* unit_08862518: 0x08862518-0x088626D0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08862518: builds texture-setup display-list commands for each entry. */
#pragma optimize_for_size off

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

extern s32 D_08A62C40;
extern int func_08859848(s32, s32, s32, s32, s32, Tex *);
extern s32 func_0885981C(s32, u32);

s32 func_08862518(char *arg0, char *arg1, char *arg2, u8 arg3) {
    Tex tex;
    char *p;
    u32 hi;
    s32 i;

    if (arg0 != 0) {
        *(char **)(arg0 + 4) = arg1;
        for (i = 0; i < *(s32 *)(arg2 + 8); i++) {
            if (func_08859848(D_08A62C40, (s32)arg2, i, 0, 0, &tex) == 0) {
                return 0;
            }
            p = *(char **)(arg0 + 4) + i * 0x20 + arg3 * 0x20;
            *(s32 *)(p + 0x0) = tex.unk4 | 0xC3000000;
            *(s32 *)(p + 0x4) = (tex.unk0 & 0xFFFFFF) | 0xA0000000;
            *(s32 *)(p + 0x8) = ((tex.unk0 & 0xFF000000) >> 8) | 0xA8000000 | tex.unk8;
            hi = (func_0885981C(D_08A62C40, tex.unkA) << 8) | 0xB8000000;
            *(s32 *)(p + 0xC) = hi | func_0885981C(D_08A62C40, tex.unk8);
            *(s32 *)(p + 0x10) = tex.unk10 | 0xC500FF00;
            *(s32 *)(p + 0x14) = (tex.unkC & 0xFFFFFF) | 0xB0000000;
            *(s32 *)(p + 0x18) = ((tex.unkC & 0xFF000000) >> 8) | 0xB1000000;
            *(s32 *)(p + 0x1C) = ((tex.unk14 + 7) >> 3) | 0xC4000000;
        }
        *(char **)(arg0 + 0) = arg2;
        *(u8 *)(arg0 + 8) = *(s32 *)(arg2 + 8);
        return 1;
    }
    return 0;
}
