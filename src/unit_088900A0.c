/* unit_088900A0: 0x088900A0-0x088900C4 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned short u16;

extern char *D_089CC438;
extern char *D_08A631A0;

void func_088900A0(void) {
    *(u16 *)((char *)D_08A631A0 + 0xF7A570) = (u16) *(u16 *)(D_089CC438 + 0x44BE);
}
