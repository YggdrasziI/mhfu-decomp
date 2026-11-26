/* unit_088790F4: 0x088790F4-0x08879158 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * arg0 is unused: the callers pass D_08A62CB4 in $a0 (same code).
 */

typedef short s16;
typedef int s32;
typedef unsigned short u16;

typedef struct {
    u16 id;
    s16 count;
} Slot;

typedef struct {
    char pad[0x10];
    s32 value;
    char pad2[4];
} Item;

extern char *D_089CC438;
extern Item D_0899D198[];

s32 func_088790F4(char *arg0) {
    Slot *s = (Slot *)(D_089CC438 + 0x390);
    s32 i;
    s32 sum = 0;
    s32 c;
    s32 id;

    for (i = 0; i < 0x20; i++, s++) {
        id = s->id;
        if (id != 0) {
            c = s->count;
            sum += c * D_0899D198[id].value;
        }
    }
    return sum;
}
