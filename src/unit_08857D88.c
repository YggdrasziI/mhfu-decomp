/* unit_08857D88: 0x08857D88-0x08857E6C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef unsigned int u32;
typedef unsigned long long u64;

/* The flags at 0x34 are a 64-bit mask kept as two words (0x34 low, 0x38
 * high; not 8-byte aligned). Rebuilding it with a 64-bit add keeps the
 * `addu v1, v0, zero` of the low word; the high-word load is dead. */
s32 func_08857D88(char *arg0, char *arg1) {
    u64 v = *(u32 *)(arg1 + 0x34) + ((u64)*(u32 *)(arg1 + 0x38) << 32);

    if (v & 0x400) return 1;
    if (v & 0x800) return 2;
    if (v & 0x1000) return 3;
    if (v & 0x2000) return 4;
    if (v & 0x4000) return 5;
    if (v & 0x8000) return 6;
    if (v & 0x10000) return 7;
    if (v & 0x20000) return 8;
    return 0;
}
