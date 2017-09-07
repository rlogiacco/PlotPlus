/*
 simplot.h - PlotPlus library
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

#ifndef SIMPLOT_H_
#define SIMPLOT_H_


#include "PlotPlus.h"


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
