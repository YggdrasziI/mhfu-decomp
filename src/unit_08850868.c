/* unit_08850868: 0x08850868-0x08850910 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between two functions still in assembly.
 * Its jump table (0x0893138C-0x089313A8) is linked from this unit.
 */

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 unk0;
    u8 unk1;
    char unk2[0xA];
} E;

typedef struct {
    char unk0[0xA8];
    E unkA8[0x54A];
    u16 unk4020[6];
} T;

s32 func_08850868(char *arg0, u16 arg1) {
    T *p = (T *) (arg0 + 0x4A0);

    if (p->unkA8[arg1].unk0 == 0) {
        return 0;
    }
    switch (p->unkA8[arg1].unk1) {
    case 0:
        p->unk4020[1] = arg1;
        break;
    case 1:
        p->unk4020[2] = arg1;
        break;
    case 2:
        p->unk4020[3] = arg1;
        break;
    case 3:
        p->unk4020[4] = arg1;
        break;
    case 4:
        p->unk4020[5] = arg1;
        break;
    case 5:
    case 6:
        if (arg1 == 0xFFFF) {
            return 0;
        }
        p->unk4020[0] = arg1;
        break;
    default:
        return 0;
    }
    return 1;
}
