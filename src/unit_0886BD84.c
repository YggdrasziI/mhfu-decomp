/* unit_0886BD84: 0x0886BD84-0x0886BE34 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    s32 active;
    u16 id;
    s8 count;
    s8 level;
} Ent;

extern void func_0886BBE4(char *);

void func_0886BD84(char *arg0, u16 arg1) {
    Ent *e;
    s32 i;

    e = (Ent *)(arg0 + 0x74C);
    for (i = 0; i < 2; i++, e++) {
        switch (e->active) {
        case 1:
            break;
        default:
            continue;
        }
        if (e->id == arg1) {
            if (--e->count <= 0) {
                if (e->level > *(s8 *)(arg0 + 0x20)) {
                    *(s8 *)(arg0 + 0x20) = e->level;
                    func_0886BBE4(arg0);
                }
                e->active = 0;
            }
        }
    }
}
