/* unit_08855410: 0x08855410-0x08855428 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern char *D_08A62C7C;

s32 func_08855410(void) {
    return (*(s32 *)(D_08A62C7C + 0x28) & 0x10) != 0;
}
