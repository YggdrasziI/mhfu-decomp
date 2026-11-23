/* unit_0886C768: 0x0886C768-0x0886C8AC (ULES01213)
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
    u16 id;
    s16 val;
} Ent;

typedef struct {
    char pad0[0x542];
    Ent ent[4];
} Obj;

extern s32 D_09A4F0C4;
extern char *D_089CC438;
extern Obj *func_088DCEBC(s32, s32);

s16 func_0886C768(s32 arg0, u16 arg1, s32 arg2) {
    Obj *p;
    s32 i;
    s32 j;
    s16 sum = 0;

    switch (arg2) {
    case 0:
        for (j = 0; j < 4; j++) {
            p = func_088DCEBC(D_09A4F0C4, j);
            if (p != 0) {
                for (i = 0; i < 4; i++) {
                    if (p->ent[i].id == arg1) {
                        sum += p->ent[i].val;
                    }
                }
            }
        }
        break;
    case 1:
        p = func_088DCEBC(D_09A4F0C4, *(u8 *)(D_089CC438 + 0x28));
        for (i = 0; i < 4; i++) {
            if (p->ent[i].id == arg1) {
                return p->ent[i].val;
            }
        }
        break;
    default:
        p = func_088DCEBC(D_09A4F0C4, arg2 - 2);
        for (i = 0; i < 4; i++) {
            if (p->ent[i].id == arg1) {
                return p->ent[i].val;
            }
        }
        break;
    }
    return sum;
}
