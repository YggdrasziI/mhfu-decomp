/* unit_0888A538: 0x0888A538-0x0888A668 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef unsigned char u8;

typedef struct {
    float f0;
    float f4;
    u8 b8;
    char pad9[7];
} Unk;

typedef struct {
    float f0;
    char pad[0xC];
} Entry;

typedef struct {
    char pad[0x10C];
    Entry e[1];
} Ctx;

extern u8 func_0888B884(char *, Ctx *, s32);
extern s32 func_0888B994(char *, Unk *, Ctx *, s32);
extern void func_0888A388(char *, Unk *, Ctx *, float, s32);

s32 func_0888A538(char *arg0, Unk *arg1, Ctx *arg2, s32 arg3) {
    Unk tmp;
    float target;
    float cur;

    tmp.b8 = func_0888B884(arg0, arg2, arg3);
    if (func_0888B994(arg0, &tmp, arg2, arg3) != 0) {
        if (arg1->b8 == tmp.b8) {
            target = tmp.f0;
            cur = arg1->f0;
            if (cur < target) {
                if (target - cur <= 0.5f) {
                    arg1->f0 = target;
                } else {
                    arg1->f0 += 0.5f;
                }
            } else if (cur > target) {
                if (cur - target <= 0.5f) {
                    arg1->f0 = target;
                } else {
                    arg1->f0 = cur - 0.5f;
                }
            }
        } else {
            func_0888A388(arg0, arg1, arg2, tmp.f0, tmp.b8);
        }
        arg1->f4 = arg1->f0 / arg2->e[arg1->b8].f0;
        return 1;
    }
    return 0;
}
