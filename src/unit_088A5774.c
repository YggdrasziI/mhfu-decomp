/* unit_088A5774: 0x088A5774-0x088A59C4 (ULES01213) */

#pragma optimize_for_size off

typedef int s32;
typedef short s16;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 unk0;
    s8 unk1;
    s16 unk2;
    u16 unk4;
    u16 unk6;
    u16 unk8;
    u16 unkA;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    u8 unk18;
} Out;

typedef struct {
    s32 unk0;
    s32 unk4;
    char unk8[0x4];
    s32 unkC;
    u8 unk10;
} Src3;

s32 func_088A5774(Out *out, s8 **src, u8 arg2, s32 arg3) {
    s16 v;

    out->unk0 = src[0][2];
    out->unk0 = out->unk0 * src[1][8] / 127;
    out->unk0 = out->unk0 * src[2][6] / 127;

    v = src[0][3] - 64;
    if (v < -64) {
        v = -64;
    } else if (v > 63) {
        v = 63;
    }
    v += (s16)(src[1][9] - 64);
    if (v < -64) {
        v = -64;
    } else if (v > 63) {
        v = 63;
    }
    v += (s16)(src[2][7] - 64);
    if (v < -64) {
        v = -64;
    } else if (v > 63) {
        v = 63;
    }
    out->unk1 = v + 64;
    out->unk2 = src[0][5] + src[0][4] * 100;
    out->unk2 = out->unk2 + (s16)(src[1][11] + src[1][10] * 100);
    out->unk2 = out->unk2 + (s16)(src[2][9] + src[2][8] * 100);
    out->unk2 = out->unk2 + (s16)((arg2 - ((u8 *)src[2])[5]) * 100);

    out->unk4 = *(u16 *)(src[1] + 4);
    out->unk6 = *(u16 *)(src[1] + 6);
    out->unk8 = *(u16 *)(src[2] + 0);
    out->unkA = *(u16 *)(src[2] + 2);
    out->unk10 = arg3 + ((Src3 *)src[3])->unk0;
    out->unkC = ((Src3 *)src[3])->unkC;
    out->unk14 = ((Src3 *)src[3])->unk4;
    out->unk18 = ((Src3 *)src[3])->unk10;
    return 0;
}
