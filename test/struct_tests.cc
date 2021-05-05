#include <stdlib.h>
#include <napi.h>

#ifdef _WIN32
  #define __alignof__ __alignof
#endif

using namespace Napi;

namespace {

typedef struct _test1 {
  int a;
  int b;
  double c;
} test1;

typedef struct _test2 {
  int a;
  double b;
  int c;
} test2;

typedef struct _test3 {
  double a;
  int b;
  int c;
} test3;

typedef struct _test4 {
  double a;
  double b;
  int c;
} test4;

typedef struct _test5 {
  int a;
  double b;
  double c;
} test5;

typedef struct _test6 {
  char a;
  short b;
  int c;
} test6;

typedef struct _test7 {
  int a;
  short b;
  char c;
} test7;

typedef struct _test8 {
  int a;
  short b;
  char c;
  char d;
} test8;

typedef struct _test9 {
  int a;
  short b;
  char c;
  char d;
  char e;
} test9;

typedef struct _test10 {
  test1 a;
  char b;
} test10;

// this one simulates the `ffi_type` struct
typedef struct _test11 {
  size_t a;
  unsigned short b;
  unsigned short c;
  struct _test11 **d;
} test11;

typedef struct _test12 {
  char *a;
  int b;
} test12;

typedef struct _test13 {
  char a;
  char b[2];
} test13;

typedef struct _test14 {
  char a;
  char b[2];
  short c;
  char d;
} test14;

typedef struct _test15 {
  test1 a;
  test1 b;
} test15;

typedef struct _test16 {
  double a[10];
  char b[3];
  int c[6];
} test16;

typedef struct _test17 {
  char a[3];
} test17;

typedef struct _test18 {
  test17 a[100];
} test18;

/* test19 example is from libdespotify
 * See: https://github.com/TooTallNate/ref-struct/issues/1
 */

#define STRING_LENGTH 256
typedef struct _test19 {
  bool has_meta_data;
  bool playable;
  bool geo_restricted;
  unsigned char track_id[33];
  unsigned char file_id[41];
  unsigned int file_bitrate;
  unsigned char album_id[33];
  unsigned char cover_id[41];
  unsigned char *key;

  char *allowed;
  char *forbidden;

  char title[STRING_LENGTH];
  struct artist* artist;
  char album[STRING_LENGTH];
  int length;
  int tracknumber;
  int year;
  float popularity;
  struct _test19 *next; /* in case of multiple tracks
                          in an album or playlist struct */
} test19;

#pragma pack(1)
typedef struct _test20 {
  char a;
  void *p;
} test20;

#pragma pack()
typedef struct _test21 {
  char a;
  void *p;
} test21;

Object Initialize(Env env, Object exports) {

  exports.Set("test1 sizeof", sizeof(test1));
  exports.Set("test1 alignof", __alignof__(test1));
  exports.Set("test1 offsetof a", offsetof(test1, a));
  exports.Set("test1 offsetof b", offsetof(test1, b));
  exports.Set("test1 offsetof c", offsetof(test1, c));

  exports.Set("test2 sizeof", sizeof(test2));
  exports.Set("test2 alignof", __alignof__(test2));
  exports.Set("test2 offsetof a", offsetof(test2, a));
  exports.Set("test2 offsetof b", offsetof(test2, b));
  exports.Set("test2 offsetof c", offsetof(test2, c));

  exports.Set("test3 sizeof", sizeof(test3));
  exports.Set("test3 alignof", __alignof__(test3));
  exports.Set("test3 offsetof a", offsetof(test3, a));
  exports.Set("test3 offsetof b", offsetof(test3, b));
  exports.Set("test3 offsetof c", offsetof(test3, c));

  exports.Set("test4 sizeof", sizeof(test4));
  exports.Set("test4 alignof", __alignof__(test4));
  exports.Set("test4 offsetof a", offsetof(test4, a));
  exports.Set("test4 offsetof b", offsetof(test4, b));
  exports.Set("test4 offsetof c", offsetof(test4, c));

  exports.Set("test5 sizeof", sizeof(test5));
  exports.Set("test5 alignof", __alignof__(test5));
  exports.Set("test5 offsetof a", offsetof(test5, a));
  exports.Set("test5 offsetof b", offsetof(test5, b));
  exports.Set("test5 offsetof c", offsetof(test5, c));

  exports.Set("test6 sizeof", sizeof(test6));
  exports.Set("test6 alignof", __alignof__(test6));
  exports.Set("test6 offsetof a", offsetof(test6, a));
  exports.Set("test6 offsetof b", offsetof(test6, b));
  exports.Set("test6 offsetof c", offsetof(test6, c));

  exports.Set("test7 sizeof", sizeof(test7));
  exports.Set("test7 alignof", __alignof__(test7));
  exports.Set("test7 offsetof a", offsetof(test7, a));
  exports.Set("test7 offsetof b", offsetof(test7, b));
  exports.Set("test7 offsetof c", offsetof(test7, c));

  exports.Set("test8 sizeof", sizeof(test8));
  exports.Set("test8 alignof", __alignof__(test8));
  exports.Set("test8 offsetof a", offsetof(test8, a));
  exports.Set("test8 offsetof b", offsetof(test8, b));
  exports.Set("test8 offsetof c", offsetof(test8, c));
  exports.Set("test8 offsetof d", offsetof(test8, d));

  exports.Set("test9 sizeof", sizeof(test9));
  exports.Set("test9 alignof", __alignof__(test9));
  exports.Set("test9 offsetof a", offsetof(test9, a));
  exports.Set("test9 offsetof b", offsetof(test9, b));
  exports.Set("test9 offsetof c", offsetof(test9, c));
  exports.Set("test9 offsetof d", offsetof(test9, d));
  exports.Set("test9 offsetof e", offsetof(test9, e));

  exports.Set("test10 sizeof", sizeof(test10));
  exports.Set("test10 alignof", __alignof__(test10));
  exports.Set("test10 offsetof a", offsetof(test10, a));
  exports.Set("test10 offsetof b", offsetof(test10, b));

  exports.Set("test11 sizeof", sizeof(test11));
  exports.Set("test11 alignof", __alignof__(test11));
  exports.Set("test11 offsetof a", offsetof(test11, a));
  exports.Set("test11 offsetof b", offsetof(test11, b));
  exports.Set("test11 offsetof c", offsetof(test11, c));
  exports.Set("test11 offsetof d", offsetof(test11, d));

  exports.Set("test12 sizeof", sizeof(test12));
  exports.Set("test12 alignof", __alignof__(test12));
  exports.Set("test12 offsetof a", offsetof(test12, a));
  exports.Set("test12 offsetof b", offsetof(test12, b));

  exports.Set("test13 sizeof", sizeof(test13));
  exports.Set("test13 alignof", __alignof__(test13));
  exports.Set("test13 offsetof a", offsetof(test13, a));
  exports.Set("test13 offsetof b", offsetof(test13, b));

  exports.Set("test14 sizeof", sizeof(test14));
  exports.Set("test14 alignof", __alignof__(test14));
  exports.Set("test14 offsetof a", offsetof(test14, a));
  exports.Set("test14 offsetof b", offsetof(test14, b));
  exports.Set("test14 offsetof c", offsetof(test14, c));
  exports.Set("test14 offsetof d", offsetof(test14, d));

  exports.Set("test15 sizeof", sizeof(test15));
  exports.Set("test15 alignof", __alignof__(test15));
  exports.Set("test15 offsetof a", offsetof(test15, a));
  exports.Set("test15 offsetof b", offsetof(test15, b));

  exports.Set("test16 sizeof", sizeof(test16));
  exports.Set("test16 alignof", __alignof__(test16));
  exports.Set("test16 offsetof a", offsetof(test16, a));
  exports.Set("test16 offsetof b", offsetof(test16, b));
  exports.Set("test16 offsetof c", offsetof(test16, c));

  exports.Set("test17 sizeof", sizeof(test17));
  exports.Set("test17 alignof", __alignof__(test17));
  exports.Set("test17 offsetof a", offsetof(test17, a));

  exports.Set("test18 sizeof", sizeof(test18));
  exports.Set("test18 alignof", __alignof__(test18));
  exports.Set("test18 offsetof a", offsetof(test18, a));

  exports.Set("test19 sizeof", sizeof(test19));
  exports.Set("test19 alignof", __alignof__(test19));
  exports.Set("test19 offsetof has_meta_data", offsetof(test19, has_meta_data));
  exports.Set("test19 offsetof playable", offsetof(test19, playable));
  exports.Set("test19 offsetof geo_restricted", offsetof(test19, geo_restricted));
  exports.Set("test19 offsetof track_id", offsetof(test19, track_id));
  exports.Set("test19 offsetof file_id", offsetof(test19, file_id));
  exports.Set("test19 offsetof file_bitrate", offsetof(test19, file_bitrate));
  exports.Set("test19 offsetof album_id", offsetof(test19, album_id));
  exports.Set("test19 offsetof cover_id", offsetof(test19, cover_id));
  exports.Set("test19 offsetof key", offsetof(test19, key));
  exports.Set("test19 offsetof allowed", offsetof(test19, allowed));
  exports.Set("test19 offsetof forbidden", offsetof(test19, forbidden));
  exports.Set("test19 offsetof title", offsetof(test19, title));
  exports.Set("test19 offsetof artist", offsetof(test19, artist));
  exports.Set("test19 offsetof album", offsetof(test19, album));
  exports.Set("test19 offsetof length", offsetof(test19, length));
  exports.Set("test19 offsetof tracknumber", offsetof(test19, tracknumber));
  exports.Set("test19 offsetof year", offsetof(test19, year));
  exports.Set("test19 offsetof popularity", offsetof(test19, popularity));
  exports.Set("test19 offsetof next", offsetof(test19, next));

  exports.Set("test20 sizeof", sizeof(test20));
  exports.Set("test20 alignof", __alignof__(test20));

  exports.Set("test21 sizeof", sizeof(test21));
  exports.Set("test21 alignof", __alignof__(test21));

  return exports;
}

} // anonymous namespace

NODE_API_MODULE(struct_tests, Initialize);
