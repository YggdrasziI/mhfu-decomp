/* unit_0886E2EC: 0x0886E2EC-0x0886E36C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Speed setting (`#pragma optimize_for_size off`): needed to match.
 */

/* func_0886E2EC: claim a free 8-byte slot (flag 0x10) and mirror it two slots on. */

#pragma optimize_for_size off


typedef int s32;
typedef short s16;
typedef unsigned short u16;

typedef struct {
    s32 flags;
    u16 a;
    s16 b;
} Ent;

typedef struct {
    char pad[0x728];
    Ent ent[4];
} Obj;

void func_0886E2EC(Obj *obj, Ent *src) {
    s32 i;

    for (i = 0; i < 2; i++) {
        if (!(obj->ent[i].flags & 0x10)) {
            obj->ent[i].flags = src->flags;
            obj->ent[i].a = src->a;
            obj->ent[i].b = src->b;
            obj->ent[i + 2].flags = obj->ent[i].flags;
            obj->ent[i + 2].a = obj->ent[i].a;
            obj->ent[i + 2].b = obj->ent[i].b;
            obj->ent[i + 2].flags |= 0x10;
            obj->ent[i].flags |= 0x10;
            return;
        }
    }
}
