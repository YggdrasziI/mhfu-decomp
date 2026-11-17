/* unit_088DAEB0: 0x088DAEB0-0x088DAF18 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * Optimized for speed: divisions by a constant are multiplications.
 *
 * C++: bool test.
 */

#pragma optimize_for_size off

typedef int s32;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

extern "C" {

extern char *D_089CC438;

u8 func_088DAEB0(char *arg0) {
    u8 n = *(s16 *)(arg0 + 0x672) / 30;

    if (n > 3) {
        n = 3;
    }
    if ((bool) (*(u16 *)(arg0 + 0x1E6) == *(u8 *)(D_089CC438 + 0x28)) == 1) {
        *(u8 *)(arg0 + 0x60E) = n;
        return n;
    }
    return *(u8 *)(arg0 + 0x60E);
}

}