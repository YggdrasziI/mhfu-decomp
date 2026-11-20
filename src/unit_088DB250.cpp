/* unit_088DB250: 0x088DB250-0x088DB488 (ULES01213)
 *
 * Bounds (hypothesis): 4 functions between unit_088DB1C0 and unit_088DB488.
 *
 * Passes over the six object pointers at +0xC: func_088DB250 runs
 * func_088DBA0C for the slots whose object has flag 1 clear (after
 * func_088DB424, and func_09B62E00 unless a global mode bit is set),
 * func_088DB338 runs func_088D2894 on the objects with flag 1,
 * func_088DB39C func_088D2E04 on those with flags 1, 2 and bit 0x200 of
 * +0x410. func_088DB424 runs func_088D61CC on the object of the global
 * index (0 unless bit 0 of +0xF7A57C of D_08A631A0 is set).
 *
 * C++: bool conversions. Optimized for speed (loops over the slots through
 * a stepped pointer).
 */

#pragma optimize_for_size off

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct Obj {
    void *vtable;
    s32 flags;
} Obj;

typedef struct Group {
    char pad0[0xC];
    Obj *slot[6];
} Group;

extern "C" {

extern char *D_089CC438;
extern char *D_08A631A0;
extern s32 D_08A62C5C;
extern s32 D_09C18FD0;

extern void func_088666B4(s32, s32);
extern void func_09B62E00(s32);
extern void func_088D2894(char *);
extern void func_088D2E04(char *);
extern void func_088D61CC(char *);
extern void func_088DBA0C(Group *, s32);

void func_088DB424(Group *arg0);

void func_088DB250(Group *arg0) {
    s32 i;
    s32 flags;

    func_088DB424(arg0);
    func_088666B4(D_08A62C5C, 2);
    flags = *(s32 *)(D_089CC438 + 0x6AF14);
    if ((bool) (flags & 1) == 0 && (bool) (flags & 8) == 0 && (bool) (flags & 0x20) == 0
        && (bool) (flags & 0x40) == 0) {
        func_09B62E00(D_09C18FD0);
    }
    for (i = 0; i < 6; i++) {
        if (arg0->slot[i] != 0 && (bool) (arg0->slot[i]->flags & 1) == 0) {
            func_088DBA0C(arg0, i);
        }
    }
}

void func_088DB338(Group *arg0) {
    s32 i;

    for (i = 0; i < 6; i++) {
        if (arg0->slot[i] != 0 && (bool) (arg0->slot[i]->flags & 1) != 0) {
            func_088D2894((char *) arg0->slot[i]);
        }
    }
}

void func_088DB39C(Group *arg0) {
    s32 i;

    for (i = 0; i < 6; i++) {
        if (arg0->slot[i] != 0 && (bool) (arg0->slot[i]->flags & 1) != 0
            && (bool) (arg0->slot[i]->flags & 2) != 0
            && (bool) (*(s32 *)((char *) arg0->slot[i] + 0x410) & 0x200) != 0) {
            func_088D2E04((char *) arg0->slot[i]);
        }
    }
}

void func_088DB424(Group *arg0) {
    s32 idx;

    if ((bool) (*(s32 *)(D_08A631A0 + 0xF7A57C) & 1) == 0) {
        idx = 0;
    } else {
        idx = *(u8 *)(D_089CC438 + 0x28);
    }
    if (arg0->slot[idx] != 0) {
        func_088D61CC((char *) arg0->slot[idx]);
    }
}

}
