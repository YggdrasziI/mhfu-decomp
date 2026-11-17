/* unit_08857A80: 0x08857A80-0x08857C18 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly and
 * unit_08857C18. Its jump table (0x089313F0-0x0893142C) is linked from this
 * unit.
 */

typedef int s32;
typedef unsigned short u16;

typedef struct {
    char unk0[0x18];
    u16 unk18;
} Unk4A0;

s32 func_08857A80(char *arg0, u16 arg1) {
    Unk4A0 *p = (Unk4A0 *)(arg0 + 0x4A0);

    switch (arg1) {
    default:
    case 0:
        if (p->unk18 >= 0) {
            return 1;
        }
        break;
    case 1:
        if (p->unk18 >= 1) {
            return 1;
        }
        break;
    case 2:
        if (p->unk18 >= 2) {
            return 1;
        }
        break;
    case 3:
        if (p->unk18 >= 3) {
            return 1;
        }
        break;
    case 4:
        if (p->unk18 >= 4) {
            return 1;
        }
        break;
    case 5:
        if (p->unk18 >= 5) {
            return 1;
        }
        break;
    case 6:
        if (p->unk18 >= 6) {
            return 1;
        }
        break;
    case 7:
        if (p->unk18 >= 7) {
            return 1;
        }
        break;
    case 8:
        if (p->unk18 >= 8) {
            return 1;
        }
        break;
    case 9:
        if (p->unk18 >= 9) {
            return 1;
        }
        break;
    case 10:
        if (p->unk18 >= 10) {
            return 1;
        }
        break;
    case 11:
        if (p->unk18 >= 11) {
            return 1;
        }
        break;
    case 12:
        if (p->unk18 >= 12) {
            return 1;
        }
        break;
    case 13:
        if (p->unk18 >= 13) {
            return 1;
        }
        break;
    case 14:
        if (p->unk18 >= 14) {
            return 1;
        }
        break;
    }
    return 0;
}
