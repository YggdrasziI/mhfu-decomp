/* unit_08901A60: 0x08901A60-0x08901FDC (ULES01213)
 *
 * Bounds (hypothesis): 1 function.
 * Compacts the 0x60 records of 0x1078 bytes at +0x4A58 of D_089CC438: each
 * free record (first halfword 0) is removed by shifting the next ones down,
 * with the two parallel arrays at +0x687D0 (0x28 bytes) and +0x6A384 (4
 * bytes); the last slot of each array is then cleared.
 *
 * C++: the record and header copies are structure assignments, which
 * mwccpsp expands member by member (one count-down loop per array member).
 * #pragma optimize_for_size off: the loops step pointers, tested at the
 * bottom behind a guard.
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
    /* 0x00 */ f32 unk0;
    /* 0x04 */ s8 name[0x22];
    /* 0x26 */ s8 unk26;
} Header; /* 0x28 */

typedef struct {
    /* 0x00000 */ char pad0[0x4A58];
    /* 0x04A58 */ Record rec[0x60];
    /* 0x67758 */ char pad67758[0x1078];
    /* 0x687D0 */ Header hdr[0x60];
    /* 0x696D0 */ char pad696D0[0xCB4];
    /* 0x6A384 */ s32 val[0x60];
} Save;

extern char *D_089CC438;

#define SAVE ((Save *)D_089CC438)

extern void memset(void *, s32, s32);

static inline s32 count_used(void) {
    char *p = D_089CC438 + 0x4A58;
    s32 n = 0;
    s32 i;

    for (i = 0; i < 0x60; i++, p += 0x1078) {
        if (*(u16 *)p != 0) {
            n++;
        }
    }
    return n;
}

static inline s32 is_used(Record *r) {
    return *(u16 *)r != 0;
}

void func_08901A60(void *arg0) {
    s32 i;
    Record *rec;
    Record *rec2;
    s32 *val;
    s32 *val2;
    Header *hdr;
    Header *hdr2;
    s32 count;
    s32 j;

    count = count_used();
    for (i = 0; i < count; i++) {
        rec = &SAVE->rec[i];
        val = &SAVE->val[i];
        hdr = &SAVE->hdr[i];
        if (is_used(rec)) {
            continue;
        }
        rec2 = rec + 1;
        val2 = val + 1;
        hdr2 = hdr + 1;
        for (j = i + 1; j < 0x60; j++) {
            *rec = *rec2;
            *val = *val2;
            *hdr = *hdr2;
            rec++;
            rec2++;
            val++;
            val2++;
            hdr++;
            hdr2++;
        }
        memset(&SAVE->rec[0x5F], 0, sizeof(Record));
        memset(&SAVE->hdr[0x5F], 0, sizeof(Header));
        SAVE->val[0x5F] = 0;
        i--;
    }
}

}
