/* unit_088AEF64: 0x088AEF64-0x088AEF98 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088AEEB8 and unit_088AEF98.
 *
 * Copies the 8-byte block at D_09A202C0 to arg0.
 */

typedef signed char s8;

typedef struct {
    s8 b[8];
} Bytes8;

extern Bytes8 D_09A202C0;

void func_088AEF64(Bytes8 *arg0) {
    *arg0 = D_09A202C0;
}
