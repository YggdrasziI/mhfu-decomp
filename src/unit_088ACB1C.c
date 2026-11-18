/* unit_088ACB1C: 0x088ACB1C-0x088ACC54 (ULES01213)
 *
 * Bounds (hypothesis): last function of the old asm piece text_088AC308,
 * before unit_088ACC54.
 *
 * Step of the connection state block at 0x09A1DB60 (see unit_088ACC60):
 * runs the step of the current phase; once it reports 2 (connected),
 * records the local MAC address and, in infrastructure mode, the IP
 * address from the access point information.
 */

typedef unsigned char u8;
typedef int s32;

typedef struct {
    u8 busy;
    u8 unk1;
    char unk2[2];
    u8 mode;
    char unk5[7];
    s32 unkC;
    char unk10[8];
} State;

extern s32 sceNetGetLocalEtherAddr(u8 *);
extern s32 sceNetApctlGetInfo(s32, void *);
extern s32 sceNetInetInetAddr(void *);
extern void func_0880C464(void *, s32, s32);
extern int func_0880C084(void *, void *, s32);
extern void func_088AC0D0(void);
extern void func_088AC0D8(void);
extern s32 func_088AC308(State *);
extern s32 func_088AC5E0(State *);
extern s32 func_088AC870(State *);
extern State D_09A1DB60;
extern s32 D_09A1DB54;
extern u8 D_09A1DB58[6];

s32 func_088ACB1C(void) {
    State *s = &D_09A1DB60;
    s32 ret;
    u8 mac[8];
    char info[0x80];

    switch (s->busy) {
    case 0:
        ret = func_088AC5E0(s);
        break;
    case 1:
        ret = func_088AC308(s);
        break;
    case 2:
        ret = func_088AC870(s);
        break;
    default:
        ret = 3;
        break;
    }
    if (ret == 2) {
        if (sceNetGetLocalEtherAddr(mac) < 0) {
            func_0880C464(D_09A1DB58, 0, 6);
        } else {
            func_0880C084(D_09A1DB58, mac, 6);
        }
        switch (s->mode) {
        case 1:
            func_088AC0D0();
            break;
        case 2:
            if (sceNetApctlGetInfo(8, info) < 0) {
                D_09A1DB54 = 0;
            } else {
                D_09A1DB54 = sceNetInetInetAddr(info);
            }
            func_088AC0D8();
            break;
        }
    }
    return ret;
}
