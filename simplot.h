/*
 simplot.h - PlotPlus library
 Copyright (c) 2014 Roberto Lo Giacco.  All right reserved.
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

#ifndef SIMPLOT_H_
#define SIMPLOT_H_


#include "SimPlotPlus.h"


#define _simple_plot_(output, numData, data1, data2, data3, data4, data5, data6) \
	__plot(output, numData, data1, data2, data3, data4, data5, data6)

#define plot6(output,  data1,  data2,  data3,  data4,  data5,  data6) \
	__plot(output, 6, data1, data2, data3,  data4,  data5,  data6)

#define plot5(output,  data1,  data2,  data3,  data4,  data5 ) \
	__plot(output, 5, data1, data2, data3,  data4,  data5,  0)

#define plot4(output,  data1,  data2,  data3,  data4) \
	__plot(output, 4, data1, data2, data3,  data4,  0,  0)

#define plot3(output,  data1,  data2,  data3) \
	__plot(output, 3, data1, data2, data3,  0,  0,  0)

#define plot2(output,  data1,  data2) \
	__plot(output, 2, data1, data2, 0,  0,  0,  0)

#define plot1(output,  data1) \
	__plot(output, 1, data1, 0, 0,  0,  0,  0)


#endif /* SIMPLOT_H_ */
