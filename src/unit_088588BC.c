/* unit_088588BC: 0x088588BC-0x08858904 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

/* layout of ScePspDateTime in pspsdk (psptypes.h) */
typedef struct {
    u16 year;
    u16 month;
    u16 day;
    u16 hour;
    u16 minute;
    u16 second;
    u32 microsecond;
} ScePspDateTime;

extern int sceRtcGetCurrentClockLocalTime(ScePspDateTime *);

void func_088588BC(s32 arg0, char *arg1, s16 arg2, s16 arg3) {
    ScePspDateTime t;

    *(s16 *)(arg1 + 4) = arg2;
    *(s16 *)(arg1 + 6) = arg3;
    sceRtcGetCurrentClockLocalTime(&t);
    *(u16 *)(arg1 + 2) = t.year;
    *(s8 *)(arg1 + 1) = (s8) t.month;
    *(s8 *)arg1 = (s8) t.day;
}
