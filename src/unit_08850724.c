/* unit_08850724: 0x08850724-0x088507F4 (ULES01213)
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
    u8 used;
    u8 type;
    s16 a;
    s16 b;
    s16 c;
    s16 d;
    s16 e;
} Entry;

typedef struct {
    char pad[0xA8];
    Entry ent[1];
} Pool;

extern s16 func_08850EC4(char *arg0);

u16 func_08850724(char *arg0, u8 arg1, s16 arg2, s16 arg3) {
    Pool *p = (Pool *)(arg0 + 0x4A0);
    s16 n;
    s16 i;

    if (arg1 > 6) {
        return 0xFFFF;
    }
    n = func_08850EC4(arg0);
    for (i = 0; i < n; i++) {
        if (p->ent[i].used == 0) {
            p->ent[i].used = 1;
            p->ent[i].type = arg1;
            p->ent[i].a = arg2;
            p->ent[i].b = arg3;
            p->ent[i].c = 0;
            p->ent[i].d = 0;
            p->ent[i].e = 0;
            return i;
        }
    }
    return 0xFFFF;
}
