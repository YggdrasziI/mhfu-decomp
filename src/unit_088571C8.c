/* unit_088571C8: 0x088571C8-0x088571E8 (ULES01213)
 *
 * Bounds (hypothesis): one function between unrelated code.
 */

int func_088571C8(char *o, int bit) {
    return (*(int *)(o + 0x696E4) & (1 << bit)) != 0;
}
