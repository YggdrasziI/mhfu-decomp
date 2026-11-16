/* unit_0889EF40: 0x0889EF40-0x0889F018 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_0889EF20 and unit_0889F018.
 */

#include "unk_msg.h"

extern s32 sceKernelCreateVTimer(const char *, void *);
extern s32 sceKernelSetVTimerHandlerWide(s32, long long, void *, void *);
extern int func_0880D9EC(char *, ...);
extern s32 func_0889F03C(s32, s32, s32, char *);
extern s32 D_09A0B5B0;
extern s32 D_09A0B5B4;
extern s32 D_09A0B5B8;
extern char D_089B20A0;
extern char D_089B20B0;
extern char D_089B20B8;
extern char D_089B20C0;

s32 func_0889EF40(void) {
    s32 opt;

    clear((char *) &opt, sizeof(opt));
    D_09A0B5B0 = 0;
    D_09A0B5B4 = 0;
    D_09A0B5B8 = 0;
    D_09A0B5B0 = sceKernelCreateVTimer(&D_089B20A0, &opt);
    if (D_09A0B5B0 < 0) {
        func_0880D9EC(&D_089B20B0);
        func_0880D9EC(&D_089B20B8);
        func_0880D9EC(&D_089B20C0, D_09A0B5B0);
        return 0x80000018;
    }
    D_09A0B5B4 = 0x411A;
    D_09A0B5B8 = 0;
    sceKernelSetVTimerHandlerWide(D_09A0B5B0, 0, func_0889F03C, &D_09A0B5B0);
    return D_09A0B5B0;
}
