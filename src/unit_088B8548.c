/* unit_088B8548: 0x088B8548-0x088B85CC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code already in units.
 * sceGeEdramGetAddr / sceGeEdramGetSize take no argument (pspsdk).
 */

typedef int s32;
typedef unsigned int u32;

extern void *sceGeEdramGetAddr(void);
extern u32 sceGeEdramGetSize(void);
extern char D_089B2A58;
extern s32 sceKernelCreateSema(char *, s32, s32, s32, s32);

void func_088B8548(char *arg0) {
    *(s32 *)(arg0 + 0x29300) = (s32) sceGeEdramGetAddr();
    *(s32 *)(arg0 + 0x29304) = (s32) (*(s32 *)(arg0 + 0x29300) + sceGeEdramGetSize());
    *(s32 *)(arg0 + 0x29308) = 0;
    *(s32 *)(arg0 + 0x2931C) = sceKernelCreateSema(&D_089B2A58, 0x100, 1, 1, 0);
}
