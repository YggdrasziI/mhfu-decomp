/* unit_0884EC3C: 0x0884EC3C-0x0884ECAC (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;
typedef unsigned int u32;

void func_0884EC3C(char *arg0, u32 arg1) {
    *(s32 *)(arg0 + 0x2FBD4) = (s32) (arg1 & 0xFFFF);
    *(s32 *)(arg0 + 0x2FBD8) = (s32) ((arg1 >> 0x10) & 0xFFFF);
    if (*(s32 *)(arg0 + 0x2FBD4) == 0) {
        *(s32 *)(arg0 + 0x2FBD4) = 0x7F8D;
    }
    if (*(s32 *)(arg0 + 0x2FBD8) == 0) {
        *(s32 *)(arg0 + 0x2FBD8) = 0x2345;
    }
}
