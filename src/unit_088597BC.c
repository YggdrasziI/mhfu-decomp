/* unit_088597BC: 0x088597BC-0x088597FC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly and
 * unit_088597FC.
 */

typedef unsigned char u8;

extern volatile u8 D_08A62C45;

/* Waits for the flag; the two nops of the loop body are in the original. */
void func_088597BC(void) {
    int wait = !D_08A62C45;

    if (wait) {
        do {
            asm { nop; nop }
            wait = !D_08A62C45;
        } while (wait);
    }
}
