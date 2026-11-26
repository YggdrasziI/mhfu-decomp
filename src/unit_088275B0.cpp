/* unit_088275B0: 0x088275B0-0x0882774C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * Inserts a record built by func_08827194 into a 54-entry table at
 * arg0 + 0x684, sorted by its first halfword. arg3 is unused: the caller
 * func_08826FCC passes it in $a3 (same code).
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef int s32;

typedef struct B6 { s8 b[3][2]; } B6;
typedef struct B7 { s8 b[7]; } B7;

typedef struct Rec {
    u16 key;
    u8 used;
    u8 unk3;
    B6 unk4;
    s8 unkA;
    B7 unkB;
} Rec;

extern "C" u8 func_08827194(char *, s32, Rec *);

extern "C" void func_088275B0(char *arg0, s32 arg1, u8 arg2, char *arg3) {
    Rec rec;
    Rec *q;
    Rec *e;
    Rec *s;
    s32 i;
    s32 j;

    rec.unk3 = arg2;
    if (func_08827194(arg0, arg1, &rec) != 1) {
        return;
    }
    e = (Rec *)(arg0 + 0x684);
    i = 54;
    do {
        if (e->used == 0) {
            q = (Rec *)(arg0 + 0x684);
            e++;
            j = 54;
            do {
                if (q->used != 0) {
                    if (q->key > rec.key) {
                        goto next;
                    }
                    s = e - 1;
                    do {
                        s--;
                        e--;
                        *e = *s;
                    } while (q < s);
                }
                *q = rec;
                return;
            next:
                j--;
                q++;
            } while (j > 0);
            return;
        }
        i--;
        e++;
    } while (i > 0);
}
