/* unit_0884DBB8: 0x0884DBB8-0x0884DE34 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0884DBB8: 0x0884DBB8-0x0884DE34 (ULES01213)
 *
 * The first D_089CC438 read goes through a volatile access: the original
 * reloads the global there instead of reusing the cached copy.
 */

typedef int s32;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

extern char *D_09A44C60;
extern char *D_089CC438;
extern char *D_08A62C64;
extern char D_089CC020[];
extern char D_0899A170[];

extern char *func_08851680(char *, u16);
extern int func_0880E8F0(char *, char *, ...);
extern void func_088BFEF8(char *, char *);
extern void func_088B8A58(char *);

void func_0884DBB8(char *arg0) {
    char *p;
    s32 msg;
    s32 sub;
    char *a;

    switch (*(s32 *)(arg0 + 0x2FBE4)) {
    case 0:
        p = D_09A44C60;
        if (*(u8 *)(p + 0x970) == 0 && *(u8 *)(p + 0x971) == 0 &&
            *(s32 *)(arg0 + 0x2FBE0) != 0) {
            *(u8 *)(D_089CC438 + 0x6ADDE) = 0;
            if (*(u8 *)(arg0 + 0x2FBDC) != 0) {
                switch (*(s32 *)(arg0 + 0x2FBE0)) {
                case 1: sub = 0x41; msg = 0x40; break;
                case 2: sub = 0x42; msg = 0x40; break;
                case 3: sub = 0x43; msg = 0x40; break;
                case 4: sub = 0; msg = 0x40; break;
                case 5: sub = 0x45; msg = 0x44; break;
                case 6: sub = 0x46; msg = 0x44; break;
                case 7: sub = 0x47; msg = 0x44; break;
                case 8: sub = 0; msg = 0x44; break;
                case 9: sub = 0x45; msg = 0x48; break;
                case 10: sub = 0x46; msg = 0x48; break;
                case 11: sub = 0x47; msg = 0x48; break;
                case 12: sub = 0; msg = 0x48; break;
                }
                p = D_089CC438;
                if (*(u8 *)(p + 0x480) != 0 && msg == 0x44) {
                    msg = 0x65;
                }
                if (sub != 0) {
                    a = func_08851680(*(char * volatile *)&D_089CC438, msg);
                    func_0880E8F0(D_089CC020, a, func_08851680(p, sub));
                } else {
                    func_0880E8F0(D_089CC020, func_08851680(p, msg), D_0899A170);
                }
                func_088BFEF8(D_09A44C60, D_089CC020);
                *(u8 *)(D_08A62C64 + 0x17) = 1;
                (*(s32 *)(arg0 + 0x2FBE4))++;
            }
        }
        break;
    case 1:
        if (*(u8 *)(D_09A44C60 + 0x971) == 0) {
            *(s32 *)(arg0 + 0x2FBE4) = 0;
            *(s32 *)(arg0 + 0x2FBE0) = 0;
            *(u8 *)(D_08A62C64 + 0x17) = 0;
        }
        break;
    }
    func_088B8A58(arg0);
}
