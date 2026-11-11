/* unit_088B9910: 0x088B9910-0x088B996C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 D_089CC438;
extern int func_08850FB8(s32);
extern s32 func_088567B4(s32);
extern int func_088971A0(char *);

void func_088B9910(char *arg0) {
    *(s32 *)(arg0 + 0x30) = (s32) (*(s32 *)(arg0 + 0x30) + 1);
    if (!(func_088567B4(D_089CC438) & 0xFF)) {
        func_08850FB8(D_089CC438);
    }
    func_088971A0(arg0);
}
