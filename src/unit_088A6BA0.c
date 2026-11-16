/* unit_088A6BA0: 0x088A6BA0-0x088A6C48 (ULES01213)
 *
 * NonMatching: compiled for the report only, the code is linked from assembly.
 * Bounds (hypothesis): 1 function before unit_088A6C48 (same family).
 */

#include "unk_msg.h"

extern void func_088A6A78(R *, s32);
extern s32 func_088A6E44(R *, s32);

/* The original does not load $a0 again for the call of func_088A6E44: `&r` is
 * still there from the call of func_088A6A78 (which leaves $a0 alone). mwccpsp
 * 3.0.1 reloads it, even with func_088A6A78 defined in the same file. */
void func_088A6BA0(s32 a, s32 b, s32 c, s32 arg3) {
    R r;

    clear((char *) &r, sizeof(R));
    if (a == -1) {
        r.h.f.flags |= 2;
    } else {
        r.h.f.a = a;
        r.h.f.flags |= 4;
    }
    if (b != -1) {
        r.h.f.b = b;
        r.h.f.flags |= 0x20;
    }
    if (c != -1) {
        r.h.f.c = c;
        r.h.f.flags |= 0x40;
    }
    func_088A6A78(&r, arg3);
    func_088A6E44(&r, 0x10000003);
}

