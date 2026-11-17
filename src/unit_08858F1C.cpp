/* unit_08858F1C: 0x08858F1C-0x08858FF4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly. Its
 * initialised array (0x0899CCFC-0x0899CD24, in .data) is linked from this
 * unit.
 *
 * C++: bool test.
 */

typedef int s32;
typedef unsigned int u32;
typedef unsigned short u16;

extern "C" {

extern char *D_08A62C7C;

void func_08858F1C(char *arg0, u16 arg1) {
    u16 ids[20] = {
        0x12E, 0x32F, 0x2B9, 0x2C3, 0x278, 0x272, 0x229, 0x20D, 0x254, 0x263,
        0x2EC, 0x2E4, 0x2D8, 0x2B8, 0x228, 0x20C, 0x2A3, 0x227, 0x20B, 0,
    };

    if ((bool) (*(s32 *)(arg0 + 0x6AF14) & 1) == 0) {
        u32 cur = 0;
        u32 n;
        u16 *p;

        if (ids[0] != 0) {
            u16 id = *(u16 *)(D_08A62C7C + 0x682);

            p = ids;
            do {
                if (id == *p) {
                    break;
                }
                p++;
                cur++;
            } while (*p != 0);
        }
        n = 0;
        if (ids[0] != 0) {
            p = ids;
            do {
                if (arg1 == *p) {
                    break;
                }
                p++;
                n++;
            } while (*p != 0);
        }
        if (n < cur) {
            *(u16 *)(D_08A62C7C + 0x682) = arg1;
        }
    }
}

}