/* unit_088AC308: 0x088AC308-0x088AC5E0 (ULES01213)
 *
 * Bounds (hypothesis): first function of the old asm piece text_088AC308,
 * after unit_088AC1FC (unit_088AC0E8).
 *
 * Connection phase 1 of func_088ACB1C: runs the system network
 * configuration dialog (sceUtilityNetconf*) step by step. The parameter
 * block at 0x09A1DB0C is 0x44 bytes: the common dialog header, then the
 * action, the ad hoc parameters and the hotspot flags. Field names follow
 * the order of the stores; the values are copied from the code.
 */

typedef unsigned char u8;
typedef int s32;

typedef struct {
    u8 busy;
    u8 step;
    u8 unk2;
    u8 unk3;
    u8 mode;
    char unk5[3];
    s32 err;
    s32 unkC;
    s32 unk10;
    s32 unk14;
} State;

typedef struct {
    s32 size;
    s32 language;
    s32 buttonSwap;
    s32 graphicsThread;
    s32 accessThread;
    s32 fontThread;
    s32 soundThread;
    s32 result;
    s32 reserved[4];
    s32 action;
    void *adhocparam;
    s32 hotspot;
    s32 hotspot_connected;
    s32 wifisp;
} Netconf;

extern s32 sceUtilityNetconfInitStart(Netconf *);
extern s32 sceUtilityNetconfGetStatus(void);
extern s32 sceUtilityNetconfUpdate(s32);
extern s32 sceUtilityNetconfShutdownStart(void);
extern void memset(void *, s32, s32);
extern Netconf D_09A1DB0C;
extern s32 D_09A1DB50;
extern char D_09A1DB00[];

s32 func_088AC308(State *s) {
    s32 ret;

    switch (s->step) {
    case 0:
        s->step = 0xA;
        s->unk2 = 0;
        s->unk3 = 0;
        s->unk14 = 0;
        s->unk10 = 0;
        break;
    case 0xA:
        memset(&D_09A1DB0C, 0, sizeof(Netconf));
        D_09A1DB0C.size = sizeof(Netconf);
        switch (D_09A1DB50) {
        case 1:
        default:
            D_09A1DB0C.language = 1;
            break;
        case 2:
            D_09A1DB0C.language = 4;
            break;
        case 3:
            D_09A1DB0C.language = 2;
            break;
        case 4:
            D_09A1DB0C.language = 3;
            break;
        case 5:
            D_09A1DB0C.language = 5;
            break;
        }
        D_09A1DB0C.buttonSwap = 1;
        D_09A1DB0C.graphicsThread = 0x2A;
        D_09A1DB0C.accessThread = 0x2C;
        D_09A1DB0C.fontThread = 0x2B;
        D_09A1DB0C.soundThread = 0x29;
        switch (s->mode) {
        case 2:
            D_09A1DB0C.action = 0;
            D_09A1DB0C.hotspot = 1;
            D_09A1DB0C.wifisp = 1;
            break;
        case 1:
            D_09A1DB0C.action = 2;
            D_09A1DB0C.adhocparam = D_09A1DB00;
            break;
        }
        ret = sceUtilityNetconfInitStart(&D_09A1DB0C);
        if (ret < 0) {
            s->err = ret;
            s->step = 0x5A;
        } else {
            s->step++;
        }
        break;
    case 0xB:
        ret = sceUtilityNetconfGetStatus();
        if (ret < 0) {
            s->err = ret;
            s->step = 0x5A;
        } else if (ret == 2) {
            ret = sceUtilityNetconfUpdate(2);
            if (ret < 0) {
                s->err = ret;
                s->step = 0x5A;
            }
        } else if (ret == 3) {
            ret = sceUtilityNetconfShutdownStart();
            if (ret < 0) {
                s->err = ret;
                s->step = 0x5A;
            }
        } else if (ret == 0) {
            if (D_09A1DB0C.result == 0) {
                s->step++;
            } else {
                s->err = D_09A1DB0C.result;
                s->step = 0x5A;
            }
        }
        break;
    case 0xC:
        return 2;
    case 0x5A:
        ret = sceUtilityNetconfGetStatus();
        if (ret == 2) {
            sceUtilityNetconfUpdate(2);
        } else if (ret == 3) {
            sceUtilityNetconfShutdownStart();
        } else if (ret == 0) {
            s->step++;
        }
        break;
    case 0x5B:
        s->busy = 2;
        s->step = 0;
        return 3;
    default:
        break;
    }
    return 0;
}
