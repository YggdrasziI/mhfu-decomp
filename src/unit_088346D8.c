/* unit_088346D8: 0x088346D8-0x08834730 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef int s32;

extern s32 D_08A631A8;
extern int func_08825DA8(char *);
extern int func_08830D3C(char *);
extern int func_08890E08(s32, s32);

void func_088346D8(char *arg0) {
    *(s8 *)(arg0 + 0x534) = 0xB;
    func_08890E08(D_08A631A8, 2);
    func_08825DA8(arg0);
    if (*(s8 *)(arg0 + 0x5F0) != 0) {
        func_08830D3C(arg0);
        *(s8 *)(arg0 + 0x5F0) = 0;
    }
}
