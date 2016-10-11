#include <glib.h>

/* defines an array of strings named caps_list, that contains a list of caps for
   general tests. So if you don't know what caps to use to write a test, just
   include this file */

static const gchar *caps_list[] = {
  "audio/x-adpcm, layout=(string)quicktime; audio/x-adpcm, layout=(string)quicktime; audio/x-adpcm, layout=(string)wav; audio/x-adpcm, layout=(string)wav; audio/x-adpcm, layout=(string)dk3; audio/x-adpcm, layout=(string)dk3; audio/x-adpcm, layout=(string)dk4; audio/x-adpcm, layout=(string)dk4; audio/x-adpcm, layout=(string)westwood; audio/x-adpcm, layout=(string)westwood; audio/x-adpcm, layout=(string)smjpeg; audio/x-adpcm, layout=(string)smjpeg; audio/x-adpcm, layout=(string)microsoft; audio/x-adpcm, layout=(string)microsoft; audio/x-adpcm, layout=(string)4xm; audio/x-adpcm, layout=(string)4xm; audio/x-adpcm, layout=(string)xa; audio/x-adpcm, layout=(string)xa; audio/x-adpcm, layout=(string)adx; audio/x-adpcm, layout=(string)adx; audio/x-adpcm, layout=(string)ea; audio/x-adpcm, layout=(string)ea; audio/x-adpcm, layout=(string)g726; audio/x-adpcm, layout=(string)g726",
  "video/x-raw-yuv, width=(int)[ 16, 4096 ], height=(int)[ 16, 4096 ], framerate=(double)[ 0, 1.7976931348623157e+308 ], format=(fourcc)I420; video/x-raw-yuv, width=(int)[ 16, 4096 ], height=(int)[ 16, 4096 ], framerate=(double)[ 0, 1.7976931348623157e+308 ], format=(fourcc)YUY2; video/x-raw-rgb, width=(int)[ 16, 4096 ], height=(int)[ 16, 4096 ], framerate=(double)[ 0, 1.7976931348623157e+308 ], bpp=(int)24, depth=(int)24, red_mask=(int)16711680, green_mask=(int)65280, blue_mask=(int)255, endianness=(int)4321; video/x-raw-rgb, width=(int)[ 16, 4096 ], height=(int)[ 16, 4096 ], framerate=(double)[ 0, 1.7976931348623157e+308 ], bpp=(int)24, depth=(int)24, red_mask=(int)255, green_mask=(int)65280, blue_mask=(int)16711680, endianness=(int)4321; video/x-raw-yuv, width=(int)[ 16, 4096 ], height=(int)[ 16, 4096 ], framerate=(double)[ 0, 1.7976931348623157e+308 ], format=(fourcc)Y42B; video/x-raw-rgb, width=(int)[ 16, 4096 ], height=(int)[ 16, 4096 ], framerate=(double)[ 0, 1.7976931348623157e+308 ], bpp=(int)32, depth=(int)24, red_mask=(int)65280, green_mask=(int)16711680, blue_mask=(int)-16777216, endianness=(int)4321; video/x-raw-yuv, width=(int)[ 16, 4096 ], height=(int)[ 16, 4096 ], framerate=(double)[ 0, 1.7976931348623157e+308 ], format=(fourcc)YUV9; video/x-raw-yuv, width=(int)[ 16, 4096 ], height=(int)[ 16, 4096 ], framerate=(double)[ 0, 1.7976931348623157e+308 ], format=(fourcc)Y41B; video/x-raw-rgb, width=(int)[ 16, 4096 ], height=(int)[ 16, 4096 ], framerate=(double)[ 0, 1.7976931348623157e+308 ], bpp=(int)16, depth=(int)16, red_mask=(int)63488, green_mask=(int)2016, blue_mask=(int)31, endianness=(int)1234; video/x-raw-rgb, width=(int)[ 16, 4096 ], height=(int)[ 16, 4096 ], framerate=(double)[ 0, 1.7976931348623157e+308 ], bpp=(int)16, depth=(int)15, red_mask=(int)31744, green_mask=(int)992, blue_mask=(int)31, endianness=(int)1234",
  "video/x-raw-yuv, format=(fourcc){ YUY2, I420 }, width=(int)[ 1, 2147483647 ], height=(int)[ 1, 2147483647 ], framerate=(double)[ 0, 1.7976931348623157e+308 ]; video/x-jpeg, width=(int)[ 1, 2147483647 ], height=(int)[ 1, 2147483647 ]; video/x-divx, divxversion=(int)[ 3, 5 ], width=(int)[ 1, 2147483647 ], height=(int)[ 1, 2147483647 ]; video/x-xvid, width=(int)[ 1, 2147483647 ], height=(int)[ 1, 2147483647 ]; video/x-3ivx, width=(int)[ 1, 2147483647 ], height=(int)[ 1, 2147483647 ]; video/x-msmpeg, msmpegversion=(int)[ 41, 43 ], width=(int)[ 1, 2147483647 ], height=(int)[ 1, 2147483647 ]; video/mpeg, mpegversion=(int)1, systemstream=(boolean)false, width=(int)[ 1, 2147483647 ], height=(int)[ 1, 2147483647 ]; video/x-h263, width=(int)[ 1, 2147483647 ], height=(int)[ 1, 2147483647 ]; video/x-dv, systemstream=(boolean)false, width=(int)720, height=(int){ 576, 480 }; video/x-huffyuv, width=(int)[ 1, 2147483647 ], height=(int)[ 1, 2147483647 ]",
  "video/x-raw-yuv, format=(fourcc){ YUY2, I420 }, width=(int)[ 16, 4096 ], height=(int)[ 16, 4096 ], framerate=(double)[ 0, 1.7976931348623157e+308 ]; image/jpeg, width=(int)[ 16, 4096 ], height=(int)[ 16, 4096 ]; video/x-divx, width=(int)[ 16, 4096 ], height=(int)[ 16, 4096 ], divxversion=(int)[ 3, 5 ]; video/x-xvid, width=(int)[ 16, 4096 ], height=(int)[ 16, 4096 ]; video/x-3ivx, width=(int)[ 16, 4096 ], height=(int)[ 16, 4096 ]; video/x-msmpeg, width=(int)[ 16, 4096 ], height=(int)[ 16, 4096 ], msmpegversion=(int)[ 41, 43 ]; video/mpeg, width=(int)[ 16, 4096 ], height=(int)[ 16, 4096 ], mpegversion=(int)1, systemstream=(boolean)false; video/x-h263, width=(int)[ 16, 4096 ], height=(int)[ 16, 4096 ]; video/x-dv, width=(int)720, height=(int){ 576, 480 }, systemstream=(boolean)false; video/x-huffyuv, width=(int)[ 16, 4096 ], height=(int)[ 16, 4096 ]",
  "video/x-raw-rgb, bpp=(int)32, depth=(int)24, endianness=(int)4321, red_mask=(int)65280, green_mask=(int)16711680, blue_mask=(int)-16777216, width=(int)[ 16, 4096 ], height=(int)[ 16, 4096 ], framerate=(double)[ 0, 1.7976931348623157e+308 ]; video/x-raw-rgb, bpp=(int)32, depth=(int)24, endianness=(int)4321, red_mask=(int)-16777216, green_mask=(int)16711680, blue_mask=(int)65280, width=(int)[ 16, 4096 ], height=(int)[ 16, 4096 ], framerate=(double)[ 0, 1.7976931348623157e+308 ]",
  "video/x-raw-rgb, bpp=(int)32, depth=(int)24, endianness=(int)4321, red_mask=(int)65280, green_mask=(int)16711680, blue_mask=(int)-16777216, width=(int)[ 16, 4096 ], height=(int)[ 16, 4096 ], framerate=(double)[ 0, 1.7976931348623157e+308 ]",
  "video/x-raw-yuv, format=(fourcc){ I420 }, width=(int)[ 16, 4096 ], height=(int)[ 16, 4096 ], framerate=(double)[ 0, 1.7976931348623157e+308 ]",
  "video/x-raw-rgb, bpp = (int) 32, depth = (int) 24, endianness = (int) BIG_ENDIAN, red_mask = (int) 0x000000FF, framerate = (double) [ 0, max ]",
  "video/x-raw-rgb, bpp = (int) 32, depth = (int) 24, endianness = (int) BIG_ENDIAN, red_mask = (int) 0xFF000000, framerate = (double) [ 0, max ]",
  "video/x-raw-rgb,\\ bpp=(int)32",
  /* Test fraction type */
  "test/gst-fraction, fraction = (fraction) 1/8",
  "test/gst-fraction, fraction = (fraction) MIN",
  "test/gst-fraction, fraction = (fraction) MAX",
  /* Test fraction range */
  "test/gst-fraction-range, fraction = (fraction) [ 1/4, 1/3 ]",
  "test/gst-fraction-range, fraction = (fraction) [ MIN, MAX ]",
  "test/gst-fraction-range, fraction = (fraction) [ 1/MAX, MAX ]",
  /* Test lists of fractions and fraction ranges */
  "test/gst-fraction-range, fraction = (fraction) { [ 1/4, 1/3 ], 1/8 }",
  "test/gst-fraction-range, fraction = (fraction) { [ 1/4, 1/3 ], [ 1/8, 2/8 ] }",

  /* Some random checks */
  "video/x-raw-yuv, format = (fourcc) { I420, Y42B, Y444 }, framerate = (fraction) [1/MAX, MAX], width = (int) [ 1, MAX ], height = (int) [ 1, MAX ]",

  "ANY",
  "EMPTY"
};

