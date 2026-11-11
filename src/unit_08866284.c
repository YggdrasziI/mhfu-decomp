/* unit_08866284: 0x08866284-0x088662B8 (ULES01213)
 *
 * Bounds: a single function, taken as a unit of its own; the real translation
 * unit around it is not known yet.
 */

int func_08866284(unsigned char *p) {
    int r;

    switch (p[0x1E9]) {
    case 0:
        r = 0x20;
        break;
    case 1:
        r = 0x40;
        break;
    case 2:
        r = 0x40;
        break;
    default:
        r = 0xE0;
        break;
    }
    return r | p[0x1E4];
}
