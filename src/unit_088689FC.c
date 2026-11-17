/* unit_088689FC: 0x088689FC-0x08868B6C (ULES01213)
 *
 * Bounds (hypothesis): 1 function followed by a function still in assembly.
 * Its jump tables (0x089315DC-0x08931628) are linked from this unit.
 */

typedef int s32;
typedef unsigned char u8;

extern char *D_08A631A0;

void func_088689FC(char *arg0) {
    switch (*(s32 *)(D_08A631A0 + 0xF7A574)) {
    default:
    case 0:
        *(u8 *)(arg0 + 0x75) = 0;
        *(u8 *)(arg0 + 0x76) = 0;
        break;
    case 1:
        *(u8 *)(arg0 + 0x75) = 1;
        *(u8 *)(arg0 + 0x76) = 1;
        break;
    case 2:
        *(u8 *)(arg0 + 0x75) = 4;
        *(u8 *)(arg0 + 0x76) = 1;
        break;
    case 3:
        *(u8 *)(arg0 + 0x75) = 2;
        *(u8 *)(arg0 + 0x76) = 1;
        break;
    case 4:
        *(u8 *)(arg0 + 0x75) = 3;
        *(u8 *)(arg0 + 0x76) = 1;
        break;
    case 5:
        *(u8 *)(arg0 + 0x75) = 5;
        *(u8 *)(arg0 + 0x76) = 1;
        break;
    case 6:
        *(u8 *)(arg0 + 0x75) = 9;
        *(u8 *)(arg0 + 0x76) = 0;
        break;
    }
    switch (*(u8 *)(arg0 + 0x75)) {
    case 0:
        *(u8 *)(arg0 + 0x77) = 1;
        break;
    case 1:
        *(u8 *)(arg0 + 0x77) = 2;
        break;
    case 2:
        *(u8 *)(arg0 + 0x77) = 3;
        break;
    case 3:
        *(u8 *)(arg0 + 0x77) = 4;
        break;
    case 4:
        *(u8 *)(arg0 + 0x77) = 5;
        break;
    case 5:
        *(u8 *)(arg0 + 0x77) = 6;
        break;
    case 6:
        *(u8 *)(arg0 + 0x77) = 7;
        break;
    case 7:
        *(u8 *)(arg0 + 0x77) = 8;
        break;
    case 8:
        *(u8 *)(arg0 + 0x77) = 9;
        break;
    case 9:
        *(u8 *)(arg0 + 0x77) = 0;
        break;
    case 10:
        *(u8 *)(arg0 + 0x77) = 0;
        break;
    case 11:
        *(u8 *)(arg0 + 0x77) = 0;
        break;
    default:
        *(u8 *)(arg0 + 0x77) = 0;
        break;
    }
}
