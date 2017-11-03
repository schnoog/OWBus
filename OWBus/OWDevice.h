/* Generic OneWire device handling
 *
 * 02/11/2017 - L.Faillie - First version
 */
#ifndef OWDEVICE_H
#define OWDEVICE_H 0.0200

#include <OWBus.h>

class OWDevice {
public:
private:
	OWBus &bus;
	OWBus::Address &addr;

public:
	OWDevice( OWBus &abus, OWBus::Address &aa ) : bus(abus), addr(aa){};

		/* This enum contains all (useful) known 1-w commands.
		 * Commands directly handled by OneWire library are omitted.
		 * getOWCommand() will convert to a particular chip code if it
		 * is not the same as this table.
		 * Notez-bien : this list contains ALL code, not only for a particular
		 * chip.
		 */
	enum OWCommands {
		CONVERT_T=0x44,
		WRITE_SCRATCHPAD=0x4e, READ_SCRATCHPAD=0xBE, COPY_SCRATCHPAD=0x48,
		RECALL_E2=0xb8, READ_POWER_SUPPLY=0xB4
	};
	virtual uint8_t getOWCommand( OWCommands c ){ return c; }

	OWBus &getBus(){ return bus; }
	OWBus::Address &getAddress(){ return addr; }
	bool ifConnected();
};

#endif