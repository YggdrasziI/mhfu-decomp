/* unit_08859768: 0x08859768-0x088597BC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

extern char D_08A62C45;

void func_08859768(void) {
    __asm__ volatile("sync\n nop\n nop\n nop\n nop\n nop\n nop\n nop\n nop\n nop\n nop\n nop\n nop\n nop\n nop\n nop\n nop");
    D_08A62C45 = 1;
}
