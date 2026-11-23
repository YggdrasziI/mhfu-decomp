/* unit_0886BE50: 0x0886BE50-0x0886BEA4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0886BE50: copies two 8-byte entries when their first word is set. */

typedef signed char s8;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    s32 a;
    u16 b;
    s8 c;
    s8 d;
} Entry;

void func_0886BE50(char *p)
{
    Entry *dst;
    Entry *src;
    s32 i;

    dst = (Entry *)(p + 0x74C);
    src = (Entry *)(*(char **)(p + 0x4C) + 0x28);
    for (i = 0; i < 2; i++, dst++, src++) {
        if (src->a != 0) {
            dst->a = src->a;
            dst->b = src->b;
            dst->c = src->c;
            dst->d = i + 1;
        }
    }
}
