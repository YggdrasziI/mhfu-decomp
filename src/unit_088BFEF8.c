/* unit_088BFEF8: 0x088BFEF8-0x088C0198 (ULES01213)
 *
 * Bounds (hypothesis): the whole text_088BFEF8 asm piece, 2 functions
 * between unit_088BFE54 and unit_088C0198.
 *
 * func_088BFEF8 opens the system message dialog (as func_088BFE54) on a
 * copy of the text arg1 in which "~10" becomes the UTF-8 trademark sign
 * (E2 84 A2) and "~11" the registered sign and a space (C2 AE 20).
 * func_088C0084 drives the save data and message dialogs by their status.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

extern char *D_08A62C64;
extern s32 D_08A631A0;

extern void memset(void *, s32, s32);
extern void func_0880F178(char *, char *, s32);
extern s32 func_088903BC(s32);
extern s32 sceUtilityMsgDialogInitStart(void *);
extern s32 sceUtilityMsgDialogGetStatus(void);
extern s32 sceUtilityMsgDialogUpdate(s32);
extern s32 sceUtilityMsgDialogShutdownStart(void);
extern s32 sceUtilitySavedataGetStatus(void);
extern s32 sceUtilitySavedataUpdate(s32);
extern s32 sceUtilitySavedataShutdownStart(void);

void func_088BFEF8(char *arg0, char *arg1) {
    s8 *p;

    memset(arg0 + 0x688, 0, 0x2C4);
    *(s32 *) (arg0 + 0x688) = 0x2C4;
    *(s32 *) (arg0 + 0x68C) = func_088903BC(D_08A631A0);
    *(s32 *) (arg0 + 0x690) = 1;
    *(s32 *) (arg0 + 0x694) = 0x32;
    *(s32 *) (arg0 + 0x698) = 0x34;
    *(s32 *) (arg0 + 0x69C) = 0x33;
    *(s32 *) (arg0 + 0x6A0) = 0x29;
    *(s32 *) (arg0 + 0x6BC) = 1;
    *(s32 *) (arg0 + 0x8C4) = 0;
    func_0880F178(arg0 + 0x6C4, arg1, 0x200);
    p = (s8 *) (arg0 + 0x6C4);
    while (p[0] != 0 && p[1] != 0 && p[2] != 0) {
        if (p[0] == '~' && p[1] == '1' && p[2] == '2') {
            p[2] = '1';
        }
        if (p[0] == '~' && p[1] == '1' && p[2] == '0') {
            p[2] = 0xA2;
            p[1] = 0x84;
            p[0] = 0xE2;
            p += 2;
        } else if (p[0] == '~' && p[1] == '1' && p[2] == '1') {
            p[2] = 0x20;
            p[1] = 0xAE;
            p[0] = 0xC2;
        }
        p++;
    }
    sceUtilityMsgDialogInitStart(arg0 + 0x688);
    *(u8 *) (arg0 + 0x971) = 1;
    *(u8 *) (D_08A62C64 + 0x17) = 1;
}

void func_088C0084(char *arg0) {
    if (*(u8 *) (arg0 + 0x970) != 0) {
        switch (sceUtilitySavedataGetStatus()) {
        case 1:
            break;
        case 4:
            break;
        case 2:
            sceUtilitySavedataUpdate(2);
            break;
        case 0:
            *(u8 *) (arg0 + 0x970) = 0;
            *(u8 *) (D_08A62C64 + 0x17) = 0;
            break;
        case 3:
            sceUtilitySavedataShutdownStart();
            break;
        }
    }
    if (*(u8 *) (arg0 + 0x971) != 0) {
        switch (sceUtilityMsgDialogGetStatus()) {
        case 1:
            break;
        case 4:
            break;
        case 2:
            sceUtilityMsgDialogUpdate(2);
            break;
        case 0:
            *(u8 *) (arg0 + 0x971) = 0;
            *(u8 *) (D_08A62C64 + 0x17) = 0;
            break;
        case 3:
            sceUtilityMsgDialogShutdownStart();
            break;
        }
    }
}
