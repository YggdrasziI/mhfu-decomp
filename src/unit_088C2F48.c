/* unit_088C2F48: 0x088C2F48-0x088C2F88 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;
typedef unsigned int u32;

void func_088C2F48(char *arg0, u32 arg1) {
    *(s32 *)(arg0 + 0xAA8) = (s32) (arg1 & 0xFFFF);
    *(s32 *)(arg0 + 0xAAC) = (s32) ((arg1 >> 0x10) & 0xFFFF);
    if (*(s32 *)(arg0 + 0xAA8) == 0) {
        *(s32 *)(arg0 + 0xAA8) = 0x215F;
    }
    if (*(s32 *)(arg0 + 0xAAC) == 0) {
        *(s32 *)(arg0 + 0xAAC) = 0xDFA3;
    }
}
