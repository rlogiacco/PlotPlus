### &#x26A0; **IMPORTANT**
 
> Please, before submitting a support request read carefully this README and check if an answer already exists among [previously answered questions](https://github.com/rlogiacco/PlotPlus/issues?q=label:question): do not abuse of the Github issue tracker.

<!-- omit in toc -->
PlotPlus [![Build Status][travis-status]][travis]
=============
[travis]: https://travis-ci.org/rlogiacco/PlotPlus
[travis-status]: https://travis-ci.org/rlogiacco/PlotPlus.svg?branch=master

This work is largely based on the [SimPlot Arduino library](https://github.com/jantje/ArduinoLibraries/tree/master/simplot) authored by my friend [jantje](https://github.com/jantje) who is also the author of [Sloeber](http://sloeber.io), the best IDE for Arduino out there!

Once upon a time, there was SimPlot, a plotting tool working side by side with a plotting library available for many platforms, including Arduino.

That library, while still available for use, has become quite difficult to retrieve and it's not listed by the Arduino Library Manager, which makes it even more hidden than before.

This is an attempt to bring that library back to life while also trying to improve its API.

<!-- toc -->

- [Preamble](#preamble)
- [Usage](#usage)
  - [Modern API](#modern-api)
    - [Import and configure](#import-and-configure)
    - [Setup](#setup)
    - [Data plotting](#data-plotting)
  - [Classic API](#classic-api)
    - [Import and configure](#import-and-configure-1)
    - [Setup](#setup-1)
    - [Data plotting](#data-plotting-1)
- [Clients](#clients)

<!-- tocstop -->

# Preamble

Data plotting can be quite challenging for microcontrollers as those devices are commonly unable to access to the high-resolution display and rarely have the required computational power. 
The common approach in these cases is to store the information on a permanent support for later analysis or send the data live to a more powerful device. This library supports the latter using a client application to render a graphical representation of the transferred data.

The `PlotPlus` library can either use the Arduino hardware `Serial` (used by default) or any other stream, like `SoftwareSerial` or `Serial2` to send the information to the plotting device.
 
To avoid to clutter too much the serial console, which is commonly also used for debugging purposes, and in order to reduce to the bare minimum the size of the transferred data, the used protocol is binary: the SIMPLOT packet structure which supports up to 6 concurrent channels.


  | header   | size    | payload         |
  |----------|---------|-----------------|
  | `0xABCD` | 2 bytes | up to 12 bytes  |


# Usage

The library is fully backwards compatible with the old SimPlot library, but it also introduces a more modern API.

## Modern API

### Import and configure

Library configuration must occur **BEFORE** importing the header file and can be performed via macro definitions:

* by defining `PLOT_PLUS` or setting it to `false` the library can be completely disabled allowing to leave the plot statements in your production code and enabling/disabling them whenever necessary
* the `PLOT_PLUS_STREAM` definition controls the output stream used by the `plot(...)` function (defaults to `Serial`)

The following represents a fully configured example import:
 
```c
// the following definition can replace the default output stream (Serial)
#define PLOT_PLUS_STREAM Serial2

//the following completely disables the plot statements
#define PLOT_PLUS false

#include <PlotPlus.h>
```

### Setup

The library does not attempt to mangle with the output stream, meaning you should ensure the stream is properly set **BEFORE** using the `plot(...)` function.

In case you are going for the *default* setup, this means you should set the serial port speed, but you need to adapt your setup in case of more exotic configurations (`SoftwareSerial`, `Serial2`, etc...)

``` cpp
void setup() {
  Serial.begin(9600);
}
```

### Data plotting

Plotting a datapoint is as simple as calling a single function with all the channels you want want to plot:

``` cpp
plot(analogRead(A0), analogRead(A1), analogRead(A2));
// the above is equivalent to 
plotWith(Serial, analogRead(A0), analogRead(A1), analogRead(A2));
```

One caveat is you should maintain the channel order and send a channel value even in case you don't want to update the channel value:

``` cpp
plot(temperature, humidity);
  
// if later on, you want to also plot luminance, you must also send temperature and humidity
plot(temperature, humidity, luminance);
```

The API allows to specify the output stream on a per data point, allowing to send certain data over one stream and other over another stream, actually expanding the plotting capabilities:

``` cpp
// gyro is sent over Serial
plotWith(Serial, x, y, z, vx, vy, vz);
  
// gps is sent over Serial2
plotWith(Serial2, latitude, longitude);
  
// environment is sent over SoftwareSerial
plotWith(Soft, temp, humidity, luminance, altitude);  
```


## Classic API

The old SimPlot API is fully supported allowing for a smooth transition from SimPlot to PlotPlus.

### Import and configure

There is no library confirutaion option, so the classical import is the only directive here:
 
``` cpp
#include <simplot.h>
```

### Setup

The library does not attempt to mangle with the output stream, meaning you should ensure the stream is properly set **BEFORE** using any of the `plot` functions.

``` cpp
void setup() {
  Serial.begin(9600);
}
```

### Data plotting

Plotting a datapoint is as simple as calling a single function with all the channels you want want to plot, with multiple options available supporting multiple channel configurations:

``` cpp
plot1(output,  data1);
plot2(output,  data1,  data2);
plot3(output,  data1,  data2,  data3);
plot4(output,  data1,  data2,  data3,  data4);
plot5(output,  data1,  data2,  data3,  data4,  data5);
plot6(output,  data1,  data2,  data3,  data4,  data5,  data6);

// the most versatile approach is using the simple_plot function
simple_plot_(output, numData, data1, data2, data3, data4, data5, data6);  
```

One caveat is you should maintain the channel order and send a channel value even in case you don't want to update the channel value:

``` cpp
plot2(Serial, temperature, humidity);
  
// if later on, you want to also plot luminance, you must also send temperature and humidity
plot3(Serial, temperature, humidity, luminance);
```

The API allows to specify the output stream on a per data point, allowing to send certain data over one stream and other over another stream, actually expanding the plotting capabilities:

``` cpp
// gyro is sent over Serial
plot6(Serial, x, y, z, vx, vy, vz);
  
// gps is sent over Serial2
plot2(Serial2, latitude, longitude);

// environment is sent over SoftwareSerial
plot4(Soft, temp, humidity, luminance, altitude);
```

# Clients

My client of choice is [Sloeber](http:///sloeber.io), an Eclipse Plugin providing full development support for Arduino and other MCUs like ESP8266 and similar. This should be also your favourite choice if you are on an OS other than Windows.

[Sloeber](http:///sloeber.io) has a very nice 6 channels plotter view and the ability to filter out the plotting info from the serial console resulting in a very smooth experience.

If you look for something more lightweight, then the old [SimPlot client for Windows](https://github.com/infomaniac50/projectsimplot) should satisfy your needs.
