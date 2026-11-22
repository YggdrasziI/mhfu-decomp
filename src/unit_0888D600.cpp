/* unit_0888D600: 0x0888D600-0x0888D708 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef unsigned char u8;

extern "C" {

extern char *D_089CBBE4;
extern char *D_089CBBEC;
extern s32 func_08830F74(char *);
extern s32 func_0888D708(char *);

s32 func_0888D600(char *arg0) {
    char *p = *(char **)(D_089CBBE4 + 0xA84);
    u8 kind;

    if (*(u8 *)(D_089CBBEC + 0x554) != 0) {
        return 0;
    }
    if ((u8) func_08830F74(D_089CBBEC) == 1) {
        return 0;
    }
    if ((bool) (*(s32 *)(p + 0x614) & 2) == 1) {
        return 0;
    }
    if ((bool) *(u8 *)(p + 0x564) == 1) {
        return 0;
    }
    if ((u8) func_0888D708(arg0) != 0) {
        return 0;
    }
    kind = *(u8 *)(p + 0x1E8);
    if ((kind == 1 || kind == 5) && (bool) (*(s32 *)(p + 0x410) & 8) != 0) {
        if ((bool) (*(s32 *)(p + 0x614) & 0x8000) == 1) {
            return 0;
        }
    }
    return *(signed char *)(arg0 + 0x131) < 0;
}

}
