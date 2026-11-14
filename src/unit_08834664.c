/* unit_08834664: 0x08834664-0x088346D8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

extern char *D_089CC438;
extern s32 D_08A631A8;
extern void func_08825DA8(void *);
extern s32 func_08834730(s32);
extern s32 func_0883E4B8(s32);
extern int func_08890E08(s32, s32);

void func_08834664(char *arg0) {
    *(s8 *)(arg0 + 0x534) = 0xA;
    func_08890E08(D_08A631A8, 1);
    func_08825DA8(arg0);
    if (*(u8 *)(arg0 + 0x52F) != 0) {
        func_0883E4B8((s32) arg0);
        return;
    }
    if (*(u8 *)(D_089CC438 + 0x10) != 0) {
        func_08834730((s32) arg0);
    }
}
