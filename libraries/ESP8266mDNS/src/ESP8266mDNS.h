/*
    ESP8266mDNS.h - mDNSResponder for ESP8266 family
    This file is part of the esp8266 core for Arduino environment.

    Legacy_ESP8266mDNS:
    The well known, thouroughly tested (yet no flawless) default mDNS library for the ESP8266 family

    LEA_ESP8266mDNS:
    An (currently) experimental mDNS implementation, that supports a lot more of mDNS features than Legacy_ESP8266mDNS, like:
    - Presenting a DNS-SD service to interested observers, eg. a http server by presenting _http._tcp service
    - Support for multi-level compressed names in input; in output only a very simple one-leven full-name compression is implemented
    - Probing host and service domains for uniqueness in the local network
    - Tiebreaking while probing is supportet in a very minimalistic way (the 'higher' IP address wins the tiebreak)
    - Announcing available services after successful probing
    - Using fixed service TXT items or
    - Using dynamic service TXT items for presented services (via callback)
    - Remove services (and un-announcing them to the observers by sending goodbye-messages)
    - Static queries for DNS-SD services (creating a fixed answer set after a certain timeout period)
    - Dynamic queries for DNS-SD services with cached and updated answers and user notifications
    - Support for multi-homed client host domains

    See 'LEA_ESP8266mDNS/EPS8266mDNS.h' for more implementation details and usage informations.
    See 'examples/mDNS_Clock' and 'examples/mDNS_ServiceMonitor' for implementation examples of the advanced features.

    LEA_ESP8266mDNS is (mostly) client source code compatible to 'Legacy_ESP8266mDNS', so it could be
    use as a 'drop-in' replacement in existing projects.


    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

*/

// mDNS on esp8266 Arduino, 4 available versions, select one with a define
// to add before `#include <ESP8266mDNS>` prior `#include <ESP8266mDNS.h>`:
//
// - original (default until core-2.4.2):    add `#define MDNS_ORIGINAL`
// - default LEAmDNS (v1, from core-2.5.0 to core 2.7.2)  (nothing to add)
// - LEAmDNSv2 with V1 API compatibility:    add `#define MDNS2_EXPERIMENTAL_V1COMPAT`
// - LEAmDNSv2, new API:                     add `#define MDNS2_EXPERIMENTAL`

#if defined(MDNS_ORIGINAL)
#include "ESP8266mDNS_Legacy.h"

#elif defined(MDNS2_EXPERIMENTAL_V1COMPAT)
#include "LEAmDNS2_Legacy.h"
using MDNSResponder = experimental::MDNSImplementation::clsLEAMDNSHost_Legacy;

#elif defined(MDNS2_EXPERIMENTAL)
#include "LEAmDNS2Host.h"
using MDNSResponder = esp8266::experimental::clsLEAMDNSHost;

#else // default
#include "LEAmDNS.h"
using MDNSResponder = esp8266::MDNSImplementation::MDNSResponder;

#endif // version selection

#if !defined(NO_GLOBAL_INSTANCES) && !defined(NO_GLOBAL_MDNS)
extern MDNSResponder MDNS;
#endif // global instance
