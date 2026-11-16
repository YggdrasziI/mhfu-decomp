/* unit_088AE1EC: 0x088AE1EC-0x088AE25C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088AE1D4 and unit_088AE25C.
 * Its jump table (0x0893213C-0x08932154) is linked from this unit.
 */

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

s32 func_088ACB1C(void);

void func_088AE1EC(u8 *arg0) {
    switch (func_088ACB1C()) {
    case 2:
        arg0[0x22]++;
        break;
    case 3:
        arg0[0x21] = 3;
        arg0[0x22] = 0;
        *(u16 *) (arg0 + 0x26) = 0x8003;
        break;
    case 0:
    case 1:
    case 4:
    case 5:
        break;
    }
}
