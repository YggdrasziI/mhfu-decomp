/* unit_08889C90: 0x08889C90-0x08889CAC (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

void func_08889C90(char *arg0) {
    *(s32 *)(arg0 + 0x88) = 0x3F490FDB;
    *(s32 *)(arg0 + 0x80) = 0;
    *(s32 *)(arg0 + 0xFC) = 0x3F490FDB;
    *(s32 *)(arg0 + 0x100) = 0x3F490FDB;
}
