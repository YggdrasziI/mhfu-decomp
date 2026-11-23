/* unit_0886C914: 0x0886C914-0x0886CA74 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Speed setting (`#pragma optimize_for_size off`): needed to match.
 */

#pragma optimize_for_size off
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    u16 id;
    s16 num;
} Pair;

typedef struct {
    s32 flags;
    u16 id;
    u16 pad;
} Ent;

extern char *D_089CC438;
extern s32 func_0886A30C(char *, s32);
extern s32 func_0886F78C(char *);
extern Pair *func_08856884(char *, s32);
extern s32 func_088D7904(s32, s32, s32);
extern int func_0886C8AC(char *, s32);

s32 func_0886C914(char *arg0, s32 arg1) {
    s32 i;
    s32 ret;
    Ent *e;
    s32 j;
    Pair *p;

    ret = 0;
    if (func_0886A30C(arg0, 1) != 0) {
        return 0;
    }
    e = (Ent *)(arg0 + 0x728);
    for (i = 0; i < 2; i++, e++) {
        if (((e->flags & 0x20) | 0x12) != 0x12) {
            continue;
        }
        if (e->id == 0) {
            continue;
        }
        if (e->id == 0x3A0 && (*(s32 *)(arg0 + 0x28) & 0x10)) {
            if (func_0886F78C(arg0) < 2000) {
                continue;
            }
        }
        for (j = 0; j < 24; j++) {
            if (e->id == func_08856884(D_089CC438, j)->id) {
                p = func_08856884(D_089CC438, j);
                if ((u16)func_088D7904(arg1, p->id, func_08856884(D_089CC438, j)->num) > 0) {
                    ret = 1;
                    func_0886C8AC(arg0, e->id);
                }
            }
        }
    }
    return ret;
}
