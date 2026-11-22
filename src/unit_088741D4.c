/* unit_088741D4: 0x088741D4-0x08874218 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef unsigned char u8;

extern char *D_089CC438;
extern s32 D_09A4F0C4;
extern char *func_088DCEBC(s32, u8);
extern void memcpy(void *, void *, s32);

void func_088741D4(void) {
    char *p = func_088DCEBC(D_09A4F0C4, *(u8 *)(D_089CC438 + 0x28));
    memcpy(D_089CC438 + 0x43C8, p + 0x568, 0x60);
}
