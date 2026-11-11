/* unit_0884ECAC: 0x0884ECAC-0x0884ED24 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;
typedef unsigned int u32;

s32 func_0884ECAC(char *arg0) {
    u32 temp_hi;

    *(u32 *)(arg0 + 0x2FBD4) = (u32) ((u32) (*(u32 *)(arg0 + 0x2FBD4) * 0x7F8D) % 65521U);
    temp_hi = (u32) (*(u32 *)(arg0 + 0x2FBD8) * 0x2345) % 65497U;
    *(u32 *)(arg0 + 0x2FBD8) = temp_hi;
    return (temp_hi << 0x10) + *(u32 *)(arg0 + 0x2FBD4);
}
