/* unit_088345FC: 0x088345FC-0x08834664 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned short u16;
typedef int s32;

extern char *D_089CC438;
extern s32 D_08A631A8;
extern int func_08825DA8(char *);
extern int func_088392F4(char *, char *);
extern int func_08890E08(s32, s32);

void func_088345FC(char *arg0) {
    *(s8 *)(arg0 + 0x534) = 9;
    func_08890E08(D_08A631A8, 0);
    func_08825DA8(arg0);
    if (*(u16 *)(D_089CC438 + 0x6AF0E) == 0xD) {
        func_088392F4(arg0, D_089CC438);
    }
}
