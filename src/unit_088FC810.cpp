/* unit_088FC810: 0x088FC810-0x088FCF40 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Stores part arg4 (six parts: five of 0x2E0 bytes, the last of 0x218) of a
 * record received under an eight-byte key into one of ten 0x1090-byte slots
 * at +0x188; once the six parts are there (low six bits of the slot flags),
 * the record is copied over the global record (0x1078 bytes at +0x4A58 of
 * D_089CC438) holding the same key.
 *
 * arg7 is not used here; func_0889B1A4 passes it in $t3.
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
    /* 0x00 */ char unk0[6];
    /* 0x06 */ char key[8];
    /* 0x0E */ u16 timer;
    /* 0x10 */ u16 flags;
    /* 0x12 */ char pad12[2];
    /* 0x14 */ s32 unk14;
    /* 0x18 */ Record rec;
} Slot; /* 0x1090 */

typedef struct {
    /* 0x0000 */ char pad0[0x188];
    /* 0x0188 */ Slot slot[10];
    /* 0xA728 */ s8 unkA728;
    /* 0xA729 */ char padA729[3];
    /* 0xA72C */ s8 unkA72C;
} Box;

extern char *D_089CC438;

extern s32 func_0880BFF0(void *, void *, s32);
extern void func_08854BAC(char *, char *);
extern void func_0885128C(char *, s32);
extern void memcpy(void *, void *, s32);

s32 func_088FC810(Box *arg0, char *arg1, char *arg2, char *arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    Slot *p;
    s32 i;
    s32 j;
    s32 n;
    s32 m;
    s32 k;
    Slot *s;
    u16 *flags;
    char *rec;

    if (func_0880BFF0(D_089CC438 + 0x679A0, arg2, 8) == 0) {
        return 0;
    }
    for (i = 0; i < 10; i++) {
        if (func_0880BFF0(arg0->slot[i].key, arg2, 8) == 0 && arg0->slot[i].unk14 == arg5) {
            flags = &((Slot *)arg0->slot)[i].flags;
            if ((*flags & 0x3F) != 0x3F) {
                rec = (char *)&arg0->slot[i].rec;
                if (arg4 == 0) {
                    *flags = 0;
                }
                *flags |= (u16)(1 << arg4);
                memcpy(rec + arg4 * 0x2E0, arg3, arg4 != 5 ? 0x2E0 : 0x218);
                arg0->slot[i].timer = 300;
                if ((*flags & 0x3F) == 0x3F) {
                    s = &arg0->slot[i];
                    for (j = 0; j < 0x60; j++) {
                        if (func_0880BFF0(((Record *)(D_089CC438 + j * 0x1078 + 0x4A58))->unk248, arg2, 8) == 0) {
                            *(Record *)(D_089CC438 + j * 0x1078 + 0x4A58) = s->rec;
                            func_08854BAC(D_089CC438, D_089CC438 + j * 0x28 + 0x687D0);
                            func_0885128C(D_089CC438, j);
                            arg0->unkA72C = 0;
                            s->flags = 0;
                            return 1;
                        }
                    }
                    if (arg6 != 0) {
                        s->flags = 0;
                        return 0;
                    }
                    for (m = 0; m < 10; m++) {
                        if (m != i) {
                            if (func_0880BFF0(arg0->slot[m].key, arg0->slot[i].key, 8) == 0 && (arg0->slot[m].flags & 0x3F) == 0x3F) {
                                arg0->slot[m].flags = 0;
                            }
                        }
                    }
                }
                arg0->unkA728 = 1;
                return 2;
            }
            return 0;
        }
    }
    p = arg0->slot;
    n = 0;
    for (i = 0; i < 10; i++, p++) {
        if ((p->flags & 0x3F) == 0x3F) {
            n++;
        }
    }
    if (n < 10) {
        for (k = 0; k < 10; k++) {
            if ((arg0->slot[k].flags & 0x3F) == 0) {
                rec = (char *)&arg0->slot[k].rec;
                if (arg4 == 0) {
                    arg0->slot[k].flags = 0;
                }
                arg0->slot[k].flags |= (u16)(1 << arg4);
                rec += arg4 * 0x2E0;
                memcpy(arg0->slot[k].key, arg2, 8);
                memcpy(arg0->slot[k].unk0, arg1, 6);
                arg0->slot[k].unk14 = arg5;
                arg0->slot[k].timer = 300;
                memcpy(rec, arg3, arg4 != 5 ? 0x2E0 : 0x218);
                return 2;
            }
        }
    }
    return 3;
}

}
