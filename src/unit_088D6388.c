/* unit_088D6388: 0x088D6388-0x088D6488 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly and
 * unit_088D6488. Its jump table (0x08932444-0x0893245C) is linked from this
 * unit.
 */

typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

extern s16 *D_089B6664[];
extern s16 *D_089B66EC[];
extern s16 *D_089B6774[];

u16 func_088D6388(u8 arg0, u8 arg1, u16 arg2, u8 arg3, u8 arg4) {
    s16 ret = arg2;

    switch (arg1) {
    case 0:
        if (arg2 == 0) {
            ret = *(*(D_089B6664 + arg0) + (arg3 + arg4 * 4));
        }
        break;
    case 3:
        if (arg2 == 0) {
            ret = *(*(D_089B66EC + arg0) + (arg3 + arg4 * 4));
        }
        break;
    case 4:
        if (arg2 == 0) {
            ret = *(*(D_089B6774 + arg0) + (arg3 + arg4 * 4));
        }
        break;
    case 1:
    case 2:
    case 5:
        break;
    }
    return ret;
}
