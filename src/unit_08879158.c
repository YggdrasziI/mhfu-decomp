/* unit_08879158: 0x08879158-0x08879198 (ULES01213)
 *
 * Bounds (hypothesis): one function (sums 32 used values) between unrelated code.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 used;
    short value;
} Pair;

extern char *D_089CC438;

int func_08879158(void) {
    Pair *p = (Pair *)(D_089CC438 + 0x390);
    int sum = 0;
    int i;

    for (i = 0; i < 32; i++, p++) {
        if (p->used) {
            sum += p->value;
        }
    }
    return sum;
}
