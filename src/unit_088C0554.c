/* unit_088C0554: 0x088C0554-0x088C0594 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088C0468 (NonMatching)
 * and unit_088C0594.
 *
 * Compares the two words at +0x980 with those at +0x16A0E0 of the image.
 */

typedef int s32;

s32 func_088C0554(char *arg0) {
    s32 r;

    r = 0;
    if (*(s32 *) (arg0 + 0x980) == *(s32 *) (*(char **) (arg0 + 0x94C) + 0x16A0E0) &&
        *(s32 *) (arg0 + 0x984) == *(s32 *) (*(char **) (arg0 + 0x94C) + 0x16A0E4)) {
        r = 1;
    }
    return r;
}
