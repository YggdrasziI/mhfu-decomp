/* unit_08866B5C: 0x08866B5C-0x08866B8C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08866B5C: returns the base plus the current offset, then advances the offset by n. */
typedef int s32;

s32 func_08866B5C(char *p, s32 n)
{
    s32 ret = *(s32 *)(p + 0x80230) + *(s32 *)(p + 0x8022C);
    *(s32 *)(p + 0x8022C) += n;
    return ret;
}
