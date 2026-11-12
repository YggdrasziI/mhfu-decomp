/* unit_08895F3C: 0x08895F3C-0x08895FFC (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

extern char *D_089CC438;
extern s32 D_08A62D8C;
extern s32 D_08A631A0;
extern s32 func_088567B4(void *);
extern s32 func_088567C8(s32);
extern int func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_088900C4(s32, s32);
extern s32 func_08896CF8(s32, s32, s32);

void func_08895F3C(char *arg0) {
    if (((func_088567B4(D_089CC438) & 0xFF) != 1) && (*(u8 *)(arg0 + 0x1115) != 0)) {
        *(u8 *)(arg0 + 0x1115) = 0U;
        *(u8 *)(arg0 + 0x1117) = (u8) (*(u8 *)(arg0 + 0x1117) + 1);
        *(s8 *)(arg0 + 0x110E) = 0;
        *(s8 *)(arg0 + 0x1110) = func_08896CF8((s32) arg0, (s32) *(u8 *)(arg0 + 0x1111), (s32) *(u8 *)(arg0 + 0x1112));
        func_088567C8((s32) D_089CC438);
        func_08883988(D_08A62D8C, 3, (s32) (func_088900C4(D_08A631A0, 1) & 0xFFFF) % 3, 0, 0, 0, 0, 0, 0);
    }
}
