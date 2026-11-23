/* unit_0886E828: 0x0886E828-0x0886E92C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Speed setting (`#pragma optimize_for_size off`): needed to match.
 */

#pragma optimize_for_size off
typedef int s32;
typedef unsigned char u8;

typedef struct {
    s32 flags;
    s32 unk4;
} Ent;

typedef struct {
    char pad0[0x67C];
    u8 mode;
    char pad67D[0x728 - 0x67D];
    Ent ent[2];
} Obj;

extern void func_0886E92C(Obj *, s32);
extern void func_0886E978(Obj *, s32);

s32 func_0886E828(Obj *arg0, s32 arg1) {
    s32 i;
    s32 mask;
    s32 flags;

    mask = 0;
    for (i = 0; i < 2; i++) {
        flags = arg0->ent[i].flags;
        if (flags & 0x10) {
            if (flags & 0x20) {
                mask |= 1 << i;
            }
            if ((flags & 0x440) == 0x40) {
                arg0->ent[i].flags |= 0x400;
                if (arg1 != 0) {
                    func_0886E92C(arg0, 0);
                }
                return 0;
            }
        }
    }
    switch (arg0->mode) {
    case 1:
        if ((mask & 1) == 1) {
            if (arg1 != 0) {
                func_0886E978(arg0, 0);
            }
            return 1;
        }
        break;
    case 2:
        if ((mask & 3) == 3) {
            if (arg1 != 0) {
                func_0886E978(arg0, 0);
            }
            return 1;
        }
        break;
    }
    return 0;
}
