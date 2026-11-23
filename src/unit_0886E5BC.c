/* unit_0886E5BC: 0x0886E5BC-0x0886E6A8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Speed setting (`#pragma optimize_for_size off`): needed to match.
 */

#pragma optimize_for_size off

typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    s32 flags;
    u16 id;
    s16 count;
} Ent;

typedef struct {
    char pad[0x728];
    Ent ent[2];
} Obj;

extern void func_0886E0D8(Obj *, u16, s32);
extern void func_08873044(Obj *, u8, s16, s16);

s32 func_0886E5BC(Obj *obj, s32 arg1) {
    Ent *e;
    s32 i;
    char *p;
    s32 ret;

    ret = 0;
    e = obj->ent;
    i = 0;
    p = (char *)obj;
    for (; i < 2; i++, e++, p += 8) {
        if (e->flags & 0x60) {
            continue;
        }
        if ((e->flags & 0x11) == 0x11 && e->id == (u16)arg1) {
            if (--e->count <= 0) {
                func_0886E0D8(obj, i, 0x100);
                ret = 1;
            } else {
                func_08873044(obj, arg1, e->count, *(s16 *)(p + 0x73E));
            }
        }
    }
    return ret;
}
