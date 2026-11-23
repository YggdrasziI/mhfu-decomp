/* unit_0886AF2C: 0x0886AF2C-0x0886B064 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Speed setting (`#pragma optimize_for_size off`): needed to match.
 */

#pragma optimize_for_size off

typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    s32 flags;
    u16 id;
    s16 timer;
} Ent;

typedef struct {
    s32 pad0;
    u16 pad4;
    s16 val;
} Ent2;

typedef struct {
    char pad0[0x728];
    Ent ent[2];
    Ent2 ent2[2];
} Obj;

extern void func_0886E0D8(Obj *, u16, s32);
extern void func_08873044(Obj *, u8, s16, s16);

s32 func_0886AF2C(Obj *arg0, s32 arg1) {
    Ent *e;
    s32 ret;
    s32 i;
    Obj *p;

    e = arg0->ent;
    ret = 0;
    i = 0;
    p = arg0;
    for (; i < 2; i++, e++, p = (Obj *)((char *)p + 8)) {
        if (e->flags & 0x60) {
            continue;
        }
        if ((e->flags & 0x11) == 0x11 && e->id == (u16)arg1) {
            if (e->flags & 0x100) {
                e->flags |= 0x40;
                return 0;
            }
            if (--e->timer <= 0) {
                func_0886E0D8(arg0, i, 0x200);
                ret = 1;
            } else {
                func_08873044(arg0, arg1, e->timer, p->ent2[0].val);
            }
        }
        if ((e->flags & 0x8014) == 0x8014 && e->id == (u16)arg1) {
            func_0886E0D8(arg0, i, 0x8000);
            ret = 1;
        }
    }
    return ret;
}
