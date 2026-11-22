/* unit_08885BB8: 0x08885BB8-0x08885D80 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

extern u8 D_089AC01C[][12];

u8 func_08885BB8(char *arg0, u8 arg1) {
    u8 idx;

    switch (*(u16 *)(arg0 + 0x562468)) {
    case 0x1532:
        idx = 0;
        break;
    case 0x154C:
        idx = 1;
        break;
    case 0x1551:
        idx = 2;
        break;
    case 0x1553:
        idx = 3;
        break;
    case 0x1555:
        idx = 4;
        break;
    case 0x155A:
        idx = 5;
        break;
    case 0x158E:
        idx = 6;
        break;
    case 0x155C:
        idx = 7;
        break;
    case 0x155E:
        idx = 8;
        break;
    case 0x1560:
        idx = 9;
        break;
    case 0x1590:
        idx = 10;
        break;
    case 0x1562:
        idx = 11;
        break;
    case 0x1564:
        idx = 12;
        break;
    case 0x1566:
        idx = 13;
        break;
    case 0x1592:
        idx = 14;
        break;
    case 0x1568:
        idx = 15;
        break;
    case 0x156A:
        idx = 16;
        break;
    case 0x156C:
        idx = 17;
        break;
    case 0x156E:
        idx = 18;
        break;
    case 0x1570:
        idx = 19;
        break;
    case 0x1572:
        idx = 20;
        break;
    case 0x1574:
        idx = 21;
        break;
    case 0x1576:
        idx = 22;
        break;
    case 0x1594:
        idx = 23;
        break;
    case 0x1578:
        idx = 24;
        break;
    case 0x157A:
        idx = 25;
        break;
    case 0x157C:
        idx = 26;
        break;
    case 0x157E:
        idx = 27;
        break;
    case 0x1580:
        idx = 28;
        break;
    case 0x1582:
        idx = 29;
        break;
    case 0x1584:
        idx = 30;
        break;
    case 0x1598:
        idx = 31;
        break;
    case 0x1596:
        idx = 32;
        break;
    default:
        idx = 0;
        break;
    }
    return D_089AC01C[idx][arg1];
}
