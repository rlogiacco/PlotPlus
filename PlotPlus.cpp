/*
 PlotPlus.cpp - PlotPlus library
 Copyright (c) 2014 Roberto Lo Giacco.

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as 
 published by the Free Software Foundation, either version 3 of the 
 License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "PlotPlus.h"

void __plot(Stream &output, byte channelsNo,
		int16_t ch1, int16_t ch2, int16_t ch3, int16_t ch4, int16_t ch5, int16_t ch6) {

	/*
	 * SIMPLOT packet structure
	 *
	 * | header |  size   | payload         |
	 * | 0xABCD | 2 bytes | up to 12 bytes  |
	 *
	 */

	uint8_t buffer[16];

	// payload size
	uint16_t size = channelsNo * sizeof(uint16_t);

	// header
	buffer[0] = 0xAB; buffer[1] = 0xCD;

	// packet size
	buffer[2] = lowByte(size); buffer[3] = highByte(size);

	// channels data
	buffer[4] = lowByte(ch1); buffer[5] = highByte(ch1);
	buffer[6] = lowByte(ch2); buffer[7] = highByte(ch2);
	buffer[8] = lowByte(ch3); buffer[9] = highByte(ch3);
	buffer[10] = lowByte(ch4); buffer[11] = highByte(ch4);
	buffer[12] = lowByte(ch5); buffer[13] = highByte(ch5);
	buffer[14] = lowByte(ch6); buffer[15] = highByte(ch6);

	output.write((uint8_t *) buffer, (2 * sizeof(uint16_t)) + size);
}
