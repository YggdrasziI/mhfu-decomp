/* unit_088AEF98: 0x088AEF98-0x088AEFCC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088AEF64 and unit_088AEFCC.
 *
 * Copies the 20-byte block at D_09A20602 to arg0.
 */

typedef signed char s8;

typedef struct {
    s8 b[20];
} Bytes20;

extern Bytes20 D_09A20602;

void func_088AEF98(Bytes20 *arg0) {
    *arg0 = D_09A20602;
}
