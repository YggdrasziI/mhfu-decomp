/* unit_088A93A4: 0x088A93A4-0x088A9660 (ULES01213)
 *
 * Bounds (hypothesis): first function of the asm piece text_088A93A4, after
 * unit_088A9334.
 *
 * One step of the session wait: counts the peers still pending and closes
 * the session (clearing its first 8 bytes) once all are ready or on timeout.
 */

/* Speed mode: each loop is entered through a count check before its body. */
#pragma optimize_for_size off

#include "unk_peer.h"

extern void func_088A84B4(Session *, s32, u8);
extern void func_0880C464(void *, s32, s32);
extern s32 func_088A9084(Session *);
extern void func_088A868C(Session *);

s32 func_088A93A4(Session *arg0) {
    s32 i;

    if (arg0->count == 1) {
        func_088A84B4(arg0, arg0->self, 3);
        func_0880C464(arg0, 0, 8);
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
        func_0880C464(arg0, 0, 8);
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
        func_0880C464(arg0, 0, 8);
        return 1;
    }
    return 0;
}
