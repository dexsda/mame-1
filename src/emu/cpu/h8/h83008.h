/***************************************************************************

    h83008.h

    H8/3008

    H8/300H-based mcu.

****************************************************************************

    Copyright Olivier Galibert
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are
    met:

        * Redistributions of source code must retain the above copyright
          notice, this list of conditions and the following disclaimer.
        * Redistributions in binary form must reproduce the above copyright
          notice, this list of conditions and the following disclaimer in
          the documentation and/or other materials provided with the
          distribution.
        * Neither the name 'MAME' nor the names of its contributors may be
          used to endorse or promote products derived from this software
          without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY OLIVIER GALIBERT ''AS IS'' AND ANY EXPRESS OR
    IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL OLIVIER GALIBERT BE LIABLE FOR ANY DIRECT,
    INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
    SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
    HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
    STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
    IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
    POSSIBILITY OF SUCH DAMAGE.

***************************************************************************/

#ifndef __H83008_H__
#define __H83008_H__

#include "h8h.h"
#include "h8_adc.h"
#include "h8_port.h"
#include "h8_intc.h"
#include "h8_sci.h"
#include "h8_timer8.h"
#include "h8_timer16.h"

class h83008_device : public h8h_device {
public:
	h83008_device(const machine_config &mconfig, device_type type, const char *name, const char *tag, device_t *owner, UINT32 clock, const char *shortname, const char *source);
	h83008_device(const machine_config &mconfig, const char *tag, device_t *owner, UINT32 clock);

	DECLARE_READ8_MEMBER(syscr_r);
	DECLARE_WRITE8_MEMBER(syscr_w);	

protected:
	required_device<h8h_intc_device> intc;
	required_device<h8_adc_device> adc;
	required_device<h8_port_device> port4;
	required_device<h8_port_device> port6;
	required_device<h8_port_device> port7;
	required_device<h8_port_device> port8;
	required_device<h8_port_device> port9;
	required_device<h8_port_device> porta;
	required_device<h8_port_device> portb;
	required_device<h8h_timer8_channel_device> timer8_0;
	required_device<h8h_timer8_channel_device> timer8_1;
	required_device<h8h_timer8_channel_device> timer8_2;
	required_device<h8h_timer8_channel_device> timer8_3;
	required_device<h8_timer16_device> timer16;
	required_device<h8h_timer16_channel_device> timer16_0;
	required_device<h8h_timer16_channel_device> timer16_1;
	required_device<h8h_timer16_channel_device> timer16_2;
	required_device<h8_sci_device> sci0;
	required_device<h8_sci_device> sci1;

	UINT8 syscr;

	virtual void update_irq_filter();
	virtual void interrupt_taken();
	virtual int trapa_setup();
	virtual void irq_setup();
	virtual void internal_update(UINT64 current_time);
	virtual machine_config_constructor device_mconfig_additions() const;
	DECLARE_ADDRESS_MAP(map, 16);

	virtual void device_start();
	virtual void device_reset();
	virtual void execute_set_input(int inputnum, int state);
};

extern const device_type H83008;

#endif