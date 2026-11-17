/* unit_0887E9AC: 0x0887E9AC-0x0887EA88 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly and
 * unit_0887EA88.
 *
 * Optimized for speed: divisions by a constant are multiplications.
 *
 * C++: bool test.
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;

extern "C" {

extern char *D_089CC438;
extern char *D_08A631A0;
extern char *D_09A0B544;

extern s32 func_08855410(char *);
extern int func_08856D60(char *o, u8 v);

u32 func_0887E9AC(s32 arg0, u32 arg1, s32 arg2) {
    if (arg2 == 0) {
        func_08855410(D_089CC438);
        arg1 /= 10;
        if (func_08855410(D_089CC438) != 0) {
            if ((bool) (*(s32 *)(D_08A631A0 + 0xF7A57C) & 1) != 0) {
                if (*(u8 *)(D_09A0B544 + 0xBBD) == 2) {
                    arg1 >>= 1;
                }
            }
        }
    }
    if (func_08856D60(D_089CC438, 0x20) != 0) {
        arg1 = arg1 * 150 / 100;
    }
    return arg1;
}

}