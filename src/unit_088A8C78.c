/* unit_088A8C78: 0x088A8C78-0x088A8D74 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between func_088A8B98 and func_088A8D74
 * (still in assembly).
 *
 * Reads a 6-byte header from a buffer, checks its length against the size
 * left and copies it out.
 */

#include "unk_peer.h"

extern int memcpy(void *, void *, s32);
extern s32 func_088A8028(Session *, s32, s32);

s32 func_088A8C78(Session *arg0, char *data, s32 size, Header *out) {
    Header hdr;
    s32 state;
    s32 left;

    state = 0;
    if (size > 0) do {
        switch (state) {
        case 0:
            if (size < 6) {
                return 0;
            }
            size -= 6;
            memcpy(&hdr, data, 6);
            if (hdr.len < 6) {
                func_088A8028(arg0, 5, hdr.len);
                return 0;
            }
            left = hdr.len - 6;
            if (left == 0) {
                return -6;
            }
            state = 4;
            break;
        case 4:
            if (size < left) {
                return 0;
            }
            if (out != 0) {
                memcpy(out, &hdr, 6);
            }
            return hdr.len;
        }
    } while (size > 0);
    return 0;
}
