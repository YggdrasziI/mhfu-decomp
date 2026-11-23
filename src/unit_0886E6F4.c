/* unit_0886E6F4: 0x0886E6F4-0x0886E828 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Speed setting (`#pragma optimize_for_size off`): needed to match.
 */

#pragma optimize_for_size off

typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct { u16 id; s16 val; } Ent;
typedef struct { char pad[0x542]; Ent ent[4]; } Big;
typedef struct { s32 flags; u16 id; u16 pad; } Slot;
typedef struct { char pad[0x728]; Slot slot[2]; } Obj;

extern char *D_089CC438;
extern s32 D_09A4F0C4;
extern Big *func_088DCEBC(s32, s32);

s32 func_0886E6F4(Obj *arg0, s32 arg1) {
    u16 id;
    s16 sum;
    s32 i;
    s32 j;
    Big *e;
    Slot *p;
    s32 k;

    p = arg0->slot;
    id = arg1;
    sum = 0;
    for (k = 0; k < 2; k++, p++) {
        if ((p->flags & 0x12) == 0x12 && p->id == id) {
            break;
        }
    }
    if (k >= 2) {
        return 0;
    }
    if (p->flags & 0x80) {
        e = func_088DCEBC(D_09A4F0C4, *(u8 *)(D_089CC438 + 0x28));
        for (i = 0; i < 4; i++) {
            if (e->ent[i].id == id) {
                sum = e->ent[i].val;
                break;
            }
        }
    } else {
        for (j = 0; j < 4; j++) {
            e = func_088DCEBC(D_09A4F0C4, j);
            if (e != 0) {
                for (i = 0; i < 4; i++) {
                    if (e->ent[i].id == id) {
                        sum += e->ent[i].val;
                    }
                }
            }
        }
    }
    return sum;
}
