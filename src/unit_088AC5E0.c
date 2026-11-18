/* unit_088AC5E0: 0x088AC5E0-0x088AC870 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088AC308 and func_088AC870
 * (still in assembly).
 *
 * Connection phase 0 of func_088ACB1C: initialises the network modules one
 * step at a time (sceNetInit, then the inet or ad hoc layer, then the
 * access point or ad hoc control layer and its event handler, see
 * unit_088AC0E8). Mode 1 is ad hoc, mode 2 infrastructure.
 */

typedef unsigned char u8;
typedef int s32;

typedef struct {
    u8 busy;
    u8 step;
    u8 unk2;
    u8 unk3;
    u8 mode;
    u8 unk5;
    char unk6[2];
    s32 err;
    s32 unkC;
    s32 unk10;
    s32 unk14;
} State;

extern s32 sceNetInit(s32, s32, s32, s32, s32);
extern s32 sceNetInetInit(void);
extern s32 sceNetAdhocInit(void);
extern s32 sceNetApctlInit(s32, s32);
extern s32 sceNetAdhocctlInit(s32, s32, void *);
extern s32 sceNetApctlAddHandler(void (*)(s32, s32, s32, s32), void *);
extern s32 sceNetAdhocctlAddHandler(void (*)(s32, s32), void *);
extern s32 func_088AA304(s32, s32);
extern void func_088AC0E0(void);
extern void func_088AC0E8(s32, s32);
extern void func_088AC1FC(s32, s32, s32, s32);
extern void func_09A69B58(void);
extern char D_09A1DAF0[];

s32 func_088AC5E0(State *s) {
    s32 ret = 0;

    switch (s->step) {
    case 0:
        s->step = 0xA;
        s->unk5 = 0;
        s->unk2 = 0;
        s->unk3 = 0;
        s->unk14 = 0;
        s->unk10 = 0;
        s->err = 0;
        break;
    case 0xA:
        ret = sceNetInit(0x20000, 0x20, 0, 0x20, 0);
        if (ret < 0) {
            s->err = ret;
            s->busy = 2;
            s->step = 0;
        } else {
            switch (s->mode) {
            case 2:
                func_088AA304(1, 0);
                break;
            case 1:
                func_088AA304(0, 0);
                break;
            }
            func_088AC0E0();
            s->unk5 = 1;
            s->step++;
        }
        break;
    case 0xB:
        switch (s->mode) {
        case 2:
            ret = sceNetInetInit();
            break;
        case 1:
            ret = sceNetAdhocInit();
            break;
        }
        if (ret < 0) {
            s->err = ret;
            s->busy = 2;
            s->step = 0;
        } else {
            s->unk5 = 2;
            s->step++;
        }
        break;
    case 0xC:
        switch (s->mode) {
        case 2:
            ret = sceNetApctlInit(0x2000, 0x30);
            break;
        case 1:
            ret = sceNetAdhocctlInit(0x2000, 0x30, D_09A1DAF0);
            break;
        }
        if (ret < 0) {
            s->err = ret;
            s->busy = 2;
            s->step = 0;
        } else {
            s->unk5 = 3;
            s->step++;
        }
        break;
    case 0xD:
        switch (s->mode) {
        case 2:
            ret = sceNetApctlAddHandler(func_088AC1FC, 0);
            func_09A69B58();
            break;
        case 1:
            ret = sceNetAdhocctlAddHandler(func_088AC0E8, 0);
            break;
        }
        if (ret < 0) {
            s->err = ret;
            s->busy = 2;
            s->step = 0;
        } else {
            s->unkC = ret;
            s->unk5 = 4;
            s->step++;
        }
        break;
    case 0xE:
        s->busy = 1;
        s->step = 0;
        return 1;
    default:
        break;
    }
    return 0;
}
