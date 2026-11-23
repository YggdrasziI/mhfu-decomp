/* unit_08865A64: 0x08865A64-0x08865A9C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08865A64: set flag bits in one of two words (bit 31 selects the word). */
typedef unsigned int u32;

void func_08865A64(char *arg0, u32 arg1) {
    if (!(arg1 & 0x80000000)) {
        *(u32 *)(arg0 + 0x288) |= arg1;
    } else {
        *(u32 *)(arg0 + 0x28C) |= arg1 & 0x7FFFFFFF;
    }
}
