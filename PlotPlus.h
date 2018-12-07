/*
 PlotPlus.h - PlotPlus library
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

#ifndef PLOT_PLUS_H_
#define PLOT_PLUS_H_

    #if (defined ARDUINO && (!defined(PLOT_PLUS) || PLOT_PLUS))
        #include <Arduino.h>

        #ifndef PLOT_PLUS_STREAM
            #define PLOT_PLUS_STREAM Serial
        #endif

        void __plot(Stream &output, uint8_t numData, int16_t data1, int16_t data2, int16_t data3, int16_t data4, int16_t data5, int16_t data6);

        #define __PLOT_PLUS_1(A)                     __plot(PLOT_PLUS_STREAM,1,A,0,0,0,0,0)
        #define __PLOT_PLUS_2(A,B)                   __plot(PLOT_PLUS_STREAM,2,A,B,0,0,0,0)
        #define __PLOT_PLUS_3(A,B,C)                 __plot(PLOT_PLUS_STREAM,3,A,B,C,0,0,0)
        #define __PLOT_PLUS_4(A,B,C,D)               __plot(PLOT_PLUS_STREAM,4,A,B,C,D,0,0)
        #define __PLOT_PLUS_5(A,B,C,D,E)             __plot(PLOT_PLUS_STREAM,5,A,B,C,D,E,0)
        #define __PLOT_PLUS_6(A,B,C,D,E,F)           __plot(PLOT_PLUS_STREAM,6,A,B,C,D,E,F)

		#define __PLOT_PLUS_WITH_1(OUT,A)            __plot(OUT,1,A,0,0,0,0,0)
        #define __PLOT_PLUS_WITH_2(OUT,A,B)          __plot(OUT,2,A,B,0,0,0,0)
        #define __PLOT_PLUS_WITH_3(OUT,A,B,C)        __plot(OUT,3,A,B,C,0,0,0)
        #define __PLOT_PLUS_WITH_4(OUT,A,B,C,D)      __plot(OUT,4,A,B,C,D,0,0)
        #define __PLOT_PLUS_WITH_5(OUT,A,B,C,D,E)    __plot(OUT,5,A,B,C,D,E,0)
        #define __PLOT_PLUS_WITH_6(OUT,A,B,C,D,E,F)  __plot(OUT,6,A,B,C,D,E,F)

        #define __PLOT_PLUS_X(x,A,B,C,D,E,F,MACRO, ...) MACRO

        #define plot(...)      __PLOT_PLUS_X(, ##__VA_ARGS__,\
									__PLOT_PLUS_WITH_6(PLOT_PLUS_STREAM,__VA_ARGS__),\
									     __PLOT_PLUS_WITH_5(PLOT_PLUS_STREAM,__VA_ARGS__),\
									     __PLOT_PLUS_WITH_4(PLOT_PLUS_STREAM,__VA_ARGS__),\
									     __PLOT_PLUS_WITH_3(PLOT_PLUS_STREAM,__VA_ARGS__),\
									     __PLOT_PLUS_WITH_2(PLOT_PLUS_STREAM,__VA_ARGS__),\
									     __PLOT_PLUS_WITH_1(PLOT_PLUS_STREAM,__VA_ARGS__) )

		#define __PLOT_PLUS_WITH_X(x,OUT,A,B,C,D,E,F,MACRO, ...) MACRO

        #define plotWith(...) __PLOT_PLUS_WITH_X(, ##__VA_ARGS__,\
							     __PLOT_PLUS_WITH_6(__VA_ARGS__),\
							     __PLOT_PLUS_WITH_5(__VA_ARGS__),\
							     __PLOT_PLUS_WITH_4(__VA_ARGS__),\
							     __PLOT_PLUS_WITH_3(__VA_ARGS__),\
							     __PLOT_PLUS_WITH_2(__VA_ARGS__),\
							     __PLOT_PLUS_WITH_1(__VA_ARGS__) )

    #else
        #define plot(...)
		#define plotWith(...)
    #endif // PLOT_PLUS
#endif //PLOT_PLUS_H_
