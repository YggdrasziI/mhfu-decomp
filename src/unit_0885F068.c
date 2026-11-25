/* unit_0885F068: 0x0885F068-0x0885F194 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

extern char *D_08978474[];
extern char *D_089CC438;

extern s32 func_0885EF20(s32 arg0, char *arg1);
extern s32 func_08857A80(char *, s32);

s32 func_0885F068(s32 arg0, char *arg1) {
    u8 lv = *(u16 *)(arg1 + 4) + 1;
    u8 *rec;
    u8 cur;

    if (*(u8 *)(arg1 + 1) >= 5) {
        return 0;
    }
    rec = (u8 *)D_08978474[*(u8 *)(arg1 + 1)];
    rec += *(u16 *)(arg1 + 2) * 0x28;
    cur = func_0885EF20(arg0, arg1);
    if (cur < lv) {
        return -1;
    }
    if (cur != 0) {
        if (lv < rec[0x14]) {
            return 0;
        }
        if (lv < rec[0x15]) {
            return 1;
        }
        if (lv < rec[0x16]) {
            return 2;
        }
        if (lv < rec[0x17]) {
            return 3;
        }
        if (lv < rec[0x18]) {
            return 4;
        }
        if ((u8)func_08857A80(D_089CC438, 0xE) == 0) {
            return 5;
        }
        if (lv < rec[0x19]) {
            return 5;
        }
        return 6;
    }
    return -1;
}
