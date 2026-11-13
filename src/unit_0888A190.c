/* unit_0888A190: 0x0888A190-0x0888A1D0 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

extern s32 func_0888A668(s32, void *);
extern s32 func_0888A8C0(s32, void *);

void func_0888A190(char *arg0) {
    func_0888A668((int) (arg0), arg0 + 0xA4);
    if (*(u8 *)(arg0 + 0x91) == 0) {
        func_0888A8C0((int) (arg0), arg0 + 0xB0);
    }
}
