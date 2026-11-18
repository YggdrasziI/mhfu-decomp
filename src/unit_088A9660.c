/* unit_088A9660: 0x088A9660-0x088A9914 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088A93A4 and func_088A9914
 * (still in assembly). NonMatching: the code stays in the asm piece
 * text_088A9660 and its switch table jtbl_08931FC0 in the data piece.
 *
 * Per-frame update of the session state machine (state byte at 0x21).
 */

/* Speed mode: the case 2 loop is entered through a count check. */
#pragma optimize_for_size off

#include "unk_peer.h"

extern void func_088A7E44(float *, void *);
extern void func_088A73B8(Session *);
extern s32 func_088A7788(Session *);
extern void func_0880C464(void *, s32, s32);
extern s32 func_088A9CFC(void);
extern void func_088A8E3C(Session *);
extern s32 func_088A93A4(Session *);
extern s32 func_088A812C(Session *, Store *, s32);
extern s32 func_088A8D74(Session *, Store *);
extern void func_088A920C(Session *);
extern s32 func_088A9084(Session *);
extern void func_088A91F4(Session *);
extern void func_088A9334(Session *);
extern Store D_09A1D56C;
extern Store D_09A1D578;

/* NonMatching, 97.6 %: one scheduling difference in case 4. Before the call
 * to func_088A91F4 the original puts the unk80 store in the delay slot, ours
 * puts the a0 move there (the unk7C store before func_088A9084 matches).
 * Tried: a float local, a pointer or cast store, the comma form, >=, the
 * float constant first, the callee as s32 / char * / unprototyped.
 */
void func_088A9660(Session *arg0) {
    func_088A7E44(&arg0->unk78, arg0->unk70);
    switch (arg0->unk21) {
    case 0:
        arg0->unk21 = 1;
        break;
    case 1:
        arg0->unk21 = 2;
        func_088A73B8(arg0);
        break;
    case 2:
        if (func_088A7788(arg0)) {
            arg0->unk21 = 3;
            arg0->unk7C = arg0->unk78;
            for (arg0->unk0 = 0; arg0->unk0 < arg0->count; arg0->unk0++) {
                arg0->unkE0[arg0->unk0] = arg0->unk78;
            }
            func_0880C464(arg0, 0, 8);
        }
        break;
    case 3:
        if (func_088A9CFC()) {
            arg0->unk21 = 7;
            break;
        }
        func_088A8E3C(arg0);
        if (func_088A9CFC()) {
            arg0->unk21 = 7;
            break;
        }
        if (func_088A93A4(arg0)) {
            arg0->unk21 = 4;
            arg0->unk7C = arg0->unk78;
            arg0->unk80 = arg0->unk78;
        }
        func_088A812C(arg0, &D_09A1D56C, 1);
        func_088A8D74(arg0, &D_09A1D578);
        break;
    case 4:
        if (func_088A9CFC()) {
            arg0->unk21 = 7;
            break;
        }
        func_088A8E3C(arg0);
        func_088A920C(arg0);
        if (func_088A9CFC()) {
            arg0->unk21 = 7;
            break;
        }
        if (arg0->unk7C + 1.0f <= arg0->unk78) {
            arg0->unk7C = arg0->unk78;
            func_088A9084(arg0);
        }
        if (arg0->unk80 + 60.0f <= arg0->unk78) {
            arg0->unk80 = arg0->unk78;
            func_088A91F4(arg0);
        }
        func_088A812C(arg0, &D_09A1D56C, 1);
        func_088A8D74(arg0, &D_09A1D578);
        break;
    case 5:
        func_088A9334(arg0);
        arg0->unk21 = 3;
        break;
    case 6:
        if (func_088A9CFC() == 0) {
            func_088A8E3C(arg0);
            func_088A812C(arg0, &D_09A1D56C, 1);
            func_088A8D74(arg0, &D_09A1D578);
        }
        break;
    case 7:
    case 8:
        break;
    }
}
