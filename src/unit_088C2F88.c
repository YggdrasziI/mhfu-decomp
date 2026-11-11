/* unit_088C2F88: 0x088C2F88-0x088C2FD8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;
typedef unsigned int u32;

s32 func_088C2F88(char *arg0) {
    u32 temp_hi;

    *(u32 *)(arg0 + 0xAA8) = (u32) ((u32) (*(u32 *)(arg0 + 0xAA8) * 0x215F) % 65423U);
    temp_hi = (u32) (*(u32 *)(arg0 + 0xAAC) * 0xDFA3) % 65519U;
    *(u32 *)(arg0 + 0xAAC) = temp_hi;
    return (temp_hi << 0x10) + *(u32 *)(arg0 + 0xAA8);
}
