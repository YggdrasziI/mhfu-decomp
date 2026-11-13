/* unit_0883FD44: 0x0883FD44-0x0883FDF4 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

extern char *D_089CC438;
extern s32 D_08A631A8;
extern void func_08825DA8(void *);
extern int func_08830D3C(void *);
extern s32 func_08846FAC(s32);
extern s32 func_08847CB0(s32);
extern s32 func_088487B8(s32);
extern s32 func_088567B4(void *);
extern int func_08890E08(s32, s32);

void func_0883FD44(char *arg0) {
    if ((func_088567B4(D_089CC438) & 0xFF) != 1) {
        *(s8 *)(arg0 + 0x534) = 0xB;
        func_08890E08(D_08A631A8, 2);
        func_08825DA8(arg0);
        func_08846FAC((s32) arg0);
        if ((*(u8 *)(arg0 + 0x604) == 0) && (*(u8 *)(arg0 + 0x52F) == 0) && (*(u8 *)(arg0 + 0x52D) == 0)) {
            func_08847CB0((s32) arg0);
            func_088487B8((s32) arg0);
        }
        if (*(s8 *)(arg0 + 0x5F0) != 0) {
            func_08830D3C(arg0);
            *(s8 *)(arg0 + 0x5F0) = 0;
        }
    }
}
