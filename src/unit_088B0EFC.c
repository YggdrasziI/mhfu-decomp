/* unit_088B0EFC: 0x088B0EFC-0x088B0F30 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088B0EC8 and unit_088B0F30.
 *
 * Copies the first 8 bytes (the key) of the record D_09A28AD0 to arg0.
 * Returns 0.
 */

typedef signed char s8;
typedef int s32;

typedef struct {
    s8 b[8];
} Key;

extern Key D_09A28AD0;

s32 func_088B0EFC(Key *arg0) {
    *arg0 = D_09A28AD0;
    return 0;
}
