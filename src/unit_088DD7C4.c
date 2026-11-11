/* unit_088DD7C4: 0x088DD7C4-0x088DD7D8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned short u16;
typedef int s32;

void func_088DD7C4(char *arg0) {
    *(u16 *)arg0 = 0;
    *(u16 *)(arg0 + 2) = 0xFFFF;
    *(s32 *)(arg0 + 4) = 0;
}
