/* unit_088A91F4: 0x088A91F4-0x088A9914 (ULES01213)
 *
 * Bounds (hypothesis): 5 functions, one source file (see below).
 *
 * func_088A91F4: clears the four counters at 0x9C-0xA8 of the session.
 * func_088A920C: drops each other peer whose timers have run past the
 *                session clock.
 * func_088A9334: clears the ready mask and resets each peer in state 3.
 * func_088A93A4: one step of the session wait: counts the peers still
 *                pending and closes the session (clearing its first 8 bytes)
 *                once all are ready or on timeout.
 * func_088A9660: per-frame update of the session state machine (state byte
 *                at 0x21).
 *
 * func_088A91F4 is static: func_088A9660 keeps an argument move before the
 * jal to it and fills the delay slot with a store, which only happens with a
 * static callee defined earlier in the file.
 *
 * Functions optimized for speed are preceded by `#pragma optimize_for_size
 * off`; `#pragma optimize_for_size reset` restores the default after them.
 */

#include "unk_peer.h"

extern void func_088A84B4(Session *, s32, u8);
extern void memset(void *, s32, s32);
extern s32 func_088A9084(Session *);
extern void func_088A868C(Session *);
extern void func_088A7E44(float *, void *);
extern void func_088A73B8(Session *);
extern s32 func_088A7788(Session *);
extern s32 func_088A9CFC(void);
extern void func_088A8E3C(Session *);
extern s32 func_088A812C(Session *, Store *, s32);
extern s32 func_088A8D74(Session *, Store *);
extern Store D_09A1D56C;
extern Store D_09A1D578;

static s32 func_088A91F4(Session *arg0) {
    arg0->unk9C = 0;
    arg0->unkA0 = 0;
    arg0->unkA4 = 0;
    arg0->unkA8 = 0;
    return 0;
}

/* Speed mode: the loop walks arg0 with a strength-reduced pointer. */
#pragma optimize_for_size off

s32 func_088A920C(Session *arg0) {
    s32 i;

    for (i = 0; i < arg0->count; i++) {
        if (i == arg0->self) {
            continue;
        }
        switch (arg0->unk68[i]) {
        case 4:
            if (arg0->unkF0[i] + (u32) arg0->unk138[i] <= arg0->unk78) {
                func_088A84B4(arg0, (u8) i, 6);
            }
        case 1:
        case 2:
        case 3:
            if (arg0->unkE0[i] + arg0->unk130 <= arg0->unk78) {
                func_088A84B4(arg0, (u8) i, 6);
            }
            break;
        }
    }
    return 0;
}

#pragma optimize_for_size reset

void func_088A9334(Session *arg0) {
    s32 i;

    arg0->unk64 = 0;
    i = 0;
    if ((s32) arg0->count > 0) {
        do {
            if (arg0->unk68[i] == 3) {
                func_088A84B4(arg0, i & 0xFF, 1);
            }
            i += 1;
        } while (i < (s32) arg0->count);
    }
}

/* Speed mode: each loop of func_088A93A4 is entered through a count check
 * before its body, as is the case 2 loop of func_088A9660. */
#pragma optimize_for_size off

s32 func_088A93A4(Session *arg0) {
    s32 i;

    if (arg0->count == 1) {
        func_088A84B4(arg0, arg0->self, 3);
        memset(arg0, 0, 8);
        return 1;
    }
    if (arg0->unk7C + arg0->unk0 < arg0->unk78) {
        arg0->unk0++;
        func_088A9084(arg0);
        func_088A868C(arg0);
    }
    arg0->unk2 = 0;
    for (i = 0; i < arg0->count; i++) {
        if (i == arg0->self) {
            continue;
        }
        switch (arg0->unk68[i]) {
        case 0:
        case 6:
            break;
        case 1:
        case 2:
            if (!(arg0->unk64 & (1 << i))) {
                arg0->unk2++;
            }
            break;
        }
    }
    if (arg0->unk2 == 0) {
        func_088A84B4(arg0, arg0->self, 2);
    }
    arg0->unk2 = 0;
    arg0->unk4 = 0;
    for (i = 0; i < arg0->count; i++) {
        switch (arg0->unk68[i]) {
        case 2:
            arg0->unk4++;
        case 1:
            arg0->unk2++;
            break;
        }
    }
    if (arg0->unk2 == arg0->unk4) {
        for (i = 0; i < arg0->count; i++) {
            if (arg0->unk68[i] == 2) {
                func_088A84B4(arg0, (u8) i, 3);
            }
        }
        memset(arg0, 0, 8);
        return 1;
    }
    if (arg0->unk7C + arg0->unk134 < arg0->unk78) {
        for (i = 0; i < arg0->count; i++) {
            if (i == arg0->self) {
                func_088A84B4(arg0, (u8) i, 3);
                continue;
            }
            switch (arg0->unk68[i]) {
            case 1:
                func_088A84B4(arg0, (u8) i, 6);
                break;
            case 2:
                func_088A84B4(arg0, (u8) i, 3);
                break;
            }
        }
        memset(arg0, 0, 8);
        return 1;
    }
    return 0;
}

/* Matching except the switch table name (jtbl_08931FC0, compiler @N). */
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
            memset(arg0, 0, 8);
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

#pragma optimize_for_size reset
