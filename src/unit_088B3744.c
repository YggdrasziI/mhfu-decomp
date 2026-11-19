/* unit_088B3744: 0x088B3744-0x088B3778 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between matched units.
 */

typedef signed char s8;
typedef int s32;

typedef struct {
    s8 b[8];
} Addr8;

extern Addr8 D_09A29CD0;

s32 func_088B3744(Addr8 *arg0) {
    *arg0 = D_09A29CD0;
    return 0;
}
