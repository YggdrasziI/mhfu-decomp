/* unit_08830F74: 0x08830F74-0x08830FAC (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

extern char *D_089CC438;

s32 func_08830F74(char *arg0) {
    if (*(u8 *)(D_089CC438 + 0x10) != 0) {
        return 1;
    }
    if (*(u8 *)(arg0 + 0x604) != 0) {
        return 1;
    }
    return *(u8 *)(arg0 + 0x52F) != 0;
}
