/* unit_08901FDC: 0x08901FDC-0x089030D8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function.
 * Moves record `from` of the 0x60 records (+0x4A58, 0x1078 bytes each) to
 * slot `to`, shifting the records in between, together with the 0x28-byte
 * header (+0x687D0) and the word (+0x6A384) of each record.
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

extern "C" {

typedef struct { s16 a, b, c; } S3;
typedef long long s64;
typedef struct { f32 a, b, c, d; } F4;
typedef struct { f32 a, b, c; } F3;
typedef struct { F4 a; F3 b; } F7;

typedef struct {
    /* 0x0000 */ s8 unk0[18];
    /* 0x0012 */ u16 unk12;
    /* 0x0014 */ u16 unk14;
    /* 0x0016 */ s16 unk16[5];
    /* 0x0020 */ s16 unk20[7];
    /* 0x0030 */ s32 unk30;
    /* 0x0034 */ s8 unk34[98];
    /* 0x0096 */ u8 unk96;
    /* 0x0097 */ u8 unk97;
    /* 0x0098 */ u8 unk98;
    /* 0x009A */ S3 unk9A;
    /* 0x00A0 */ s64 unkA0;
    /* 0x00A8 */ F7 unkA8;
    /* 0x00C4 */ s8 unkC4[126];
    /* 0x0148 */ s64 unk148;
    /* 0x0150 */ s16 unk150[124];
    /* 0x0248 */ s8 unk248[8];
    /* 0x0250 */ s32 unk250[23];
    /* 0x02AC */ s32 unk2AC[100];
    /* 0x043C */ s32 unk43C[23];
    /* 0x0498 */ s32 unk498[100];
    /* 0x0628 */ s16 unk628[11];
    /* 0x0640 */ s32 unk640[340];
    /* 0x0B90 */ s32 unkB90[208];
    /* 0x0ED0 */ s32 unkED0[35];
    /* 0x0F5C */ s32 unkF5C[35];
    /* 0x0FE8 */ s32 unkFE8[35];
    /* 0x1074 */ u16 unk1074;
    /* 0x1076 */ u8 unk1076;
    /* 0x1077 */ u8 unk1077;
} Record; /* 0x1078 */

typedef struct {
    /* 0x00 */ struct { f32 a; } unk0;
    /* 0x04 */ s8 name[0x22];
    /* 0x26 */ s8 unk26;
} Header; /* 0x28 */

extern char *D_089CC438;

#define REC(i) (*(Record *) (D_089CC438 + (i) * 0x1078 + 0x4A58))
#define HDR(i) (*(Header *) (D_089CC438 + (i) * 0x28 + 0x687D0))
#define WORD(i) (((s32 *) (D_089CC438 + 0x6A384))[i])

void func_08901FDC(void *arg0, u32 from, u32 to) {
    Record rec;
    Header hdr;
    s32 word;

    if (from == to) {
        return;
    }
    rec = REC(from);
    hdr = HDR(from);
    word = WORD(from);
    if (to < from) {
        for (; from != to; from--) {
            REC(from) = REC(from - 1);
            HDR(from) = HDR(from - 1);
            WORD(from) = *(s32 *) (D_089CC438 + from * 4 + 0x6A380);
        }
    } else {
        to--;
        for (; from != to; from++) {
            REC(from) = REC(from + 1);
            HDR(from) = HDR(from + 1);
            WORD(from) = *(s32 *) (D_089CC438 + from * 4 + 0x6A388);
        }
    }
    REC(to) = rec;
    HDR(to) = hdr;
    WORD(to) = word;
}

}
