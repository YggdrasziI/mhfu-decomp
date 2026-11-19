/* unit_088CDCC8: 0x088CDCC8-0x088CDCF4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088CDCB0 and unit_088CDCF4.
 * Id of the record of the current entry, -1 when the queue is idle.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

s32 func_088CDCC8(char *arg0) {
    if (*(u8 *)arg0 == 0) {
        return -1;
    }
    return *(u16 *)(*(char **)((char *)((arg0 + (*(u8 *)(arg0 + 1) << 5))) + 0x20));
}
