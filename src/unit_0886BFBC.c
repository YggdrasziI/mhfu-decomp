/* unit_0886BFBC: 0x0886BFBC-0x0886C008 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off
typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    u16 id;
    s8 val;
    s8 pad;
} Ent;

typedef struct {
    char pad[0x6C];
    Ent ent[5];
} Obj;

s32 func_0886BFBC(Obj *arg0, u16 arg1) {
    s16 i;

    for (i = 0; i < 5; i++) {
        if (arg0->ent[i].id == arg1) {
            return arg0->ent[i].val;
        }
    }
    return 0;
}
