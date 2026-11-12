/* unit_088C77D8: 0x088C77D8-0x088C7814 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

extern char *D_089CC438;
extern char D_09CE4708;

u16 func_088C77D8(s32 arg0, s32 arg1) {
    return *(s32 *)((*(s32 *)((char *)((&D_09CE4708 + (*(u8 *)(D_089CC438 + 0x6AF10) * 8))) + 4) + ((arg1 & 0xFF) * 2)));
}
