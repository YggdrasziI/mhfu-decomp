/* unit_088AC870: 0x088AC870-0x088ACB1C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088AC5E0 and unit_088ACB1C.
 *
 * Connection phase 2 of func_088ACB1C: shuts the network down one step at
 * a time (disconnect, handler removal, then each layer's Term), the
 * reverse of func_088AC5E0. The step is in unk2, the layers still up in
 * unk5.
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

extern s32 sceNetApctlDisconnect(void);
extern s32 sceNetAdhocctlDisconnect(void);
extern s32 sceNetApctlDelHandler(s32);
extern s32 sceNetAdhocctlDelHandler(s32);
extern s32 sceNetApctlTerm(void);
extern s32 sceNetAdhocctlTerm(void);
extern s32 sceNetInetTerm(void);
extern s32 sceNetAdhocTerm(void);
extern s32 sceNetTerm(void);
extern void func_088AA368(void);
extern void func_088AC0E0(void);
extern void func_09A69C00(void);

s32 func_088AC870(State *s) {
    switch (s->unk2) {
    case 0:
        s->unk2 = 0xA;
        break;
    case 0xA:
        if (!(s->unk10 & 2)) {
            s->unk2 += 2;
        } else if (s->unk10 & 4) {
            s->unk2 += 2;
        } else {
            switch (s->mode) {
            case 2:
                sceNetApctlDisconnect();
                break;
            case 1:
                sceNetAdhocctlDisconnect();
                break;
            }
            s->unk2++;
        }
        break;
    case 0xB:
        if (s->unk10 & 4) {
            s->unk2++;
        }
        break;
    case 0xC:
        s->unk2 = 0x14;
        return 4;
    case 0x14:
        if (s->unk5 < 4) {
            s->unk2++;
        } else {
            switch (s->mode) {
            case 2:
                func_09A69C00();
                sceNetApctlDelHandler(s->unkC);
                break;
            case 1:
                sceNetAdhocctlDelHandler(s->unkC);
                break;
            }
            s->unkC = -1;
            s->unk5 = 3;
            s->unk2++;
        }
        break;
    case 0x15:
        if (s->unk5 < 2) {
            s->unk2++;
        } else {
            switch (s->mode) {
            case 2:
                sceNetApctlTerm();
                break;
            case 1:
                sceNetAdhocctlTerm();
                break;
            }
            s->unk5 = 2;
            s->unk2++;
        }
        break;
    case 0x16:
        if (s->unk5 <= 0) {
            s->unk2++;
        } else {
            switch (s->mode) {
            case 2:
                sceNetInetTerm();
                break;
            case 1:
                sceNetAdhocTerm();
                break;
            }
            s->unk5 = 1;
            s->unk2++;
        }
        break;
    case 0x17:
        if (s->unk5 <= 0) {
            s->unk2++;
        } else {
            func_088AC0E0();
            func_088AA368();
            sceNetTerm();
            s->unk5 = 0;
            s->unk2++;
        }
        break;
    case 0x18:
        return 5;
    default:
        break;
    }
    return 0;
}
