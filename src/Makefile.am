bin_PROGRAMS = harpsplayer
harpsplayer_SOURCES = harps_player.cpp

# set the include path found by configure
INCLUDES= $(all_includes)

harpsplayer_CPPFLAGS= @HARPS_CFLAGS@
harpsplayer_CFLAGS= @HARPS_CFLAGS@

# the library search path.
harpsplayer_LDFLAGS = $(all_libraries) @HARPS_LIBS@

noinst_HEADERS = score.hpp
