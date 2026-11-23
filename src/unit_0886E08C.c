/* unit_0886E08C: 0x0886E08C-0x0886E0D8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0886E08C: flag test on an 8-byte entry table at offset 0x728. */

typedef int s32;

typedef struct {
    s32 flags;
    s32 unk4;
} Entry;

typedef struct {
    char pad[0x728];
    Entry ent[1];
} Obj;

s32 func_0886E08C(Obj *arg0, s32 arg1) {
    s32 f = arg0->ent[arg1].flags;

    if (f & 0x10) {
        if ((f & 0x440) == 0x40) {
            return 0;
        }
        if (f & 0x20) {
            return 1;
        }
    }
    return 0;
}
