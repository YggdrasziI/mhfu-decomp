/* unit_088858EC: 0x088858EC-0x08885BB8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned int u32;
typedef unsigned short u16;

extern char *D_089CC438;

extern "C" s32 func_088858EC(char *arg0, s32 arg1, s32 arg2, u32 arg3) {
    char *g = D_089CC438;
    s32 kind;
    s32 flag;

    if ((bool)(*(s32 *)(g + 0x6AF14) & 1) == 1) {
        if (*(u16 *)(g + 0x6AF0E) == 0xD) {
            kind = *(signed char *)(arg0 + 0x562466);
            if (kind != 0) {
                flag = 0;
                if (arg2 == 3) {
                    switch (arg3) {
                    case 0x0:
                    case 0x1:
                    case 0x2:
                    case 0x3:
                    case 0x4:
                    case 0x5:
                    case 0xA:
                    case 0x46:
                    case 0xB:
                    case 0x47:
                    case 0x1D:
                    case 0x48:
                    case 0x1E:
                    case 0x49:
                    case 0x1F:
                    case 0x20:
                    case 0x21:
                    case 0x4A:
                    case 0x22:
                    case 0x4B:
                    case 0x25:
                    case 0x4C:
                    case 0x26:
                    case 0x4D:
                    case 0x28:
                    case 0x4E:
                    case 0x29:
                    case 0x4F:
                    case 0x2B:
                    case 0x33:
                    case 0x34:
                    case 0x37:
                        flag = 1;
                        break;
                    }
                } else if (arg2 == 7) {
                    if ((arg3 >= 0x28 && arg3 <= 0x56) || (arg3 >= 0x82 && arg3 <= 0x84)) {
                        flag = 1;
                    }
                }
                if (flag) {
                    if ((signed char)kind == 3) {
                        arg1 = 0.3f * arg1;
                    } else if ((signed char)kind & 1) {
                        arg1 = 0.5f * arg1;
                    }
                }
            } else if (arg2 == 7 && arg3 == 0x85) {
                arg1 = 0.8f * arg1;
            }
        }
    }
    return arg1;
}
