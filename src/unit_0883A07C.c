/* unit_0883A07C: 0x0883A07C-0x0883A758 (ULES01213)
 *
 * Bounds (hypothesis): 1 function.
 *
 * Optimized for speed (pointer-stepped copy loops). Records are copied field
 * by field with the 3-halfword tail as one sub-structure assignment.
 *
 * D_0893B3C4 is read as u16 (lhu) by the func_08831338 calls and as s16 (lh)
 * in the sums: a u16 array with (s16) casts in the sums. With an s16 array the
 * conversion to the u16 parameter made the scheduler hoist both %hi loads of
 * the first call (lui v1 / lui v0 instead of v0 twice).
 *
 * NonMatching: func_0883A07C 98.03 %. Left: in the first func_08831338 call
 * ours sets a0 and t3 (0xFF) first and loads a1 after a3 (original: sw zero,
 * a1, a3, a2, a0, t0, t2, t3 in the delay slot); in the loop call ours computes
 * (i + 1) first into a0 and passes a1 with andi 0xFF (original: t3 first,
 * (i + 1) into v1 after the sub-record load, seh a1). The second parameter as
 * u8 scores better than s16 (97.21 %), which gives the seh but not the order.
 */

#pragma optimize_for_size off

typedef int s32;
typedef short s16;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Box {
    u8 unk0[6];
    s16 unk6;
    u8 unk8;
    u8 unk9[3];
    u16 unkC;
    u16 unkE;
    u16 unk10;
    u8 unk12[2];
    s32 unk14;
    u8 unk18[0x10];
} Box;

typedef struct V3 {
    s16 x;
    s16 y;
    s16 z;
} V3;

typedef struct Rec {
    u8 a;
    u8 b;
    u16 c;
    u16 d;
    V3 v;
} Rec;

typedef struct Set {
    u8 unk0[0x20];
    Rec main;
    Rec sub[5];
    u8 unk68;
    char unk69[1];
} Set;

typedef struct Big {
    u8 unk0[0x4C8];
    Set s;
} Big;

extern s32 D_09B22D70;
extern u16 D_09B051AE;
extern char D_0893B218;
extern char D_0893B39C;
extern char D_0893B3B0;
extern char D_0893B3D0;
extern u16 D_089AC8C4[];
extern u16 D_089AC8E0;
extern char *D_089CC438;
extern char *D_08A631A8;
extern char *D_08A62C54;
extern char *D_089CBBEC;
extern s32 D_09A4F0C4;
extern u16 D_0893B3BC;
extern u16 D_0893B3BE;
extern s32 D_0893B3C0;
extern u16 D_0893B3C4[2];
extern u16 D_0893B3C8;
extern s16 D_0893B3CA;
extern s16 D_0893B3CC;
extern s16 D_0893B3CE;
extern s32 D_0893AEB8[];

extern char *func_09A7B790(s32, u16);
extern int func_0880E8F0(char *, char *, ...);
extern void func_0882FA24(Box *, char *, char *, s32, s32);
extern void func_0882F580(char *, Box *, char *, s32, s32, s32);
extern void func_0882FB38(char *, Box *, u16, u16, s32, s32);
extern char *func_0885151C(char *, u16);
extern void func_0882FC50(char *, char *, char *, s32);
extern void func_08890E38(char *, s8);
extern void func_08890DFC(char *, s16, s16);
extern void func_08890DE8(char *, s8, u8);
extern int func_088911A0(char *, char *);
extern void func_0881B384(char *, s16, s16, Rec *);
extern void func_08891474(char *, s16, s16, char *, ...);
extern void func_0881B7F0(char *, char *, Rec *, s16, s16, s16);
extern void func_08831338(char *, u8, s16, s32, u16, s32, s32, s32, s32);
extern char *func_0885C968(char *, u8, u16);
extern void func_088920A8(char *, s16, s16, char *, ...);
extern char *func_088DCEBC(s32, s32);
extern void func_088D897C(char *);
extern void func_08838894(char *, char *, char *, s16, s16);

#define COPY(D_, S_) ((D_).a = (S_).a, (D_).b = (S_).b, (D_).c = (S_).c, (D_).d = (S_).d, (D_).v = (S_).v)

void func_0883A07C(char *arg0, s32 arg1, char *arg2) {
    Box box;
    s32 j;
    s32 m;
    s32 n;
    char text[0x40];
    Rec saved;
    Rec subs[5];
    Set *set;
    Set *cur;
    Big *dst;
    char *fmt;
    s32 i;
    s32 k;
    s16 x;

    set = (Set *)(arg2 + 0x20);
    func_0880E8F0(text, &D_0893B218, func_09A7B790(D_09B22D70, D_09B051AE));
    func_0882FA24(&box, &D_0893B39C, text, 0, 0);
    switch (arg1) {
    case 1:
        box.unk14 = 0;
        box.unk6 = 0x90;
        break;
    }
    func_0882F580(arg0, &box, text, -1, 0xFF, 1);
    func_0882FB38(arg0, &box, arg1, 2, 0, 0);
    func_0882FC50(arg0, &D_0893B3B0, func_0885151C(D_089CC438, D_089AC8C4[arg1]), 0xFF);
    switch (arg1) {
    case 0:
        func_08890E38(D_08A631A8, 0);
        x = box.unkC + box.unk8 * 4;
        func_08890DFC(D_08A631A8, x, box.unkE);
        func_08890DE8(D_08A631A8, 0x10, 0xE);
        func_088911A0(D_08A631A8, arg2 + 8);
        func_08890DE8(D_08A631A8, 0xE, 0xE);
        func_0881B384(arg0, x, box.unkE + box.unk10, &set->main);
        func_08891474(D_08A631A8, x, box.unkE + box.unk10 * 2, &D_0893B3D0, set->unk68 + 1);
        func_0881B7F0(arg0, set->unk69, &set->main, D_0893B3BC, D_0893B3BE + D_0893B3C0, D_0893B3C0);
        break;
    case 1:
        func_08831338(arg0, set->main.b, set->main.c, D_0893B3C4[0], D_0893B3C4[1], D_0893B3C8, D_0893B3C8, 0xFF, 0);
        func_088920A8(D_08A631A8, (s16)D_0893B3C4[0] + D_0893B3CC, (s16)D_0893B3C4[1] + D_0893B3CE, func_0885151C(D_089CC438, D_089AC8E0),
                      func_0885C968(D_08A62C54, set->main.b, set->main.c));
        for (i = 0; i < 5; i++) {
            func_08831338(arg0, D_0893AEB8[i], set->sub[D_0893AEB8[i]].c, D_0893B3C4[0], (i + 1) * D_0893B3CA + (s16)D_0893B3C4[1],
                          D_0893B3C8, D_0893B3C8, 0xFF, 0);
            k = D_0893AEB8[i];
            func_088920A8(D_08A631A8, (s16)D_0893B3C4[0] + D_0893B3CC, (s16)D_0893B3C4[1] + D_0893B3CE + D_0893B3CA * (i + 1), func_0885151C(D_089CC438, D_089AC8E0),
                          func_0885C968(D_08A62C54, k, set->sub[k].c));
        }
        cur = (Set *)(D_089CC438 + 0x4A0);
        dst = (Big *)func_088DCEBC(D_09A4F0C4, *(u8 *)(D_089CC438 + 0x28));
        COPY(saved, cur->main);
        for (j = 0; j < 5; j++) {
            COPY(subs[j], cur->sub[j]);
        }
        COPY(dst->s.main, set->main);
        COPY(cur->main, dst->s.main);
        for (m = 0; m < 5; m++) {
            COPY(dst->s.sub[m], set->sub[m]);
            COPY(cur->sub[m], dst->s.sub[m]);
        }
        func_088D897C((char *)dst);
        func_08838894(D_089CBBEC, (char *)dst, 0, D_0893B3BC, D_0893B3BE + D_0893B3C0);
        COPY(dst->s.main, saved);
        COPY(cur->main, dst->s.main);
        for (n = 0; n < 5; n++) {
            COPY(dst->s.sub[n], subs[n]);
            COPY(cur->sub[n], dst->s.sub[n]);
        }
        func_088D897C((char *)dst);
        break;
    }
}
