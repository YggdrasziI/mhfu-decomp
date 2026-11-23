/* unit_0886E578: 0x0886E578-0x0886E5BC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * Looks up an entry of an 8-byte table at 0x738.
 */

typedef int s32;
typedef short s16;
typedef unsigned short u16;

typedef struct {
    s32 flags;
    u16 id;
    s16 val;
} Ent;

typedef struct {
    char pad[0x738];
    Ent ent[1];
} Obj;

s32 func_0886E578(Obj *arg0, u16 arg1, u16 arg2) {
    if ((arg0->ent[arg2].flags & 0x12) == 0x12 && arg0->ent[arg2].id == arg1) {
        return arg0->ent[arg2].val;
    }
    return -1;
}
