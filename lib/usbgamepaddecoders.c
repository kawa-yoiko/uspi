#include <uspi/usbgamepaddecoders.h>
#include <uspios.h>

#define REPORT_LEN 64

#define bit(_var, _i) (((_var) >> (_i)) & 1)

void USBGamePadDeviceReportDecoder_PS4(TUSBGamePadDevice *d)
{
    u8 *report = d->m_pReportBuffer;
    USPiGamePadState *state = &d->m_State;
    DebugHexdump(report, REPORT_LEN, "ds4 controller");

    // Buttons
    state->nbuttons = 14;
    unsigned int btns = 0;

    // Square, Cross, Circle, Triangle
    btns |= (bit(report[5], 4) << 0);
    btns |= (bit(report[5], 5) << 1);
    btns |= (bit(report[5], 6) << 2);
    btns |= (bit(report[5], 7) << 3);
    // L1, R1, L2, R2
    btns |= (bit(report[6], 0) << 4);
    btns |= (bit(report[6], 1) << 5);
    btns |= (bit(report[6], 2) << 6);
    btns |= (bit(report[6], 3) << 7);
    // Share, Options
    btns |= (bit(report[6], 4) << 8);
    btns |= (bit(report[6], 5) << 9);
    // L3, R3 (thumbstick)
    btns |= (bit(report[6], 6) << 10);
    btns |= (bit(report[6], 7) << 11);
    // PS, Touchpad
    btns |= (bit(report[7], 0) << 12);
    btns |= (bit(report[7], 1) << 13);

    state->buttons = btns;

    // Hat
    state->nhats = 1;
    state->hats[0] = report[5] & 0xf;

    // Axes
    state->naxes = 6;
    state->axes[0].value = report[1];   // L thumbstick X (right+)
    state->axes[1].value = report[2];   // L thumbstick Y (down+)
    state->axes[2].value = report[3];   // R thumbstick X (right+)
    state->axes[3].value = report[4];   // R thumbstick Y (down+)
    state->axes[4].value = report[8];   // L trigger (L2)
    state->axes[5].value = report[9];   // R trigger (R2)
    for (int i = 0; i < 6; i++) {
        state->axes[i].minimum = 0;
        state->axes[i].maximum = 255;
    }

    d->m_nReportSize = REPORT_LEN;
}
