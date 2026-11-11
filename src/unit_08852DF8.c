/* unit_08852DF8: 0x08852DF8-0x08852E38 (ULES01213)
 *
 * Bounds (hypothesis): one function (is any of 24 slots empty) between unrelated code.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    char pad[0x3F28];
    u16 value;
    u16 pad2;
} Slot;

int func_08852DF8(char *o) {
    short i = 0;
    char *base = o + 0x4A0;
    int offset = 0;

    do {
        if (((Slot *)(base + offset))->value == 0) {
            return 1;
        }
        i++;
        offset += 4;
    } while (i < 24);
    return 0;
}
