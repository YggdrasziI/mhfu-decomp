/* unit_088AD0F8: 0x088AD0F8-0x088AD12C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;
typedef unsigned int u32;

s32 func_088AD0F8(u32 arg0) {
    return ((arg0 << 0x18) & 0xFF000000) | (((arg0 << 8) & 0xFF0000) | (((arg0 >> 0x18) & 0xFF) | ((arg0 >> 8) & 0xFF00)));
}
