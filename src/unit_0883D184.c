/* unit_0883D184: 0x0883D184-0x0883D274 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

#pragma optimize_for_size off

typedef int s32;

extern void memcpy(void *, void *, s32);

typedef struct {
    char data[0x14];
    s32 id;
} Ent;

typedef struct {
    char pad0[0x5E8];
    s32 flags;
    char pad5EC[0x20];
    Ent ent[5];
} Obj;

void func_0883D184(Obj *p, void *src, s32 id) {
    s32 i;
    s32 j;

    for (i = 0; i < 5; i++) {
        if (p->ent[i].id == -1) {
            break;
        }
    }
    if (i >= 5) {
        for (j = 0; j < 4; j++) {
            memcpy(&p->ent[j], &p->ent[j + 1], 0x18);
        }
        i = 4;
    }
    memcpy(&p->ent[i], src, 0x12);
    p->ent[i].id = id;
    p->flags |= 0x80;
}
