/* unit_088A7378: 0x088A7378-0x088A73A8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between unit_088A7368 and unit_088A73A8.
 */

typedef int s32;

extern s32 func_088A9CFC(void);
extern void func_088A9DF4(char *);

s32 func_088A7378(void) {
    s32 v[2];

    if (func_088A9CFC() != 0) {
        func_088A9DF4((char *) v);
        return v[0];
    }
    return 0;
}
