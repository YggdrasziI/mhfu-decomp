/* unit_0887FC40: 0x0887FC40-0x0887FCBC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;

typedef struct {
    s32 a;
    s32 b;
    s32 c;
    s32 pad[2];
} Entry;

typedef struct {
    s32 base;
    s32 pad[5];
    Entry entries[1];
} Obj;

extern s32 func_0889EA5C(s32);
extern void func_0889EA64(s32, s32);
extern int func_0889EA6C(s32, s32);

void func_0887FC40(Obj *arg0, s32 arg1, s32 arg2, s32 arg3) {
    Entry *e = &arg0->entries[arg1];

    e->a = arg2;
    e->b = arg3;
    e->c = arg0->base + func_0889EA5C(arg1);
    func_0889EA64(arg1, e->a);
    func_0889EA6C(arg1, e->b);
}
