/* unit_088AE4A0: 0x088AE4A0-0x088AE4EC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088AE464 and unit_088AE4EC.
 *
 * Runs a connection step (func_088ACC54 returns the result of
 * func_088AC870) and moves the record to its next phase (+0x22) when the
 * step returns 4.
 */

typedef unsigned char u8;
typedef int s32;

typedef struct {
    char unk0[0x22];
    u8 phase;
} Record;

extern s32 func_088ACC54(void);

void func_088AE4A0(Record *r) {
    switch (func_088ACC54()) {
    case 4:
        r->phase++;
        break;
    case 5:
        break;
    }
}
