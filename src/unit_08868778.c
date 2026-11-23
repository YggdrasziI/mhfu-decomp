/* unit_08868778: 0x08868778-0x088688C8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08868778: frees and clears three blocks of a1, each picked by a1[0x10F1] < 5. */
typedef unsigned char u8;
typedef int s32;

extern void func_08859C40(void *, s32);
extern void memset(void *, s32, s32);

static inline char *sel_50(char *p)
{
    return *(u8 *)(p + 0x10F1) < 5 ? p + 0x50 : p + 0xF60;
}

static inline char *sel_80(char *p)
{
    return *(u8 *)(p + 0x10F1) < 5 ? p + 0x80 : p + 0xF80;
}

static inline char *sel_70(char *p)
{
    return *(u8 *)(p + 0x10F1) < 5 ? p + 0x70 : p + 0x10C0;
}

void func_08868778(char *a0, char *a1)
{
    if (*(s32 *)(sel_50(a1) + 0x8) != 0) {
        func_08859C40(a0 + 0x80000, *(s32 *)(sel_50(a1) + 0x8));
    }
    memset(sel_50(a1), 0, 0x20);
    if (*(s32 *)(sel_80(a1) + 0x110) != 0) {
        func_08859C40(a0 + 0x80000, *(s32 *)(sel_80(a1) + 0x110));
    }
    memset(sel_80(a1), 0, 0x140);
    if (*(s32 *)(sel_70(a1) + 0x4) != 0) {
        func_08859C40(a0 + 0x80000, *(s32 *)(sel_70(a1) + 0x4));
    }
    memset(sel_70(a1), 0, 0x10);
}
