/* unit_08859728: 0x08859728-0x08859768 (ULES01213)
 *
 * Bounds (hypothesis): one function (queues one of two display lists) between unrelated code.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 D_08A62C45;
extern int sceGeListEnQueue(const void *list, void *stall, int cbid, void *arg);

void func_08859728(char *o) {
    D_08A62C45 = 0;
    sceGeListEnQueue(o + (*(int *)(o + 4) ^ 1) * 0xA0 + 8, 0, *(int *)(o + 0x8019C), 0);
}
